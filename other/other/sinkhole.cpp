#include <iostream>
using namespace std;



int xb,yb,xt,yt;

int fun(int dp[][1001], int N, int M, int k){
    int msum = INT_MAX;
    for(int i=0; i<=N-k; i++){
        for(int j=0; j<=M-k; j++){
            int sum = dp[i+k][j+k]-dp[i+k][j]-dp[i][j+k]+dp[i][j];
            if(sum < msum){
                msum = sum;
                if(msum <=1){
                    xb = i+k;
                    yb = j+1;
                    xt = i+1;
                    yt = j+k;
                }
            }
        }
    }
    return msum;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    
    int N,M;
    cin>>N>>M;
    int A[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            A[i][j]=0;
        }
    }

    int K;
    cin>>K;
    for(int i=0; i<K; i++){
        int x,y;
        cin>>x>>y;
        A[x-1][y-1]=1;
    }
    
    int dp[1001][1001]; /* dp[i][j] = sum of submatrix top-left(0,0) to bottom-right(i,j) */
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            dp[i][j]=0;
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+A[i-1][j-1];
        }
    }

    /* applying binary search */
    int l=1, r=min(M,N);
    int ones;
    while(l<r){
        int mid = (l+r)/2;
        ones = fun(dp,N,M,mid);
        
        if(ones >1)
            r = mid;
        
        
        else
            l = mid+1;
        
    }

    cout<<xb<<" "<<yb<<" "<<xt<<" "<<yt<<endl;
    return 0;
}
