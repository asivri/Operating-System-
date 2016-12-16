#include <iostream>

using namespace std;

//TODO: Check for the style!

//Set the global variables

int allocation[100][100];
int maxMatrix[100][100]; //Don't ever use max as name because it's declared as sth else and can't implemented as arrays.
int available[100];
int needMatrix[100][100];
int safeSequence[100];

int flag[100]; //A flag which checks completed processes

int getProcessNum()
{
    int n;
    cout << "Please enter the number of process:";
    cin >> n;
    cout << endl;
    return n;
}

int getResourceType()
{
    int m;
    cout << "Please enter the number of resources types:";
    cin >> m;
    return m;
}

int getMaxMatrix()
{
    int j, k;
    //Getting input for Max Matrix
    //TODO: Implement a string array for title :)
    cout << "Input for Max" << endl;
    for ( j = 0; j < getProcessNum(); j++) //Getting input across process number
    {
        cout << "P[" << j << "]:  ";
        for ( k = 0; k < getResourceType(); k++) //Getting input across resource types;
        {
            cin >> maxMatrix[j][k];
        }
    }
    return maxMatrix[j][k];
}

int getAllocationMatrix()
{
    int k, j;
    //Getting input for Allocation Matrix
    //TODO: Implement a string array for title :)
    cout << "Input for Allocation" << endl;
    for (j = 0; j < getProcessNum(); j++) //Getting input across process number
    {
        cout << "P[" << j << "]:  ";
        for (k = 0; k < getResourceType(); k++) //Getting input across resource types;
        {
            cin >> allocation[j][k];
        }
    }
    return allocation[j][k];
}

int getAvailableResource()
{
    int k;
    cout << "Input for Available Resources" << endl;
    for (k = 0; k < getResourceType(); k++) //Getting input across process number
    {
        cin >> available[k];
    }
    return available[k];
}

int controlFlag()
{
    int i;
    //Looping the control f lag.
    for (i = 0; i <getProcessNum(); i++) {
        flag[i] = 0;
    }
    return flag[i];
}

int calculateNeed()
{
    //declaration of loop variables;
    int i, j;
    for(i = 0; i<getProcessNum(); i++)
    {
        for(j = 0; j<getResourceType(); j++)
        {
            needMatrix[i][j] = maxMatrix[i][j] - allocation[i][j];
        }
    }
    return needMatrix[i][j];
}

void bankersFun()
{
    int processNum = getProcessNum();
    int i, j;
    int counter = 0;
    do{
        cout<<endl;
        cout<<"Max matrix:           Allocation Matrix: "<<endl;
        for( i = 0; i<getProcessNum(); i++)
        {
            for( j=0 ; j<getResourceType(); j++)
            {
                cout<<maxMatrix[i][j]<<"     ";
                cout<<allocation[i][j]<<"     ";
                cout<<endl;
            }
            processNum = -1;
            for(i = 0; i<getProcessNum(); i++)
            {
                if(controlFlag() == 0)
                {
                    processNum = i;
                    for (j=0 ; j<getResourceType(); j++)
                    {
                        if(available[j] < needMatrix[i][j]);
                        {
                            processNum = -1;
                            break;
                        }
                    }
                }
                if(processNum != -1)
                {
                    break;
                }
            }
            if(processNum != -1)
            {
                cout<<"P["<<getProcessNum() + 1<<"]";
                safeSequence[counter] = getProcessNum() + 1;
                counter++;
                for(j= 0; j<getResourceType(); j++)
                {
                    available[getResourceType()] += allocation[getProcessNum()][j];
                    allocation[getProcessNum()][j] = 0;
                    maxMatrix[getProcessNum()][j] = 0;
                    flag[processNum] = 1;
                }
            }
        }
    }while(counter != getResourceType() && processNum !=-1);
    if(counter == getProcessNum())
    {
        cout<<"The system is in the safe state"<<endl;
        cout<<"The safe sequence is: ";
        for( i = 0; i < getProcessNum(); i++)
        {
            cout<<safeSequence[i];
        }
    }
    else
    {
        cout<<"The system is not in the safe state"<<endl;
    }

}

int main(){

    return 0;
}