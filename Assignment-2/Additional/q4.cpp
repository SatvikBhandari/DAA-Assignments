// question 4

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas,vector<int>& cost){

    int total=0;
    int tank=0;
    int start=0;

    for (int i=0;i<gas.size();i++){

        int diff=gas[i]-cost[i];
        total=total+diff;
        tank=tank+diff;

        if(tank<0){
            start=i+1;
            tank=0;
        }
    }

    return(total<0)?-1:start;
}

int main() {

    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};

    cout<<"Gas stations:";
    for(int i=0;i<gas.size();i++){
        cout<<gas[i]<<" ";
    }
    cout<<endl<<"Cost:";
    for(int i=0;i<cost.size();i++){
        cout<<cost[i]<<" ";
    }

    cout<<endl<<"Starting index="<<canCompleteCircuit(gas,cost);

    return 0;
}