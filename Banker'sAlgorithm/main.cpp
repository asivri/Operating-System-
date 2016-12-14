#include <iostream>

using namespace std;


//Set the global variables
int process[100];
int allocation[100], max[100], available[100];

/*
  def banker(N: int, cash: int, loan: list, claim: list) -> bool:
    """
    Banker's algorithm, return True if in safe state,
    False if in unsafe state
    """
    p = [i for i in range(N)]
    for k in range(N):
        sum = 0
        for j in range(k):
            sum += loan[p[j]]
        found = False
        for h in range(k, N):
            if claim[p[h]] <= cash + sum:
                p[h],p[k] = p[k],p[h]
                found = True
        if not found:
            return False
    return True

 */

void bankersFun(int processNum, int available[],
                int alloc[], int need[])
{

}

void getVariables(){
    int n, m;
    cout<<"Please enter the number of process:";
    cin>>n;
    cout<<endl;
    cout<<"Please enter the number of resources types:";
    cin>>m;
    cout<<endl;
}



int main(){

    getVariables();
    return 0;
}