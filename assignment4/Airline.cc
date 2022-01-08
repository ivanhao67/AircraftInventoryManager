#include "Airline.h"

Airline::Airline(string n){
	name = n;
}

Airline::~Airline(){
	for(int index = 0; index<p.getSize();index++){
		delete p[index];
	}
	for(int index2 = 0; index2<a.getSize();index2++){
		delete a[index2];
	}
}

Aircraft* Airline::getAircraft(string reg){
	for(int index = 0; index<a.getSize();index++){
		if(a[index]->getReg()==reg){
			return a[index];
		}
	}
	return NULL;
}

Part* Airline::getPart(string nam){
	for(int index = 0; index<p.getSize();index++){
		if(p[index]->getName()==nam){
			return p[index];
		}
	}
	return NULL;
}

void Airline::addAircraft(string type, string reg){
	Aircraft* air = new Aircraft(type,reg);
	a.add(air);
}

void Airline::addPart(string part, int fh_inspect, int it_inspect){
	if(fh_inspect == 0){
		IT_Part* par = new IT_Part(part,it_inspect);
		p.add(par);
	}else if(it_inspect == 0){
		FH_Part* par = new FH_Part(part,fh_inspect);
		p.add(par);
	}else{
		FHIT_Part* par = new FHIT_Part(part,fh_inspect,it_inspect);
		p.add((Part*)par);
	}
}

void Airline::takeFlight(string reg, int hours){
	for(int index = 0; index<a.getSize();index++){
		if(a[index]->getReg()==reg){
			a[index]->takeFlight(hours);
		}
	}	
}

void Airline::printAircraft(){
	cout<<a<<endl;
}

void Airline::printParts(){
	cout<<p<<endl;
}

void Airline::inspectionReport(string reg, Date& d){
	for(int index = 0; index<a.getSize();index++){
		if(a[index]->getReg()==reg){
			cout<<"The following parts from "<<reg<<" require inspection:"<<endl;
			Array<Part*>* temp = new Array<Part*>();
			a[index]->inspectionReport(d,temp);
			cout<<*temp<<endl;
			delete temp;
		}
	}
}

bool Airline::install(string reg,string name ,Date& d){
	for(int index = 0; index<a.getSize();index++){
		if(a[index]->getReg()==reg){
			for(int index2 = 0; index2<p.getSize();index2++){
				if(p[index2]->getName()==name){
					a[index]->install(p[index2],d);
					return true;
				}
			}
		}
	}	
	return true;
}





