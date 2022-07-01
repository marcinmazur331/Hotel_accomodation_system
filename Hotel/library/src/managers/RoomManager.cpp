//
// Created by student on 08.06.2022.
//

#include "../../include/managers/RoomManager.h"
#include "../../include/exceptions/LogicException.h"

RoomPtr RoomManager::registerRoom(int roomNumber, int roomCapacity, double basePrice) {
    RoomPtr room = getRoom(roomNumber);
    if(room != nullptr) { throw LogicException("Cant register 2 rooms with the same roomnumber!");};
    room = std::make_shared<Room>(roomNumber,roomCapacity,basePrice);
    repository.addToRepo(room);
    return room;
}

void RoomManager::unregisterRoom(RoomPtr room) {
    if(getRoom(room->getRoomNumber()) != nullptr) room->setArchive(true);
}

std::vector<RoomPtr> RoomManager::findRoom(const RoomPredicate &predicate) {
    RoomPredicate f = [predicate](const RoomPtr & room) -> bool {
        return !room->isArchive() && predicate(room);
    };
    return repository.find(f);
}

std::vector<RoomPtr> RoomManager::findAllRoom() {
    RoomPredicate f = [](const RoomPtr & room) -> bool {return true;};
    return findRoom(f);
}

RoomPtr RoomManager::getRoom(const int &roomNumber) const {
    return repository.findByRoomNumber(roomNumber);
}


