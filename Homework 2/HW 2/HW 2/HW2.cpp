//Ryan Ramphal
//CS211 -32A
//Homework #2

#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
using namespace std;

class Contact{
private:
	string firstname;
	string lastname;
	string address;
	string phone;
	string email;
	
	//regex input checkers (these will hold the input requirements for phone numbers and email addressses)
	static const regex checkPhone;
	static const regex checkEmail;
	
public:
	//constructors
	Contact(string fn, string ln, string add, string ph, string em);
	Contact();

	//accessors (will return the data as a string to wherever it was called)
	string getFirstName();
	string getLastName();
	string getAddress();
	string getPhone();
	string getEmail();

	//mutators
	void setFirstName(string x);
	void setLastName(string x);
	void setAddress(string x);
	void setPhone(string x);
	void setEmail(string x);

	//input (displays querys to make the input of a new contact very easy to do)
	void input();

	//output (displays the specified contact's info in a way that is very easy to read)
	void output();
};

const regex Contact::checkPhone("[0-9]{10}");
//checks that a phone number contains exactly 10 digits and only digits
const regex Contact::checkEmail("[0-9a-zA-Z\._\-]+@[0-9a-zA-Z\._\-]+\.(com|gov|net|edu|nyc|info|biz|cn|co\.uk|eu|jp|au|int|mil|arpa|fr|hk|in|kr|kp|my|ru|us|vn)");
//checks that an email address is of the correct format (alphanumeric string or dash or hyphen at least once, followed by "@", followed by alphanumeric string or dash or hyphen at least once, followed by ".", followed by one of the stated acceptable high-level domains.)

Contact::Contact(string fn, string ln, string add, string ph, string em){ //since these values are usually input by the user, we call the mutator functions so that all input is verified prior to being officially set
	setFirstName(fn);
	setLastName(ln);
	setAddress(add);
	setPhone(ph);
	setEmail(em);
}

//since the following line is a default constructor that shall always input the same values (that are guaranteed to be correct), we need not perform verification on this default input, so we just declare the object's values in-line with the constructor definition.
Contact::Contact() : firstname("John"), lastname("Doe"), address("123 Address Lane, Seattle, WA 01234"), phone("1234567890"), email("john.doe@gmail.com"){}

//accessors:
string Contact::getFirstName() { return firstname; }
string Contact::getLastName() { return lastname; }
string Contact::getAddress() { return address; }
string Contact::getPhone() { return phone; }
string Contact::getEmail() { return email; }

//mutators:
void Contact::setFirstName(string x){ firstname = x; }
void Contact::setLastName(string x){ lastname = x; }
void Contact::setAddress(string x){ address = x; }
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
	string fn, ln, add, ph, em;
	cout << "Please enter the first name of the new contact.: ";
	cin >> fn;
	setFirstName(fn);

	cout << "Please enter the last name of the new contact.: ";
	cin >> ln;
	setLastName(ln);

	cout << "Please enter the address of the new contact.: ";
	cin.ignore(); //PLEASE help me understand why this is necessary for this code to execute properly? I needed to use the stackoverflow site to find this. Without this line, the getline on the next line stores an empty string instead of asking for user input. Please help me understand why this is the case. Thanks.
	getline(cin, add); //getline is used since an address will need several whitespace characters
	setAddress(add);

	cout << "Please enter the phone number of the new contact.: ";
	cin >> ph;
	setPhone(ph);

	cout << "Please enter the email address of the new contact.: ";
	cin >> em;
	setEmail(em);

	cout << endl << endl;
}

void Contact::output() {
	cout << "First Name: " << firstname << endl
		<< "Last Name: " << lastname << endl
		<< "Address: " << address << endl
		<< "Phone Number: " << phone << endl
		<< "Email Address: " << email << endl << endl;
}


int main(){
	cout << "Test Program for the Contact Class" << endl << endl;

	cout << "The following 3 contact function test will also test the functionality of the output function." << endl << endl << endl;

	cout << "Test of Contact Constructor for alias Amy Lau in object instantiation, with all correct input formats:" << endl;
	Contact x("Amy", "Lau", "456 Park Lane, Dallas, TX 54321", "5624531667", "amy.lau67@yahoo.biz");
	x.output();
	cout << endl;

	cout << "Test of Contact Constructor for alias Andrew Woo with error in phone number format:" << endl;
	Contact y("Andrew", "Woo", "747 Boeing Drive, Denver, CO 78564", "45123", "andrew@kjl.net");
	y.output();
	cout << endl;

	cout << "Test of Contact Constructor for alias Morgan Stanley with error in email address format:" << endl;
	Contact z("Morgan", "Stanley", "001 Grand Avenue, New York, NY 57782", "4561237920", "oiwenv");
	z.output();
	cout << endl;

	system("PAUSE");
	cout << endl << endl;

	cout << "Test of Default Contact Constructor:" << endl;
	Contact b;
	b.output();
	system("PAUSE");
	cout << endl;	

	cout << endl << endl << "Input Function Test:" << endl << endl;
	Contact c;
	c.input();
	c.output();
	cout << endl << "This program will now close." << endl;
	system("PAUSE");

	return 0;
}