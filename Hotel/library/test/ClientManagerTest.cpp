//
// Created by student on 12.06.2022.
//
#include <boost/test/unit_test.hpp>

#include "managers/ClientManager.h"
#include "repositories/Repository.h"
#include "repositories/StorageContainer.hpp"
#include "exceptions/LogicException.h"

struct ClientManagerFixture {
    std::string testFirstName = "Marcin";
    std::string testLastName = "Mazur";
    std::string testPersonalId = "242467";

    ClientTypePtr testClientDefault;
    StorageContainer container;

    ClientManagerFixture() {
        testClientDefault = std::make_shared<Default>();
    }

    ~ClientManagerFixture() {}
};
bool testFindByClienLastName(const ClientPtr ptr){
    return ptr->getLastName() == "Kowalski";
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, ClientManagerFixture)


    BOOST_AUTO_TEST_CASE(ContructorTestCase) {
        ClientManager cManager;
        BOOST_TEST(&cManager != nullptr);
    }
    BOOST_AUTO_TEST_CASE(RegisterClientTestCase){
    ClientManager cManager;
        ClientPtr testClient = cManager.registerClient(testFirstName, testLastName, testPersonalId,testClientDefault);

        BOOST_TEST(testClient == cManager.getClient(testPersonalId));
}
    BOOST_AUTO_TEST_CASE(RegisterClientTestTheSameID) {
        ClientManager cManager;
        ClientPtr testClient = cManager.registerClient(testFirstName, testLastName, testPersonalId,testClientDefault);
        BOOST_REQUIRE_THROW(cManager.registerClient(testFirstName, testLastName, testPersonalId,testClientDefault),LogicException);
    }
    BOOST_AUTO_TEST_CASE(GetClientTest) {
        ClientManager cManager;

        ClientPtr testClient = cManager.registerClient(testFirstName, testLastName, testPersonalId, testClientDefault);

        int size = 5;
        for (int i = 0; i < size; i++) {
            std::ostringstream sout;
            sout << "012345678 " << (i);
            cManager.registerClient("Janusz", "Kowalski", sout.str(), testClientDefault);
        }
        BOOST_TEST(cManager.findAllClients().size()==6);
        BOOST_TEST(cManager.getClient(testPersonalId) == testClient);
    }
    BOOST_AUTO_TEST_CASE(GetClientTestNullPtr) {
        ClientManager cManager;

        int size = 5;
        for (int i = 0; i < size; i++) {
            std::ostringstream sout;
            sout << "012345678 " << (i);
            cManager.registerClient("Janusz", "Kowalski", sout.str(), testClientDefault);
        }
        BOOST_TEST(cManager.findAllClients().size()==5);
        BOOST_TEST(cManager.getClient(testPersonalId) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest) {
        ClientManager cManager;

        ClientPtr client = cManager.registerClient(testFirstName, testLastName, testPersonalId, testClientDefault);
        cManager.unregisterClient(client);

        BOOST_TEST(cManager.getClient(testPersonalId)->isArchive());
    }
    BOOST_AUTO_TEST_CASE(findByClientsTest){
        ClientManager cManager;
        cManager.registerClient("Janusz", "Nowak", testPersonalId, testClientDefault);
        int size = 5;
        for (int i = 0; i < size; i++) {
            std::ostringstream sout;
            sout << "012345678 " << (i);
            cManager.registerClient("Janusz", "Kowalski", sout.str(), testClientDefault);
        }
        BOOST_TEST(cManager.findClients(testFindByClienLastName).size()==5);
}
    BOOST_AUTO_TEST_CASE(findAllClientsTest){
        ClientManager cManager;
        cManager.registerClient("Janusz", "Nowak", testPersonalId, testClientDefault);
        int size = 5;
        for (int i = 0; i < size; i++) {
            std::ostringstream sout;
            sout << "012345678 " << (i);
            cManager.registerClient("Janusz", "Kowalski", sout.str(), testClientDefault);
        }
        BOOST_TEST(cManager.findAllClients().size()==6);
    }
BOOST_AUTO_TEST_SUITE_END()