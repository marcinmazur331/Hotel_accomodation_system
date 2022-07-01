//
// Created by student on 10.06.2022.
//

#ifndef INTRODUCTIONPROJECT_ROOMREPOSITORY_H
#define INTRODUCTIONPROJECT_ROOMREPOSITORY_H
#include "Repository.h"
#include "../model/Room.h"

class RoomRepository : public Repository<Room> {
public:
    std::string report() ;
    void writeToFile() override;
    RoomPtr findByRoomNumber(const int roomNumber) const;
};


#endif //INTRODUCTIONPROJECT_ROOMREPOSITORY_H
