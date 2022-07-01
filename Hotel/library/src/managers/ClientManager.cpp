//
// Created by student on 08.06.2022.
//

#include "../../include/managers/ClientManager.h"
#include "../../include/exceptions/LogicException.h"


ClientPtr ClientManager::getClient(const std::string &personalID) const {
    return repository.findByPersonalId(personalID);
}

ClientPtr ClientManager::registerClient(const std::string & firstName,const std::string & lastName,const std::string & personalID,const ClientTypePtr & clientType) {
    ClientPtr klient = getClient(personalID);
    if(klient != nullptr) { throw LogicException("Cant register 2 clients with the same id!");}
//    if(klient != nullptr) return klient;
    klient = std::make_shared<Client>(firstName,lastName,personalID,clientType);
    repository.addToRepo(klient);
    return klient;
}

void ClientManager::unregisterClient(ClientPtr client) {
    if(getClient(client->getPersonalId()) != nullptr) client->setArchive(true);
}

std::vector<ClientPtr> ClientManager::findClients(const ClientPredicate &predicate) {
    ClientPredicate f = [predicate](const ClientPtr & client) -> bool {
        return !client->isArchive() && predicate(client);
    };
    return repository.find(f);
}

std::vector<ClientPtr> ClientManager::findAllClients() {
    ClientPredicate f = [](const ClientPtr & client) -> bool {return true;};
    return findClients(f);
}




