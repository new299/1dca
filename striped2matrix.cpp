#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc,char **argv) {

  typedef vector<vector<int> >  matrix_type;
  matrix_type matrix(257,vector<int>(257,0));


  if(argc < 2) {
    cout << "strip2matrix <input file>" << endl;
    return 0;
  }
  
  ifstream infile(argv[1]);
  int x,y,z;
  for(int pos=0;!infile.eof();pos++) {
    int i;
    infile >> i;

    if(pos%3 == 0) x = i; 
    if(pos%3 == 1) y = i; 
    if(pos%3 == 2) {
      z = i;  
      matrix[x][y] = z;
    }
  }
  infile.close();

  for(matrix_type::iterator i = matrix.begin();i != matrix.end();i++) {
    for(vector<int>::iterator i2 = (*i).begin();i2 != (*i).end();i2++) {
      cout << (*i2) << " ";
    }
    cout << endl;
  }

}
