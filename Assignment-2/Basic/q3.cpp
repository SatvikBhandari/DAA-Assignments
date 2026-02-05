// question 3

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int Max_Value(int N,vector<int> value,vector<int> weight,int W){

    vector<double> ratio(N);

    for(int i=0;i<N;i++){
        ratio[i]=(double) value[i]/(double) weight[i];
    }

    vector <pair<double,pair<int,int>>> data;

    for(int i=0;i<N;i++){
        data.push_back({ratio[i],{value[i],weight[i]}});
    }

    sort(data.begin(),data.end(),greater<>());

    int sum=0;
    double profit=0;

    for(int i=0;i<N;i++){
        if(sum<W){
            if((W-sum)>=data[i].second.second){
                sum=sum+data[i].second.second;
                profit=profit+data[i].second.first;
            }
            else{
                profit=profit+data[i].second.first*(W-sum)/data[i].second.second;
                sum=W;
            }
        }
    }

    return profit;
}

int main(){

    int N=3;
    vector<int> value={100,60,120};
    vector<int> weight={20,10,40};
    int W=50;

    cout<<"N="<<N<<endl;
    cout<<"value=";
    for(int i=0;i<N;i++){
        cout<<value[i]<<"  ";
    }
    cout<<endl<<"weight:";
    for(int i=0;i<N;i++){
        cout<<weight[i]<<"  ";
    }

    int max=Max_Value(N,value,weight,W);
    cout<<endl<<"Maximum Value="<<max<<endl;

    return 0;
}