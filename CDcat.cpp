//
// Created by v on 7/03/22.
//

#include "CDcat.h"
#include "parser.h"

CDcat::CDcat() { catalog = new vector<eenCD*>(); }

CDcat::~CDcat() {

}
vector<eenCD*>* CDcat::parseCatalog(TiXmlElement* elem) {
    for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){

        parser cdp;
        eenCD* cd = cdp.parse(e);
        if(cd->isConsistent())
            catalog->push_back(cd);
    }

    return catalog;
}

vector<eenCD*>* CDcat::getCatalog() {
    return catalog;
}
