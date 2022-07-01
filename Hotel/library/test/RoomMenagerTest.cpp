//
// Created by student on 12.06.2022.
//
#include <boost/test/unit_test.hpp>
#include "managers/RoomManager.h"
#include "repositories/Repository.h"
#include "repositories/RoomRepository.h"
#include "repositories/StorageContainer.hpp"
#include "exceptions/LogicException.h"
#include "model/Room.h"

struct RepositoryLocalFixture {

    int testRoomNumber = 1;
    double testBasePrice = 100;
    int testRoomCapacity = 2;
    StorageContainer container;
    RoomRepository rooms;
    RepositoryLocalFixture() {
        rooms = container.getRoomRepo();
    }

    ~RepositoryLocalFixture() {}
};

struct ClientManagerFixture {
    std::string testFirstName = "Marcin";
    std::string testLastName = "Mazur";
    std::string testPersonalId = "242467";

    ClientTypePtr testClientDefault;
    StorageContainer container;
    ClientRepository clients;

    ClientManagerFixture() {
        clients = container.getClientRepo();
        testClientDefault = std::make_shared<Default>();
    }

    ~ClientManagerFixture() {}
};

bool testFindByRoomCapaciity(const RoomPtr ptr) {
    return ptr->getRoomCapacity() == 1;
}

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoomManager, RepositoryLocalFixture)


    BOOST_AUTO_TEST_CASE(RoomConstructorTestCase) {
        RoomManager roomManager;
        BOOST_TEST(&roomManager != nullptr);
    }

    BOOST_AUTO_TEST_CASE(RegisterRoomTest) {
        RoomManager roomManager;

        RoomPtr testRoom = roomManager.registerRoom(testRoomNumber, testRoomCapacity, testBasePrice);

        BOOST_TEST(testRoom == roomManager.getRoom(testRoomNumber));
    }

    BOOST_AUTO_TEST_CASE(RegisterRoomTestExceptions){
        RoomManager roomManager;
        RoomPtr testRoom = roomManager.registerRoom(testRoomNumber, testRoomCapacity, testBasePrice);
        BOOST_REQUIRE_THROW(roomManager.registerRoom(testRoomNumber, testRoomCapacity, testBasePrice),LogicException);
}

    BOOST_AUTO_TEST_CASE(GetRoomTestNullPtr) {
        RoomManager roomManager;

        int size = 5;
        for (int i = 0; i < size; i++) {
            roomManager.registerRoom(testRoomNumber + i + 1, testRoomCapacity, testBasePrice);
        }

        BOOST_TEST(roomManager.getRoom(testRoomNumber) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(UnregisterRoomTest) {
        RoomManager roomManager;

        RoomPtr testRoom = roomManager.registerRoom(testRoomNumber, testRoomCapacity, testBasePrice);
        roomManager.unregisterRoom(testRoom);

        BOOST_TEST(roomManager.getRoom(testRoomNumber)->isArchive());
    }

    BOOST_AUTO_TEST_CASE(findByRoomsTest) {
        RoomManager roomManager;
        roomManager.registerRoom(testRoomNumber, 1, testBasePrice);
        int size = 5;
        for (int i = 1; i <= size; i++) {
            roomManager.registerRoom(testRoomNumber + i, testRoomCapacity, testBasePrice);
        }
        BOOST_TEST(roomManager.findRoom(testFindByRoomCapaciity).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(findAllRoomsTest) {
        RoomManager roomManager;
        roomManager.registerRoom(testRoomNumber, testRoomCapacity, testBasePrice);
        int size = 5;
        for (int i = 1; i <= size; i++) {
            roomManager.registerRoom(testRoomNumber + i, testRoomCapacity, testBasePrice);
        }
        BOOST_TEST(roomManager.findAllRoom().size() == 6);
    }

BOOST_AUTO_TEST_SUITE_END()