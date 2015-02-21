//
//  main.cpp
//  LAB04
//  N12265380
//  Created by Rafi Rizwan on 2/19/15.
//  Copyright (c) 2015 Rafi Rizwan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Complex {
    double real;
    double img;
};

class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    //void setX( int val )  { x = val; }
    void setX( int x )  { this->x = x; }
private:
    int x;
};

class Colour {
public:
    Colour( const string& name, unsigned r, unsigned g, unsigned b )
    : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string   name;    // what we call this color
    unsigned r, g, b; // red/green/blue values for displaying
};

class SpeakerSystem {
public:
    void vibrateSpeakerCones( unsigned signal ) const {
        
        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Amplifier {
public:
    Amplifier( ) : attachedSpeakers( NULL ) {}
    void attachSpeakers( const SpeakerSystem& spkrs )
    {
        if( attachedSpeakers )
            cout << "already have speakers attached!\n";
        else
            attachedSpeakers = &spkrs;
    }
    void detachSpeakers()
    { attachedSpeakers = NULL; }
    // should there be an "error" message if not attached?
    void playMusic( ) const {
        if( attachedSpeakers )
            attachedSpeakers -> vibrateSpeakerCones( 440 );
        else
            cout << "No speakers attached\n";
    }
private:
    const SpeakerSystem* attachedSpeakers;
};

class Person {
public:
    Person( const string& name ) : name(name) {}
    void movesInWith( Person& newRoomate ) {
        roomie = &newRoomate;        // now I have a new roomie
        newRoomate.roomie = this;    // and now they do too
    }
    string getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    string getRoomiesName() const { return roomie->getName(); }
private:
    Person* roomie;
    string name;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
#pragma mark task 1 through 7
    
    int x;
    x = 10;
    cout << "x = " << x << endl;
    
#pragma mark task 8 through 10
    
    int* p;
    p = &x;
    cout << "p = " << p << endl << endl;
    
    //p = 0x0012fed4; // using the value from my Watch window
    
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl << endl;
    
#pragma mark task 11
    
    *p = 12;
    
    cout << "the value of p is now: " << *p << endl;
    cout << "since p was a pointer to an int assigned to x \n the value of x is: " << x << endl;
    
#pragma mark task 12
    
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    
#pragma mark task 13
    
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl << endl;
    
#pragma mark task 14
    
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    cout << "the value of pD is nao: " << *pD << endl; //this is okay, a double can hold an int value.
    *pD = 73.2343;
    *p  = *pD;
    *q  = *p;
    // pD  = p; //EXCEPT THIS DOESN'T WORK BECAUSE THIS IS RETARDED. YOU CAN'T HAVE A PTR TO AN INT BE ASSIGNED THE VALUE OF A PTR TO A DOUBLE
    
    cout << "\n\n\n";
    
    int joe( 24 );
    const int sal( 19 );
    int* const joeP(&joe); // address cannot be changed
    
    const int* moe(&joe); //value cannot be changed
    
    *joeP = 22;
    
    // *moe = 4; //throws error, trying to change constant (read only) value.
    
    moe = &joe; //but this works. since moe is now pointing to what's at the address of joe (could also be "joeP"), the value is now 22.
    
    cout << "CHECK DIS: " << *moe << endl;
    
    const int* const salP(&sal); // this is an example of a pointer where neither address nor value can be changed.
    // *salP = 12; // NOPE, THAT'S READ ONLY
    // salP = joeP; // NOPE, THAT'S READ ONLY TOO
    
    //wrote my own code.
    
    int*  pI; //ew this is indescriptive.
    //  pI = &joe;
    // *pI = 234;
    //  pI = &sal;
    // *pI = 7623;
    
    //const int* pcI;
    //  pcI = &joe;
    // *pcI = 234;
    //  pcI = &sal;
    // *pcI = 7623;
    
    //int* const cpI;
    //int* const cpI(&joe);
    //int* const cpI(&sal);
    //  cpI = &joe;
    // *cpI = 234;
    //  cpI = &sal;
    // *cpI = 7623;
    
    //const int* const cpcI;
    //const int* const cpcI(&joe);
    //const int* const cpcI(&sal);
    //  cpcI = &joe;  
    // *cpcI = 234;  
    //  cpcI = &sal;  
    // *cpcI = 7623;
    
    cout << "\n\n\n";
    
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    
    cout << "\n\n\n";
    
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
    
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    
    pDyn = NULL;
    double* pDouble( NULL );

    // cout << "Can we dereference NULL?  " << *pDyn << endl; //bad access
    // cout << "Can we dereference NULL?  " << *pDouble << endl; same
    
    double* pTest = new double( 12 );
    delete pTest;
    pTest = NULL;
    delete pTest; // safe
    
    short* pShrt = new short( 5 );
    delete pShrt;
    // delete pShrt; //LOL don't try to delete something that isn't there.
    
    long jumper( 12238743 );
    long* ptrTolong( &jumper );
    // delete ptrTolong; // ?????? WHY WOULD THIS WORK IF IT'S NOT ON THE HEAP?
    double dAr[ 3 ];
    // delete dAr; // "why would this work if it's not on the heap?"
    
    
#pragma mark task 27
    
    vector<Complex*> compli;
    Complex* tmpPCmplx;      // grab heap space for 3 Complex objects and "store" them
    // in the vector. We are really storing the Complex objects
    // we think of this as "storing" them
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        tmpPCmplx = new Complex;
        tmpPCmplx->real = ndx;
        tmpPCmplx->img  = ndx;
        compli.push_back( tmpPCmplx );
    }
    // display them
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        cout << compli[ ndx ]->real << endl;
        cout << compli[ ndx ]->img  << endl;
    }
    // release them
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        delete compli[ ndx ];
    }
    // clear the vector
    compli.clear();    

#pragma mark task 28
    vector< Colour* > colours;
    string inputName;
    unsigned inputR, inputG, inputB;   // fill vector with Colours from the file
    // this could be from a file but we are using the keyboard for now
    // (do you remember the keystrokes to indicate "end of file" at the keyboard?)
    while ( cin >> inputName >> inputR >> inputG >> inputB ) {
        colours.push_back( new Colour(inputName, inputR, inputG, inputB) );
    }
    
    // display all the Colours in the vector:
    for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {
        colours[ndx]->display();
        cout << endl;
    }

    
#pragma mark nothing
    //-------------------------------------------------------------------------
    
    char anykey;
    cout << "DEBUG MODE\n\nEnter the any key to quit\n";
    cin >> anykey;
    
    return 0;
}
