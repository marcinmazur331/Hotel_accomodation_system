//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_REGULARCUSTOMER_H
#define INTRODUCTIONPROJECT_REGULARCUSTOMER_H


#include "ClientType.h"

class RegularCustomer : public ClientType {
    double applyDiscount(double price) override;
    std::string getType() override;
};



#endif //INTRODUCTIONPROJECT_REGULARCUSTOMER_H
