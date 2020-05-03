#include<bits/stdc++.h>
using namespace std;
/*
    Collatz Conjecture
*/
int cons_cnt=0;
long long mx_n = 1;
unordered_map<long long int,long long int> dp;
long long int fillDP(long long int n){
   // cerr << n << endl;
    mx_n = max(mx_n,n);
    if(dp[n]!=0) {
        cons_cnt++; 
        return dp[n];
    }
    if(n==1) {
        cons_cnt++; 
        dp[n]=1;
    }
    else if(n%2==0){
        cons_cnt++; 
        dp[n]=1+fillDP(n/2);
    }
    else{
        cons_cnt++; 
        dp[n]=1+fillDP(3*n+1);
    }
    cons_cnt++; 
    return dp[n];
}
long long int solve(long long int n){
    long long int ans = 1;
    for(int i=1;i<n;i++){
        if(dp[i]==0)
            fillDP(i);
        cons_cnt++; 
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main(){
    long long int n = 1000000;
    cout << solve(n) << '\n';
    cout << cons_cnt << '\n';
    cout << mx_n << '\n';
    cout << "Time Complexity O( " << (double)(cons_cnt)/(double)n <<" * N )\n";
    return 0;
}




















































