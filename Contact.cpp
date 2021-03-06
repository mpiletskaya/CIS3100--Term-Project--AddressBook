/*
 * Contact.cpp
 * Class definitions for Contact class
 *  Created on: July 18, 2015
 */

#include "Contact.h"
#include "ContactList.h"
#include <iostream>
#include <iomanip>

using namespace std;

Contact:: Contact(void){
}
//Destructor of Contact
Contact::~Contact(void)
{
}

//getters

int Contact :: getId()
{
	return id;
}

string Contact :: getFirstName()
{
	return firstName;
}

string Contact :: getLastName()
{
	return lastName;


}


string Contact :: getCompany() //added new function to return company name MR
{
	return companyName;
}

//setters
void Contact::setId(int field)
{
	id = field;
}

void Contact::setFirstName(string field)
{
	firstName = field;
}

void Contact::setLastName(string field)
{
	lastName = field;
}

void Contact::setHomePhone(string field)
{
	homePhone = field;
}

void Contact::setAddress(string field)
{
	Address = field;
}

void Contact::setEmail(string field)
{
	email = field;
}

void Contact::setCompany(string field)
{
	companyName = field;
}
void Contact::setJob(string field)
{
	jobTitle = field;
}

//specify how the contact will be displayed in console window
//changed the spacing to allow more room MR
void Contact :: displayContact(){
	cout <<left <<setw(4)<<id<<setw(12)<< firstName<<setw(12)<<lastName<<setw(14) <<homePhone<<setw(18)<<Address <<setw(24)<<email<<setw(11)<< jobTitle<<setw(13)<<companyName<<endl;
}



int Contact :: editContact()
{
		int choice;
		string input; 
	start_menu:

	  cout << " _____________________________________" << endl;
      cout << "|     What do you want to change?     |" << endl;
      cout << "|                                     |" << endl;
      cout << "| 1. Edit last name                   |" << endl;
      cout << "| 2- Edit first name                  |" << endl;
	  cout << "| 3- Edit phone number                |" << endl;
	  cout << "| 4- Edit address                     |" << endl;
	  cout << "| 5- Edit email                       |" << endl;
	  cout << "| 6- Edit company name                |" << endl;
	  cout << "| 7- Edit job title                   |" << endl;
	  cout << "| 8- Stop editing                     |" << endl;
      cout << "|_____________________________________|" << endl;
		cin >> choice;
		//clears cin buffer. In other words, if you try to input some text with spaces, we'd clear unnecessary part
		fflush(stdin);
		// process the menu option entered by the user
		
	if(choice < 8)
	{
		cout << "Enter New Information: " << endl;
		getline(cin, input);
		//cin >> input;
		//clears cin buffer. In other words, if you try to input some text with spaces, we'd clear unnecessary part
		fflush(stdin);
	}

	switch(choice)
	{
		case 1:setLastName(input);break;
		case 2:setFirstName(input); break;
		case 3:setHomePhone(input);break;
		case 4:setAddress(input); break;
		case 5:setEmail(input);break; 
		case 6:setCompany(input);break;
		case 7:setJob(input);break;
		case 8:goto stop;break;
		default:goto stop;break;
	}
	goto start_menu;
stop: 
	return 0;
}

string Contact :: writeContact()
{
	string c  = ",";
	string s = to_string(id) + c + firstName + c + lastName  + c + homePhone + c + Address + c +email + c + jobTitle + c + companyName + "\n";
	return s;
}

int Contact ::deleteContact() // replacing strings with empty space
{
		int choice;
		string input; 
	start_menu:

	  cout << " _______________________________________________________" << endl;
      cout << "|    Are you sure you want to delete this contact?      |" << endl;
      cout << "|                                                       |" << endl;
      cout << "| 1. Yes                                                |" << endl;
      cout << "| 8- No                                                 |" << endl;
	  cout << "|                                                       |" << endl;
      cout << "|_______________________________________________________|" << endl;
		cin >> choice;
		//clears cin buffer. In other words, if you try to input some text with spaces, we'd clear unnecessary part
		fflush(stdin);
		// process the menu option entered by the user
		
	if(choice < 8)
	{
		cout << "Enter New Information: " << endl;
		string input = " ";
		//cin >> input;
		//clears cin buffer. In other words, if you try to input some text with spaces, we'd clear unnecessary part
		fflush(stdin);
	}

	switch(choice)
	{
		case 1:setLastName(input);
		case 2:setFirstName(input); 
		case 3:setHomePhone(input);
		case 4:setAddress(input); 
		case 5:setEmail(input);
		case 6:setCompany(input);
		case 7:setJob(input);
		case 8:goto stop;break;
		default:goto stop;break;
	}
	goto start_menu;
stop: 
	return 0;
}

string Contact :: writeContact2() //used by the remove function
{
	string c  = ",";
	string s = to_string(id) + c + firstName + c + lastName  + c + homePhone + c + Address + c +email + c + jobTitle + c + companyName + "\n";
	return s;
}