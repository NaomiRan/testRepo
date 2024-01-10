
#pragma once
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"
namespace sdds {
	const int maxYear = 2030;
	class Date {
		int Year;
		int Month;
		int Day;
		Status State;
		bool Formatted=true;
		bool validate();
		int uniqueDateValue() const;
		void setCurrentTime();
	public:
		Date();
		Date(int year, int month, int day);
		bool operator==(Date& compared) const;
		bool operator!=(Date& compared) const;
		bool operator<(Date& compared) const;
		bool operator>(Date& compared) const;
		bool operator<=(Date& compared) const;
		bool operator>=(Date& compared) const;
		const Status& state() const;
		Date& formatted(bool formatF);
	    operator Status() const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);

	};
	std::ostream& operator<<(std::ostream& os, const Date& newDate);
	std::istream& operator>>(std::istream& is, Date& newDate);
}
#endif //!SDDS_DATE_H
