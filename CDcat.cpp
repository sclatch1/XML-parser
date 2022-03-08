//
// Created by v on 7/03/22.
//

#include "CDcat.h"
#include "parser.h"

CDcat::CDcat() { catalog = new vector<eenCD*>(); }
CDcat::~CDcat() {}

vector<eenCD*>* CDcat::parseCat(TiXmlElement* elem) {
    for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
        parser cdp;
        eenCD* cd = cdp.parseCD(e);
        catalog->push_back(cd);
        return catalog;
    }
}

vector<eenCD *> *CDcat::getCatalog() {
        return catalog;
    }
