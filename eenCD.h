//
// Created by david Scalais on 20/02/2022.
//

#ifndef UNTITLED10_EENCD_H
#define UNTITLED10_EENCD_H
#include <iostream>
using namespace std;

class eenCD {
private:
    string Artist;
    string Title;
    string Country;
    string Company;
    int Year;
    int Price;
public:
    void set_Artist(string &artist);
    string get_Artist();
    void set_Title(string &title);
    string get_Title();
    void set_Year(int year);
    int get_Year();
    void set_Price(int price);
    int get_Price();
    void set_Country(string coutry);
    string get_Country();
    void set_Company(string company);
    string get_Company();
    string to_string();
};


#endif //UNTITLED10_EENCD_H
