#include<iostream>
#include<vector>
using namespace std;

int calc(int mask, vector<int>&balloons, vector<int>&dp){
    if(mask==0)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ans=0;
    for(int i=0;i<balloons.size();i++){
        if((mask&(1<<i))==0) continue;
        int v1=1;
        int v2=1;
        for(int j=i-1;j>=0;j--){
            if(mask&(1<<j)){
                v1=balloons[j];
                break;
            }
        }
        for(int j=i+1;j<balloons.size();j++){
            if(mask&(1<<j)){
                v2=balloons[j];
                break;
            }
        }
        ans=max(ans, v1*v2*balloons[i] +calc(mask&(~(1<<i)), balloons, dp));
    }
    dp[mask]=ans;
    return dp[mask];

}

void solve(){
  int i, n;
  cin>>n;
  vector<int>dp(1<<n, -1), balloons(n);
  for(i=0; i<n; i++)cin>>balloons[i];
  cout<<(calc((1<<n)-1, balloons, dp))<<'\n';
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)solve();
  return 0;
}
