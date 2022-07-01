//
// Created by student on 08.06.2022.
//

#include "../../include/model/Client.h"
#include "../../include/exceptions/ParameterException.h"
#include "../../include/exceptions/LogicException.h"

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const ClientTypePtr &clientType) : firstName(firstName), lastName(lastName), personalID(personalId),
                                                  clientType(clientType) {
    if(firstName == "" ) { throw ParameterException("Please insert client name!"); }
    if(lastName == "" ) { throw  ParameterException("Please insert client lastname!"); }
    if(personalId == "" ) { throw ParameterException("Please insert client's personalID");}
    if(clientType == nullptr) { throw ParameterException("Please insert client's type");}
}

Client::~Client() {

}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getPersonalId() const {
    return personalID;
}


bool Client::isArchive() const {
    return Archive;
}

void Client::setFirstName(const std::string &firstName) {
    Client::firstName = firstName;
}

void Client::setLastName(const std::string &lastName) {
    Client::lastName = lastName;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    if(clientType == nullptr) { throw LogicException("Client's type can't be nullptr!");}
    Client::clientType = clientType;
}

std::string Client::toString() {

    return "Type: Client\tClientFirstName: " + getFirstName() + "\tClientLastName: " +
           getLastName() + "\tPresonalID: " + getPersonalId() + "\tType: " +
           getClientType()->getType() + "\tArchived: " +
           ((isArchive()) ? "True" : "False");
}

double Client::applyDiscount(double price) const {
    return clientType->applyDiscount(price);
}

void Client::setArchive(bool archive) {
    Archive = archive;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}
