//
// Created by student on 13.06.2022.
//

#ifndef INTRODUCTIONPROJECT_PARAMETEREXCEPTION_H
#define INTRODUCTIONPROJECT_PARAMETEREXCEPTION_H

#include <stdexcept>

class ParameterException : public std::logic_error {
public:
    explicit ParameterException(const std::string & str) : std::logic_error(str) {}
};

#endif //INTRODUCTIONPROJECT_PARAMETEREXCEPTION_H
