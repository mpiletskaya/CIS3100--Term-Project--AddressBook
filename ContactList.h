/*
 * ContactList.h
 * Header for ContactList class
 *  Created on: July 18, 2015
 *      Author: Maria Piletskaya
 */

#pragma once
#include "Contact.h"
#include <vector>
class ContactList
{
private: 
	std::vector <Contact> clist; //use vector for our list of contacts to be able to change size of aray dynamically
	std::vector <Contact> flist; // filtered list
public:
	ContactList(void);
	~ContactList(void);
	
	
	//accessor functions
	std::vector<Contact> getList();
	void setList(std::vector <Contact> clist);

	//reads the contacts.csv file
	void readData();

	//displays a list of contacts passed to this function
	void displayList(std::vector <Contact>);

	//does a search by last name
	std::vector<Contact> searchByLName(std::string);

	//does a search by company name MR
	std::vector<Contact> searchByCName(std::string);

	//sort the list of contacts alphabetically by last name(ascending)
	void sortAlphabetically();

	//adds a new contact MR
	void AddContact();

};

