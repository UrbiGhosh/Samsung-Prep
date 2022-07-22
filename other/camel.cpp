#include<bits/stdc++.h> 
using namespace std; 
 
int n;
int a[1000]; 
bool vis[1000]; 
int globalAns; 

void init(){
    globalAns=INT_MAX;
    for(int i=0;i<1000;i++){
        a[i]=0;
        vis[i]=false;
    }
}
 
void solve(int a[], int n, bool vis[], int LtoR, int ans, int visCnt){
 
    if(ans>globalAns) return;                                                       /* optimization */

    if(visCnt == n)                                                                /*base case // all visited */
       globalAns = min(ans, globalAns);   
    
    if(LtoR == 1){
    
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
             
                if(vis[i] == false && vis[j] == false){
                    int bada = max(a[i],a[j]); 
           
                     /* backtracking logic */
                    vis[i] = true; vis[j] = true; 
                    solve(a,n,vis,1-LtoR, ans + bada, visCnt + 2); 
                    vis[i] = false; vis[j] = false; 
                }
            
            }
        }
        
    }
    else{
        for(int i = 0; i<n; i++){
            if(vis[i] == true){
               /* backtracking logic */
                vis[i] = false; 
                solve(a,n,vis,1-LtoR, ans + a[i], visCnt - 1); 
                vis[i] = true; 
            }
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
        init();
        cin>>n; 
        
        for(int i = 0; i<n; i++)
            cin>>a[i]; 
       
        solve(a,n,vis,1,0,0); 
        cout<<globalAns<<endl; 
    }
    
}
