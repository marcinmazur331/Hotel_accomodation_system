//
// Created by student on 08.06.2022.
//

#include "../../include/managers/RentManager.h"
#include "../../include/exceptions/LogicException.h"




RentPtr RentManager::rentRoom(int id,ClientPtr client,RoomPtr room) {
    if(client == nullptr || room == nullptr || client->isArchive() || room->isArchive() ) {throw LogicException("Wrong parameters!"); }
    RentPtr newrent = std::make_shared<Rent>(1,client,room,pt::second_clock::local_time());
    currentRents.addToRepo(newrent);
    return newrent;
}

void RentManager::returnRoom(RoomPtr room) {
    RentPtr rent = getRoomRent(room);
    if(rent == nullptr) return;
    rent->endRent(pt::second_clock::local_time());
    currentRents.removeFromRepo(rent);
    archiveRents.addToRepo(rent);
    changeClientType(rent->getClient());
}

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) const {
    return currentRents.find( [client](const RentPtr &rent) -> bool {
        return rent->getClient() == client;
    });
}

RentPtr RentManager::getRoomRent(RoomPtr room) const {
    RentPredicate f = [room] (RentPtr rent) -> bool {
        return rent->getRoom() == room;
    };
    std::vector<RentPtr> wynik = currentRents.find(f);
    if(wynik.empty()) return nullptr;
    return wynik[0];
}

double RentManager::checkClientRentBalance( ClientPtr client) const {
    double balans = 0;
    RentPredicate f = [client] (const RentPtr &rent) -> bool {
        return rent->getClient() == client;
    };
    for(auto &i : archiveRents.find(f)){
        balans += i->getRentCost();
    }
    return balans;
}

void RentManager::changeClientType(ClientPtr client){
    if(client == nullptr) return;
    double balans = checkClientRentBalance(client);
    if(balans >= 0 && balans < 3000) client->setClientType(std::make_shared<Default>());
    if(balans >= 3000 ) client->setClientType(std::make_shared<RegularCustomer>());
}

std::vector<RentPtr> RentManager::findRents(const RentPredicate &predicate) const {
    return currentRents.find(predicate);
}

std::vector<RentPtr> RentManager::findAllRents(){
    return currentRents.findAll();
}

const RentRepository &RentManager::getCurrentRents() const {
    return currentRents;
}
