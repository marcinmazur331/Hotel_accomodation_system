//
// Created by student on 10.06.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENTREPOSITORY_H
#define INTRODUCTIONPROJECT_CLIENTREPOSITORY_H
#include "../typedef.h"
#include "Repository.h"
#include "../model/Client.h"

class ClientRepository : public Repository<Client>{
public:
    std::string report() ;
    void writeToFile() override;
    ClientPtr findByPersonalId(const std::string & id) const;
};


#endif //INTRODUCTIONPROJECT_CLIENTREPOSITORY_H
