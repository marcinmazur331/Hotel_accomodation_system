//
// Created by student on 12.06.2022.
//

#include "repositories/StorageContainer.hpp"

StorageContainer::StorageContainer() {}

StorageContainer::~StorageContainer() {

}

const ClientRepository &StorageContainer::getClientRepo() const {
    return clientRepo;
}

const RentRepository &StorageContainer::getRentRepo() const {
    return rentRepo;
}

const RoomRepository &StorageContainer::getRoomRepo() const {
    return roomRepo;
}
