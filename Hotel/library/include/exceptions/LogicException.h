//
// Created by student on 13.06.2022.
//

#ifndef INTRODUCTIONPROJECT_LOGICEXCEPTION_H
#define INTRODUCTIONPROJECT_LOGICEXCEPTION_H

#include <stdexcept>

class LogicException : public std::logic_error {
public:
    explicit LogicException(const std::string & str) : std::logic_error(str) {}
};

#endif //INTRODUCTIONPROJECT_LOGICEXCEPTION_H
