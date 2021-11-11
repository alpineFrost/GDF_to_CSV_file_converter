#ifndef MAIN_CPP_NODE_H
#define MAIN_CPP_NODE_H 
#include <string>

using namespace std; 

// A Class to represent directed graph node 
class Node
{ 
	string name; // name of node
	string label; // label of node
	int number; // node number
	
public: 
	Node(string n, string l, int num); // Constructor 
	~Node(); // Destructor

	// Setters or Manipulators
	void setName(string n);
	void setLabel(string l);
	void setNumber(int num);	

	// Getters or Accessors
	string getName();
	string getLabel();
	int getNumber();

}; 

#endif //MAIN_CPP_NODE_H
