#include<bits/stdc++.h>
#include "GDFFileReader.h"
#include "Node.h"
#include "Edge.h"

using namespace std;

string GetFileExtension(const std::string&);

int main(int agrv, char* argc[]){  //command line input

   string filename= argc[1];

   if(GetFileExtension(filename) == "gdf") {
     GDFFileReader g(filename);
     g.read(filename);
     g.write();
     return 0;
   }

   else
   cout << "Error: Unsupported file";
 }

string GetFileExtension(const std::string& FileName){
   if(FileName.find_last_of(".") != std::string::npos)
      return FileName.substr(FileName.find_last_of(".") + 1);
   return "";
}
