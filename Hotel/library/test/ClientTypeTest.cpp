//
// Created by student on 11.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/Default.h"
#include "model/RegularCustomer.h"
#include "typedef.h"

BOOST_AUTO_TEST_SUITE(ClientTypeTestSuite)

    BOOST_AUTO_TEST_CASE(GetTypeTestCase) {
        ClientTypePtr clientType = std::make_shared<Default>();
        ClientTypePtr clientType1 = std::make_shared<RegularCustomer>();
        BOOST_TEST(clientType->getType() == "DEFAULT");
        BOOST_TEST(clientType1->getType() == "REGULAR_CUSTOMER");
    }
    BOOST_AUTO_TEST_CASE(ApplyDiscountTestCase) {
        ClientTypePtr clientType = std::make_shared<Default>();
        ClientTypePtr clientType1 = std::make_shared<RegularCustomer>();
        BOOST_TEST(clientType->applyDiscount(100) == 100);
        BOOST_TEST(clientType1->applyDiscount(100) == 70);
    }

BOOST_AUTO_TEST_SUITE_END()