# include<bits/stdc++.h>
using namespace std;    
#include <climits>

int n;

void solve(vector<char>& pic, int i){

    if(n==1){
        pic[0]='X';
        return;
    }
    vector<int> starts;
    vector<int> ends;

    int start=0;
    while(pic[start]=='X')
        start++;
    int end=start;
    while(end<n){
        if(pic[end]=='_'){
            end++;
        }
        else{
            starts.push_back(start);
            ends.push_back(end-1);
            start=end;
            while(pic[start]=='X')
                start++;
            end=start;
        }
    }
    starts.push_back(start);
    ends.push_back(end);
    int x=-1, y=-1;
    int diff= INT_MIN;
    for(int i=0;i<starts.size();i++){
        if(ends[i]-starts[i]+1 > diff){
            diff= ends[i]-starts[i]+1;
            x=starts[i];
            y=ends[i];
        }
    }
    //cout<<starts.size()<<endl;

    pic[(x+y)/2]='X';
    return;
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
        cin>>n;
        vector<char> pic(n,'_');
        for(int i=0;i<n;i++){
            solve(pic, i);
            for(int j=0;j<n;j++){
                cout<<pic[j]<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
    }
}
