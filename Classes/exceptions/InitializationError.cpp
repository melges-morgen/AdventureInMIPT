//
// Created by melge on 24.04.2016.
//

#include "InitializationError.h"

InitializationError::InitializationError(std::string &what) : what_(what)
{
}

const char *InitializationError::what() const noexcept
{
    return what_.c_str();
}

InitializationError::~InitializationError()
{

}





