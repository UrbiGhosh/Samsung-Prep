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




//////////////////////


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int k;
    cin>>k;
    string s;
    cin>>s;
    int open=0;
    int close=0;
    vector<pair<int,int>> store;
    int prev=0;
    for(int i=0;i< s.size();i++){
        if(s[i]=='(')open++;
        else if(s[i]==')')close++;
        else{
            int val=s[i]-'0';
            if (prev!=0){
                val = prev*10 + val;
                if(s[i+1]!='(' && s[i+1]!=')'){
                    prev=val;
                }
                else {
                    prev=0;
                    store.push_back({val,open-close});
                }
            }
            
            else if(s[i+1]!='(' && s[i+1]!=')'){
                prev=val;
            
            }
            else {
                prev=0;
                store.push_back({val,open-close});
                
            }
                
        }
    }
    int ans=0;
    for(int i=0;i<store.size();i++){
      //  cout<<store[i].first<<" "<<store[i].second<<"\n";
        if(store[i].second==k+1)
            ans+=store[i].first;
    }
    cout<<ans;
    return 0;
}

