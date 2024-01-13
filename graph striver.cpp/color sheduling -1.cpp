#include <bits/stdc++.h>
using namespace std;

class Solution 
{

    public:

    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites){

        vector<int> adj[V];

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }


        int indegree[V] = {0};

        for(int i = 0; i<V: i++){

            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;

        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;

        while(!q.empty()){
            int node = q.front();

            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == V) return topo;

        return {};
    }
};

// COurce Seduling -1  Leetcode


#include <bits/stdc++.h>
using namespace std;

class Solution 
{

    public:

bool canFinish(int m, vector<vector<int>> prerequisites){
     int V = prerequisites.size();
        vector<int> adj[m];
     vector<int>indegree(m);


        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
             indegree[it[0]]++;
        }



      
        queue<int>q;

        for(int i = 0; i<m; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;

        while(!q.empty()){
            int node = q.front();

            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]){

                if(--indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == m) return true;

        return false;
    }
};

//Cource Seduling -2  - Leetcode 

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& P) {
        vector<vector<int>> G(N);          
        vector<int> ans, indegree(N);         
        for(auto& pre : P) 
            G[pre[1]].push_back(pre[0]),        
            indegree[pre[0]]++;                     
        
        queue<int> q;
        for(int i = 0; i < N; i++)
            if(indegree[i] == 0) q.push(i);     
        
        while(size(q)) {
            auto cur = q.front(); q.pop();
            ans.push_back(cur);                    
            for(auto nextCourse : G[cur]) 
                if(--indegree[nextCourse] == 0)    
                    q.push(nextCourse);             
        }
        if(size(ans) == N) return ans;            
        return {};                                      
    }
};
   
   // TIMER COMPLEXCITY - O(M + E) E= NUMBER OF EDGES