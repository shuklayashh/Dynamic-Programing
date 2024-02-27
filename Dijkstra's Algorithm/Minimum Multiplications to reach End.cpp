#include <bits/stdc++.h>
using namespace std;
class Solution {

    public:

int minimum(vector<int> & arr, int start, int end){

    if(start == end) return 0;

    queue<pair<int,int>>q;
    q.push({start,0});
    vector<int> dist(100000,1e5);
    dist[start] =0;
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(auto it :arr){
            int num = (it * node) %mod;

            if(steps +1 < dist[num]){

                dist[num] = steps +1;

                if(num == end) return steps +1;

                q.push({num,steps+1});
            }
        }
    }
    return -1;
}

int main(){
      int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    Solution obj;

    int ans = obj.minimumM(arr, start, end);

    cout << ans;
    cout << endl;

    return 0;
}
}