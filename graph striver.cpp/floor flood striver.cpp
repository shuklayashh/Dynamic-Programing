#include <bits/stdc++.h>
using namespace std;

class solution{

    private:

    void dfs(int row, int col , vector<vector<int>>&ans, vector<vector<int>>&image,int newcolor, int delCol[], int delRow[],int inicolor){

        ans[row][col] = newcolor;

        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i<4; i++){

            int nrow = row + delRow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && ncol <n && ncol >= 0 && ncol <m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor){
                dfs(nrow,ncol,ans,image,newcolor,delRow,delcol,inicolor);
            }
        }
    }


    vector<vector<int>> fllorFlood(vector<vector<int>>&image, int sr, int sc, int color){

        vector<vector<int>>ans = image;
        int inicolor = image[sr][sc];

        int delRow = {-1,0,+1,0};
        int delcol = {0,-1,0,+1};
        dfs(sr,sc,color,image,ans,inicolor, delRow,delcol)
    }
};