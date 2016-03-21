//Ryan Ramphal, CS211, Homework #4

#include <iostream>
#include <string>
#include "Address.h"
#include "Contact.h"
#include "ContactBook.h"

using namespace std;

void displayContact(ContactBook in); //user is prompted to search for contact to be displayed

void updateContact(ContactBook in); //user is prompted to search for contact to be updated



int main() {
	int menu = 1; //stores the user's choice from the menu for proper program execution
	ContactBook list; //the ContactBook instance to be used by this program

	cout << "Welcome to your new digital contact book! ";

	while (menu > 0 && menu < 7){
		cout << "Please make a selection from the menu below by entering the number next to your choice to proceed.\n\n";
		
		//menu
		cout << "1. Add a new contact" << endl
			<< "2. Delete an old contact" << endl
			<< "3. Display a contact's info" << endl
			<< "4. Update a contact's info" << endl
			<< "5. Display the entire contact list" << endl
			<< "6. Exit" << endl << endl;

		cin >> menu;
		if (menu == 6) break; //exits if user enters 6 or any invalid menu choice

		else if (menu == 1){ //executed if user chooses to add a new contact
			Contact x; //creates a new contact that will be input by the user
			x.input();
			list.add(x);
			continue;
		}

		else if (menu == 2){ //executed if user decides to delete an old contact
			int index;
			char answer;
			
			deleteIndex: //reference point to return to if the user give invalid answer to the following question
			cout << "Do you know the index of the contact you'd like to delete? (Y/N): ";
			cin.ignore();
			cin >> answer;

			if (answer == 'Y' || answer == 'y'){
				cout << "Please enter the index you'd like to delete.: ";
				cin >> index;
				list.remove(index);
				continue;
			}

			else if (answer == 'N' || answer == 'n'){
				string name;
				cout << "Please enter the name of the contact you'd like to delete.: ";
				cin.ignore();
				getline(cin, name);
				list.remove(list.search(name));
				continue;
			}

			else {
				cerr << "Error: Invalid answer. Please try again." << endl << endl;
				goto deleteIndex;
			}
		}

		else if (menu == 3){ //executed if a user decides to display a contact's info
			string display;
			cout << "Please enter the name of the contact you'd like to have displayed.: ";
			cin.ignore();
			getline(cin, display);

			list.contactAtIndex(list.search(display)).output(); //outputs the contact specified if it exists, throws an exception otherwise
			continue;
		}

		else if (menu == 4){ //executed if the user decides to modify a contact's info
			string mod;
			cout << "Please enter the full name of the contact you'd like to modify.: ";
			cin.ignore();
			getline(cin, mod);

			int index = list.search(mod);

			cout << "Please enter the new data for the contact " << list.contactAtIndex(list.search(mod)).getFirstName()
				<< ' ' << list.contactAtIndex(list.search(mod)).getLastName() << '.' << endl << endl;
			
			Contact input; //stores the new data to be used to modify the existing contact
			input.input();
			list.update(index, input);

			cout << "Contact updated successfully!" << endl << endl;
			continue;
		}

		else if (menu == 5){ //executed if the user decides to display the entire contact list
			list.displayAll();
			cout << endl << endl;
			continue;
		}
	}

	cout << "Thanks for using the digital contact book! This program will now exit." << endl;

	system("PAUSE");
	return 0;
}