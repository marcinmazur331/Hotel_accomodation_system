//
// Created by student on 10.06.2022.
//

#ifndef INTRODUCTIONPROJECT_RENTREPOSITORY_H
#define INTRODUCTIONPROJECT_RENTREPOSITORY_H
#include "Repository.h"
#include "../model/Rent.h"


class RentRepository : public Repository<Rent>{
public:
    std::string report() ;
    void writeToFile() override;
    RentPtr findById(const int & id) const;
};


#endif //INTRODUCTIONPROJECT_RENTREPOSITORY_H
