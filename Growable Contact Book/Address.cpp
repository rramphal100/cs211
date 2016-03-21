//Ryan Ramphal, CS211, Homework #6
// Address.cpp

/**
* Defenition of class Address. It is used to store and retrieve
* information on Address such as home number, street, apt#, city,
* state, and zip.
*
* Author: Yosef Alayev
*/


#include "Address.h"
#include <string>
#include <iostream>

using namespace std;

Address::Address() : home(""),
street(""),
apt("none"),
city(""),
state(""),
zip("")
{
   // empty
}

string Address::getHome() const
{
   return home;
}

string Address::getStreet() const
{
   return street;
}

string Address::getApt() const
{
   return apt;
}

string Address::getCity() const
{
   return city;
}

string Address::getState() const
{
   return state;
}

string Address::getZip() const
{
   return zip;
}

void Address::output() const
{
   cout << home << " " << street;
   if (apt != "none")
      cout << ", Apt# " << apt;
   cout << endl;
   cout << city << ", " << state << " " << zip << endl;
}

void Address::input()
{
   char choice;
   cout << "Apartment or House (a/h):> ";
   cin >> choice;
   cout << endl;

   cin.ignore(10, '\n');
   cout << "Enter home number (EX: 141-92)___: ";
   getline(cin, home);
   cout << "Enter street number (EX: 70th RD): ";
   getline(cin, street);

   if (choice == 'a')
   {
      cout << "Enter Apartment Number: (EX: 1A)_: ";
      getline(cin, apt);
   }
   else
      apt = "none";

   cout << "Enter city (Ex: Flushing)________: ";
   getline(cin, city);

   cout << "Enter state (EX: NY)_____________: ";
   getline(cin, state);

   cout << "Enter zip code (EX: 11367)_______: ";
   getline(cin, zip);
}

istream& operator >> (istream& input, Address& add){
   char choice;
   cout << "Apartment or House (a/h):> ";
   input >> choice;
   cout << endl;

   input.ignore(10, '\n');
   cout << "Enter home number (EX: 141-92)___: ";
   getline(input, add.home);
   cout << "Enter street number (EX: 70th RD): ";
   getline(input, add.street);

   if (choice == 'a')
   {
      cout << "Enter Apartment Number: (EX: 1A)_: ";
      getline(input, add.apt);
   }
   else
      add.apt = "none";

   cout << "Enter city (Ex: Flushing)________: ";
   getline(input, add.city);

   cout << "Enter state (EX: NY)_____________: ";
   getline(input, add.state);

   cout << "Enter zip code (EX: 11367)_______: ";
   getline(input, add.zip);

   return input;
}

ostream& operator << (ostream& output, const Address& add){
   output << add.home << " " << add.street;
   if (add.apt != "none")
      output << ", Apt# " << add.apt;
   output << endl;
   output << add.city << ", " << add.state << " " << add.zip << endl;

   return output;
}