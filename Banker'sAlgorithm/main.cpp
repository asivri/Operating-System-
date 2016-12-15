#include <iostream>

using namespace std;


//Set the global variables
int n; //Number of processes
int m; //number of resources types
int allocation[100][100];
int maxMatrix[100][100]; //Don't ever use max as name because it's declared as sth else and can't implemented as arrays.
int available[100];
int needMatrix[100][100];

int flag[100]; //A flag which checks completed processes



void getVariables() {
    //declaration of loop variables;
    int i, j, k;

    cout << "Please enter the number of process:";
    cin >> n;
    //Looping the control flag.
    for (i = 0; i < n; i++) {
        flag[i] = 0;
    }
    cout << endl;
    cout << "Please enter the number of resources types:";
    cin >> m;
    cout << endl;
    //----------------------
    //Getting input for Max Matrix
    //TODO: Implement a string array for title :)
    cout << "Input for Max" << endl;
    for (j = 0; j < n; j++) //Getting input across process number
    {
        cout << "P[" << j << "]:  ";
        for (k = 0; k < m; k++) //Getting input across resource types;
        {
            cin >> maxMatrix[j][k];
        }
    }

    //----------------------
    //Getting input for Allocation Matrix
    //TODO: Implement a string array for title :)
    cout << "Input for Allocation" << endl;
    for (j = 0; j < n; j++) //Getting input across process number
    {
        cout << "P[" << j << "]:  ";
        for (k = 0; k < m; k++) //Getting input across resource types;
        {
            cin >> allocation[j][k];
        }
    }
    //----------------------
    //Getting input for Allocation Matrix
    cout << "Input for Available Resources" << endl;
    for (k = 0; k < m; k++) //Getting input across process number
    {
        cin >> available[k];
    }
}

void calculateNeed()
{
    //declaration of loop variables;
    int i, j;
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<m; j++)
        {
            needMatrix[i][j] = maxMatrix[i][j] - allocation[i][j];
        }
    }
}

void bankersFun(int processNum, int available[],
                int alloc[], int need[])
{

}





int main(){

    getVariables();
    return 0;
}