// question 2

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int min_platforms(int N,vector<double> AT,vector<double> DT){
    sort(AT.begin(),AT.end());
    sort(DT.begin(),DT.end());

    int i=0,j=0;
    int platforms=0;
    int max_platforms=0;
    
    while(i<N && j<N){
        if(AT[i]<=DT[j]){
            platforms++;
            max_platforms=max(platforms,max_platforms);
            i++;
        }
        else{
            platforms--;
            j++;
        }
    }

    return max_platforms;
}

int main(){

    int N=5;
    vector<double> AT={09.00,09.10,09.20,11.00,11.20};
    vector<double> DT={09.40,12.00,09.50,11.30,11.40};

    cout<<"Train=";
    for(int i=1;i<=5;i++){
        cout<<"T"<<i<<"  ";
    }
    cout<<endl<<"AT=";
    for(int i=0;i<N;i++){
        cout<<AT[i]<<"  ";
    }
    cout<<endl<<"DT=";
    for(int i=0;i<N;i++){
        cout<<DT[i]<<"  ";
    }

    int n=min_platforms(N,AT,DT);
    cout<<endl<<"Minimum Number of Platforms Required="<<n<<endl;

    return 0;
}