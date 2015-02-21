//
//  main.cpp
//  DAY02
//
//  Created by Rafi Rizwan on 1/28/15.
//  Copyright (c) 2015 Rafi Rizwan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> seqNums;
    vector<string> seqNames;
    
    seqNums.push_back(10);
    seqNums.push_back(82);
    seqNums.push_back(-107);
    
    for (size_t i = 0; i < seqNums.size(); ++i) {
        cout << seqNums[i] << endl;
        seqNums[i] += i;
    }
    
    //for each loop:
    for (int x: seqNums){
        cout << x << endl;
        x += 5;
    } // this does not allow mutation during enumeration and copies the item over. When with objects, use with pointers. Note that there is also no index.
    
    seqNums.pop_back();
    seqNums.back();
    seqNums.clear();
    
    string str = "hello there";
    for (char a: str) {
        cout << a << endl;
    }
    
    return 0;
}
