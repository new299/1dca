#INCLUDE <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc,char **argv) {

  if(argc < 2) {
    cout << "stripzero <input file>" << endl;
    cout << "strip zeros from left and right of line" << endl;
    return 0;
  }
  
  ifstream infile(argv[1]);
  for(;!infile.eof();) {
    string line;
    getline(infile,line);
    if(!infile.eof()) {
      
      string::iterator i = line.begin();
      for(;(i != line.end()) && ((*i) == '0'); i++); 
     
      int zerocount=0;
      
      
      for(;i != line.end(); i++) if((*i) == '0') zerocount++;
      else {for(int n=0;n<zerocount;n++) cout << '0'; cout << '1'; zerocount=0;}

      cout << endl;
    }
  }

  infile.close();
}
