#pragma once
// Tri Nguyen CPSC 131-01
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() 
	{  // default constructor
		

	};

	Baby(string s, int w) 
	{ 
	  
		name = s; // appoint 's' as name.
		weight = w; // appoint 'w' as weight.
	
	}

	// a "getter" method
	int getWeight() {
		return weight; 
	}

	// a "getter" method
	string getName() 
	{
		return name; 
	}

private:
	string name; // store the name
	int weight;  // store the weight
	
};