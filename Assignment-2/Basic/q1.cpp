// question 1

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void max_activities(int N,vector<int> start,vector<int> finish){
    vector<pair<int,int>> time;
    for(int i=0;i<N;i++){
        time.push_back({finish[i],start[i]});
    }

    sort(time.begin(),time.end());

    vector<pair<int,int>> selected_activities;
    selected_activities.push_back({time[0].second,time[0].first});

    int count=1;
    int l=time[0].first;
    
    for(int i=1;i<N;i++){
        if(time[i].second>=l){
            selected_activities.push_back({time[i].second,time[i].first});
            count++;
            l=time[i].first;
        }
    }

    cout<<endl<<"Maximum Number of Activities="<<count<<endl;
    cout<<"Selected Activities:";
    for(int i=0;i<count;i++){
        cout<<"("<<selected_activities[i].first<<","<<selected_activities[i].second<<") ";
    }
    cout<<endl;
}

int main(){

    int N=6;
    vector<int> start={1,3,0,5,8,5};
    vector<int> finish={2,4,6,7,9,9};

    cout<<"N="<<N<<endl;
    cout<<"Start=";
    for(int i=0;i<N;i++){
        cout<<start[i]<<" ";
    }
    cout<<endl<<"Finish=";
    for(int i=0;i<N;i++){
        cout<<finish[i]<<" ";
    }

    max_activities(N,start,finish);

    return 0;
}