#include<iostream>
#include<climits>
#include <vector>
using namespace std;

int n,ans;

void solve(vector<vector<int>>& grid, vector<bool>& visited, int count, int cost, int src){
    visited[src]=true;
    
    if(count==n-1){
        // Corner Case if no path exists from last city 
        if(grid[src][0]!=0)
            ans = min(ans, cost + grid[src][0]);
        return;
    }
    
    
    for(int i=0;i<n;i++){
        if(!visited[i] && grid[src][i]){
            visited[i] = true;
            solve(grid, visited, count+1, cost+grid[src][i], i);
            visited[i] = false;
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        cin>>n;
        
        vector<vector<int>> grid(n,vector<int>(n,-1));
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];

        ans=INT_MAX;    
        solve(grid, visited, 0, 0, 0);

        if(ans==INT_MAX)
            cout<<"-1\n";
        else 
            cout<<ans<<endl;
    }
    return 0;
}
