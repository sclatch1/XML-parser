//
// Created by v on 7/03/22.
//

#include "CDcat.h"
#include "parser.h"

CDcat::CDcat() { catalog = new vector<eenCD*>(); }

CDcat::~CDcat() {

}
vector<eenCD*>* CDcat::parseCat(TiXmlElement* elem) {
    for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
        //note that we are explicitly creating a CDParser to parse separate instances of CD's inside this catalog.
        parser cdp;
        eenCD* cd = cdp.parseCD(e);
        catalog->push_back(cd);
        return catalog;
    }
}

vector<eenCD *> *CDcat::getCatalog() {
        return catalog;
    }
