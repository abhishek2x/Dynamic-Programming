/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

// Its an example of 2-D Dynamic Programming
// We need to maximise the profit

#include <bits/stdc++.h>
using namespace std;

// Using Recursion : It you can take one Unit of each item
int knapsack(int wts[], int prices[], int N, int W){

    if(N == 0 || W == 0){
        return 0;
    }
    

    int inc = 0, exc = 0;
    
    // Including the current Item
    if(wts[N-1] <= W){
        inc = prices[N-1] + knapsack(wts, prices, N-1, W-wts[N-1]);
    }

    // Excluding the current item
    exc = 0 + knapsack(wts, prices, N-1, W);
    
    return max(inc, exc);
}

// Using Recursion : It you can take 'n' Unit of each item
int knapsackNUnit(int wts[], int prices[], int N, int W){

    if(N == 0 || W == 0){
        return 0;
    }
    

    int inc = 0, exc = 0;
    
    // Including the current Item
    if(wts[N-1] <= W){
        inc = prices[N-1] + knapsack(wts, prices, N, W-wts[N-1]);
    }

    // Excluding the current item
    exc = 0 + knapsack(wts, prices, N-1, W);
    
    return max(inc, exc);
}

int BottomUp(int wts[], int prices[], int N, int W){

    int dp[100][100] = {0};

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= W; j++){       //j -> weights of dp[1]'th element
            
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{

                int inc = 0, exc = 0;
                
                // If we include the item
                if(j >= wts[i-1]){
                    inc = prices[i-1] + dp[i-1][j - wts[i-1]];
                }

                // If we exclude the item
                exc = 0 + dp[i-1][j];

                dp[i][j] = max(inc, exc);
            }
        }
    }
    return dp[N][W];
}

// int TopDown(int wts[], int prices[], int N, int W, int* dp){
    
//     if(N == 0 || W == 0){
//         dp[N] = 0;
//         return 0;
//     }

//     int inc = 0, exc = 0;

//     // It item is included
//     if(W >= wts[N]){
//         inc = prices[N-1] + TopDown(wts, prices, N-1, W-wts[N], dp);
//     }
    

//     exc = 0 + TopDown(wts, prices, N-1, W, dp);

//     dp[N] = max(inc, exc);

// }

int main(){
    
    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int N = 4;
    int W = 11;

    int* dp = new int[100];
    for (int i = 0; i < 100; i++){
        dp[i] = -1;
    }
    
    cout << "Recursion, using 1 unit per item : ";
    cout << knapsack(wts, prices, N, W) << endl;

    cout << "Recursion, using n unit per item : ";
    cout << knapsackNUnit(wts, prices, N, W) << endl;
    // cout << TopDown(wts, prices, N, W, dp);

    cout << "Bottom Up DP, using 1 unit per item : ";
    cout << BottomUp(wts, prices, N, W) << endl;

    return 0;
} 
