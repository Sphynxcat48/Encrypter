#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string full;
bool isVowel(char x) {
  return(x == 'a' || x == 'e' || x == 'i' || x == 'o'
    || x == 'u' || x == 'A' || x == 'E' || x == 'I'
    || x == 'O' || x == 'U');
}

bool isY(char t) {
  return(t == 'y');
}

string fromPigLatin(string full) {
    transform(full.begin(), full.end(), full.begin(),
              [](unsigned char c) { return tolower(c); }); // turns all letters lowercase

    if (full.size() >= 3 && full.substr(full.size() - 3) == "yay") {
       if(isY(full[0])){
        return full.substr(0, full.size() - 2);
      } else {
        return full.substr(0, full.size() - 3);
    }
    }
    else {
        full = full.substr(0, full.size() - 2);
        string last(1, full.back());
        full = full.insert(0, last);
        return full.substr(0, full.size() - 1);
        // decodes piglatin
    }
}



string toPigLatin(string full) {

  transform(full.begin(), full.end(), full.begin(),
    [](unsigned char c){ return tolower(c); });
// makes all letters lower case
  if (isVowel(full[0])) {
    return full + "ay";
  } else {
    return full.substr(1) + full[0] + "yay";
    // isolates the entire word exept the first letter and adds it to the end of the word and adds ay
  }
}
    
int main() {
  // user input/output
  string inname;
  string outname;
  char y;
  cout << "type E for converting to piglatin, type D for decrypting pig latin: ";
  cin >> y;
  cout << "Input File Name:" << inname << endl;
  cin >> inname;
  ifstream file(inname + ".txt");
  cout << "Please enter Output File Name: ";
  cin >> outname;
  cout << "Output File Name:" << outname << endl;
  ofstream outFile(outname + ".txt");
  if (file.is_open() && outFile.is_open()) {
    while (file >> full) {
      if (y == 'E') {
        string pigLatinWord = toPigLatin(full);
        outFile << pigLatinWord << " ";
      } else if (y == 'D') {
        string originalWord = fromPigLatin(full);
        outFile << originalWord << " ";
      } else {
        cout << "Unable to open file";
      }

    }
     return 0;
  }
}