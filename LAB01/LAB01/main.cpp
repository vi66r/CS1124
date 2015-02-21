//
//  main.cpp
//  LAB01
//
//  Created by Rafi Rizwan on 1/29/15.
//  Copyright (c) 2015 Rafi Rizwan. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readLine(ifstream &ifs)
{
    cout << "\nLine by line: \n";
    string line;
    while (getline(ifs, line)) cout << line << endl;
}

void readWords(ifstream &ifs)
{
    cout << "\nWord by word:\n";
    string word;
    int counter = 0;
    while (ifs >> word)
    {
        cout << word << endl;
        counter++;
    }
    cout << "There are " << counter << " words in this file.\n";
}

int main()
{
    // getting file name from user
    string fileName = "";
    cout << "Enter the file name: ";
    cin >> fileName;
    
    // ifs, and testing if it exists
    ifstream ifs(fileName);
    if (!ifs)
    {
        cerr << "File not found\n";
        exit(1);
    } else {
    
    // reading line-by-line
    readLine(ifs);
    ifs.close();

    }
    //alternatively, use the same ifstream and clear the buffer with ifs.clear(); and set the cursor to the beginning of the file with ifs.seekg(0);
    
    // reading word-by-word
    cout << "Enter the file name: ";
    cin >> fileName;
    ifstream new_ifs(fileName); // last ifs was exhausted
    if (!new_ifs) {
        cerr << "File not found\n";
    } else {
    readWords(new_ifs);
    new_ifs.close(); // close file
    }
}