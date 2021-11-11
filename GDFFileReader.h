#ifndef MAIN_CPP_GDFFILEREADER_H
#define MAIN_CPP_GDFFILEREADER_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "Node.h"
#include "Edge.h"
#include"Base.h"
using namespace std;

class GDFFileReader : public Base
{ 
private:
	string fileName; // Name of file to be read
	vector<string> myText; // Vector which will store the lines of input
	string str; // Temporary string used while taking input
	vector<Node> nodes; // Vector which stores node objects
	vector<Edge> edges; //Vector which stores edge objects
	int numberOfNodes; //Number of nodes in the graph
	int numberOfEdges; //Number of edges in the graph
	int pos,pos1; // Variables used while splitting strings
	int weightOrNot; //If weight is given in input or not. Its value is 1 if weights are not given
	int i; // Temporary variable
	size_t found; // Variable used to check for ">"
	int w; // Variable to decide if we have to print adjacency matrix with weights or not. Its 1 if no weights 2 if weights are involved
public:
	GDFFileReader(string fn); // Constructor

	int read(std::string &); // Method to read the data from the .gdf file
	void findNodesAndNumberOfEdges(); // Method to find and stores nodes and edges in a vector
	void findEdges(); // To find edges
	int write(); // Creates .csv file
};

#endif //MAIN_CPP_EDGE_H
