/*
 * ContactList.h
 * Header for ContactList class
 *  Created on: July 18, 2015
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

	enum searchParam{CId, CName, LName};
	


	
	//accessor functions
	std::vector<Contact> &getList();
	void setList(std::vector <Contact> clist);

	//reads the contacts.csv file
	void readData(std:: string filename);

	//displays a list of contacts passed to this function
	void displayList(std::vector <Contact> list);

	//one method for doing search(by LName, CompanyName, Id)
	std::vector<Contact> & search(std::string, searchParam);

	//sort the list of contacts alphabetically by last name(ascending)
	std::vector<Contact> sortAlphabetically();

	//adds a new contact MR
	void AddContact();

	//rewrite contacts to a file
	void rewriteList(std::string);

	//deletes contacts to a file
	void deleteList(std::string);


};

