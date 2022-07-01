//
// Created by student on 12.06.2022.
//
#include <boost/test/unit_test.hpp>
#include "repositories/Repository.h"
#include "repositories/RoomRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/ClientRepository.h"
#include "typedef.h"
#include "model/Client.h"
#include "repositories/StorageContainer.hpp"

struct RepositoryLocalFixture {
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
    RentPtr testRent;
    ClientTypePtr testClientDefault;

    StorageContainer container;

    ClientRepository clients;
    RoomRepository rooms;
    RentRepository rents;

    RepositoryLocalFixture() {
        clients = container.getClientRepo();
        rooms = container.getRoomRepo();
        rents = container.getRentRepo();

        testRoom = std::make_shared<Room>(testRoomNumber, testRoomCapacity, testBasePrice);
        testClientDefault = std::make_shared<Default>();
        testClient = std::make_shared<Client>(testFirstName, testLastName, testPersonalId, testClientDefault);
        testRent = std::make_shared<Rent>(testID, testClient, testRoom, testBeginRentTime);
    }

    ~RepositoryLocalFixture() {}
};
static bool testClientPID(const ClientPtr ptr){
    return ptr->getPersonalId() == "242467";
}
static bool testClientFirstName(const ClientPtr ptr){
    return ptr->getFirstName() == "Marcin";
}
static bool testClientLastName(const ClientPtr ptr){
    return ptr->getLastName() == "Mazur";
}
static bool testRRoomNumber(const RoomPtr ptr){
    return ptr->getRoomNumber() == 39;
}
static bool testRentId(const RentPtr ptr){
    return ptr->getId() == 123;
}
static bool testWrongRentId(const RentPtr ptr){
    return ptr->getId() == 1234;
}
static bool testWrongClientPID(const ClientPtr ptr){
    return ptr->getPersonalId() == "123";
}
static bool testWrongRoomNumber(const RoomPtr ptr){
    return ptr->getRoomNumber() == 329;
}
BOOST_FIXTURE_TEST_SUITE(AllRepositoriesTestSuite, RepositoryLocalFixture)

    BOOST_AUTO_TEST_CASE(AddToRepoTestCase) {
        clients.addToRepo(testClient);
        rooms.addToRepo(testRoom);
        rents.addToRepo(testRent);
        BOOST_TEST(clients.getRepo(0) == testClient);
        BOOST_TEST(rooms.getRepo(0) == testRoom);
        BOOST_TEST(rents.getRepo(0) == testRent);
        clients.addToRepo(nullptr);
        rooms.addToRepo(nullptr);
        rents.addToRepo(nullptr);
        BOOST_TEST(clients.size() == 1);
        BOOST_TEST(rooms.size() == 1);
        BOOST_TEST(rents.size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RemoveFromRepoTestCase) {
        BOOST_TEST(clients.size() == 0);
        BOOST_TEST(rooms.size() == 0);
        BOOST_TEST(rents.size() == 0);
        clients.addToRepo(testClient);
        rooms.addToRepo(testRoom);
        rents.addToRepo(testRent);
        BOOST_TEST(clients.size() == 1);
        BOOST_TEST(rooms.size() == 1);
        BOOST_TEST(rents.size() == 1);
        BOOST_TEST(clients.getRepo(0) == testClient);
        BOOST_TEST(rooms.getRepo(0) == testRoom);
        BOOST_TEST(rents.getRepo(0) == testRent);
        BOOST_TEST(clients.getRepo(1) == nullptr);
        BOOST_TEST(rooms.getRepo(1) == nullptr);
        BOOST_TEST(rents.getRepo(1) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(GetRepoTestCase) {
        clients.addToRepo(testClient);
        rooms.addToRepo(testRoom);
        rents.addToRepo(testRent);
        BOOST_TEST(clients.getRepo(0) == testClient);
        BOOST_TEST(rooms.getRepo(0) == testRoom);
        BOOST_TEST(rents.getRepo(0) == testRent);
        clients.removeFromRepo(testClient);
        rooms.removeFromRepo(testRoom);
        rents.removeFromRepo(testRent);
        BOOST_TEST(clients.getRepo(0) == nullptr);
        BOOST_TEST(rooms.getRepo(0) == nullptr);
        BOOST_TEST(rents.getRepo(0) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(SizeTestCase) {
        BOOST_TEST(clients.size() == 0);
        BOOST_TEST(rooms.size() == 0);
        BOOST_TEST(rents.size() == 0);
        clients.addToRepo(testClient);
        rooms.addToRepo(testRoom);
        rents.addToRepo(testRent);
        BOOST_TEST(clients.size() == 1);
        BOOST_TEST(rooms.size() == 1);
        BOOST_TEST(rents.size() == 1);
    }

    BOOST_AUTO_TEST_CASE(ReportTestCase) {
        BOOST_TEST_MESSAGE(clients.report());
        BOOST_TEST_MESSAGE(rooms.report());
        BOOST_TEST_MESSAGE(rents.report());
    }

    BOOST_AUTO_TEST_CASE(FindByTestCase) {
        clients.addToRepo(testClient);
        rooms.addToRepo(testRoom);
        rents.addToRepo(testRent);
        BOOST_TEST(clients.size() == 1);
        BOOST_TEST(rooms.size() == 1);
        BOOST_TEST(rents.size() == 1);
        BOOST_TEST(clients.find(testClientPID).size()==1);
        BOOST_TEST(clients.find(testClientLastName).size()==1);
        BOOST_TEST(clients.find(testClientFirstName).size()==1);
        BOOST_TEST(rooms.find(testRRoomNumber).size()==1);
        BOOST_TEST(rents.find(testRentId).size()==1);
        BOOST_TEST(rents.find(testWrongRentId).size()==0);
        BOOST_TEST(clients.find(testWrongClientPID).size()==0);
        BOOST_TEST(rooms.find(testWrongRoomNumber).size()==0);

        BOOST_TEST(clients.find(testClientPID).at(0)==testClient);
        BOOST_TEST(clients.find(testClientLastName).at(0)==testClient);
        BOOST_TEST(clients.find(testClientFirstName).at(0)==testClient);
        BOOST_TEST(rooms.find(testRRoomNumber).at(0)==testRoom);
        BOOST_TEST(rents.find(testRentId).at(0)==testRent);

        BOOST_TEST(clients.find(testClientPID).at(0)!=nullptr);
        BOOST_TEST(clients.find(testClientLastName).at(0)!=nullptr);
        BOOST_TEST(clients.find(testClientFirstName).at(0)!=nullptr);
        BOOST_TEST(rooms.find(testRRoomNumber).at(0)!=nullptr);
        BOOST_TEST(rents.find(testRentId).at(0)!=nullptr);

}

    BOOST_AUTO_TEST_CASE(FindAllTestCase) {
        clients.addToRepo(testClient);
        rooms.addToRepo(testRoom);
        rents.addToRepo(testRent);
        BOOST_TEST(clients.size() == 1);
        BOOST_TEST(rooms.size() == 1);
        BOOST_TEST(rents.size() == 1);
        BOOST_TEST(clients.findAll().size()==1);
        BOOST_TEST(rooms.findAll().size()==1);
        BOOST_TEST(rents.findAll().size()==1);

}

BOOST_AUTO_TEST_SUITE_END()