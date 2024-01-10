

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