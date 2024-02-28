#include <iterator>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <emscripten/emscripten.h>
using namespace std;

string input;

string convert(const string& word) {
    string word_with_underscore = word + "_";
    string line;
    string antonym = word;

    ifstream file("anty.tsv");
    if (!file.is_open()) {
        cerr << "Error opening file anty.tsv\n";
        return word_with_underscore; // Return the word with underscore if file cannot be opened
    }

    while (getline(file, line)) {
        size_t position = line.find(word_with_underscore);
        if (position == 0) {
            antonym = line.substr(word_with_underscore.length() + 2);
            return antonym;
        }
    }

    return word;
}

string getOutput() {
    // Store words in a vector
    istringstream iss(input);
    vector<string> words{istream_iterator<string>{iss},
                         istream_iterator<string>{}};
    vector<string> output;

    // Run each word through the convert function and store the result
    for (const string& word : words) {
        output.push_back(convert(word));
    }

    // Output the results all in the same line
    stringstream buffer;
    for (int i = 0; i < output.size(); i++) {
        buffer << output.at(i) << endl;
    }

    return buffer.str();
}

// Custom input function
extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void setInput(const char* user) {
        // Get input containing multiple words
        input = user;
    }

    // Custom output function
    EMSCRIPTEN_KEEPALIVE
    const char* getOutput() {
        return getOutput().c_str();
    }
}

int main() {
    return 0;
}
