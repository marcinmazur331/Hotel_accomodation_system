//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENT_H
#define INTRODUCTIONPROJECT_CLIENT_H


#include <string>
#include "../typedef.h"
#include "ClientType.h"
class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    ClientTypePtr clientType;
public:
    void setArchive(bool archive);

private:
    bool Archive=false;
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           const ClientTypePtr &clientType);

    virtual ~Client();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    const ClientTypePtr &getClientType() const;

    bool isArchive() const;

    std::string toString();

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setClientType(const ClientTypePtr &clientType);

    double applyDiscount(double price) const;

};



#endif //INTRODUCTIONPROJECT_CLIENT_H
