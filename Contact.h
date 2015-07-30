/*
 * Contact.h
 * Header for Contact class
 *  Created on: July 18, 2015
 *      Author: Maria Piletskaya
 */

#pragma once
#include <string>
#include <iostream>

class Contact //define a class
{
private:
	int id;
	//add a comment
	std::string firstName;
	std::string lastName;
	std::string homePhone;
	std::string Address; //changed workphone to Address MR
	std::string email;
	std::string companyName;
	std::string jobTitle;

public:
	Contact(void);
	Contact(int, std::string, std::string, std::string, std::string,std::string, std::string, std::string); //constructor
	~Contact(void); //destructor

	// accessor functions 
	int getId();         
	void setId(int id);

	std::string getFirstName();
	void setFirstName(std::string firstName);

	std::string getLastName();
	void setLastName(std::string lastName);

	std::string getHomePhone();
	void setHomePhone(std::string homePhone);

	std::string getAddress(); //changed workphone to Address MR
	void setAddress(std::string Address);

	std::string getEmail();
	void setEmail(std::string email);

	std::string getCompany();
	void setCompany(std::string companyName);

	std::string getJob();
	void setJob(std::string jobTitle);

	//define the way of presenting a record of our addressbook
	void displayContact(); 
};

