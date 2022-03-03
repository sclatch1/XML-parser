#include <iostream>
#include "tinyxml.h"
#include "eenCD.h"
#include "parser.h"
#include <string>


using namespace std;



int main()
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
            cd.set_Title(el_text);
        }
        else if(elemName == "ARTIST")
        {
            cd.set_Artist(el_text);
        }
        else if(elemName == "COUNTRY")
        {
            cd.set_Country(el_text);
        }
        else if(elemName == "COMPANY")
        {
            cd.set_Company(el_text);
        }

    }
    cd.to_string();
}

