#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
class Solution {

    public :

      int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

   priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;
                               vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        q.push({0,{0,0}});

        int delr[] = {-1,0,+1,0};
        int delc[] = {0,+1,0,-1};

        while(!q.empty()){
            auto it = q.top();
            q.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1) return d;

            for(int i = 0; i<4 ; i++){
                int nrow = r + delr[i];
                int ncol = c + delc[i];

                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol <m){
                    int newdiff = max(abs(heights[r][c] - heights[nrow][ncol]),d);

                    if(newdiff < dist[nrow][ncol]){
                        dist[nrow][ncol] = newdiff;
                        q.push({newdiff,{nrow,ncol}});
                    }
                }
        
            }
        }
            return 0;
        
      }
};

      int main()
{
    // Driver Code.

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    int ans = obj.minimumEffortPath(heights);

    cout << ans;
    cout << endl;

    return 0;

}