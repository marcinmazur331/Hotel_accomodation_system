//
// Created by student on 10.06.2022.
//

#include "../../include/repositories/RoomRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../../include/exceptions/LogicException.h"


std::string RoomRepository::report() {
    std::stringstream out;
    for(auto  i: element){
        out << i->toString()<<"\t";
    }
    return out.str();
}

void RoomRepository::writeToFile() {
    std::ofstream file("/home/student/HotelInfo.txt");
    if(!file.is_open()) throw LogicException("File has not open properly!!");
    for (auto i: element) {
        file << i->toString() << "\n";
    }
    file.close();
    if(file.is_open()) throw LogicException("File has not close properly!");
}

RoomPtr RoomRepository::findByRoomNumber(const int roomNumber) const {
    auto wynik = std::find_if(element.begin(), element.end(), [roomNumber](RoomPtr room) -> bool {
        return (room->getRoomNumber() ==roomNumber);
    });
    if (wynik == element.end()) return nullptr;
    return *wynik;
}
