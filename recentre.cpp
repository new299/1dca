#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc,char **argv) {

  if(argc < 2) {
    cout << "recentre_matrix <input file>" << endl;
    cout << "strip zeros from left and right of line equally" << endl;
    return 0;
  }
  
  ifstream infile(argv[1]);
  
  bool start=true;
  int min_zero=0;
  for(;!infile.eof();) {
    string line;
    getline(infile,line);
    if(!infile.eof()) {
      
      string::iterator i = line.begin();
      int lzero = 0;
      for(;(i != line.end()) && ((*i) == '0'); i++) lzero++; 
     
      int rzero = 0;
      for(;i != line.end();i++) { if((*i) == '0') rzero++; else rzero=0;}
     
      if(start == true) min_zero = lzero;
      start = false;

      if(lzero < min_zero) min_zero = lzero;
      if(rzero < min_zero) min_zero = rzero;
    }
  }
  infile.close();

  ifstream infile2(argv[1]);
  for(;!infile2.eof();) {
     string line;
     getline(infile2,line);
     if(!infile2.eof()) {
       string print = line.substr(min_zero,line.size()-min_zero-min_zero);
       cout << print << endl;
     }  
  }

  infile2.close();
}
