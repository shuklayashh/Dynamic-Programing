#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
    public :
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){

        int n = grid.size();
        if(grid[0][0] != 0) return -1;

        if(n == 1) return 1;

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        dist[0][0] =1;
        q.push({1,{0,0}});

        int delr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delc[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){

            int d = q.front().first;
            int r = q.front().second.first;
            int l = q.front().second.second;
            q.pop();

            for(int i = 0; i< 8; i++){

                int nrow = r + delr[i];
                int ncol = l + delc[i];

                if(nrow < n && nrow >= 0 && ncol >= 0 && ncol <n && d +1 < dist[nrow][ncol] && grid[r][l] == 0){
                     dist[nrow][ncol] = d + 1;
                    if (nrow == n - 1 && ncol == n - 1)
                        return dist[nrow][ncol];
                    q.push({d + 1, {nrow, ncol}});
                }
            }

        }

        return -1;

    }

    
}