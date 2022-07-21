#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int mv[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        int r,c;
        cin>>n>>m;
        int a[m+1][n+1];
        memset(a,0,sizeof(int)*m*n);
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                cin>>a[i][j];

        cin>>r>>c;
       
        queue<pair<pair<int,int>,int>> q;
        int tmx,tmy,tml;

        q.push({{c,r},1});
        a[c][r] = 2;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            for(int k=0; k<4; k++)
            {
                tmx = curr.first.first + mv[k][0];
                tmy = curr.first.second + mv[k][1];
                tml = curr.second + 1;
                if(a[tmx][tmy] == 1)
                {
                    a[tmx][tmy] = 2;
                    q.push({{tmx, tmy},tml});
                }
            }
        }
        
        cout<<tml-1<<endl;
    }
    
    return 0;
}
