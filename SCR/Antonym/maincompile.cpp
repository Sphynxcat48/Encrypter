#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <emscripten/emscripten.h>

using namespace std;

string word;

// Custom input function
extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void setInput(const char* input) {
        word = input;
    }

    // Custom output function
    EMSCRIPTEN_KEEPALIVE
    const char* getOutput() {
        return convert(word).c_str();
    }
}

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
    // Not used, but required for compilation
    return 0;
}
