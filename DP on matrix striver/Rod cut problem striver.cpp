#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, vector<int>&cuts){

    if(i >j){

        return 0;
    }

    int mini = INT_MAX;

    for(int ind = i; ind <= j; ind++){

        int ans = cuts[j+1] - cuts[i-1] + f(i,ind-1, cuts) + f(ind+1, j, cuts);// taken and not taken concept

        mini = min(mini,ans);
    }

    return ans;
}

int findMinimumcuts(int n, vector<int>&cuts){
    // initiliaze the size of the cuts
    int c = cuts.size();
   // push the value of n into cuts
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);

    sort(cuts.begin(),cuts.end());

    return f(1,c,cuts);
}