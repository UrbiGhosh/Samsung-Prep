#include<bits/stdc++.h>
using namespace std;

void bombed(int row, vector<vector<char>>& grid)
{
    if(row<0)
        return;
    int upLimit=max(0,row-4);

    for(int i=row;i>=upLimit;i--)
        for(int j=0;j<5;j++)
            if(grid[i][j]=='2')
                grid[i][j]='0';
        
}

int solve(int row, int col, int bombs, vector<vector<char>>& grid){
    if(row<=0 || col<0 || col>=5)
        return 0;
    
    int answer=0;

    //no enemy in front
    if(row>0 && grid[row-1][col]!='2')    
        answer=max(answer, grid[row-1][col]-'0'+solve(row-1,col,bombs,grid));

    //no enemy in front to the left
    if(col>0 && row>0 && grid[row-1][col-1]!='2')  
        answer=max(answer, grid[row-1][col-1]-'0'+solve(row-1,col-1,bombs,grid));
    
    //no enemy in front to the right
    if(col<4 && row>0 && grid[row-1][col+1]!='2') 
        answer=max(answer, grid[row-1][col+1]-'0'+solve(row-1,col+1,bombs,grid));
    
    if(answer==0 && bombs>0){
        bombed(row-1,grid);
        answer=solve(row,col,bombs-1,grid);
    }

    return answer;
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
        int n;//
        cin>>n;
        vector<vector<char>> grid(n, vector<char> ('*',5));

        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                cin>>grid[i][j];
            
        cout<<solve(n,2,1,grid)<<endl;  
    }
    return 0;
}

