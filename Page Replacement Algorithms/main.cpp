#include <iostream>

using namespace std;

/*
     Consider the following reference string:
    7, 0, 1, 2,  3, 0, 4, 2, 2, 3, 5 , 7, 1, 4,  2, 3, 2, 0, 1, 4, 7, 5, 2, 3, 2, 7, 0, 1, 5
    Write a program that simulates the followig page replacement algorithms given in Chapter 9.4:
    First-come, first out page replacement algorithm
    Optimal page replacement algorithm
    Least recently used page replacement algorithm
    The number of frames should be given by the user. The program should give the number of
     page faults for each page replacement algorithm.
*/

//Set the global variables
int ReferenceString[] = {7, 0, 1, 2,  3, 0, 4, 2, 2, 3, 5 , 7, 1, 4,  2, 3, 2, 0, 1, 4, 7, 5, 2, 3, 2, 7, 0, 1, 5};
int frameNo;


void getFrameNo()
{
    cout<<"Please enter the number of frames: ";
    cin>>frameNo;
}

void FCFO()
{

}

void optimalReplecament()
{

}

void LRUReplacement()
{
    
}


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}