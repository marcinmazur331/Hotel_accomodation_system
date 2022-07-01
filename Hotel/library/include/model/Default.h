//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_DEFAULT_H
#define INTRODUCTIONPROJECT_DEFAULT_H


#include "ClientType.h"

class Default: public ClientType {
public:
    double applyDiscount(double price) override;
    std::string getType() override;
};


#endif //INTRODUCTIONPROJECT_DEFAULT_H
