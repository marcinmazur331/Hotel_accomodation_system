//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENTMANAGER_H
#define INTRODUCTIONPROJECT_CLIENTMANAGER_H
#include "../repositories/ClientRepository.h"
#include "../model/Client.h"

class ClientManager {
    ClientRepository repository;
public:

    ClientPtr registerClient(const std::string &firstName,const std::string & lastName,const std::string & personalID, const ClientTypePtr &clientType);

    void unregisterClient(ClientPtr client);

    std::vector<ClientPtr> findClients(const ClientPredicate &predicate);

    std::vector<ClientPtr> findAllClients();

    ClientPtr getClient(const std::string &personalID) const;
};


#endif //INTRODUCTIONPROJECT_CLIENTMANAGER_H
