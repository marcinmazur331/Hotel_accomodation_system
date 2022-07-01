//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENTTYPE_H
#define INTRODUCTIONPROJECT_CLIENTTYPE_H


#include "Client.h"

class ClientType {
public:
    virtual double applyDiscount(double price)=0;
    virtual std::string getType()=0;
};


#endif //INTRODUCTIONPROJECT_CLIENTTYPE_H
