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



int getMaxMatrix(int processNum, int resourceType)
{
    int j, k;
    //Getting input for Max Matrix
    //TODO: Implement a string array for title :)
    cout << "Input for Max" << endl;
    for ( j = 0; j <processNum; j++) //Getting input across process number
    {
        cout << "P[" << j << "]:  ";
        for ( k = 0; k < resourceType; k++) //Getting input across resource types;
        {
            cin >> maxMatrix[j][k];
        }
    }
    return maxMatrix[j][k];
}

int getAllocationMatrix(int processNum, int resourceType)
{
    int k, j;
    //Getting input for Allocation Matrix
    //TODO: Implement a string array for title :)
    cout << "Input for Allocation" << endl;
    for (j = 0; j < processNum; j++) //Getting input across process number
    {
        cout << "P[" << j << "]:  ";
        for (k = 0; k < resourceType; k++) //Getting input across resource types;
        {
            cin >> allocation[j][k];
        }
    }
    return allocation[j][k];
}

//int getAvailableResource(int resourceType)
//{
//    int k;
//    cout << "Input for Available Resources" << endl;
//    for (k = 0; k < resourceType; k++) //Getting input across process number
//    {
//        cin >> available[k];
//    }
//    return available[k];
//}

int controlFlag(int processNum)
{
    int i;
    //Looping the control f lag.
    for (i = 0; i <processNum; i++) {
        flag[i] = 0;
    }
    return flag[i];
}

int calculateNeed(int processNum, int resourceType)
{
    //declaration of loop variables;
    int i, j;
    for(i = 0; i<processNum; i++)
    {
        for(j = 0; j<resourceType; j++)
        {
            needMatrix[i][j] = maxMatrix[i][j] - allocation[i][j];
        }
    }
    cout<<needMatrix[i][j];
}

void bankersFun(int processNumber, int resourceType)
{
    int processNum = processNumber;
    int i, j;
    int counter = 0;
    do{
        cout<<endl;
        cout<<"Max matrix:           Allocation Matrix: "<<endl;
        for( i = 0; i<processNum; i++)
        {
            for( j=0 ; j<resourceType; j++)
            {
                cout<<maxMatrix[i][j]<<"     ";
                cout<<allocation[i][j]<<"     ";
                cout<<endl;
            }
            processNum = -1;
            for(i = 0; i<resourceType; i++)
            {
                if(controlFlag(processNumber) == 0)
                {
                    processNum = i;
                    for (j=0 ; j<resourceType; j++)
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
                cout<<"P["<<processNumber+ 1<<"]";
                safeSequence[counter] = processNumber + 1;
                counter++;
                for(j= 0; j<resourceType; j++)
                {
                    available[resourceType] += allocation[processNumber][j];
                    allocation[processNumber][j] = 0;
                    maxMatrix[processNumber][j] = 0;
                    flag[processNum] = 1;
                }
            }
        }
    }while(counter != resourceType && processNum !=-1);
    if(counter == processNumber)
    {
        cout<<"The system is in the safe state"<<endl;
        cout<<"The safe sequence is: ";
        for( i = 0; i < processNumber; i++)
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
    int n;
    cout << "Please enter the number of process:";
    cin >> n;
    cout << endl;
    int m;
    cout << "Please enter the number of resources types:";
    cin >> m;
    getMaxMatrix(n, m);
    cout<<endl;
    getAllocationMatrix(n, m);
    cout<<endl;
    //getAvailableResource(n);
    cout<<endl;
    cout<<"---------"<<endl;
    calculateNeed(n, m);
    controlFlag(n);
    calculateNeed(n, m);
    bankersFun(n, m);
    return 0;
}