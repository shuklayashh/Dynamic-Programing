#include <bits/stdc++.h>
using namespace std;


// Recurssive code
int f(vector<int>& arr, int i,int j){

    if(i ==j) return 0; // base case

    int maxi = INT_MAX;

    for(int k = i; k<= j-1; k++){

        int ans = f(arr,i,k) + f(arr,k+1,j) + arr[i-1]* arr[k] * arr[j];

        maxi = max(maxi,ans);

    }

    return maxi;
}

int matrixMultiplication(vector<int>& arr, int n){

    int i = 0;
    int j = n -1;

    return f(arr,i,j);
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}


// memoization technique

// only insert the dp array into the code we can memorise the solution in the less time comlexcity.
int f(vector<int>& arr, int i,int j,vector<vector<int>>& dp){

    if(i ==j) return 0; // base case

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int maxi = INT_MAX;

    for(int k = i; k<= j-1; k++){

        int ans = f(arr,i,k,dp) + f(arr,k+1,j,dp) + arr[i-1]* arr[k] * arr[j];

        maxi = max(maxi,ans);

    }

    return maxi;
}
int matrixMultiplication(vector<int>& arr, int n){
vector<vector<int>> dp(n,vector<int>(n,-1));
    int i = 0;
    int j = n-1;

    return f(arr,i,j,dp);
}


//Time comlexcity : O(N*N*N);// Reason - there are N*N states in which we are explixitly run a loop inside the function N times  
//Space Complexity : O(N*N) // reason - we are using auxiliary recursive  stack space 