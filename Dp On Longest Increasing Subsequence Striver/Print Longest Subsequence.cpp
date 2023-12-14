#include <bits/stdc++.h>
using namespace std;

vector<int>lis(vector<int>arr[], int n){

    vector<int>dp(n,1);
    vector<int>hash(n,1);

    for(int i =0; i<= n-1; i++){
        hash[i] = i;

        for(int prev = 0; prev <= i-1; prev++){

            if(arr[prev] <arr[i] && 1+dp[prev] >dp[i]){
                dp[i] = 1+ dp[prev];
                hash[i] = prev;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for(int i = 0; i<= n-1; i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    vector<int>temp;

    temp.push_back(lastIndex);

    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(),temp.end());

    return temp;
}

int main(){
    int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	lis(arr,n);
	return 0;
}

T.C = O(N*N);
S.C = O(N);