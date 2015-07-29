/*
 * Contact.cpp
 * Class definitions for Contact class
 *  Created on: July 18, 2015
 *      Author: Maria Piletskaya
 */
//one more test
//test
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

void Contact::setWorkPhone(string field)
{
	workPhone = field;
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
	cout <<left <<setw(3)<<id<<setw(12)<< firstName<<setw(12)<<lastName<<setw(16)<<homePhone<<setw(26)<<email<<setw(16)<< jobTitle<<endl;
}




