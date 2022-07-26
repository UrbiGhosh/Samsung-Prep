#include<iostream>
using namespace std;
 
int dp[51][2002];
bool visited[51][2002];
int a[50],n;
 
int solve(int index, int sum){
    
    if(visited[index][sum + 1000])
        return dp[index][sum + 1000];
      
    visited[index][sum + 1000] = true;
      
    int &ans = dp[index][sum + 1000]; 
    ans = -1000;
      
    if(index == n){
        if(sum == 0)
            ans = 0;
        }
    
    /* remember there is no for last time you put a for loop */
    else{
        int x = max(ans , a[index] + solve(index + 1, sum + a[index]));
        int y = max(ans , 0        + solve(index + 1, sum - a[index]));
        int z = max(ans , 0        + solve(index + 1, sum));
        ans = max(x,max(y,z));
    }
      
    return ans;
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<max(solve(0,0),0)<<endl;
    
    return 0;
}
