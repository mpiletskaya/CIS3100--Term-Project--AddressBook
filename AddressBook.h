#pragma once
#ifndef ADDRESSBOOK_H_
#define ADDRESSBOOK_H_
#include <string>
#include <iostream>
using namespace std;
/*
 * AddressBook.h
 * Header for AddressBook class
 *  Created on: July 18, 2015
 *      Author: Maria Piletskaya
 */
class AddressBook
{
public:
	AddressBook(void);
	~AddressBook(void);

	void showAll();
};

#endif /* AddressBook_H_ */