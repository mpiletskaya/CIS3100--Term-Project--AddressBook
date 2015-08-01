/*
 * ContactList.cpp
 * Class Definition for ContactList class
 *  Created on: July 18, 2015
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
				case 4: contact.setAddress(field);break;
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
		cout<<"_______________________________________________________________________________________"<<endl;
		cout <<left <<setw(4)<<"Id"<<setw(12)<<"First Name"<<setw(12)<<"Last Name"<<setw(18)<<"Address"<<setw(14)<<"Home Phone #"<<setw(24)<<"Email"<<setw(11)<<"Position"<<setw(13)<<"Company"<<endl;
		//display the contacts
		for (size_t i= 0; i < list.size(); i++)
		{
			list[i].displayContact();
		}
	}
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

  vector<Contact> ContactList:: search(string input, searchParam searchParameter)
{
	//Remove all elements from filtered list
	flist.clear();
	//depends on searchParam: either last name, id or company name
	string valueToCompare; 

	for(size_t i = 0; i < clist.size(); i++)
	{
		Contact contact = clist[i];
		switch (searchParameter)
	{
	case CId: valueToCompare = to_string(contact.getId());break;
	case CName: valueToCompare = contact.getCompany();break;//Mel Romero
	case LName: valueToCompare = contact.getLastName();break;
	}
		if (valueToCompare.compare(input)==0)
			flist.push_back(contact);
	}
	return flist;
}


 //Mel Romero
 void ContactList:: AddContact(){
	
	 string newcontact, firstname, lastname, address, homephone, email, jobtitle,company;
	 
	 char cont = 'y';
	 
	 fstream file ("contacts.csv", ios:: in |ios::out|ios::app);
	
	if (!file.is_open()){
		 
	cout <<"Could not open the file"<<endl;

	 }

	do
{ 
		cout << "Enter a new contact (id, first name, last name, address, email, home phone, job title, company" << endl;
		cout << "Enter your new contact's first name: " << endl;
		cin >> firstname;
		cout << "Enter your new contact's last name: " << endl;
		cin >> lastname;
		cout << "Enter your new contact's address: " << endl;
		cin >> address;
		cout << "Enter your new contact's home phone: " << endl;
		cin >> homephone;
		cout << "Enter your new contact's job title: " << endl;
		cin >> jobtitle;
		cout << "Enter your new contact's company: " << endl;
		cin >> company;
		newcontact = firstname+","+lastname+","+address+","+email+","+homephone+","+jobtitle+","+company;
		file << newcontact << endl;
		cout << "Enter another grade? (y|n) ";
		cin >> cont;
	 
	 } while (cont == 'y');
		 file.close();
 }