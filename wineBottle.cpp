/*!
* Copyright (c) 2020 Abhishek Srivastava
*/


#include <bits/stdc++.h>
using namespace std;

// Using Recursion
int WineRecursive(int p[], int i, int j, int year){
    if(i > j){
        return 0;
    }

    int k1 = (p[i]*year) + WineRecursive(p, i+1, j, year+1);
    int k2 = (p[j]*year) + WineRecursive(p, i, j-1, year+1);
    return max(k1, k2);
}

// Using top-down DP
int TopDownWine(int p[], int i, int j, int year, int dp[][100]){
    if(i > j){
        return 0;
    }

    if(dp[i][j] != 0){
        return dp[i][j];
    }

    int k1 = (p[i]*year) + TopDownWine(p, i+1, j, year+1, dp);
    int k2 = (p[j]*year) + TopDownWine(p, i, j-1, year+1, dp);
    return dp[i][j] =  max(k1, k2);
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int p[] = {2, 3, 5, 1, 4};
    int n = sizeof(p)/sizeof(int);
    
    int year = 1;

    int dp[100][100] = {0};

    // recursion
    cout << WineRecursive(p, 0, n-1, year) << endl;
    cout << TopDownWine(p, 0, n-1, year, dp) ;
    return 0;
}
