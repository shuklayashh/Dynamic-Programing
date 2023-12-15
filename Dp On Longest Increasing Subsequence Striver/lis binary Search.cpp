#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n){
    vector<int>temp;

    temp.push_back(arr[0]);

    int len = 1;

    for(int i = 0; i<n; i++){

        if(arr[i] > temp.back()){
            len++;
            temp.push_back(arr[i]);
        } else {
            int ind = (temp.begin(), temp.end(),arr[i])- temp.begin();

            temp[ind] = arr[i];
        }
    }

    return len;
}

int main(){

    int arr[] = {1,7,8,4,5,6,-1,9};
 int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The length of the longest increasing subsequence is " << lis(arr, n);

    return 0;

    }

    T.C = O(N*LOG(N))
    S.C = O(N);