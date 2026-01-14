// binary search

#include<iostream>

using namespace std;

bool binarySearch(int a[],int num,int size){
    int r=size-1;
    int l=0;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        
        if(a[mid]==num){
            return true;
        }
        else if(a[mid]>num){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return false;
}

int main(){
    
    int a[5]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]);
    int num=3;
    if(binarySearch(a,num,size)){
        cout<<num<<" found"<<endl;
    }
    else{
        cout<<num<<" not found"<<endl;
    }
    
    return 0;
}