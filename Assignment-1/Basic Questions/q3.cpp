// quick sort

#include<iostream>

using namespace std;

int partition(int a[],int low,int high){

    int pivot=a[high];

    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(a[j]<=pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
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

int main(){

    int a[7]={6,9,3,4,2,1,8};
    int size=7;

    cout<<"original array:"<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    quickSort(a,0,size-1);

    cout<<"sorted array:"<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}