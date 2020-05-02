#include <bits/stdc++.h>
using namespace std;

int maxDevide(int n, int k){
    
    while(n%k == 0){
        n = n/k;
    }
    return n;
}

bool isUgly(int n){
    
    n = maxDevide(n, 2);
    n = maxDevide(n, 3);
    n = maxDevide(n, 5);

    if(n == 1)
    return true;
    else return false;
}
 
//  Using Simple Normal Approach
int getNthUglyNum(int n){
    
    int count = 1;
    int i = 1;

    while(n > count){
        i++;
        if(isUgly(i))
            count++;
    }
    return i;
}

// Dynamic Programming
int DP(int n){
    
    int ugly[n];
    int i2=0, i3=0, i5=0;
    int for_2 = 2;
    int for_3 = 3;
    int for_5 = 5;
    int next_ugly = 1;

    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        next_ugly = min(for_2, min(for_3, for_5));
        ugly[i] = next_ugly;

        if(next_ugly == for_2){
            i2++;
            for_2 = ugly[i2]*2;
        }
        if(next_ugly == for_3){
            i3++;
            for_3 = ugly[i3]*3;
        }
        if(next_ugly == for_5){
            i5++;
            for_5 = ugly[i5]*5;
        }

    }
    
    return next_ugly;
}

int main(){

    int n = 150;
    
    cout << "Using Simple Normal Approach : " << endl;
    cout << getNthUglyNum(n) << endl;
    cout << "Using DP :"  << endl;
    cout << DP(n);
    return 0;
}
