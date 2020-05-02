// Catalan Number

#include <bits/stdc++.h>
using namespace std;

// Recursion
int Catalan(int n){

    if(n <= 1){
        return 1;
    }
    
    unsigned long int res = 0;

    for(int i=0; i < n; i++){
        res += Catalan(i) + Catalan(n-i-1);
    }
    
    return res;
}

// Dynamic Approach - BottomUp Method
int CatalanBottomUpDP(int n){

    int dp[n+1];
    for (int i = 0; i < n+2; i++){
        dp[i] = 0;
    }
    
    
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n ; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += CatalanBottomUpDP(j) + CatalanBottomUpDP(i-j-1);
        }
    }
    
    return dp[n];
}


// Dynamic Approach - TopDown Method
int CatalanTopDownDP(int n, int* dp){
    
    if(n <= 1){
        dp[n] = 1;
        return 1;
    }

    unsigned long int res = 0;
    if( dp[n] == -1){
        for (int i = 0; i < n; i++){
            res += CatalanTopDownDP(i, dp) + CatalanTopDownDP(n-i-1, dp);
        }    
        dp[n] = res;
    } 
    else res = dp[n];

    return res;
}

int main(){
    int n;
    n = 10;

    int* dp = new int[n];
    for (int i = 0; i < n; i++){
        dp[i] = -1;
    }
    
    cout << "Using Recursion\n";
    for(int i = 0; i < n; i++){
        cout << Catalan(i) << ", ";
    }
    cout << "\nUsing Dynamic Approach : \nTopDown Method\n";
    for(int i = 0; i < n; i++){
        cout << CatalanTopDownDP(i, dp) << ", ";
    }

    cout << "\nUsing Dynamic Approach\nBottomUP Method\n";
    for(int i = 0; i < n; i++){
        cout << CatalanBottomUpDP(i) << ", ";
    }
    return 0;
}
