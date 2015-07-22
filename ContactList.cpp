/*
 * ContactList.cpp
 * Class Definition for ContactList class
 *  Created on: July 18, 2015
 *      Author: Maria Piletskaya
 */

#include "ContactList.h"
#include "Contact.h"
#include <vector>
#include <iostream>
#include <iomanip>  
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ContactList::ContactList(void)
{	}


ContactList::~ContactList(void)
{
}

vector<Contact> ContactList::getList()
{
	return clist;
}

void ContactList::readData(){
	ifstream myfile ("contacts.csv"); //the file with data
	string line; 
	string field;
	if(!clist.empty())
	{
		//Remove all elements from the vector 'clist'
		clist.clear();
	}
  if (myfile.is_open())
  {
    while ( getline (myfile,line) ) // take one line
    {
		//declare a new instance of Contact class
		Contact contact;
		stringstream ls(line);
		// define iterator for a line
		int it = 0; 
		//search for fields within the line, separated by comma
		while(getline(ls, field,',')) 
		{
			//set the data to object contact
			switch(it)
			{
				case 0: contact.setId(stoi(field));break;
				case 1: contact.setFirstName(field);break;
				case 2: contact.setLastName(field);break;
				case 3: contact.setHomePhone(field);break;
				case 4: contact.setWorkPhone(field);break;
				case 5: contact.setEmail(field);break;
				case 6: contact.setJob(field);break;
				case 7: contact.setCompany(field);break;
			}
			it++;
		}
		//add an object to a vector container 'clist' 
		clist.push_back(contact);
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
}

void ContactList :: displayList(vector <Contact> list)
{
	if (list.empty())
	{
		cout << "Sorry there are no contacts that match your request"<<endl;
	} else {
		//display list header
		cout<<"________________________________________________________________________________"<<endl;
		cout <<left <<setw(3)<<"Id"<<setw(12)<<"First Name"<<setw(12)<<"Last Name"<<setw(16)<<"Home Phone #"<<setw(26)<<"Email"<<setw(16)<<"Position"<<endl;
		//display the contacts
		for (size_t i= 0; i < list.size(); i++)
		{
			list[i].displayContact();
		}
	}
}

 vector<Contact> ContactList:: searchByLName(string lname)
{
	if(!flist.empty())
	{
		//Remove all elements from the vector 'clist'
		flist.clear();
	}
	for(int i = 0; i < clist.size(); i++)
	{
		/* use '<= 0' here so that it's not case sensitive; it'll also count if 
		all compared characters match but the compared string is shorter.*/
		if (clist[i].getLastName().compare(lname)==0)
			flist.push_back(clist[i]);
	}
	return flist;
}

 void ContactList::sortAlphabetically()
 {
	for (int i = 0; i < clist.size()-1; i++)
	{
		Contact temp;
		for (int n = 0; n < clist.size()-1; n++)
		{
			if (clist[n].getLastName() > clist[n+1].getLastName()) 
			{
				temp = clist[n];
				clist[n]  = clist[n+1];
				clist[n+1] = temp;
			}
		}
	}
 }