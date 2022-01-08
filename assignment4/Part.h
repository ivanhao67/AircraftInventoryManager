#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Part
{
  friend ostream& operator<<(ostream& out, Part&);
	public:
		Part(string n);
		virtual ~Part(){};
		void addFlightHours(int);
		void install(Date&);
		string getName();
		virtual bool inspection(Date){return false;};
	protected:
		int flighthours;	
		string name;
		Date installationDate;
};

class FH_Part : virtual public Part
{
	public:
		FH_Part(string,int);
		bool inspection(Date);
	protected:
		int fh_inspect;
};
class IT_Part : virtual public Part
{
	public:
		IT_Part(string,int);
		bool inspection(Date);
	protected:
		int it_inspect;
};

class FHIT_Part : public FH_Part, public IT_Part
{
	public:
		FHIT_Part(string,int,int);
		bool inspection(Date);
};
#endif
