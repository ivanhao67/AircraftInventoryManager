
#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include "Aircraft.h"

using namespace std;

class Airline {

	public:
		Airline(string);
		~Airline();
		void addPart(string,int,int);
		void addAircraft(string,string);
		void takeFlight(string,int);
		void printAircraft();
		void printParts();
		void inspectionReport(string,Date&);
		bool install(string,string,Date&);
	private:
		Aircraft* getAircraft(string);
		Part* getPart(string); 
	protected:
		string name;
		Array<Part*> p;
		Array<Aircraft*> a;
};
#endif
