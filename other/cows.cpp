# include<bits/stdc++.h>

using namespace std;

int n,k;
int stall[1000009];

void init(){
    for(int i=0;i<1000009;i++)
        stall[i]=0;
}
bool Comperator(int least,int stalls,int cows){
    int curr = 1;
    int prev = 0;
    
    for(int i=1;i<n;++i){
        if(stall[i]-stall[prev]>=least){
            prev = i;
            curr++;

            if(curr==cows)
                return true;
        }
    }
    return false;
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
        init();
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>stall[i];
        
        sort(stall,stall+n);
        
        int l=0;
        int r=stall[n-1]-stall[0]+1;
        
        while(r>l ){
            int m=(l+r+1)/2;
            
            if(Comperator(m,n,k))
                l=m; 

            else 
                r=m-1;
        }

        cout<<l<<endl;
    }
}
