#include<iostream>
#include<climits>
#include <cmath>
#include <vector>
using namespace std;

int x[20],y[20];
int n,ans;

int dist(int i, int j){
    return (abs(x[i]-x[j]) + abs(y[i]-y[j]));
}

void solve(int curr, vector<bool>& visited, int nodes, int value){
    if(n==nodes)
        ans = min(ans,value + dist(curr,n+1));
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            solve(i, visited, nodes+1, value + dist(curr,i));
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
    cin>>t;
    while(t--){
        ans=INT_MAX;
        cin >>n;
        cin >>x[0]>>y[0]>>x[n+1]>>y[n+1];

        for(int i=1;i<=n;i++)
            cin >>x[i]>>y[i];
        
        vector<bool> visited(n+2, false);

        solve(0,visited,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
