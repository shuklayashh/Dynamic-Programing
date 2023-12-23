#include <bits/stdc++.h>
using namespace std;

int lengthlis(vector<int>& arr){

    int n = arr.size();

    vector<int>dp(n,1);
    vector<int>ct(n,1);
    int maxi = 1;


    for(int i = 0; i<n; i++){

        for(int prev = 0; prev <i; prev ++){

            if(arr[prev] <arr[i] && dp[prev]+1 >dp[i]){
                dp[i] = dp[prev]+1;
                ct[i] = ct[prev];
            }
            else if(arr[prev] <arr[i] && dp[prev]+1 == dp[i]){
                ct[i] = ct[i] + ct[prev];
            }
        }
       

       maxi = max(maxi,dp[i]);
    }

    int no =0;

    for(int i =0; i<n; i++){
        if(dp[i] == maxi){
            no += ct[i];
        }
    }

    return no;
}