#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
  // Declares 1.txt in code as ifstream
  ifstream file("1.txt");
  // user input for a word in the dictionary
  string word;
  cout << "Enter the word to search for. Don't forget to capitalize the first "
          "letter! :) ";
  cin >> word;
  word = word + " ";
  string line;
 // int lineNumber = 1;

  while (getline(file, line)) {
    size_t position = line.find(word);
    if (position == string::npos) {
      continue;  // Go to the next line if the word is not found in the current line
      if (position == string::npos) {
      cout << "no";
      }
    } else if (position != string::npos && position == 0) {
      string def = line.substr(word.length());
      cout << def << endl;
    } else {
      break;
    }
  }
  // If the loop completes without finding the word, print "no"
 

}
