//
// Created by student on 10.06.2022.
//

#include "../../include/repositories/RentRepository.h"
#include "../../include/exceptions/LogicException.h"


std::string RentRepository::report() {
    std::stringstream out;
    for(auto  i: element){
        out << i->toString()<<"\t";
    }
    return out.str();
}

void RentRepository::writeToFile() {
    std::ofstream file("/home/student/HotelInfo.txt");
    if(!file.is_open()) throw LogicException("File has not open properly!!");
    for (auto i: element) {
        file << i->toString() << "\n";
    }
    file.close();
    if(file.is_open()) throw LogicException("File has not close properly!");
}

RentPtr RentRepository::findById(const int &id) const {
    auto wynik = std::find_if(element.begin(), element.end(), [id](RentPtr rent) -> bool {
        return (rent->getId() == id);
    });
    if (wynik == element.end()) return nullptr;
    return *wynik;
}
