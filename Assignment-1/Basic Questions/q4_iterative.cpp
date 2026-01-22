// Maximum Sub Array Iterative (Kadane)

#include<iostream>

using namespace std;

int Kadane(int a[],int size){
    int max_sum=a[0];
    int curr_sum=0;

    for(int i=0;i<size;i++){
        curr_sum=curr_sum+a[i];
        if(curr_sum>max_sum){
            max_sum=curr_sum;
        }

        if(curr_sum<0){
            curr_sum=0;
        }
    }

    return max_sum;
}

int main(){

    int a[7]={1,2,3,4,-5,6,7};
    int maxSum=Kadane(a,7);
    cout<<"maximum sum of subarray:"<<maxSum<<endl;


    return 0;
}