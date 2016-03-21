//Ryan Ramphal, CS211, Homework #6                                                                                                                                                             

#include <iostream>
#include <string>
#include "Address.h"
#include "Contact.h"                                                                                                                                                                           
using namespace std;

const regex Contact::checkPhone("[0-9]{10}");
//checks that a phone number contains exactly 10 digits and only digits                                                                                                                        
const regex Contact::checkEmail("[0-9a-zA-Z._-]+@[0-9a-zA-Z._-]+.(com|gov|net|edu|nyc|info|biz|cn|co.uk|eu|jp|au|int|mil|arpa|fr|hk|in|kr|kp|my|ru|us|vn)");
/*checks that an email address is of the correct format (alphanumeric string or dash or hyphen at least once, followed by "@", followed by 
alphanumeric string or dash or hyphen at least once, followed by ".", followed by one of the stated acceptable high-level domains.) */

//only the auto-generated default constructor will be used for hw4                                                                                                                                           
/*
Contact::Contact(string fn, string ln, string add, string ph, string em){ //since these values are usually input by the user, we call
//the mutator functions so that all input is verified prior to being officially set
setFirstName(fn);
setLastName(ln);
setAddress(add);
setPhone(ph);
setEmail(em);
}
*/

//for hw#4 we will only use the auto-generated default constructor (all fields are empty by default)                                                                                                           
//Contact::Contact() : firstname("John"), lastname("Doe"), phone("1234567890"), email("john.doe@gmail.com"){}

//accessors:                                                                                                                                                                                   
string Contact::getFirstName() const{ return firstname; }
string Contact::getLastName() const{ return lastname; }

string Contact::getAddress() const{  //creates an output of the address as a single string                                                                                                          
   string output = address.getHome() + " " + address.getStreet() + ", ";
   if (address.getApt().compare("none") != 0) output = output + address.getApt() + ", ";
   output = output + address.getCity() + ", " + address.getState() + " " + address.getZip();
   return output;
}

string Contact::getPhone() const{ return phone; }
string Contact::getEmail() const{ return email; }
Address Contact::returnAddress() const{ return address; }

//mutators:                                                                                                                                                                                    
void Contact::setFirstName(string x){ firstname = x; }
void Contact::setLastName(string x){ lastname = x; }
void Contact::setAddress(){ cin >> address; }
void Contact::inputAddress(Address x) { address = x; }


void Contact::setPhone(string x){
   while (true){ //loops through error message and new input query until a valid input is entered (only if the input in the function call was invalid)
      if (regex_match(x, checkPhone)){ //checks to make sure that the input string for the phone number is in the correct format
         phone = x;
         break; //exits the while loop after a valid input is entered
      }
      else { //prints an error message and asks again for a properly formatted phone number
         cout << "Error: Invalid phone number format entered for " << firstname << " " << lastname << ". Phone number must be 10 digits only - no dashes or parentheses. Please try again.:" << endl;
         cin >> x;
      }
      cout << endl << endl;
   }
}


void Contact::setEmail(string x){
   while (true){ //loops through error message and new input query until a valid input is entered (only if the input in the function call was invalid)
      if (regex_match(x, checkEmail)) { //checks to make sure that the input string for the email is in the correct format
         email = x;
         break; //exits the while loop after a valid input is entered
      }
      else { //prints an error message and asks again for a properly formatted email address
         cout << "Error: Invalid E-mail address format entered for " << firstname << " " << lastname << ". Please try again.:" << endl;
         cin >> x;
      }
      cout << endl << endl;
   }
}

void Contact::input(){
   string fn, ln, /*add,*/ ph, em;
   cout << "Please enter the first name of the new contact.: ";
   cin >> fn;
   setFirstName(fn);

   cout << "Please enter the last name of the new contact.: ";
   cin >> ln;
   setLastName(ln);

   /* I will use a different command for inputting the address since we're now using the Address object:
   cout << "Please enter the address of the new contact.: ";
   cin.ignore(); //PLEASE help me understand why this is necessary for this code to execute properly? I needed to use the stackoverflow site to find this. Without this line, the getline on\
   the next line stores an empty string instead of asking for user input. Please help me understand why this is the case. Thanks.
   getline(cin, add); //getline is used since an address will need several whitespace characters
   setAddress(add);
   */

   cout << "Please heed the following prompts to properly enter the address for this new contact." << endl;
   cin >> address;

   cout << "Please enter the phone number of the new contact.: ";
   cin >> ph;
   setPhone(ph);

   cout << "Please enter the email address of the new contact.: ";
   cin >> em;
   setEmail(em);

   cout << endl << "Contact created successfully." << endl << endl;
}

void Contact::output() const{
   cout << "First Name: " << firstname << endl
      << "Last Name: " << lastname << endl
      << "Address: " << endl;
   address.output();
   cout << "Phone Number: " << phone << endl
      << "Email Address: " << email << endl << endl;
}

//member operator overloads:
const bool Contact::operator < (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) < 0) return true;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) < 0) return true;
   return false;
}

const bool Contact::operator > (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) > 0) return true;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) > 0) return true;
   return false;
}

const bool Contact::operator == (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) == 0 && getFirstName().compare(contact.getFirstName()) == 0) return true;
   return false;
}

const bool Contact::operator != (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) == 0 && getFirstName().compare(contact.getFirstName()) == 0) return false;
   return true;
}

const bool Contact::operator <= (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) > 0) return false;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) > 0) return false;
   return true;
}

const bool Contact::operator >= (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) < 0) return false;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) < 0) return false;
   return true;
}


//non-member operator overloads:
istream& operator >> (istream& in, Contact& contact){
   string fn, ln, ph, em;
   cout << "Please enter the first name of the new contact.: ";
   in >> contact.firstname;
   
   cout << "Please enter the last name of the new contact.: ";
   in >> ln; contact.setLastName(ln);
  
   cout << "Please heed the following prompts to correctly enter the contact's address.:" << endl;
   contact.setAddress();
   cout << endl;
   
   cout << "Please enter the phone number of the new contact.: ";
   in >> ph; contact.setPhone(ph);

   cout << "Please enter the email of the new contact.: ";
   in >> em; contact.setEmail(em);

   cout << "Contact updated successfully." << endl << endl;

   return in;
}

ostream& operator << (ostream& out, const Contact& contact){
   out << "First Name: " << contact.getFirstName() << endl
      << "Last Name: " << contact.getLastName() << endl
      << "Address:" << endl;
   out << contact.returnAddress();
   out << "Phone number: " << contact.getPhone() << endl
      << "Email Address: " << contact.getEmail() << endl;

   return out;
}