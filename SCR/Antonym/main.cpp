#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string word;
string inname;
string outname;

string convert(string word) {
  string word1 = word;
  word = word + "_";
  string line;
  string antonym;
  ifstream file("anty.tsv");
  size_t position = line.find(word); 
  while (getline(file, line)) {
        position = line.find(word); 
    if (position == string::npos) {
      continue;
    } else if (position == 0) {
      antonym = line.substr(word.length() + 2);
      break;  // Break from the loop after finding the antonym
    }
  }
  if (position == string::npos) {
    antonym = word.substr(word.length() - 1);
     }
  return antonym;
}

int main() {
 cin >> word;
 cout << convert(word);
}

