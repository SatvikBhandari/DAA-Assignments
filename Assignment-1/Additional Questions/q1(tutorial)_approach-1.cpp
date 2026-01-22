// Q1 (APPROACH-1)(Without Binary Search)

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

int returnRank(int query,int a[],int size){
    int rank=0;
    for(int i=0;i<size;i++){
        if(a[i]==query){
            rank=i+1;
        }
    }
    return rank;
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

    int r[q];

    for(int i=0;i<q;i++){
        r[i]=returnRank(queries[i],a,size);
    }

    cout<<endl<<"ranks of queries:"<<endl;
    for(int i=0;i<q;i++){
        cout<<r[i]<<endl;
    }
    
    return 0;
}