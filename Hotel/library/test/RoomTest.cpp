//
// Created by student on 11.06.2022.
//
#include <boost/test/unit_test.hpp>
#include "model/Room.h"
#include "exceptions/ParameterException.h"
#include "exceptions/ParameterException.h"
struct RoomTestSuitFixture {
    int roomTestNumber = 39;
    int roomTestCapacity = 2;
    double TestBasePrice = 100;
    bool TestArhived = false;
};

BOOST_FIXTURE_TEST_SUITE(RoomTestsuite, RoomTestSuitFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTestCase) {
        Room room(roomTestNumber, roomTestCapacity, TestBasePrice);
        BOOST_TEST_REQUIRE(&room != nullptr);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestCase_Exceptions) {
        BOOST_REQUIRE_THROW(Room room(1,2,-23),ParameterException);
        BOOST_REQUIRE_THROW(Room room(1,-2,23),ParameterException);
        BOOST_REQUIRE_THROW(Room room(-1,2,-23),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(GettersTestCase) {
        Room room(roomTestNumber, roomTestCapacity, TestBasePrice);
        BOOST_TEST(room.getRoomNumber() == roomTestNumber);
        BOOST_TEST(room.getRoomCapacity() == roomTestCapacity);
        BOOST_TEST(room.getBasePrice() == TestBasePrice);
        BOOST_TEST(room.isArchive() == TestArhived);
    }

    BOOST_AUTO_TEST_CASE(SettersTestCase) {
        Room room(roomTestNumber, roomTestCapacity, TestBasePrice);
        room.setBasePrice(150);
        room.setArchive(true);
        BOOST_TEST(room.getBasePrice() == 150);
        BOOST_TEST(room.isArchive() == true);
    }

    BOOST_AUTO_TEST_CASE(toStringTestCase) {
        Room room(roomTestNumber, roomTestCapacity, TestBasePrice);
        std::string toStringTest = "Type: Room\tRoomNumber: " + std::to_string(roomTestNumber) + "\tRoomCapacity: " +
                                   std::to_string(roomTestCapacity) + "\tRoomBasePrice: " +
                                   std::to_string(TestBasePrice) + "\tArchivied: " +
                                   ((TestArhived) ? "True" : "False");
        BOOST_TEST(room.toString() == toStringTest);
    }

BOOST_AUTO_TEST_SUITE_END()