cmake_minimum_required(VERSION 3.4)

project(Program)

#Ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES
        src/main.cpp)
     #   ../library/src/model/Client.cpp ../library/include/model/Client.h ../library/src/model/ClientType.cpp ../library/include/model/ClientType.h ../library/src/model/Default.cpp ../library/include/model/Default.h ../library/src/model/RegularCustomer.cpp ../library/include/model/RegularCustomer.h ../library/src/model/Rent.cpp ../library/include/model/Rent.h ../library/src/model/Room.cpp ../library/include/model/Room.h ../library/src/managers/ClientManager.cpp ../library/include/managers/ClientManager.h ../library/src/managers/RentManager.cpp ../library/include/managers/RentManager.h ../library/src/managers/RoomManager.cpp ../library/include/managers/RoomManager.h ../library/src/repositories/Repository.cpp ../library/include/repositories/Repository.h ../library/src/repositories/ClientRepository.cpp ../library/include/repositories/ClientRepository.h ../library/src/repositories/RentRepository.cpp ../library/include/repositories/RentRepository.h ../library/src/repositories/RoomRepository.cpp ../library/include/repositories/RoomRepository.h)

#Włącz powyższy zbiór plików do zbudowania programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES} ../library/src/model/Client.cpp ../library/include/model/Client.h ../library/src/model/ClientType.cpp ../library/include/model/ClientType.h ../library/src/model/Default.cpp ../library/include/model/Default.h ../library/src/model/RegularCustomer.cpp ../library/include/model/RegularCustomer.h ../library/src/model/Rent.cpp ../library/include/model/Rent.h ../library/src/model/Room.cpp ../library/include/model/Room.h ../library/src/managers/ClientManager.cpp ../library/include/managers/ClientManager.h ../library/src/managers/RentManager.cpp ../library/include/managers/RentManager.h ../library/src/managers/RoomManager.cpp ../library/include/managers/RoomManager.h ../library/src/repositories/Repository.cpp ../library/include/repositories/Repository.h ../library/src/repositories/ClientRepository.cpp ../library/include/repositories/ClientRepository.h ../library/src/repositories/RentRepository.cpp ../library/include/repositories/RentRepository.h ../library/src/repositories/RoomRepository.cpp ../library/include/repositories/RoomRepository.h)

#Dołącz katalog include podprojektu Program do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(Program PUBLIC include)