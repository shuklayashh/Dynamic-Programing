#include <bits/stdc++.h>
using namespace std;



    vector<int>Dijkstra(int n, vector<vector<pair<int,int>>>& adj,int src){

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;

        vector<int>dis(n+1,INT_MAX);

        p.push(make_pair(0,src));

        dis[src] =0;

        while(!p.empty())
        {
            /* code */

            int curr = p.top().second;
            int l = p.top().first;

            p.pop();

            if(dis[curr] != l){
                continue;
            }
            for(auto x : adj[curr]){
                int d = x.first;

                int len = x.second;

                if(dis[d] > len + dis[curr]){
                    dis[d] = len + dis[curr];
                    p.push(make_pair(dis[d],d));
                }
            }

        }

        return dis;
        
    }

    int main()
{
    int n = 6; // Number of vertices
    // Adjacency list
    vector<vector<pair<int, int> > > adj(n + 1);
 
    // Example: adding edges to the adjacency list
    // Edge from vertex 1 to 2 with weight 3
    adj[1].push_back({ 2, 3 });
    // Edge from vertex 1 to 3 with weight 5
    adj[1].push_back({ 3, 5 });
    // Edge from vertex 2 to 3 with weight 1
    adj[2].push_back({ 3, 1 });
    // Edge from vertex 3 to 4 with weight 2
    adj[3].push_back({ 4, 2 });
    // Edge from vertex 2 to 4 with weight 7
    adj[2].push_back({ 4, 7 });
 
    int src = 1; // Source vertex
 
    vector<int> distances = Dijkstra(n, adj, src);
 
    // Print the minimum distances from the source to all
    // other vertices
    for (int i = 1; i <= n; i++) {
        cout << "Minimum distance from vertex " << src
            << " to " << i << " is " << distances[i]
            << "\n";
    }
 
    return 0;
}
