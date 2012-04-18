#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc,char **argv) {

  if(argc < 2) {
    cout << "addspaces <input file>" << endl;
    cout << "add space between each character" << endl;
    return 0;
  }
  
  ifstream infile(argv[1]);
  for(;!infile.eof();) {
    string line;
    getline(infile,line);
    if(!infile.eof()) {
      
      for(string::iterator i = line.begin();i != line.end(); i++) cout << (*i) << " "; 
      cout << endl;
    }
  }

  infile.close();
}
