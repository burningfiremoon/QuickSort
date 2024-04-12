#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    vector<int> numbers;
    
    // Generate a list of non-repeating integers
    random_device rd;
    mt19937 gen(rd());
    for (int i = 1; i <= 10000; ++i) {
        numbers.push_back(i);
    }
    shuffle(numbers.begin(), numbers.end(), gen);
    
    // Write the numbers to a text file
    ofstream file("1000_RNG.txt");
    if (file.is_open()) {
        for (int num : numbers) {
            file << num << "\n";
        }
        file.close();
        cout << "File generated successfully." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    return 0;
}