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
#include "Date.h"
using namespace std;
namespace sdds {
	
	bool Date::validate() {
		int m_year, m_month, m_day;
		bool validateFlag = false;
		ut.getSystemDate(&m_year, &m_month, &m_day);
		if (Year < m_year || Year > maxYear) {
			State = "Invalid year in date";
			State = 1;
		}
		else if (Month < 1 || Month > 12) {
			State = "Invalid month in date";
			State = 2;
		}
		else if (Day < 1 || Day > ut.daysOfMon(Month, Year)) {
			State = "Invalid day in date";
			State = 3;
		}
		else {
			State.clear();
			validateFlag = true;
		}
		return validateFlag;
	}

	
	int Date::uniqueDateValue() const {
		return Year * 372 + Month * 31 + Day;
	}

	void Date::setCurrentTime() {
		int m_year, m_month, m_day;
		ut.getSystemDate(&m_year, &m_month, &m_day);
		this->Year = m_year;
		this->Month = m_month;
		this->Day = m_day;
	}
	
	Date::Date() {
		setCurrentTime();
	}
	
	Date::Date(int year, int month, int day) {
		this->Year = year;
		this->Month = month;
		this->Day = day;
		/*if (!validate()) {
		  setCurrentTime();
		}*/
	}

	
	bool Date::operator==(Date& compared) const {
		return uniqueDateValue() == compared.uniqueDateValue();
	}

	bool Date::operator!=(Date& compared) const {
		return uniqueDateValue() != compared.uniqueDateValue();
	}

	bool Date::operator<(Date& compared) const {
		return uniqueDateValue() < compared.uniqueDateValue();
	}

	bool Date::operator>(Date& compared) const {
		return uniqueDateValue() > compared.uniqueDateValue();
	}

	bool Date::operator<=(Date& compared) const {
		return uniqueDateValue() <= compared.uniqueDateValue();
	}

	bool Date::operator>=(Date& compared) const {
		return uniqueDateValue() >= compared.uniqueDateValue();
	}

	const Status& Date::state() const {
		return State;
	}

	
	Date& Date::formatted(bool formatF) {
		Formatted = formatF;
		return *this;
	}

	
	Date::operator Status() const {
		return State;
	}


	ostream& Date::write(ostream& os = cout) const {
		if (Formatted) {
			os << Year << '/';
			os.width(2);
			os.fill('0');
			os << Month << '/';
			os.width(2);
			os.fill('0');
			os << Day;
		}
		else {
			os << (Year % 100);
			os.width(2);
			os.fill('0');
			os << Month;
			os.width(2);
			os.fill('0');
			os << Day;
		}
		return os;
	}

	
	istream& Date::read(istream& is) {
		int m_date;
		if (is >> m_date) {
			if (m_date < 9999) {
				setCurrentTime();
				Month = m_date / 100;
				Day = m_date % 100;
			}
			else if (m_date >= 100000) {
				Year = 2000 + m_date / 10000;
				Month = m_date % 10000 / 100;
				Day = m_date % 100;
			}
			else {}
			if (!validate())
				is.setstate(ios::badbit);
		}
		else {
			cout << "Invalid date value";
		}
		return is;
	}


	std::ostream& operator<<(ostream& os, const Date& newDate) {
		return newDate.write(os);
	}

	
	istream& operator>>(istream& is, Date& newDate) {
		return newDate.read(is);
	}
}