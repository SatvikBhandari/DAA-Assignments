// Quick Sort Recursive

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

int main(){

    int a[7]={4,1,7,6,5,2,3};
    
    cout<<"original array:";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }

    quickSort(a,0,6);

    cout<<endl<<"sorted array:";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}