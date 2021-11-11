#ifndef MAIN_CPP_EDGE_H
#define MAIN_CPP_EDGE_H
#include <string>

using namespace std;

// A Class to represent directed graph edge
class Edge
{ 
	string node1; // 1st node name
	string node2; // 2nd node name
	int nodeNumber1; // 1st node number
	int nodeNumber2; // 2nd node number
	string weight; // Edge weight. If edge weights are node given, weight is just stored as "1"

public:
	Edge(string n1, string n2, string w); // Constructor
	Edge(string n1, string n2); // Constructor
	~Edge();

	// Setters or Manipulators
	void setNode1(string n1);
	void setNode2(string n2);
	void setNodeNumber1(int nn1);
	void setNodeNumber2(int nn2);
	void setWeight(string w);

	// Getters or Accessors
	string getNode1();
	string getNode2();
	int getNodeNumber1();
	int getNodeNumber2();
	string getWeight();

	// utility methods
	/*friend */static string splitStringIntoHalf(string s);
	/*friend */static int stringToInt(string s);
};

#endif //MAIN_CPP_EDGE_H
