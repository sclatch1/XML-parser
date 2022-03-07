//
// Created by david Scalais on 20/02/2022.
//

#include "eenCD.h"

string eenCD::get_Artist() {return Artist;}

void eenCD::set_Artist(string &artist) {Artist = artist;}

string eenCD::get_Title(){return Title;}

void eenCD::set_Title(string &title) {Title = title;}

int eenCD::get_Year() {return Year;}

void eenCD::set_Year(int year) {Year = year;}

int eenCD::get_Price() {return Price;}

void eenCD::set_Price(int price) {Price = price;}

string eenCD::get_Company() {return Company;}

void eenCD::set_Company(string company) {Company = company;}

string eenCD::get_Country(){return Country;}

void eenCD::set_Country(string coutry) {Country = coutry;}

string eenCD::Print(){
    string output = "It worked!";
    cout << Title << endl << Artist << endl << Country << endl << Company << endl << Price << endl << Year << endl;
    return output;
}

eenCD::eenCD() {
}
