#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;
class Vehicle {
public:
	Vehicle() {}
	Vehicle(string type, string plate, int size, int occupied) : type(type), plate(plate), size(size), occupied(occupied) {}
	virtual ~Vehicle() = 0 ;
private:
	string type;
	string plate;
	int size;
	int occupied;
};

class Bus : public Vehicle {
public:
	Bus(){}
	Bus(string plate, bool isSchoolBus ) : Vehicle("BUS", plate, 4, 4), SchoolBus(isSchoolBus) {}
private:
	bool SchoolBus;
};

class ParkingLot {
private:
	vector<pair<Bus*, bool> > busSlot;
};

int main () {
	return 0;
}

