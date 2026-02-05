// question 5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoursesInPlan(int N,vector<int>& st,vector<int>& en,int L,int R){

    vector<pair<int,int>> valid;

    for (int i=0;i<N;i++){
        if(st[i]>=L && en[i]<=R){
            valid.push_back({st[i], en[i]});
        }
    }

    sort(valid.begin(),valid.end(),[](pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    });

    int count=0;
    int last_end=-1;

    for(int i=0;i<N;i++){
        if(valid[i].first>last_end){
            count++;
            last_end = valid[i].second;
        }
    }

    return count;
}

int main(){

    int N = 6;
    vector<int> st={1, 2, 4, 6, 5, 8};
    vector<int> en={3, 5, 6, 7, 9, 10};

    int Q = 3;
    vector<int> L={1, 2, 4};
    vector<int> R={6, 7, 10};

    cout<<"N="<<N<<endl;
    cout<<"St_i=";
    for(int i=0;i<N;i++){
        cout<<st[i]<<" ";
    }
    cout<<endl<<"End_i=";
    for(int i=0;i<N;i++){
        cout<<en[i]<<" ";
    }
    cout<<endl<<"Q="<<Q<<endl;
    cout<<"Plan_st_j=";
    for(int i=0;i<Q;i++){
        cout<<st[i]<<" ";
    }
    cout<<endl<<"Plan_end_j=";
    for(int i=0;i<Q;i++){
        cout<<en[i]<<" ";
    }


    cout<<endl<<"Maximum courses for each plan:"<<endl;

    for(int i = 0; i < Q; i++){
        cout<<"Plan"<<i+1<<":"<<maxCoursesInPlan(N,st, en, L[i], R[i]) << endl;
    }

    return 0;
}
