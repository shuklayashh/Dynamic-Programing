#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

vector<int> eventualSafeNodes(vector<int> adj[], int V){
    vector<int> adjRev[V];

    int in_degree[V] = {0};

    for(int u =0; u<V; u++){

        for(auto it : adj[u]){
            adjRev[it].push_back(u);
            in_degree[u]++;
        }
    }

    queue<int>q;

    for(int i =0; i<V; i++){
        if(in_degree[i] == 0) q.push(i);
    }

    vector<int>safeNodes
       while (!q.empty()){
        int k= q.front();
        q.pop();
        safeNodes.push_back(u);

        for(auto it : adjRev[k]){
            in_degree[it]--;
            if(in_degree[it] == 0) q.push(it);

        }
       }
       sort(safeNodes.begin(),safeNodes.end());
       return safeNodes;

   }

};
int main() {

	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}