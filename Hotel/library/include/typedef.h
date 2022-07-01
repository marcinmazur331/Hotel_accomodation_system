//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_TYPEDEF_H
#define INTRODUCTIONPROJECT_TYPEDEF_H

#include <functional>
#include <memory>

class Client;
class Rent;
class Room;
class ClientType;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Room> RoomPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr ;


template <class T>
using Ptr = std::shared_ptr<T>;

template<class ElementPtr>
using Predicate = std::function<bool(ElementPtr)>;

typedef Predicate<ClientPtr> ClientPredicate;
typedef Predicate<RoomPtr> RoomPredicate;
typedef Predicate<RentPtr> RentPredicate;

typedef std::shared_ptr<Ptr<ClientPtr>> ClientRepositoryPtr;
typedef std::shared_ptr<Ptr<RoomPtr>> RoomRepositoryPtr;
typedef std::shared_ptr<Ptr<RentPtr>> RentRepositoryPtr;

#endif //INTRODUCTIONPROJECT_TYPEDEF_H
