#include<iostream>

using namespace std;


//Setting the variables as global variables:
int processNum;
//Since we know resource types, I simply will use  A B C for each matrix types.
int allocationA[100], allocationB[100], allocationC[100];
int maxA[100], maxB[100], maxC[100];
int availableA,availableB, availableC;
int needA[100], needB[100], needC[100];
int checkFlag[100];

//Function to set the process number by the user.
int getProcessNum()
{
    cout<<"enter the number of process: ";
    cin>>processNum;
    return processNum;
}

//Getting the Allocation Matrix
void getAllocationMatrix()
{
    int i;
    cout<<"Please Enter the Allocation Matrix"<<endl;
    cout<<"     A-B-C"<<endl;
    for(i=1;i<=processNum;i++)
    {
        cout<<"P["<<i-1<<"}: "; //Since I started the loop from 1, to write process number in a row I decreased it by 1
        cin>>allocationA[i];
        cin>>allocationB[i];
        cin>>allocationC[i];
    }
    for(i=1;i<=processNum;i++)
    {checkFlag[i]=0;
    }
}

//Getting the Max Matrix
void getMaxMatrix()
{
    int i;
    cout<<"Please Enter the Max Matrix";
    cout<<endl<<"     A-B-C"<<endl;
    for(i=1;i<=processNum;i++)
    {
        cout<<"P["<<i-1<<"}: ";
        cin>>maxA[i];
        cin>>maxB[i];
        cin>>maxC[i];
    }
}

void getAvailableProcess()
{
    cout<<"Please Enter the Available Row:"<<endl;
    cout<<"     A-B-C"<<endl;
    cin>>availableA;
    cin>>availableB;
    cin>>availableC;
}
//We can simply calculate the Need Matrix:
//Needi = Max[i] –Available[i] ;
void calculateNeed()
{
    int i;
    cout<<"The Need Matrix is: "<<endl;
    cout<<"A-B-C"<<endl;
    for(i=1;i<=processNum;i++)
    {
        needA[i]=maxA[i]-allocationA[i];
        needB[i]=maxB[i]-allocationB[i];
        needC[i]=maxC[i]-allocationC[i];
        cout<<needA[i]<<" "<<needB[i]<<" "<<needC[i]<<endl;
    }
}

void setSequence()
{
    int i;
    cout<<"The Sequence Is:"<<endl;
    z:
    for(i=1;i<=processNum;i++)
    {
        //To check if the system is in safe state
        if(availableA>=needA[i]&&availableB>=needB[i]&&availableC>=needC[i]&&checkFlag[i]!=-1)
        {
            cout<<"P["<<i-1<<"]"<<"\t";
            checkFlag[i]=-1;
            availableA=availableA+allocationA[i];
            availableB=availableB+allocationB[i];
            availableC=availableC+allocationC[i];
        }

    }
    for(i=1;i<=processNum;i++)
    {if(checkFlag[i]!=-1)
        {goto z;
        }
    }
    //I'm declaring it as a different if statement instead of declaring as else statement above
    //to not turn it in the loop
    if(availableA<needA[i]|| availableB<needB[i] || availableC<needC[i] || checkFlag[i]!=0)
    {
        cout<<"The system is not in the safe state!"<<endl;
    }
}

void print()
{
    getProcessNum();
    cout<<endl;
    getAllocationMatrix();
    cout<<endl;
    getMaxMatrix();
    cout<<endl;
    getAvailableProcess();
    cout<<endl;
    calculateNeed();
    cout<<endl;
    setSequence();
}

int main()
{
    print();
}