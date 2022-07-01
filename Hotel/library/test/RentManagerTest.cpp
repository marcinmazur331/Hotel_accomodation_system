//
// Created by student on 12.06.2022.
//
#include <boost/test/unit_test.hpp>

#include "managers/RentManager.h"
#include "repositories/Repository.h"
#include "repositories/ClientRepository.h"
#include "repositories/StorageContainer.hpp"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Room.h"
#include "exceptions/LogicException.h"

struct RentManagerLocalFixture {
    std::string testFirstName = "Marcin";
    std::string testLastName = "Mazur";
    std::string testPersonalId = "242467";
    int testID = 123;
    pt::ptime testBeginRentTime = pt::not_a_date_time;
    int testRoomNumber = 39;
    double testBasePrice = 100;
    int testRoomCapacity = 2;

    RoomPtr testRoom;
    ClientPtr testClient;
    ClientTypePtr testClientDefault;
    RoomPtr testRoom2;
    StorageContainer container;


    RentManagerLocalFixture() {
        testRoom = std::make_shared<Room>(testRoomNumber, testRoomCapacity, testBasePrice);
        testClientDefault = std::make_shared<Default>();
        testClient = std::make_shared<Client>(testFirstName, testLastName, testPersonalId, testClientDefault);
        testRoom2 = std::make_shared<Room>(4, 2, 100);

    }

    ~RentManagerLocalFixture() {}
};
BOOST_FIXTURE_TEST_SUITE(RentManagerSuiteTest, RentManagerLocalFixture)


    BOOST_AUTO_TEST_CASE(RentRoomTest) {
        RentManager rManager;

        RentPtr testRent = rManager.rentRoom(testID,testClient, testRoom);

        BOOST_TEST(rManager.getRoomRent(testRoom) == testRent);
    }

    BOOST_AUTO_TEST_CASE(ReturnRoomTest) {
        RentManager rManager;

        RentPtr testRent = rManager.rentRoom(testID,testClient, testRoom);
        rManager.returnRoom(testRoom);

        BOOST_TEST(rManager.getRoomRent(testRoom) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(findRoomRentTest) {
        RentManager rManager;

        RentPtr testRent1 = rManager.rentRoom(testID,testClient, testRoom);
        RentPtr testRent2 = rManager.rentRoom(testID,testClient, testRoom);

        BOOST_TEST(rManager.getRoomRent(testRoom) == testRent1);
    }
    BOOST_AUTO_TEST_CASE(RentRoomTestExceptions){
    RentManager rManager;
    RentPtr rent = rManager.rentRoom(testID,testClient, testRoom);
    BOOST_REQUIRE_THROW(rManager.rentRoom(testID,nullptr, testRoom),LogicException);
}

    BOOST_AUTO_TEST_CASE(findRoomRentTestNullPtr) {
        RentManager rManager;

        rManager.rentRoom(testID,testClient, testRoom);

        BOOST_TEST(rManager.getRoomRent(testRoom2) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(ChangeClientTypeTest) {
        RentManager rManager;

        BOOST_TEST(testClient->getClientType()->getType() == "DEFAULT");

        RoomPtr expensiveRoom = std::make_shared<Room>(9999, testRoomNumber, testRoomCapacity);

        rManager.rentRoom(testID,testClient, expensiveRoom);

        rManager.returnRoom(expensiveRoom);

        BOOST_TEST(testClient->getClientType()->getType() == "DEFAULT");
    }
BOOST_AUTO_TEST_SUITE_END()


