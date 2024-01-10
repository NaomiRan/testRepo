/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Dongqin Ran
// email: dran@myseneca.ca
// Student ID : 128601226
// section : NCC
// Date: Nov.9
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef STATUS_H_
#define STATUS_H_
#include<iostream>
using namespace std;



namespace sdds {
	class Status {
		char* description=nullptr;
		int code;
	public:
		// constructors
		//Status();
		Status(const char* description = nullptr);
		// destructor
		~Status();
		// copy constructor
		Status(const Status& other);


		//assignment operator
		Status& operator=(const Status& other);
		Status& operator=(const int code);
		Status& operator=(const char* descrip);

		// conversion operator
		operator int() const;
		operator const char* ()const;
		operator bool() const;

		// clear
		Status& clear();


	};
	ostream& operator<<(ostream& os, const Status& S);
}

	

#endif