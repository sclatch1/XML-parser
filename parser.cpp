//
// Created by david Scalais on 23/02/2022.
//

#include "parser.h"
#include "tinyxml.h"
#include "eenCD.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string parser::readElement(TiXmlElement* elem, const char* tag) {
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

eenCD* parser::parseCD(TiXmlElement* elem) {
    //eenCD cd;
    TiXmlDocument doc;
    if (!doc.LoadFile("eenCD.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    //data uit doc halen
    TiXmlElement *CD = doc.FirstChildElement();

    if (CD == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    for (TiXmlElement *elem = CD->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string s = elem->Value();
        if (s == "TITLE") {
            string title = elem->GetText();
            cout << elem->Value() << ": " << elem->GetText() << endl;

            cd->set_Title(title);
        }
        if (s == "ARTIST") {
            string artist = elem->GetText();
            cout << elem->Value() << ": " << elem->GetText() << endl;

            cd->set_Artist(artist);
        }

        if (s == "COUNTRY") {
            string country = elem->GetText();
            cd->set_Country(country);
        }
        if (s == "COMPANY") {
            string company = elem->GetText();
            cd->set_Company(company);
        }
        if (s == "PRICE") {
            const char *x = elem->GetText();
            int price;
            stringstream s(x);
            s >> price;
            cd->set_Price(price);
        }
        if (s == "YEAR") {
            const char *x = elem->GetText();
            int year;
            stringstream s(x);
            s >> year;
            cd->set_Year(year);
        }

    }
}