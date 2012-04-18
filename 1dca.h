#include <iostream>
#include <vector>

using namespace std;


vector<bool> rule_decompress(int rule_number) {
  vector<bool> rule;

  for(int pos=0;pos < 8; pos++) {
    if(rule_number & (1 << pos)) rule.push_back(true); else rule.push_back(false);
  }

  return rule;
}

int three_bit_to_int(bool a,bool b,bool c) {
  int number = 0;
  if(a == true) number = 4;
  if(b == true) number += 2;
  if(c == true) number += 1;

  return number;
}

void print_rule(vector<bool> rule) {
    cout << "       000 001 010 011 100 101 110 111" << endl;
    cout << "rule: ";
    for(vector<bool>::iterator i = rule.begin();i != rule.end();i++) {
      if(*i == true)  cout << "  1 ";
      if(*i == false) cout << "  0 ";
    }
    cout << endl;
}

vector<bool> string_to_bool_vec(string s) {
  vector<bool> vec;
  for(string::iterator i = s.begin();i != s.end();i++) {
    if((*i) == '0') vec.push_back(false);
    if((*i) == '1') vec.push_back(true);
  }
 
  return vec; 
}

/// Prints a 1 dimensional CA initialised with strip to the standard output
void run_1dca(vector<bool> rule, int iterations, vector<bool> strip) {

  for(int n=0;n<iterations;n++) {
    // print strip
    for(vector<bool>::iterator i = strip.begin();i != strip.end();i++) {
      cout << (*i);
    }
    cout << endl;
    
    vector<bool> strip_new = strip;
    strip_new.push_back(*(strip_new.end()--));
    strip_new.insert(strip_new.begin(),*(strip_new.begin()));

    for(int i = 0;i < strip_new.size();i++) {
      bool left  = false;
      bool cent  = false;
      bool right = false;
      int left_idx  = i-2; // because we have shifted the whole string by one effectively
      int cent_idx  = i-1;
      int right_idx = i;

      if(left_idx < 0) left_idx = 0;
      if(cent_idx < 0) cent_idx = 0;
      if(cent_idx  >= strip.size()) cent_idx  = strip.size() - 1;
      if(right_idx >= strip.size()) right_idx = strip.size() - 1;

      left = strip[left_idx];
      cent = strip[cent_idx];
      right = strip[right_idx];

      // convert bit pattern to int
      int idx = three_bit_to_int(left,cent,right);
      strip_new[i] = rule[idx];
    }

    strip = strip_new;
  }
}
