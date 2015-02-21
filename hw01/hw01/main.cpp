//
//  main.cpp
//  hw00
//
//  Created by Rafi Rizwan on 1/27/15.
//  Copyright (c) 2015 Rafi Rizwan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define FILE_NAME "encrypted.txt" //constant name of input file

int main(int argc, const char * argv[]) {
    const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<string> lines;
    string filename;
    
//  could use noskipws...?
    
    ifstream if2(FILE_NAME);
    if (!if2) {
        cerr << "womp womp" << endl;
    } else {
        int key;
        char shift;
        
        while(if2 >> key){
            while (if2 >> noskipws >> shift) {
                shift = shift - key;
                cout << shift;
            }
        }
    } //according to documentation, noskipws only checks for, and doesn't skip the leading whitespace -- does not serve as delimiter.
    
    cout << endl << endl;
    cout<<"Please enter the name of the file in the program directory: "<<endl;
    cin >> filename;
    
    ifstream iostream(filename);
    if(!iostream){ //check for errors
        cerr << "File not found" << endl;
    } else {
        cout<<"Original Encrypted File:"<<endl;
        string line;
        int key;
        while (iostream >> key) {
            while (getline( iostream, line)) {
                cout << line << endl;
                for (size_t i = 0; i < line.length(); ++i) { //walk down the length of a line
                    if (islower(line[i])) { //check if the letter we're on is lowercase, if not, do nothing
                        if (isalpha(line[i]-key)) { // check if the result of ascii arithmetic returns a letter
                            line[i] -= key;
                        } else { //if it's not then use the array up top
                            char shift = line[i];
                            for (size_t j = 0; j < sizeof(alphabet); ++j) {
                                if (shift == alphabet[j]) {
                                    size_t nKey = j-key+sizeof(alphabet); //position - key + size of the alphabet always returns positive.
                                    line[i] = alphabet[nKey];
                                }
                            }
                        }
                    }
                }
                lines.push_back(line);
            }
        } iostream.close();
//        //STL iterator for vectors to walk from the end of the vector to the beginning.
//        for(vector<string>::reverse_iterator it = lines.rbegin(); it != lines.rend(); ++it){
//            cout << *it << endl;
//        } too bad we don't know how to use iterators yet.
        cout << "\nDecrypted File:" << endl;
        for (size_t i = lines.size(); i < -1; --i) {
            cout << lines[i] << endl;
        }
    }
    
    return 0;
}


