#include <bits/stdc++.h>
using namespace std;
class solution
{
private:

void dfs(int node , vector<int>&adji[], int vis[])
{
    vis[node] = 1;

    for(auto it : adji[node]){
        if(!vis[it]){
            dfs(it,adji,vis);
        }
    }
}

public:
  int numProvinces(vector<vector<int>> adj, int V){
    vector<int>adji[V];

    for(int i =0; i<n; i++){

        for(int j =0; j<n; j++){

            if(adj[i][j] == 1 && i != j){
                adji[i].push_back(j);
                adji[j].push_back(i);
            }
        }
    }
 vector<int>vis;
    int count = 0;

    for(int i =0; i<n; i++){
        if(!vis[i]){
            count++;
            dfs(i,vis,adji);
        }
    }
    return count;
  }
};

int main(){
      vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
        
    return 0;
}