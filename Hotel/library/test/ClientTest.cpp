//
// Created by student on 08.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/RegularCustomer.h"
#include "model/Default.h"
#include "typedef.h"
#include "exceptions/ParameterException.h"
#include "exceptions/LogicException.h"

struct ClientTestSuitLocalFuxture {
    std::string testFirstName = "Marcin";
    std::string testLastName = "Mazur";
    std::string testPersonalID = "242467";
    bool testArchived = false;
    ClientTypePtr TestClientDefault;
    ClientTypePtr TestClientRegular;

    ClientTestSuitLocalFuxture() {
        TestClientDefault = std::make_shared<Default>();
        TestClientRegular = std::make_shared<RegularCustomer>();
    }

    ~ClientTestSuitLocalFuxture() {}
};
BOOST_FIXTURE_TEST_SUITE(ClientTestSuit, ClientTestSuitLocalFuxture)

    BOOST_AUTO_TEST_CASE(ConstructorTestCase) {
        Client client(testFirstName, testLastName, testPersonalID, TestClientDefault);
        BOOST_TEST(&client != nullptr);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestCase_Exceptions) {
        BOOST_REQUIRE_THROW(Client client("",testLastName,testPersonalID,TestClientDefault),ParameterException);
        BOOST_REQUIRE_THROW(Client client(testFirstName,"",testPersonalID,TestClientDefault),ParameterException);
        BOOST_REQUIRE_THROW(Client client(testFirstName,testLastName,"",TestClientDefault),ParameterException);
        BOOST_REQUIRE_THROW(Client client(testFirstName,testLastName,testPersonalID,nullptr),ParameterException);
        Client client(testFirstName, testLastName, testPersonalID, TestClientDefault);
        BOOST_REQUIRE_THROW(client.setClientType(nullptr),LogicException);
    }

    BOOST_AUTO_TEST_CASE(GettersTestCase) {
        Client client(testFirstName, testLastName, testPersonalID, TestClientRegular);
        BOOST_TEST(client.getFirstName() == testFirstName);
        BOOST_TEST(client.getLastName() == testLastName);
        BOOST_TEST(client.getPersonalId() == testPersonalID);
        BOOST_TEST(client.getClientType() == TestClientRegular);
        BOOST_TEST(client.isArchive() == testArchived);
    }

    BOOST_AUTO_TEST_CASE(SettersTestCase) {
        Client client(testFirstName, testLastName, testPersonalID, TestClientRegular);
        client.setArchive(true);
        client.setClientType(TestClientDefault);
        client.setFirstName("Piotr");
        client.setLastName("Pleska");
        BOOST_TEST(client.getFirstName() == "Piotr");
        BOOST_TEST(client.getLastName() == "Pleska");
        BOOST_TEST(client.getClientType() == TestClientDefault);
        BOOST_TEST(client.isArchive() == true);
    }

    BOOST_AUTO_TEST_CASE(toStringTestCase) {
        Client client(testFirstName, testLastName, testPersonalID, TestClientRegular);
        std::string toStringTest = "Type: Client\tClientFirstName: " + testFirstName + "\tClientLastName: " +
                                   testLastName + "\tPresonalID: " + testPersonalID + "\tType: " +
                                   TestClientRegular->getType() + "\tArchived: " +
                                   ((client.isArchive()) ? "True" : "False");
        BOOST_TEST(client.toString() == toStringTest);
    }


BOOST_AUTO_TEST_SUITE_END()