#include<iostream>
using namespace std;
 
int solve(char s[], int k){
    
    int lvl = -1;
    int ans = 0;
    
    int i = 0;
    while(s[i] != '\0') {
        
        if(s[i] == '(')lvl++;
        
        else if(s[i] == ')')lvl--;
        
        else if(lvl == k)
        ans += s[i] - '0';
        
        i++;
    }
    
    return ans;
    
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
        char s[100];
        cin>>s;
        int k; 
        cin>>k;
        cout<<solve(s,k)<<endl;
    }
    return 0;
}
