// question 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(int m,int n,vector<int> x,vector<int> y){

    sort(x.begin(),x.end(),greater<int>());
    sort(y.begin(),y.end(),greater<int>());

    int i=0,j=0;
    int horizontal=1,vertical=1;
    int sum=0;

    while (i<m-1 && j<n-1){
        if (x[i]>y[j]){
            sum=sum+x[i]*vertical;
            horizontal++;
            i++;
        } 
        else {
            sum=sum+y[j]*horizontal;
            vertical++;
            j++;
        }
    }
    
    while (i<m-1) {
        sum=sum+x[i]*vertical;
        i++;
    }

    while (j<n-1) {
        sum=sum+y[j]*horizontal;
        j++;
    }

    return sum;
}

int main() {

    int m=3;
    int n=3;
    vector<int> x={2, 1};   
    vector<int> y={3, 1};   

    cout<<"m="<<m<<endl;
    cout<<"n="<<n<<endl;

    cout<<"Horizontal cut costs(x):";
    for(int i=0;i<2;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl<<"Horizontal cut costs(x):";
    for(int i=0;i<2;i++){
        cout<<y[i]<<" ";
    }

    cout<<endl<<"Minimum total cutting cost="<<minCost(m, n, x, y);

    return 0;
}