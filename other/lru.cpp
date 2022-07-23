#include<bits/stdc++.h>
using namespace std;
 
unordered_map<int, list<int> :: iterator> mp;

list<int>q;
int sz;
void insert(int x){
    
    // if not present 
    if(mp.find(x) == mp.end()){
        if(q.size() == sz){
            int last = q.back();
            q.pop_back();
            mp.erase(last);
        }
    }
    // if present
    else
    mp.erase(x);
    
    q.push_front(x);
    mp[x] = q.begin();
    
    
}
 
void display(){
    
    for(auto it = q.begin(); it!=q.end(); it++)
    cout<<*it<<" ";
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    cin>>sz;
    insert(1);
    insert(2);
    insert(3);
    insert(1);
    insert(4);
    insert(5);
    display();
    return 0;
}
