//
// Created by User on 11/25/2021.
//

#ifndef GRAPHMODULEC___CUSTOMEXCEPTIONS_H
#define GRAPHMODULEC___CUSTOMEXCEPTIONS_H

#include <exception>

struct NotConnectedException: public std::exception{
    const char * what () const throw() override
    {
        return "Vertices aren't connected";
    }
};


#endif //GRAPHMODULEC___CUSTOMEXCEPTIONS_H
