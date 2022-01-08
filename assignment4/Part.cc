#include "Part.h"

Part::Part(string n){
	name = n;
	flighthours = 0;
}

string Part::getName(){ return name; }

void Part::addFlightHours(int h){
	flighthours += h;
}

void Part::install(Date& d){
	installationDate = d;
}

ostream & operator<<(ostream& out, Part& p){
	return out <<"Part: "<<p.name<<"\n"<<"Flight hours: "<<p.flighthours<<"\n"<<"Installation date: "<<p.installationDate;
}

FH_Part::FH_Part(string n, int num):Part(n){
	fh_inspect = num;
}

bool FH_Part::inspection(Date d){
	return flighthours >= fh_inspect;
}

IT_Part::IT_Part(string n, int num):Part(n){
	it_inspect = num;
}

bool IT_Part::inspection(Date d){
	return (d.toDays()-installationDate.toDays())>=it_inspect;
}


FHIT_Part::FHIT_Part(string n, int fh,int it):FH_Part(n,fh),IT_Part(n,it),Part(n){
}

bool FHIT_Part::inspection(Date d){
	return (IT_Part::inspection(d) or FH_Part::inspection(d));
}

