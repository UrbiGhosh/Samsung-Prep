#include<bits/stdc++.h>
using namespace std;
 
 
int solve(int n, int flag){
    if(n<=0)return 1;
    if(n == 1)return 1;
    if(n == 2)return 2;
    if(n == 3 && flag == 0)return 3;
    if(n == 3 && flag == 1)return 4;
    int ans = 0;
    if(flag == 0)
      return ans += solve(n-1,0) + solve(n-2,0);
    
    else if(flag == 1)
      return ans +=  solve(n-1,1) + solve(n-2,1) + solve(n-3,0);
    
    return ans;
}
 
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    int n; 
    cin>>n;

    cout<<solve(n,1)<<endl;
 
    return 0;
}

//isme kuch aisa hai ki ek sequence me number 3 bas ek baar aana chahiye
