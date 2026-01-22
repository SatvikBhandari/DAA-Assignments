// Binary Search Iterative

#include<iostream>

using namespace std;

bool BinarySearch(int a[],int size,int num){
    int l=0;
    int r=size-1;
    int mid;

    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==num){
            return true;
        }
        else if(a[mid]>num){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return false;
}

int main(){

    int a[7]={1,2,3,4,5,6,7};
    int num=3;
    int size=sizeof(a)/sizeof(a[0]);

    if(BinarySearch(a,size,num)){
        cout<<num<<" found"<<endl;
    }
    else{
        cout<<num<<" not found"<<endl;
    }

    return 0;
}