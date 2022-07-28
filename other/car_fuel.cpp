#include<iostream>
using namespace std;
 
int n;
int ans;
int a[100];
 
void solve(int cars, int cost, int index, int type, int fuel){
 
    if(cost>ans)
        return; 
   
    if(cars == n){
        ans = min(ans,cost); 
        return;
    }
    
    if(cost > 50)
        return;  //to stop the recursion 
   
    int direction;
    direction = (type == 1) ? 1 : -1; // 1 for gasoline, -1 for diesel

    int cost2;
    cost2 = (type == 1) ? index : n-index + 1; // i for gasoline, n-1+i for diesel

    int decide;
    decide = (type == 1) ? 0 : n+1; // 0 for gasoline, n+1 for diesel
    
  
    if(index == 0)
        solve(cars, cost+1,1, 1,2);
    else if(index == n+1)
        solve(cars, cost+1,n, 2,2);
   
 

    else{
        if(type != a[index]){
            solve(cars, cost+1, index + direction, type, fuel);
        }

        else{
            if(fuel>0)
            {
                int x  = a[index];
                a[index] = 0; //visited 
            
                /* fill the car and move in same direction */
                solve(cars + 1, cost + 1, index + direction, type, fuel-1);   
                /* fill the car and move to same station */
                solve(cars + 1, cost+cost2, decide, 0, 0); 
                a[index] = x;
            }
                                                                        /* else cant be used here this is the heart of recursion 
                                                                           if we have fuel and the type is same then also we can 
                                                                           chose to move ahead. we can fill the the present cars
                                                                           later. in some test cases it will leads to less 
                                                                           final distance covered
                                                                        */
            solve(cars, cost + 1, index + direction, type, fuel);
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
      
        cin>>n;
        for(int i = 1; i<=n; i++)
            cin>>a[i];
   
        ans = 100000;
    
        solve(0,0,0,1,2);
        cout<<ans-1<<endl;
    }
    return 0;
}
