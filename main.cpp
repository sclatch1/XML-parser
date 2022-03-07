#include <iostream>
#include "tinyxml.h"
#include "eenCD.h"
#include "parser.h"
#include "CDcat.h"
#include <string>
#include <sstream>


using namespace std;


//Voor oef 1:
int main() {
    eenCD cd;
    cout << "Opdracht 1:\n" << endl;
    TiXmlDocument doc;
    if (!doc.LoadFile("eenCD.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    //data uit doc halen
    TiXmlElement *CD = doc.FirstChildElement();

    if (CD == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }
    for (TiXmlElement *elem = CD->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string s = elem->Value();
        if (s == "TITLE") {
            string title = elem->GetText();
            cout << elem->Value() << ": " << elem->GetText() << endl;

            cd.set_Title(title);
        }
        if (s == "ARTIST") {
            string artist = elem->GetText();
            cout << elem->Value() << ": " << elem->GetText() << endl;

            cd.set_Artist(artist);
        }

        if (s == "COUNTRY") {
            string country = elem->GetText();
            cd.set_Country(country);
        }
        if (s == "COMPANY") {
            string company = elem->GetText();
            cd.set_Company(company);
        }
        if (s == "PRICE") {
            const char* x = elem->GetText();
            int price;
            stringstream s(x);
            s >> price;
            cd.set_Price(price);
        }
        if (s == "YEAR") {
            const char* x = elem->GetText();
            int year;
            stringstream s(x);
            s >> year;
            cd.set_Year(year);
        }
    }

    cout << "\nOpdracht 2:\n" << endl;
    cout << cd.Print();

    cout << "\n\nOpdracht 3:\n" << endl;
    CDcat* cat;
    cout << cat->getCatalog();

    //auto cdList =  //lijst van alle cds uit de catalog
    //for (auto i : cdList){
//
    //}

}