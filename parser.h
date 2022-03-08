//
// Created by david Scalais on 23/02/2022.
//

#ifndef UNTITLED10_PARSER_H
#define UNTITLED10_PARSER_H
#include "tinyxml.h"
#include "eenCD.h"

class parser {
private:
    string readElement(TiXmlElement* elem, const char* tag);
    eenCD* cd;
public:
    eenCD* parseCD(TiXmlElement* elem);
};


#endif //UNTITLED10_PARSER_H
