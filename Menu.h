/*
 * Menu.h
 * Header for Menu class
 *  Created on: July 21, 2015
 */

#pragma once
class Menu
{
public:
	Menu(void);
	~Menu(void);


	int showMenu();

	//shows all contacts stored in the contacts.csv file
	void showAll();

	//search for a contact by Last Name
	void filterName();

	//filter to search for contact by company name MR
	void filterList2(); 

	//sort contacts by Last Names, Ascending
	void sortLName(); 

	 // function to add new contact MR
	void AddName();
	
	//function to edit a contact
	void editContactList();

	//function to remove a contact
	void removeContactList();
};

