
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include "Array.h"
#include "Part.h"

using namespace std;

class Aircraft {
	friend ostream& operator<<(ostream&, Aircraft&);
	public:
		Aircraft(string,string);
		string getReg();
		void install(Part*,Date&);
		void takeFlight(int);
		void inspectionReport(Date,Array<Part*>*);
	protected:
		string type;
		string registration;
		int flighthours;
		Array<Part*> a;
};
#endif
