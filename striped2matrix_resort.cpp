#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int compare_lines(int x,int y,vector<vector<int> > &matrix) {
  int diff;
  for(int n=0;n<matrix[x].size();n++) {
    if((matrix[x][n] - matrix[y][n]) >= 0) diff = matrix[x][n] - matrix[y][n];
                                      else diff = matrix[y][n] - matrix[x][n];
  }

  return diff;
}

void swap_lines(int l1,int l2,vector<vector<int> > &matrix) {
  for(int n=0;n<matrix[l1].size();n++) {
    int swap = matrix[l1][n];
    matrix[l1][n] = matrix[l2][n];
    matrix[l2][n] = swap;
  }
}

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

  // create numbering
  vector<int> x_numbering(257,0);
  vector<int> y_numbering(257,0);

  for(int n=0;n<257;n++) {
    x_numbering[n] = n;
    y_numbering[n] = n;
  }

  // bubble sort data...

/*
  // reorder matrix, keep numbering consistant
  for(int n=0;n<100;n++)
  for(int cur=0;cur<257;cur++) {
    bool first_comp = true;
    int min_diff=0;
    int min_loc =0;    

    for(int comp=0;comp<257;comp++) {
      // compare cur to comp, store lowest difference
      if(cur != comp) {
        int diff = compare_lines(cur,comp,matrix);

        if((diff < min_diff) || first_comp) {
          min_diff = diff;
          min_loc  = comp;
          first_comp = false;
        }
      }
    }

    // shuffle things around a bit...
    // cout << "cur: " << cur << " min_loc: " << min_loc << " min_dif: " << min_diff << endl;
    if((min_loc > 0) && (min_loc < 256)) {
      if(cur>min_loc)
        swap_lines(min_loc+((cur-min_loc)/2),min_loc,matrix);
      else
        swap_lines(cur+((min_loc-cur)/2),min_loc,matrix);
     }
  }
*/
  for(matrix_type::iterator i = matrix.begin();i != matrix.end();i++) {
    for(vector<int>::iterator i2 = (*i).begin();i2 != (*i).end();i2++) {
      cout << (*i2) << " ";
    }
    cout << endl;
  }

}

