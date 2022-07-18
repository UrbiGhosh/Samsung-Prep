#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int ans;
int n, temp = 0;
int worm[35][5]; 
int used[35];


int dist(int sx, int sy, int ex, int ey){
    return abs(ex-sx) + abs(ey-sy);
}

void wormhole(int sx, int sy, int ex, int ey, int value){
    ans = min(ans, dist(sx, sy, ex, ey) + value );

    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i] = 1;

            temp = dist(sx, sy, worm[i][0], worm[i][1]) + worm[i][4] + value;
            wormhole(worm[i][2], worm[i][3], ex, ey, temp);

            temp = dist(sx, sy, worm[i][2], worm[i][3]) + worm[i][4] + value;
            wormhole(worm[i][0], worm[i][1], ex, ey, temp);

            used[i] = 0;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int sx, ex, sy, ey;
        cin>>sx>>sy>>ex>>ey;
        cin>>n;
        for(int i=0;i<n;i++){
            used[i]=0;
            for(int j=0;j<5;j++){
                cin>>worm[i][j];
            }
        }
        ans = INT_MAX;
        wormhole(sx, sy, ex, ey, 0);
        cout<<ans<<endl;
    }
    return 0;
}
