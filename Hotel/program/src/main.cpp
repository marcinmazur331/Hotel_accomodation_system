//
// Created by student on 08.06.2022.
//
#include <iostream>
#include "../../library/include/managers/ClientManager.h"
#include "../../library/include/managers/RoomManager.h"
#include "../../library/include/managers/RentManager.h"
#include "../../library/include/repositories/RentRepository.h"
#include "../../library/include/model/Default.h"


int main(){

    ClientTypePtr type = std::make_shared<Default>();
    try {
        ClientPtr client = std::make_shared<Client>("", "naziwsko", "id", type);
    } catch (int) {
        std::cout<<"Your client doesn't have name!"<<std::endl;
    }
    catch(...) {
        std::cout<<"Your client isn't initiated properly!"<<std::endl;
    }

    try {
        ClientPtr client = std::make_shared<Client>("name", "", "id", type);
    } catch (int) {
        std::cout<<"Your client doesn't have name!"<<std::endl;
    }
    catch(...) {
        std::cout<<"Your client isn't initiated properly!"<<std::endl;
    }
    ClientTypePtr clientType = std::make_shared<Default>();
    ClientPtr client = std::make_shared<Client>("Marcin","Mazur","123",clientType);
    RoomPtr room = std::make_shared<Room>(1,2,100);
    RentPtr rent = std::make_shared<Rent>(1,client,room,pt::not_a_date_time);
    RentRepository rents;
    rents.addToRepo(rent);
    rents.writeToFile();
    return 0;
}