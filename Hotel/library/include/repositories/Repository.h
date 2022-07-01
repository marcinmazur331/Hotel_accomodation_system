//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_REPOSITORY_H
#define INTRODUCTIONPROJECT_REPOSITORY_H
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "../typedef.h"

template <class T> class Repository {
protected:
    std::vector<Ptr<T>> element;
public:


    virtual void writeToFile() = 0;

    virtual std::string report() = 0;


    Ptr<T> getRepo(int id) {
        int licznik = 0;
        for (auto i: element) {
            if (licznik == id) return element[id];
            licznik++;
        }
        return nullptr;
    }

void addToRepo(Ptr<T> object) {
    if(object != nullptr){
        element.push_back(object);
    }
}

void removeFromRepo(Ptr<T> object) {
    if(object != nullptr){
        for(int i=0; i < element.size(); i++){
            if(element[i] == object) element.erase(element.begin() + i);
        }
    }
}


int size() {
    return element.size();
}


std::vector<Ptr<T>> find(Predicate<Ptr<T>> predicate) const {
    std::vector<Ptr<T>> found;
    for (int i = 0; i < element.size(); ++i) {
        Ptr<T> object = element[i];
        if (object != nullptr && predicate(object)) found.push_back(object);
    }
    return found;
}

std::vector<Ptr<T>> findAll() {
        Predicate<Ptr<T>> f = [](const Ptr<T> & element) -> bool { return true; };return find(f);
    }

};

#endif //INTRODUCTIONPROJECT_REPOSITORY_H
