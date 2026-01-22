// Maximum Sub Array Recursive (Divide and Conquer)

#include<iostream>

using namespace std;

int maximum_Mid(int a[],int l,int m,int r){

    int sum=0;
    int maximum_Mid_L=-100;
    for(int i=m;i>=l;i--){
        sum=sum+a[i];
        maximum_Mid_L=max(maximum_Mid_L,sum);
    }

    sum=0;
    int maximum_Mid_R=-100;
    for(int i=m+1;i<=r;i++){
        sum=sum+a[i];
        maximum_Mid_R=max(maximum_Mid_R,sum);
    }

    return (maximum_Mid_L+maximum_Mid_R);
}

int maximum_Sum(int a[],int l,int r){
    if(l==r){
        return a[l];    
    }

    int m=(l+r)/2;
    int maxL=maximum_Sum(a,l,m);
    int maxR=maximum_Sum(a,m+1,r);
    int maxM=maximum_Mid(a,l,m,r);

    int max_LR=max(maxL,maxR);
    
    return max(max_LR,maxM);
}

int main(){

    int a[7]={1,2,3,4,-5,6,7};
    cout<<"maximum sum of subarray:"<<maximum_Sum(a,0,6)<<endl;

    return 0;
}