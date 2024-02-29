#include <bits/stdc++.h>
using namespace std;

vector<int> Belmen(int V, vector<vector<int>> & edges, int S){

    vector<int>dist(V,1e9);

    dist[S] = 0;

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int m = it[2];

        if(dist[u] != 1e9 && dist[u] + m < dist[v]){
            dist[v] = dist[u] +m;

        }
    }

       for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int m = it[2];

        if(dist[u] != 1e9 && dist[u] + m < dist[v]){
 return {-1};            
        }
    }
}
   int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	
	vector<int> dist = Belmen(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}