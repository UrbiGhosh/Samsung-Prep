#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int ans=9999;
int map[22][22];
int location[5][2];
int visited[22][22]; //also store distance
int n,m;
queue<pair<int,int>> q;
int dx[4]={-1,+1,0,0};
int dy[4]={0,0,-1,+1};

void init()
{
    for(int i=0;i<22;i++)
        for(int j=0;j<22;j++)
            visited[i][j]=0;
    while(!q.empty())
        q.pop();
}

void bfs(int x, int y)
{
    int count= 0;
    for(int k=0;k<m;k++)
        if(visited[location[k][0]][location[k][1]]>0)
            count++;
    
    if(count>=m)
        return;

    /////begin dfs
    for(int i=0;i<4;i++){
        if(x+dx[i]>=1 && x+dx[i]<=n && y+dy[i]>=1 && y+dy[i]<=n){
            if(!visited[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]]!=0){
                visited[x+dx[i]][y+dy[i]]=visited[x][y]+1;
                q.push({x+dx[i], y+dy[i]});
            }   
        }
    }

    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        bfs(i,j);
    }

}

int main(void){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(int i=0;i<m; i++)
            cin>>location[i][0]>>location[i][1];

        for(int i=1;i<=n;i++)//TODO
            for(int j=1;j<=n;j++)
                cin>>map[i][j];

        for(int k=0;k<m;k++)
            map[location[k][0]][location[k][1]]=2;
        

        ans = 9999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                init();
                int temp = 0;
                if(map[i][j]==1)// every possible location
                {
                    visited[i][j]=1;
                    bfs(i, j);

                    //update
                    for(int k=0;k<m;k++)
                        temp=max(temp, visited[location[k][0]][location[k][1]] );
   
                    ans=min(ans, temp);
                } 
            }
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
