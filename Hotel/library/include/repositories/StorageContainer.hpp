//
// Created by student on 12.06.2022.
//

#ifndef INTRODUCTIONPROJECT_STORAGECONTAINER_HPP
#define INTRODUCTIONPROJECT_STORAGECONTAINER_HPP

#include "repositories/Repository.h"
#include "repositories/RoomRepository.h"
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/Default.h"
#include "model/RegularCustomer.h"
#include "model/Rent.h"
#include "model/Room.h"

class StorageContainer {
    ClientRepository clientRepo;
    RentRepository rentRepo;
    RoomRepository roomRepo;
public:
    StorageContainer();
    virtual ~StorageContainer();

    const ClientRepository &getClientRepo() const;
    const RentRepository &getRentRepo() const;
    const RoomRepository &getRoomRepo() const;
};


#endif //INTRODUCTIONPROJECT_STORAGECONTAINER_HPP
