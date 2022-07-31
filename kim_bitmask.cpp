#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int n;
int calc(int mask, int i, vector<vector<int>>&dist, vector<vector<int>>&dp){

    if(mask==((1<<1)|(1<<i)))
        return dist[i][1];

    if(dp[mask][i]!=-1)
        return dp[mask][i];

    int m2=(mask&(~(1<<i)));
    int ans=INT_MAX;
    
    for(int j=0; j<n; j++)
    {
        if(j==1||(m2&(1<<j))==0)
            continue;
        ans=min(ans, dist[i][j]+calc(m2, j, dist, dp));
    }

    return dp[mask][i]=ans;
}


int main(){

    int t=10;
    while(t--){

        cin>>n;
        n+=2;
        vector<pair<int, int>>points;
        
        for(int i=0; i<n; i++){
            int a,b;
            cin>>a>>b;
            points.push_back({a, b});
        }
        
        vector<vector<int>> dist(n, vector<int>(n));
        vector<vector<int>> dp(1<<n, vector<int>(n, -1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j]= abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second);
            }
        }
        cout<<"# "<<10-t<<" "<<(calc((1<<n)-1, 0, dist, dp))<<'\n';
    }
    return 0;
}
