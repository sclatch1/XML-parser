//
// Created by v on 7/03/22.
//

#ifndef UNTITLED10_CDCAT_H
#define UNTITLED10_CDCAT_H


#include "eenCD.h"
#include "tinyxml.h"
#include <vector>
#include <string>
using namespace std;

class CDcat {
private:
    vector<eenCD*>* catalog;

public:
    CDcat();
    virtual ~CDcat();

    /*
     * This method expects the TiXmlElement that is passed as a parameter to represent an entire catalog of CDs.
     * It will then parse said catalog and return it as a pointer to a vector of CD*'s.
     */
    vector<eenCD*>* parseCat(TiXmlElement* elem);
    vector<eenCD*>* getCatalog();
};


#endif //UNTITLED10_CDCAT_H
