/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int coinsNeeded(int coins[], int amount, int n){
    
    // Base case
    if(amount == 0){
        return 0;
    }

    int ans = INT_MAX;
    // Rec
    for (int i = 0; i < n; i++)
    { 
        if(amount-coins[i] >= 0){
            int smallerAns = coinsNeeded(coins, amount-coins[i], n);
            // backtracking
            if(smallerAns != INT_MAX)
                ans = min(ans, smallerAns+1);
        }
    }
    return ans;
}

// BottoUP DP
int coinsNeededDP(int coins[], int amount, int n){

    int* dp = new int[amount+1];
    
    for (int i = 0; i < amount+1; i++){
        dp[i] = INT_MAX;
    }
    
    dp[0] = 0;

    for (int rupee = 1; rupee <= amount; rupee++){
        // Iterate over coins
        for (int i = 0; i < n; i++){
            if(coins[i] <= rupee){
                int smallerAns = dp[rupee - coins[i]];
                // backtracking
                if(smallerAns != INT_MAX){
                    dp[rupee] = min(dp[rupee], smallerAns+1);
                }
            }
        }
    }
    return dp[amount];
}

int main(){
    int amount = 15;
    int paise = 13;

    int us_coins[] = {1, 7, 10};
    int indian_coins[] = {1, 2, 5, 10, 50};

    cout << "Recursive " << endl;

    cout << coinsNeeded(us_coins, amount, 3) << endl; 
    cout << coinsNeeded(indian_coins, paise, 5) << endl;

    cout << "Recursive Using DP" << endl;

    cout << coinsNeededDP(us_coins, amount, 3) << endl; 
    cout << coinsNeededDP(indian_coins, 39, 5) << endl;

    return 0;
}
