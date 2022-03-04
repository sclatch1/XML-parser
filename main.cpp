#include <iostream>
#include "tinyxml.h"
#include "eenCD.h"
#include "parser.h"
#include <string>


using namespace std;


//Voor oef 1:
int main() {
    eenCD cd;
    TiXmlDocument doc;
    if (!doc.LoadFile("eenCD.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    //date uit doc halen
    TiXmlElement *CD = doc.FirstChildElement();

    if (CD == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }
    for (TiXmlElement *elem = CD->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string s = elem->Value();
        if (s == "TITLE") {
            cout << elem->Value() << ": " << elem->GetText() << endl;
        }
        if (s == "ARTIST") {
            cout << elem->Value() << ": " << elem->GetText() << endl;
        }
    }
}