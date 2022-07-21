#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int arr[1000];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin >> k;

    sort(arr,arr+n);
    
    int ans=0;

    for(int i=n-1;i>0;i--)
        arr[i] = max(0,arr[i]-arr[i-1]);
    

    for(int i=0;i<k;i++)
        ans+=(arr[i]*(n-i));
    
    cout << ans;
    return 0;
}
