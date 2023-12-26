#include <bits/stdc++.h>
using namespace std;


int maxCoinsHelper(int i, int j, vector<int> &nums) {
    if (i > j) return 0;
    int maxCoins = INT_MIN;
    
    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++) {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums) + maxCoinsHelper(k + 1, j, nums);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    return maxCoins;
}
int maxCoin(vector<int>&nums){
	int n = nums.size();
	
	nums.insert(nums.begin(),1);
	nums.push_back(1);
	
	return maxCoinsHelper(1,n,nums);
}
// T.C = exponential

// MEMOIZATION APPROACH

int f(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
	
	if(i >j) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int maxCoins = INT_MIN;
	
	for(int k = i; k<= j; k++){
		
		int coins = nums[i-1]*nums[k]* nums[j+1];
		
		int remain = f(i,k-1,nums,dp)+ f(k+1,j,nums,dp);
		
		maxCoins = max(maxCoins, remain + coins);
	}
	
	return dp[i][j] = maxCoins;
}

int maxCoin(vector<int>&nums){
	int n = nums.size();
	
	nums.insert(nums.begin(),1);
	
	nums.push_back(1);
	
	vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
	
	return f(1,n,nums,dp);
}

//T.C = O(N*N*N - reason - beacause there are two variable i and j which takes the time of O(N*N) and we run N times inside the loops so Overall time would be - O(N*N*N)
//SPACE.C = O(N*N) + O(N)

// TABULATION APPROACH

int maxCoins(vector<int>&nums){
	int n = nums.size();
	
	nums.insert(nums.begin(),1);
	nums.push_back(1);
	
	vector<vector<int>>dp(n+2,vector<int>(n+2,0));
	
	for(int i = n; i<=1; i--){
		for(int j = 1; j<=n; j++){
			
			if(i >j) continue;
			
			int maxi = INT_MIN;
			
			for(int ind = i; ind <= j; ind++){
				
				int coins = nums[i-1]*nums[ind]*nums[j+1];
				
				int remain = dp[i][ind-1] + dp[ind+1][j];
				
				maxi = max(maxi, coins+remain);
			}
			dp[i][j] = maxi;
		}
	}
	
	return dp[1][n];
}

//SPACE - O(N*N)
int main(){
	int n;
	cin>>n;
	
	vector<int>nums(n);
	
	for(int i = 0; i<n; i++){
		cin>>nums[i];
	}
	
	cout<<maxCoin(nums);
	
	return 0;
}