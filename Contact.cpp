/*
 * Contact.cpp
 * Class definitions for Contact class
 *  Created on: July 18, 2015
 *      Author: Maria Piletskaya
 */
//one more test
//test i will like to try a nice ice cream
// test for tutorial!
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
void Contact :: displayContact(){
	cout <<left <<setw(4)<<id<<setw(12)<< firstName<<setw(12)<<lastName<<setw(18)<<Address <<setw(14) <<homePhone<<setw(24)<<email<<setw(11)<< jobTitle<<setw(13)<<companyName<<endl;
}

//changed the spacing to allow more room MR




