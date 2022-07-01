//
// Created by student on 11.06.2022.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Room.h"
#include "model/Rent.h"
#include "typedef.h"
#include "model/Default.h"
#include "exceptions/ParameterException.h"


namespace pt = boost::posix_time;

struct TestSuiteRentFixture {
    unsigned int testID = 123;
    std::string testFirstName = "Marcin";
    std::string testLastName = "Mazur";
    std::string testPersonalId = "242467";
    double testRentCost = 200.0;
    double testBasePrice = 100.0;
    std::ostringstream testInfo;

    pt::ptime testBeginTime;
    pt::ptime testEndTime;
    ClientPtr testClient;
    RoomPtr testRoom;
    RoomPtr testRoom1;
    ClientTypePtr testClientType;

    TestSuiteRentFixture() {
        testClientType = std::make_shared<Default>();
        testClient = std::make_shared<Client>(testFirstName, testLastName, testPersonalId, testClientType);
        testRoom = std::make_shared<Room>(39, 2, testBasePrice);
        testRoom1 = std::make_shared<Room>(40, 1, testBasePrice);

        testBeginTime = pt::second_clock::local_time();
        testEndTime = testBeginTime + pt::hours(1);
    }

    ~TestSuiteRentFixture() {}

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTestCase) {

        Rent rent(testID, testClient, testRoom, testBeginTime);
        BOOST_TEST_REQUIRE(&rent != nullptr);
    }

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        BOOST_TEST_REQUIRE( !(rent.getBeginRentTime().is_not_a_date_time()) );
        pt::time_period delta = pt::time_period(rent.getBeginRentTime(), pt::second_clock::local_time());
        BOOST_TEST(delta.length().hours() == 0);
        BOOST_TEST(delta.length().minutes() == 0);
        BOOST_TEST(rent.getEndRentTime().is_not_a_date_time());
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestCase_Exceptions) {
        BOOST_REQUIRE_THROW(Rent rent(1,nullptr,testRoom,testBeginTime),ParameterException);
        BOOST_REQUIRE_THROW(Rent rent(-1,testClient,testRoom,testBeginTime),ParameterException);
        BOOST_REQUIRE_THROW(Rent rent(1,testClient,nullptr,testBeginTime),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(GettersTestCase) {
        Rent rent(testID, testClient, testRoom, testBeginTime);
        rent.endRent(testEndTime);
        BOOST_TEST(rent.getId() == testID);
        BOOST_TEST(rent.getBeginRentTime() == testBeginTime);
        BOOST_TEST(rent.getEndRentTime() == testEndTime);
        BOOST_TEST(rent.getRentCost() == testRentCost);
        BOOST_TEST(rent.getClient() == testClient);
        BOOST_TEST(rent.getRoom() == testRoom);
    }

    BOOST_AUTO_TEST_CASE(toStringTestCase) {
        Rent rent(testID, testClient, testRoom, testBeginTime);
        pt::ptime time = testBeginTime + pt::hours(1);
        rent.endRent(time);
        testInfo << "Type: Rent\tID: " << testID << "\tClient info: " << testClient->toString() << "\tRoom info: "
                 << testRoom->toString() << "\tbegin time: " << testBeginTime << ", end time: "
                 << testEndTime << ", To pay: " + std::to_string(rent.getRentCost());
        BOOST_TEST(rent.toString()==testInfo.str());
    }

    BOOST_AUTO_TEST_CASE(CalculateFinalRentCost1DaySingleRoom) {
        Rent rent(testID, testClient, testRoom1, testBeginTime);

        pt::ptime future1h = testBeginTime + pt::hours(23);

        rent.endRent(future1h);
        BOOST_TEST(rent.getRentCost() == 100);
}

    BOOST_AUTO_TEST_CASE(CalculateFinalRentCost0) {
        Rent rent(testID, testClient, testRoom, testBeginTime);
        rent.endRent(testBeginTime);
        BOOST_TEST(rent.CalculateFinalRentCost() == 0);
        BOOST_TEST(rent.getRentCost()==0);
    }

    BOOST_AUTO_TEST_CASE(RentCostTestPermamentCost) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        pt::ptime future1h = testBeginTime + pt::hours(1);

        rent.endRent(future1h);

        double before = rent.getRentCost();

        rent.getRoom()->setBasePrice(123);

        double after = rent.getRentCost();

        BOOST_TEST(before == after);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestEndNow) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        rent.endRent(testBeginTime);

        pt::time_period skew = pt::time_period(rent.getEndRentTime(), testBeginTime);

        BOOST_TEST(rent.getEndRentTime() == testBeginTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestEndInFuture) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        pt::ptime future = testBeginTime + pt::hours(1);

        rent.endRent(future);

        pt::time_period skew = pt::time_period(rent.getEndRentTime(), future);

        BOOST_TEST(rent.getEndRentTime() == future);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestEndInPast) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        pt::ptime past = testBeginTime - pt::hours(23);

        rent.endRent(past);

        BOOST_TEST(rent.getEndRentTime() == testBeginTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestEndRentAlreadyEnded) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        rent.endRent(testBeginTime);

        pt::ptime future = testBeginTime + pt::hours(1);

        rent.endRent(future);

        BOOST_TEST(rent.getEndRentTime() == testBeginTime);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysBefore24h){
        Rent rent(testID, testClient, testRoom, testBeginTime);
        pt::ptime before24h = testBeginTime - pt::hours(24);
        rent.endRent(before24h);
        BOOST_TEST(rent.getRentDays() == 0);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysBefore1h) {
        Rent rent(testID, testClient, testRoom, testBeginTime);
        pt::ptime before1h = testBeginTime - pt::hours(1);
        rent.endRent(before1h);
        BOOST_TEST(rent.getRentDays() == 0);
    }

    BOOST_AUTO_TEST_CASE(GetDaysTestEndedAfter1h) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        pt::ptime future1h = testBeginTime + pt::hours(1);

        rent.endRent(future1h);

        BOOST_TEST(rent.getRentDays() == 1);
    }

    BOOST_AUTO_TEST_CASE(GetDaysTestEndedAfter23h59min) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        pt::ptime almostOneDay = testBeginTime + pt::hours(23) + pt::minutes(59);

        rent.endRent(almostOneDay);

        BOOST_TEST(rent.getRentDays() == 1);
    }

    BOOST_AUTO_TEST_CASE(GetDaysTestEndedAfter24h) {
        Rent rent(testID, testClient, testRoom, testBeginTime);

        pt::ptime overOneDay = testBeginTime + pt::hours(25);

        rent.endRent(overOneDay);

        BOOST_TEST(rent.getRentDays() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()