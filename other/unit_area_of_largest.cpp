#include <bits/stdc++.h>
using namespace std;
int a[500][500];
bool visited[500][500];
int len[500][500];
int rows, cols;
int X[8] = {-1,-1,-1,0,1,1,1,0};
int Y[8] = {-1,0,1,1,1,0,-1,-1};
 
 
int solve(int r, int c){
    queue<pair<int,int>>q;

    q.push({r,c});
    visited[r][c] = true; 
    len[r][c] = 1;
   
    while(!q.empty()){
        int R = q.front().first;
        int C = q.front().second;
        q.pop();
       
        for(int i = 0; i<8; i++){
            int x = R + X[i]; 
            int y = C + Y[i];
            
            if(x<rows && y<cols && x>=0 && y>=0)
            if(a[x][y] == 1 && visited[x][y] == false){

                q.push({x,y});
                len[x][y] = 1;
                visited[x][y] = true;
             }
        }
    }
    int ans = 0;

    for(int i =0; i<rows; i++)
        for(int j =0; j<cols; j++)
            ans += len[i][j];
        
    return ans;
}
 
 
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    int t; 
    cin>>t;
    while(t--){
        int ans = 0;
        memset(visited, 0 , sizeof(visited));
        cin>>rows>>cols;
 
        for(int i =0; i<rows; i++)
            for(int j =0; j<cols; j++) 
                cin>>a[i][j];
     
        for(int i =0; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(a[i][j]==1 && !visited[i][j]){
                    memset(len, 0, sizeof(len));
                    ans = max( ans, solve(i,j) );
                }
            }
        }
       
        cout<<ans<<endl;
    }
   
    return 0;
}


/*
2
4 5
0 0 1 1 0
1 0 1 1 0
0 1 0 0 0
0 0 0 0 1 

4 5
0 0 1 1 0
0 0 1 1 0
0 0 0 0 0
0 0 0 0 1 

gives 6, 4
*/
