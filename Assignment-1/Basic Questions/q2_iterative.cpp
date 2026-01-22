// Merge Sort Recursive

#include<iostream>

using namespace std;

void merge(int a[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    int L[n1];
    int R[n2];

    for(int i=0;i<n1;i++){
        L[i]=a[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=a[mid+j+1];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int size){
    for(int curr_size=1;curr_size<size;curr_size=curr_size*2){
        for (int l=0;l<size-1;l=l+2*curr_size){

            int m=min(l+curr_size-1,size-1);
            int r = min(l+2*curr_size-1,size-1);

            if(m<r){
                merge(a,l,m,r);
            }
        }
    }
}

int main(){

    int a[7]={4,1,7,6,5,2,3};
    
    cout<<"original array:";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }

    mergeSort(a,7);

    cout<<endl<<"sorted array:";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}