#include <bits/stdc++.h>
using name space std;
//Reacurssive Approach

int getAns(int ind, int prev, int arr[], int n){

    if(ind == n) return 0;

    int len = 0+ getAns(ind+1, prev, arr,n);

    if(prev == -1 || arr[ind] >arr[prev]){

        len = max(len , 1+ getAns(ind+1,ind,arr,n));
    }

    return len;
}

int lis(int arr[], int n){
    return getAns(0,-1,arr,n);
}

//memoisation approach
int getAns(int arr[], int n, int ind, int prev, ,vector<vector<int>>&dp){

    if(ind == n)
    return 0;

    if(dp[ind][prev+1] != -1)
    return dp[ind][prev+1];


    int not_take = 0+getAns(arr,n,ind+1,prev,dp);

    int take = 0;

    if(prev == -1 || arr[ind] >arr[prev]){
        take = 1+ getAns(arr,n,ind+1,ind,dp);

    }

    return dp[ind][prev+1] = max(not_take,take);
}

int lis(int arr[], int n){

    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    return getAns(arr,n,0,-1,dp);
}

//Tabulation Approach

int lic(int arr[], int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int ind = n-1; ind>= 0; ind++){
        for(int prev = ind-1; prev >= -1; prev--){

            int notTake = 0 +dp[ind+1][prev+1];

            int take = 0;

            if(prev === -1 || arr[ind] > arr[prev]){
                take = 1+ dp[ind+1][ind+1];
            }

            dp[ind][prev+1] = max(notTake, take);

        }
    }

    return dp[0][0];
}


// spaceoptimisation

int lis(int arr[], int n){

    vector<int>next(n+1,0);
    vector<int>cur(n+1,0);

    for(int ind = n-1; ind>= 0; ind--){

        for(int prev = ind-1; prev >= -1; prev--){

            int notTake = 0 + next[prev+1];


            int take =0;

            if(prev == -1 ||arr[ind] >arr[prev]){
                take = 1 + next[ind+1];
            }

            cur[prev+1] = max(notTake,take);
        }
        next = cur;
    }
    return cur[0];
}

int main(){

    int arr[] ={10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The length of the longest increasing subsequence is " << lis(arr, n);
    
    return 0;
}

