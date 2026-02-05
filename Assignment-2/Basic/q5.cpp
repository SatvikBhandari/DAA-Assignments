// question 5

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class node{

    public:

    char ch;
    int f;
    node *left;
    node *right;

    node(char ch,int f){
        this->ch=ch;
        this->f=f;
        left=NULL;
        right=NULL;
    }

};

class comparison{

    public:

    bool operator()(node* l1,node* r1){
        return l1->f >r1->f;
    }

};

class Huffman_Codes{

    public:

    void createTree(vector<char> ch,vector<int> f){

        priority_queue<node*,vector<node*>,comparison> st;

        for(int i=0;i<ch.size();i++){
            st.push(new node(ch[i],f[i]));
        }

        while(st.size()>1){
            node *left=st.top();
            st.pop();
            node *right=st.top();
            st.pop();

            node* newNode=new node('\0',left->f+right->f);
            newNode->left=left;
            newNode->right=right;

            st.push(newNode);
        }

        node* root=st.top();
        cout<<"Character:Huffmann Code"<<endl;
        displayCodes(root,"");
    }

    void displayCodes(node *root,string code){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            cout<<root->ch<<":"<<code<<endl;
        }

        displayCodes(root->left,code+"0");
        displayCodes(root->right,code+"1");
    }

};

int main(){

    int N=6;
    vector<char> ch={'a','b','c','d','e','f'};
    vector<int> f={5,9,12,13,16,45};

    cout<<"Characters:";
    for(int i=0;i<N;i++){
        cout<<ch[i]<<" ";
    }
    cout<<endl<<"Frequencies:";
    for(int i=0;i<N;i++){
        cout<<f[i]<<" ";
    }
    cout<<endl;

    Huffman_Codes Hc;
    Hc.createTree(ch,f);

    return 0;
}