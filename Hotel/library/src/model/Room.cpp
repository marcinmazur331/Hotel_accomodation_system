//
// Created by student on 08.06.2022.
//

#include "../../include/model/Room.h"
#include "../../include/exceptions/ParameterException.h"

Room::Room(int roomNumber, int roomCapacity, double basePrice) : roomNumber(roomNumber), roomCapacity(roomCapacity),
                                                                 basePrice(basePrice) {
    if(roomCapacity <= 0 ) { throw ParameterException("RoomCapacity can't be lower than 0 or equal 0!");}
    if(basePrice < 0 ) { throw ParameterException("BasePrice can't be lower than 0!");}

}

Room::~Room() {

}

int Room::getRoomNumber() const {
    return roomNumber;
}

bool Room::isArchive() const {
    return Archive;
}

int Room::getRoomCapacity() const {
    return roomCapacity;
}

double Room::getBasePrice() const {
    return basePrice;
}

void Room::setBasePrice(double basePrice) {
    Room::basePrice = basePrice;
}

std::string Room::toString() {

    return "Type: Room\tRoomNumber: " + std::to_string(getRoomNumber()) + "\tRoomCapacity: " +
           std::to_string(getRoomCapacity()) + "\tRoomBasePrice: " +
           std::to_string(getBasePrice()) + "\tArchivied: " +
           ((isArchive()) ? "True" : "False");
}

void Room::setArchive(bool archive) {
    Archive = archive;
}
