#include "Edge.h"
#include <sstream>
#include <string>

// Constructor
Edge::Edge(string n1, string n2, string w) {
	this->node1=n1;
	this->node2=n2;
	this->nodeNumber1=stringToInt(splitStringIntoHalf(n1));
	this->nodeNumber2=stringToInt(splitStringIntoHalf(n2));
	this->weight=w;
}

// Constructor
Edge::Edge(string n1, string n2) {
	this->node1=n1;
	this->node2=n2;
	this->nodeNumber1=stringToInt(splitStringIntoHalf(n1));
	this->nodeNumber2=stringToInt(splitStringIntoHalf(n2));
}

Edge::~Edge() { // Destructor. I didn't use any pointers in this class so I don't need to explicitly delete anything

}

// Setters or Manipulators
void Edge::setNode1(string n1) {
	this->node1=n1;
}
void Edge::setNode2(string n2) {
	this->node2=n2;
}
void Edge::setNodeNumber1(int nn1) {
	this->nodeNumber1=nn1;
}
void Edge::setNodeNumber2(int nn2) {
	this->nodeNumber2=nn2;
}
void Edge::setWeight(string w) {
	this->weight=w;
}

// Getters or Accessors
string Edge::getNode1() {
	return node1;
}
string Edge::getNode2() {
	return node2;
}

int Edge::getNodeNumber1() {
	return nodeNumber1;
}
int Edge::getNodeNumber2() {
	return nodeNumber2;
}

string Edge:: getWeight() {
	return weight;
}

// Utility methods
string Edge::splitStringIntoHalf(string s) {
    string half = s.substr(0, s.length()/2);
    string otherHalf = s.substr(s.length()/2);
    return otherHalf;
}

int Edge::stringToInt(string s) {
	stringstream convert(s);
    int x=0;
    convert >> x;
    return x;
}
