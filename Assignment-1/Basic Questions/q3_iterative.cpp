// Quick Sort 

#include<iostream>
#include<stack>

using namespace std;

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;

    for(int j=low;j<high;j++){
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

void quickSort(int a[],int n){
    stack<int> st;

    st.push(0);
    st.push(n-1);

    while(!st.empty()){
        int high=st.top();
        st.pop();
        int low=st.top();
        st.pop();

        int p=partition(a,low,high);

        if(low<p-1){
            st.push(low);
            st.push(p-1);
        }
        if(high>p+1){
            st.push(p+1);
            st.push(high);
        }
    }
}

int main(){

    int a[7]={4,1,7,6,5,2,3};
    
    cout<<"original array:";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }

    quickSort(a,7);

    cout<<endl<<"sorted array:";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}   