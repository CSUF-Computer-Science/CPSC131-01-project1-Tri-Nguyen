#pragma once
// Tri Nguyen CPSC 131-01
#include <string>
#include <stdexcept>
#include "Baby.h"


using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() 
	{
		darray = new Baby [250000]; // set the size of Baby to 250000
		countname = 0;				
		
		
		
	}

	// destructor
	~MedicalRecord() 
	{
		cout << "\n";
		cout << "***Array has been deleted***" << endl;
		cout << "\n";
		
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);
		int index = 0;
		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) 
			{
				// cout << name << " " << weight << endl;
				Baby b(name, weight); // Baby b consists of name and weight of babies
				addEntry(b);		// 	call Baby.h to get name and get weight.	
				// increment the text files beginning with 0.
				index += 1; 

			}
			
			 countname = index; // set index equal to countname.
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}
	// return the most frequently appearing name in the text file
	string mostPopularName()
	{
		
		int *countarray = new int[countname]; // create an array with size of countname
		for (int i = 0; i < countname; i++)   // process each data from both files.
		{
			countarray[i] = 0;
		}
		
		for (int i = 0; i < countname; i++) // search for identical name
		{
			for (int j = 0; j < countname; j++)
			{
				if (darray[i].getName() == darray[j].getName()) // if a name is identical then proceed
				{
					countarray[i]++;		// increment
				}

			}
		}

		// find the name that exists the most in each file.
		int max = 0;
		for (int i = 0; i < countname; i++)
		{
			if (countarray[max] < countarray[i])
			{
				
				max = i;
				
			}
		}

		return darray[max].getName(); // display the name that exists the most. 
	}
	

	// return the number of baby records loaded from the text file
	int numberOfBirths() 
	{

		return countname; 
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() 
	{
		int count = 0;
		for (int i = 0; i < countname; i++) // process each data from both files 
		{
			if (darray[i].getWeight() < 2500) // any data that has weight less than 2500 then proceed to the next data.
			{
				count++;			// increment
			}
		}
		return count;
		
		 
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) 
	{
		int count = 0;
		for (int i = 0; i < countname; i++) // process each data from both files 
		{
			
			if (darray[i].getName()== s)  // find the name that has string s.
			{
				count++;				// increment
			}
		}
		return count;
		
		
	}
	

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b)	// This function adds baby name and weight to new array. 
	{
		darray[index] = b;	
		index++;			// update the index when function is called
		
		
	} 
	
	
	int index = 0;	
	 Baby *darray; // use dynamic memory to allocate using operator new.
	int countname = 0; // the length of data 




};
