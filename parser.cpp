//
// Created by david Scalais on 23/02/2022.
//

#include "parser.h"
#include "tinyxml.h"
#include "eenCD.h"
#include <iostream>

using namespace std;


void parser::parse()
{
    eenCD cd;
    TiXmlDocument doc;
    if(!doc.LoadFile("cd.xml"))
    {
        std::cerr << doc.ErrorDesc() << std::endl;

    }
    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL)
    {
        std::cerr << "Failed to load file: No root element" << std::endl;
        doc.Clear();

    }
    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
    {
        string elemName = elem->Value();
        string el_text = elem->GetText();
        if(elemName == "TITLE")
        {
            eenCD cd;
            cd.set_Title(elemName);
        }
        else if(elemName == "ARTIST")
        {
            cd.set_Artist(elemName);
        }
        else if(elemName == "Price")
        {

            cd.set_Price(stoi(elemName));
        }
        else if(elemName == "Year")
        {
            cd.set_Year(stoi(elemName));
        }

    }

}