#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc,char **argv) {

  if(argc < 2) {
    cout << "makesquare <input file> [a]" << endl;
    cout << "a to add spaces" << endl;
    return 0;
  }
  
  bool add_spaces=false;
  if(argc > 2) if(argv[2][0] == 'a') add_spaces=true;

  // read last line of file, get number of 1s and 0s store in max_length
  ifstream infile(argv[1]);

  string line;
  int max_length=0;
  for(;!infile.eof();) {
    getline(infile,line);
    if(!infile.eof())
    max_length = 0;
    for(string::iterator i = line.begin();i != line.end(); i++) 
     if (((*i) == '0') || ((*i) == '1')) max_length++;
  }

  infile.close();

  ifstream infile2(argv[1]);
  // iterate over file, subtract number of 1s and 0s on line from max_length
  // divide this number by 2 = pad_length
  for(;!infile2.eof();) {
    getline(infile2,line);
    if(!infile2.eof()) {
      int line_length=0;
      for(string::iterator i = line.begin();i != line.end(); i++) 
        if (((*i) == '0') || ((*i) == '1')) line_length++;

        int pad_length = (max_length-line_length)/2;

        for(int n=0;n<pad_length;n++) {cout << "0"; if(add_spaces) cout << " ";}
        if(!add_spaces) cout << line;
	else {
	  for(string::iterator i = line.begin();i != line.end(); i++) {
	    cout << (*i);
	    cout << " ";
	  }
	}
        for(int n=0;n<pad_length;n++) {cout << "0"; if(add_spaces) cout << " ";}
        cout << endl; 
    }
  }

  infile2.close();
}
