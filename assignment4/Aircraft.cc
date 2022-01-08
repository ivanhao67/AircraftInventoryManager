
#include "Aircraft.h"

Aircraft::Aircraft(string t,string r){
	type = t;
	registration = r;
}

string Aircraft::getReg(){
	return registration;
}

void Aircraft::install(Part* p, Date& d){
	p->install(d);
	a.add(p);
}

void Aircraft::takeFlight(int hours){
	for(int index = 0; index<a.getSize();index++){
		a[index]->addFlightHours(hours);
	}
}

void Aircraft::inspectionReport(Date d,Array<Part*>* ra){
	for(int index = 0; index<a.getSize();index++){
		if(a[index]->inspection(d)){
			ra->add(a[index]);
		}
	}
}

ostream& operator<<(ostream& out, Aircraft& a){
	return out<<"Type: "<<a.type<<"\nRegistration: "<<a.registration<<endl;
}


