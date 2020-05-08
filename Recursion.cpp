/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;

int FactorialRecursion(int n){

    // Base Case
    if(n ==0 || n == 1){
        return n;
    }

    else return FactorialRecursion(n-1) + FactorialRecursion(n-2);
}

// Reccursive Dynamic Programming
int TopDownDP(int n, int* dp){

    if(n == 1 || n == 0){
        dp[n] = n;
        return n;
    }
    
    // Already calculated - > Memory Element
    if(dp[n] != -1){
        return dp[n];
    }
    else{
        dp[n] =  TopDownDP(n-1, dp) + TopDownDP(n-2, dp);
        return dp[n];
    }
}

// Iterative Dynamic Programming
int BottomToUpDP(int n, int * dp){
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    
    return  dp[n];
}

int main(){
    
    int n = 5;

    int dp[100];
    for (int i = 0; i < 100; i++){
        dp[i] == -1;
    }
    
    cout << FactorialRecursion(n) << endl;

    cout << TopDownDP(n, dp) << endl;

    cout << BottomToUpDP(n, dp) << endl;

    return 0;
}
