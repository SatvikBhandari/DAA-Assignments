// Binary Search Recursive

#include<iostream>

using namespace std;

bool BinarySearch(int a[],int l,int r,int num){
    if(l>r){
        return false;
    }

    int mid=(l+r)/2;

    if(a[mid]==num){
        return true;
    }
    else if(a[mid]>num){
        BinarySearch(a,l,mid-1,num);
    }
    else{
        BinarySearch(a,mid+1,r,num);
    }
}

int main(){

    int a[7]={1,2,3,4,5,6,7};
    int num=3;
    int size=sizeof(a)/sizeof(a[0]);

    if(BinarySearch(a,0,size-1,num)){
        cout<<num<<" found"<<endl;
    }
    else{
        cout<<num<<" not found"<<endl;
    }

    return 0;
}