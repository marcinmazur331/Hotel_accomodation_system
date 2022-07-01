//
// Created by student on 08.06.2022.
//

#include "../../include/model/RegularCustomer.h"
double RegularCustomer::applyDiscount(double price) {
    return price*0.7;
}

std::string RegularCustomer::getType() {
    return "REGULAR_CUSTOMER";
}