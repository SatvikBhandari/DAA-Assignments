// Q1 (APPROACH-2)(With Binary Search)

#include<iostream>

using namespace std;

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<=pivot){
            i++;
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }

    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;

    return i+1;
}

void quickSort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);

        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int RANK(int a[],int size,int num){
    int l=0;
    int r=size-1;
    int mid;

    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==num){
            return mid+1;
        }
        else if(a[mid]>num){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int main(){

    int size;
    cout<<"enter size:";
    cin>>size;

    int a[size];
    cout<<"enter elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }

    quickSort(a,0,size-1);

    int q;
    cout<<endl<<"enter number of queries:";
    cin>>q;

    int queries[q];
    cout<<endl<<"enter queries:"<<endl;
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }

    int rank[q];

    for(int i=0;i<q;i++){
        rank[i]=RANK(a,size,queries[i]);
    }

    cout<<endl<<"ranks of queries:"<<endl;
    for(int i=0;i<q;i++){
        cout<<rank[i]<<endl;
    }

    return 0;
}