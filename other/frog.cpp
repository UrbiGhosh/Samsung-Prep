#include <iostream>
#include<queue>
using namespace std;

int n, sX, sY, tX, tY; 
int mat[105][105], dis[105][105], vis[105][105];


int dx[4] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
            vis[i][j] = 0;
            dis[i][j] = 0;
        }
    }

    cin >> sX >> sY >> tX >> tY;

    queue<pair<int,int>> q;
    q.push({sX,sY});

    vis[sX][sY] = 1;
    dis[sX][sY] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX>=0 && newX<n && newY>=0 && newY<n)
                if( mat[newX][newY] == 1 && vis[newX][newY] == 0){

                if(i == 0 || i == 2){
                    dis[newX][newY] = dis[x][y];
                }
                else if(i == 1 || i == 3){
                    dis[newX][newY] = 1 + dis[x][y];
                }

                vis[newX][newY] = 1;

                q.push({newX, newY});

            }
        }
    }

    cout << dis[tX][tY];
    return 0;
}
