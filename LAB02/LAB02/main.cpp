/*
 Rafi Rizwan
 ID: NS12265380
 LAB 02
 */


#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//this is the struct for the hydrocarbons.
struct Hydrocarbon{
    int numOfC;
    int numOfH;
    vector<string> names;
    
};


/*this functuion takes care of finding whether or not the hydrocarbons
 are already in the struct in terms of the molecular formula.
 if the formula is known then it returns the index positon in the vector
 to the next function.
 */

size_t find(const vector<Hydrocarbon>& hc, int numOfC, int numOfH){
    for(size_t i = 0; i < hc.size(); i++){
        if(hc[i].numOfC == numOfC && hc[i].numOfH == numOfH){
            return i;
        }
    }
            return hc.size();
    
}


/*This function, as stated, takes care of reading from the file and
 placing all of the data into a vector which is within the hydrocarbon
 struct. If the hydrocarbon is new in terms of the molecular formula then
 it creates a new hydrocarbon and then places it into a larger vector.
 Otherwise it adds the name into a prexisting classification for the
 formula.
 */
void readFromFile(ifstream& moleculeStream, vector<Hydrocarbon>& hc){
    int numOfC, numOfH;
    string name;
    char junk;
    
    while(moleculeStream >> name >> junk >> numOfC >> junk >> numOfH){
        size_t index = find(hc, numOfC, numOfH);
        if(index == hc.size()){
            Hydrocarbon molecule;
            molecule.names.push_back(name);
            molecule.numOfC = numOfC;
            molecule.numOfH = numOfH;
            hc.push_back(molecule);
            //cout << "new molecule!" << endl;
        }
        else{
            hc[index].names.push_back(name);
            //cout << "already exists" << endl;
        }
    }
    moleculeStream.clear();
    moleculeStream.seekg(0);
    
}


/* this function prints the data in ascending order by the
 numer of carbon atoms in the molecule */

void printData(const vector<Hydrocarbon>& hc){
    int max = 0;
    for(int i = 0; i < hc.size(); ++i){
        if(hc[i].numOfC > max){
            max = hc[i].numOfC;
        }
    }
    for (int j = 0; j < max; ++j) {
        for(Hydrocarbon c : hc){
            if (c.numOfC == j){
                cout << "C" << c.numOfC << "H" << c.numOfH << endl;
                for (string s : c.names){
                    cout << s << endl;
                }
                cout << endl << endl;
            }
        }
    }
}

int main(){
    
    vector<Hydrocarbon> moleculeList;
    
    ifstream moleculeStream("hydroc2.txt");
    if (moleculeStream){
        readFromFile(moleculeStream, moleculeList);
        printData(moleculeList);
    }
    else{
        cerr << "invalid file" << endl;
        exit(1);
    }
    
}