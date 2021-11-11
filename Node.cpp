#include "Node.h"
#include <string>

// Constructor
Node::Node(string n, string l, int num) {
	this->name=n; // name of node
	this->label=l; //node label
	this->number=num; //node number
}

Node::~Node() { // Destructor. I didn't use any pointers in this class so I don't need to explicitly delete anything
	
}

// Setters or Manipulators
void Node::setName(string n) {
	this->name=n;
}
void Node::setLabel(string l) {
	this->label=l;
}
void Node::setNumber(int num) {
	this->number=num;
}

// Getters or Accessors
string Node::getName() {
	return name;
}
string Node::getLabel() {
	return label;
}
int Node::getNumber() {
	return number;
}
