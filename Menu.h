/*
 * Menu.h
 * Header for Menu class
 *  Created on: July 21, 2015
 *      Author: Maria Piletskaya
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

	void filterList();
	void filterList2(); //filter to search for contact by company name MR
	void sortLName(); 
	void AddName(); // function to add new contact MR
};

