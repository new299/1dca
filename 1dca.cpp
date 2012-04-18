#include <iostream>
#include <vector>
#include "1dca.h"
using namespace std;

int main(int argc,char **argv) {

  if(argc < 3) {
    cout << "1dca <rule> <iterations> [o]" << endl;
    cout << "if o is present, output rule information" << endl;
    return 0;
  }

  int rule_number=atoi(argv[1]);
  int iterations=atoi(argv[2]);

  vector<bool> rule = rule_decompress(rule_number);

  if(argc > 3) 
  if(argv[3][0] == 'o') {
    print_rule(rule);
    cout << "rule number: " << rule_number << endl;
  }
  
  vector<bool> strip;

  strip.push_back(false);
  strip.push_back(true);
  strip.push_back(false);

  run_1dca(rule,iterations,strip);
}
