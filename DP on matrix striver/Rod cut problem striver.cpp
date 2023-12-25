#include <bits/stdc++.h>
using namespace std;

// Recursive approach
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

// TIME _COMPLEXITY = exponential 

// MEMOIZATION APPROACH - It's not so typical to initiliaze the dp into the memoozation approach - 1) Look the  recursive code the only change which is must is that we initiliaze the dp array inside the function nothing else all code will same 

// There are some rule fir the memoization of dp
//1) - create a dp array of size[c+1][c+1], i and j can we range from the 0 to c, we take the size CXC
//2) we initialize the dp array by -1

//3) whenever we want to find the answer to particular parameter (say f(i,j)), we first cheack the weather the answer are already calculated using the dp array , if yes simply return the value of the dp array

//4) if not taken then we are finding the answer for the given value for the first time, we will use the recursive relation as ususal but  before returning from the function 


int  f(int i, int j, vector<int>& cuts, vector<vector<int>>&dp){

    if(i>j) {
        return 0;
    }

    if(dp[i][j] != -1){

        return dp[i][j];
    }

    int mini = INT_MAX;


    for(int ind = i; ind <= j; ind++){

        int ans = cuts[j+1] - cuts[i -1] + f(i,ind-1,cuts) + f(ind+1, j,cuts);

        mini = min( mini , ans);
    }

    return mini;
}

int findMinimumcuts(int n , vector<int>& cuts){
    int c = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);

      vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

      return f(1,c,cuts);
}

// TIME _COMPLEXITY - O(N*N*N) reason - because we are using a two vatiable i and j which will take  N*N time  and inside this loop we run the loop over N times so that the compexity is this 
// SPACE COMPLEXITY - O(N*N + O(N  rerason - we are using  auxiliary recursive extra space O(N and a 2D array (O(N*N))
int main(){

     vector<int> cuts = {3, 5, 1, 4};
    
    int n = 7;

    cout << "The minimum cost incurred is: " << findMinimumcuts(n, c, cuts) << endl;

    return 0;
}