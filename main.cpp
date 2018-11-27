#include <iostream>
#include <fstream>
#include <sstream>
#include "MyMap.hpp"


int main() {
    MyMap<string, int> m;
    ifstream file;
    file.open("../studentMarks.txt");
    string line;

    while(getline(file, line)) {
        istringstream iss(line);
        string name;
        int mark;
        iss >> name;
        iss >> mark;
        m.add(name, mark);
    }

    cout << m << endl;
    cout << "Standard Deviation: " << m.standardDeviation(m.getFirstIter(), m.getLastIter()) << endl;
    pair<string, int> fifth = m[5];
    cout << "5th index key: " <<  fifth.first << " , 5th index value: " << fifth.second <<  endl;
    cout << "Wiggim's value is: " << m["Wiggim"] << endl;
    return 0;
}