#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u, int v){
    adj[v].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int v = u;

    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
        addEdge(adj,1,2);
            addEdge(adj,1,2);
               printGraph(adj,v);

               return 0;



}

void printGraph(vector<int>adj[], int v){
    for(int i =0; i<v; i++){
        for(int x: adj[i])
        cout<<x<<" ";

        cout<<"\n";
    }
}