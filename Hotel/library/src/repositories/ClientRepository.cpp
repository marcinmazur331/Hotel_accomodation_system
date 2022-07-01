//
// Created by student on 10.06.2022.
//

#include "../../include/repositories/ClientRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../../include/exceptions/LogicException.h"

std::string ClientRepository::report() {
    std::stringstream out;
    for(auto  i: element){
        out << i->toString()<<"\n";
    }
    return out.str();
}

void ClientRepository::writeToFile() {
    std::ofstream file("/home/student/HotelInfo.txt");
    if(!file.is_open()) throw LogicException("File has not open properly!");
    for (auto i: element) {
        file << i->toString() << "\n";
    }
    file.close();
    if(file.is_open()) throw LogicException("File has not close properly!");
}

ClientPtr ClientRepository::findByPersonalId(const std::string &id) const {
    auto wynik = std::find_if(element.begin(), element.end(), [id](ClientPtr client) -> bool {
        return (client->getPersonalId() ==id);
    });
    if (wynik == element.end()) return nullptr;
    return *wynik;
}
