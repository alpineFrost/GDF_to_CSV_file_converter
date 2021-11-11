#include "GDFFileReader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "Node.h"
#include "Edge.h"

using namespace std;

// Constructor. Sets filename and initializes all values to 0
GDFFileReader::GDFFileReader(string fn) {
	this->fileName=fn;
	this->i=0;
	numberOfNodes=0;
	numberOfEdges=0;
	pos=0;
	pos1=0;
	weightOrNot=0;
	i=0;
	found=0;
	w=0;
}

// Method to read the data from the .gdf file
int GDFFileReader::read(std::string &filename) {
	ifstream myReadFile(filename, ios::in | ios:: out);
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(myReadFile, str)) {
		myText.push_back(str);
		this->i++;
	}

	myReadFile.close(); //Done reading the file. Close it
	// Methods found
	findNodesAndNumberOfEdges();
	findEdges();
	return 0;
}

// Method to find and stores nodes and edges in a vector
void GDFFileReader::findNodesAndNumberOfEdges() {
	for(size_t j=1;j<myText.size(); j++) { // The loop used to check if the line is an edgedef or node
		found = myText[j].find(">");
 	 	if (found != string::npos) { // If it is an edgedef
  	 		this->weightOrNot=j;
  	 		break;
  	 	}
  	  	else { // If it is still defining a node
 	 		this->numberOfNodes=j;
 	  	}
	}

	for(int k=1;i<=this->numberOfNodes;k++) {
		this->pos = myText[k].find_first_of(','); // To split nodename, label string
		Node node(myText[k].substr(0, this->pos),myText[k].substr(pos+1),k-1);
		this->nodes.push_back(node); //nodes contains all the nodes
	}

	this->numberOfEdges=this->myText.size()-(this->numberOfNodes+2);
}

// To find edges
void GDFFileReader::findEdges() {
	if(myText[this->weightOrNot]=="edgedef>node1 VARCHAR,node2 VARCHAR") { // If no weights are given
		for(size_t j=this->numberOfNodes+2;j<this->myText.size();j++) {
			this->pos = this->myText[j].find_first_of(',');
			string firstPart=myText[j].substr(0, pos); // 1st node name
			string secondPart=myText[j].substr(pos+1); // 2nd node name
			Edge edge(firstPart,secondPart,"1");
			this->edges.push_back(edge); //edges contains all the edges
			this->w=1; // No weights
		}
	}

	// If weights are given
	else if(this->myText[weightOrNot]=="edgedef>node1 VARCHAR,node2 VARCHAR,weight DOUBLE" || this->myText[weightOrNot]=="edgedef>node1 VARCHAR,node2 VARCHAR, weight DOUBLE") {
		for(size_t j=this->numberOfNodes+2;j<this->myText.size();j++) {
			this->pos = myText[j].find_first_of(',');
			string firstPart=myText[j].substr(0, pos); // 1st node name
			this->pos1=myText[j].substr(this->pos+1).find_first_of(',');
			string secondPart=this->myText[j].substr(this->pos+1).substr(0,this->pos1); // 2nd node name
			string weight=this->myText[j].substr(this->pos+1).substr(this->pos1+1); // Weight
			Edge edge(firstPart,secondPart,weight);
			edges.push_back(edge); //edges contains all the edges
		}
		this->w=2;
	}
}

// Creates .csv file
int GDFFileReader::write() {
	if(w==1) { //No weights were given
		int adj[this->numberOfNodes][this->numberOfNodes];
		for(int k=0;k<this->numberOfNodes;k++) {
			for(int l=0;l<numberOfNodes;l++) {
				adj[k][l]=0;
			}
		}

		for(size_t j=0; j<edges.size(); j++) {
			adj[this->edges[j].getNodeNumber1()-1][this->edges[j].getNodeNumber2()-1]=1;
		}

		ofstream myFile("output.csv"); // Creating the .csv file

	    for(int i = 0; i < numberOfNodes; ++i) {
	        for(int j = 0; j < numberOfNodes-1; ++j) {
	            myFile << adj[i][j] << ",";
	        }
	        myFile << adj[i][numberOfNodes-1] << endl;
	    }

	    // Close the file
	    myFile.close();
	}

	else if(w==2) { //Weights were given
		string adj[numberOfNodes][numberOfNodes];
		for(int i=0;i<numberOfNodes;i++) {
			for(int j=0;j<numberOfNodes;j++) {
				adj[i][j]="0";
			}
		}

		for(size_t j=0; j<edges.size(); j++) {
			adj[edges.at(j).getNodeNumber1()-1][edges.at(j).getNodeNumber2()-1]=edges.at(j).getWeight();
		}

		ofstream myFile("output.csv"); // Creating the .csv file

	    for(int i = 0; i < numberOfNodes; ++i) {
	        for(int j = 0; j < numberOfNodes-1; ++j) {
	            myFile << adj[i][j] << ",";
	        }
	        myFile << adj[i][numberOfNodes-1] << endl;
	    }

	    // Close the file
	    myFile.close();
	}
	return 0;
}
