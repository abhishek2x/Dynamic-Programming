/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion -> Time Complexity : O(k^n)
int ways(int n){

    if(n == 0)
    return 1;

    if(n < 0)
    return 0;

    int ans = ways(n-1) + ways(n-2) + ways(n-3);
    return ans;
}

// Considerting K as K, everywhere else we have considered K as 3
int ways2(int n, int k){

    if(n == 0){
        return 1;
    }
    
    if(n<0){
        return 0;
    }

    int ans = 0;
    for(int j=1; j<=k; j++){
        ans += ways2(n-j, k);
    }
    return ans;
}

int TopDownDP(int n, int* dp){
    if(n == 0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    if(dp[n] == -1){
        int ans = TopDownDP(n-1, dp) + TopDownDP(n-2, dp) + TopDownDP(n-3, dp);
        dp[n] = ans;
        return ans;
    } else {
        return dp[n];
    }
}

// Recursion -> Time Complexity : O(k*n)
int BottomUpDP(int n, int k){
    
    int* dp = new int[50];
    for (int i = 0; i < 50; i++){
        dp[i] = -1;
    }

    dp[0] = 1;


    for (int i = 1; i <= n; i++){
        dp[i] = 0;
        for (int j = 1; j <= k; j++){
            if(i-j >= 0){
                dp[i] += BottomUpDP(i-j, k);
            }
        }
    }
    
    return dp[n];
}

// Trying to do in O(n) ?
int BottomUpDP2(int n, int k){
    
    int* dp = new int[50];
    for (int i = 0; i < 50; i++){
        dp[i] = -1;
    }

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 3;

    for (int i = k; i <= n; i++){
        dp[i] = 2*dp[i] + dp[i-k];
    }
    
    return dp[n];
}

int main(){

    int n = 6;
    // int k = 3;
    int* dp = new int[50];
    for (int i = 0; i < 50; i++){
        dp[i] = -1;
    }

    // n is the number of steps 
    // Steps can be of 1 or 2 or 3
    // ways is same nothing different

    cout << TopDownDP(n, dp) << endl;
    // recursive
    cout << ways(n) << endl;
    cout << BottomUpDP(n, 3) << endl;
    cout << BottomUpDP2(n, 3) << endl;
    // DP
    cout << ways2(n, 3);

    return 0;
}
