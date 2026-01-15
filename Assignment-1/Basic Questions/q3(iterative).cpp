// quick sort (iterative approach)

#include<iostream>
#include<stack>

using namespace std;

int partition(int a[],int low,int high){
	int pivot=a[high];
	int i=low-1;
	
	 for (int j=low;j<high;j++) {
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSortIterative(int arr[], int n) {
    stack<int> st;
    
    st.push(0);
    st.push(n - 1);

    while(!st.empty()){
        int high=st.top(); 
		st.pop();
        int low=st.top();
		st.pop();

        int p=partition(arr,low,high);
        
        if(low<p-1) {
            st.push(low);
            st.push(p-1);
        }

        if(p+1<high) {
            st.push(p+1);
            st.push(high);
        }
    }
}

int main() {
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array:";
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" "<<endl;

    quickSortIterative(arr,n);

    cout<"Sorted array: ";
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" "<<endl;

    return 0;
}