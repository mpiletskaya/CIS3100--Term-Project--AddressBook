/*
 * Menu.cpp
 * Class definitions for Menu class
 *  Created on: July 21, 2015
 */
#include "Menu.h"
#include "ContactList.h"
#include <iostream>
#include <string>

using namespace std;
//l

ContactList cl;

Menu::Menu(void)
{
	//read data from file once menu instance is created
	cl.readData("contacts.csv");
}


Menu::~Menu(void)
{
}

int Menu::showMenu()
{
	int choice;
	start_menu:

	  cout << " _____________________________________" << endl;
      cout << "|         Address Book Menu           |" << endl;
      cout << "|                                     |" << endl;
      cout << "| 1. Show all contacts                |" << endl;
      cout << "| 2- Search for an entry by last name |" << endl;
	  cout << "| 3- Search for by company name       |" << endl;
	  cout << "| 4- Sort by last name                |" << endl;
      cout << "| 5- Add a contact                    |" << endl;
	  cout << "| 6- Edit a contact                   |" << endl;
	  cout << "| 7- Delete a contact                 |" << endl;
      cout << "| 8- Exit                             |" << endl;
      cout << "|_____________________________________|" << endl;
	
		cin >> choice;
		//clears cin buffer. In other words, if you try to input some text with spaces, we'd clear unnecessary part
		fflush(stdin);

// process the menu option entered by the user
	switch(choice)
	{
		case 1:showAll();break;
		case 2:filterName();break;
		case 3:filterList2();break; //Mel Romero
		case 4:sortLName();break;
		case 5:AddName(); break; //Mel Romero
		case 6:editContactList();break;
		case 7:;break;
		case 8:goto stop;break;
		default:cout <<"Goodbye ..";
					goto stop;
	}
	goto start_menu;
	stop:
	return 0; 
}

void Menu::showAll()
{
	cl.displayList(cl.getList());
}

void Menu::filterName()
{
	string input;
	cout << "Enter a last name(Case sensitive): ";
	cin >> input;

	cl.displayList(cl.search(input, cl.LName));
}

void Menu::sortLName()
{
	cl.displayList(cl.sortAlphabetically());
}

void Menu::filterList2() // Mel Romero
{
	string input;
	cout << "Enter a company name(Case sensitive): ";
	cin >> input;

	cl.displayList(cl.search(input, cl.CName));
cout<<"company"<<endl;
}

void Menu::AddName() // Mel Romero
{
	cl.displayList(cl.getList());
	cl.AddContact();
}

void Menu::editContactList()
{
	cl.displayList(cl.getList());
	string input;
	cout << "Enter an id of a contact you want to edit: ";
	cin >> input;
	vector <Contact> fl = cl.search(input, cl.CId);
	int id = fl[0].getId();
	cl.getList()[id-1].editContact();
	cl.displayList(cl.getList());
	cl.rewriteList("contacts.csv");
}