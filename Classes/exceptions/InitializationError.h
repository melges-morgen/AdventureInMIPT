//
// Created by melge on 24.04.2016.
//

#ifndef MYGAME_INITALIZATIONERROR_H
#define MYGAME_INITALIZATIONERROR_H

#include <exception>
#include <string>


class InitializationError: std::exception {
public:
    InitializationError(std::string &what);
    ~InitializationError();

    virtual const char *what() const noexcept override;

private:
    std::string what_;

};


#endif //MYGAME_INITALIZATIONERROR_H
