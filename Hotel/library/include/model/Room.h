//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_ROOM_H
#define INTRODUCTIONPROJECT_ROOM_H


#include <string>

class Room {
    int roomNumber;
    bool Archive=false;
    int roomCapacity;
    double basePrice;
public:
    Room(int roomNumber, int roomCapacity, double basePrice);

    virtual ~Room();

    int getRoomNumber() const;

    bool isArchive() const;

    void setArchive(bool archive);

    int getRoomCapacity() const;

    double getBasePrice() const;

    void setBasePrice(double basePrice);

    std::string toString();
};



#endif //INTRODUCTIONPROJECT_ROOM_H
