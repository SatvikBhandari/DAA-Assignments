// question 4

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void max_profit(int N,vector<int> deadline,vector<int> profit,vector<int> job){
    vector<pair<int,pair<int,int>>> data;
    
    for(int i=0;i<N;i++){
        data.push_back({profit[i],{deadline[i],job[i]}});
    }

    sort(data.begin(),data.end(),greater<>());

    int m=0;
    for(int i=0;i<N;i++){
        if(deadline[i]>m){
            m=deadline[i];
        }
    }

    vector<int> visited(m+1,0);
    vector<int> sequence;

    int p=0;

    for(int i=0;i<N;i++){
        for(int j=data[i].second.first;j>0;j--){
            if(visited[j]==0){
                visited[j]=1;
                sequence.push_back(data[i].second.second);
                p=p+data[i].first;
                break;
            }
        }
    }

    cout<<endl<<"Selected Jobs:";
    for(int i=0;i<m;i++){
        cout<<"J"<<sequence[i]<<" ";
    }
    cout<<endl<<"Maximum Profit="<<p<<endl;
}

int main(){

    int N=5;
    vector<int> jobs={1,2,3,4,5};
    vector<int> deadline={2,1,2,1,3};
    vector<int> profit={100,19,27,25,15};

    cout<<"N=5"<<endl;
    cout<<"Jobs:";
    for(int i=0;i<N;i++){
        cout<<"J"<<jobs[i]<<" ";
    }
    cout<<endl<<"Deadline:";
    for(int i=0;i<N;i++){
        cout<<deadline[i]<<" ";
    }
    cout<<endl<<"Profit:";
    for(int i=0;i<N;i++){
        cout<<profit[i]<<" ";
    }

    max_profit(N,deadline,profit,jobs);

    return 0;
}