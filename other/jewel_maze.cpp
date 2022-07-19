# include<iostream>
#include <vector>
using namespace std;    
int n, ans;
int dx[4]={-1, +1, 0, 0};
int dy[4]={0, 0, -1, +1};

void dfs(int x, int y, int val, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& path){

    if(x==n-1 && y==n-1){
        if(val>=ans){
            ans=val;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                    if(visited[i][j]==1)
                        path[i][j]=3;
                    else 
                        path[i][j]=grid[i][j];
            }
        }
        
    }
    for(int i=0;i<4;i++){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X>=0 && X<n && Y>=0 && Y<n && !visited[X][Y]){
            visited[X][Y]=1;
            if(grid[X][Y]==2)
                dfs(X,Y,val+1, grid, visited, path);
            else if(grid[X][Y]==0)
                dfs(X,Y,val, grid, visited, path);

            visited[X][Y]=0;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    int t;  
    cin >> t;
    while(t--){
        cin>>n;
        vector<vector<int>> grid(n,vector<int> (n,0));

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        
        vector<vector<int>> path(n,vector<int> (n,0));

        vector<vector<bool>> visited(n,vector<bool> (n,false));    

        ans=INT_MIN;
        visited[0][0]=true;

        if(grid[0][0]==2)
            dfs(0,0,1,grid, visited, path);
        else 
            dfs(0,0,0,grid, visited, path);

        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<path[i][j]<<" ";
            }cout<<endl;
        }

    }
}
