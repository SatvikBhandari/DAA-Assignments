// question 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int,int> c1, pair<int,int> c2) {
    return c1.second < c2.second;
}

int Customers_Max(int N,int K,vector<int> arrival,vector<int> departure,vector<int> preferred){

    vector<vector<pair<int,int>>> comp(K+1);

    for(int i=0;i<N;i++){
        comp[preferred[i]].push_back({arrival[i], departure[i]});
    }

    int sum=0;

    for(int i=1;i<=K;i++){
        
        sort(comp[i].begin(), comp[i].end(), Compare);
        int ld = -1;

        for(int j=0;j<comp[i].size();j++){
            if(comp[i][j].first>=ld){
                sum++;
                ld=comp[i][j].second;
            }
        }
    }

    return sum;
}

int main() {

    int N=6;
    int K=3;

    vector<int> arrival={1,2,3,5,4,6};
    vector<int> departure={4,5,6,7,8,9};
    vector<int> preferred={1,1,2,1,2,3};

    cout<<"N="<<N<<endl;
    cout<<"K="<<K<<endl;
    cout<<"Arival:";
    for(int i=0;i<N;i++){
        cout<<arrival[i]<<" ";
    }
    cout<<endl<<"Departure:";
    for(int i=0;i<N;i++){
        cout<<departure[i]<<" ";
    }
    cout<<endl<<"Preffered:";
    for(int i=0;i<N;i++){
        cout<<preferred[i]<<" ";
    }

    cout<<endl<<"Maximum number of customers that can dine="<<Customers_Max(N,K,arrival,departure,preferred);

    return 0;
}