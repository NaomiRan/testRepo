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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Status.h"
#include "Utils.h"
#include <cstring>

using namespace std;

namespace sdds {

	/*Status::Status() {  // no parameter?
		this->description = nullptr;
		this->code = 0;
	}*/


	Status::Status(const char* description) {
		this->code = 0;
		
		if (description != nullptr)
		ut.alocpy(this->description, description);
		else
			this->description = nullptr;
		
	}
	// destructor
	Status::~Status() {
		delete[] description;
	}

	// copy constructor
	Status::Status(const Status& other) {
		//*this = nullptr;
	  // *this = other;
		if (other.description != nullptr) ut.alocpy(description, other.description);
		else description = nullptr;
		code =other.code; 
	}


	Status& Status:: operator = (const Status& other) {
		
		if (this != &other) {
			code = other.code;
			ut.alocpy(this->description, other.description);
		}

		return *this;

	}


	Status& Status::operator = (const int code) {
		this->code = code;
		return *this;
	}

	Status& Status::operator = (const char* descrip) {
		
		if (descrip != nullptr)
	    ut.alocpy(this->description, descrip);
		return *this;
	}

	Status::operator int()const {
		return this->code;
	}

	Status::operator const char* ()const {
		return this->description;
	}

	Status::operator bool()const {
		return description==nullptr;
	}

	Status& Status::clear() {
		if (description != nullptr) {
			delete[] description;
			description = nullptr;
		}
		code = 0;
		return *this;
	}



	std::ostream& operator<<(std::ostream& os, const Status& S) {
		if (!S) {
			if (int(S) !=0) 
				os << "ERR#" << int(S) << ": ";
				os << (const char*)(S);
		}
		return os;
	}

	
}