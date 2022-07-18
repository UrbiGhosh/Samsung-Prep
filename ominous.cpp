#include <vector> 
#include <iostream>

using namespace std;

int solve(int a, int b, int k,vector<int>& nums, int n){
    int count = 0;
    for(int i=a;i<=b;i++){
        int temp=i;
        int digitArray[10] = {0};

        while(temp){
            digitArray[temp%10]++;
            temp /= 10;
        }
        
        int rougeK = 0;
        for(int i=0; i<n; i++)
            rougeK += digitArray[nums[i]];
        

        if(rougeK < k)
            count++;
        
    }
    return count;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);

    int a,b,k;
    cin >>a>>b>>k;  // start end k
    int n;          
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<solve(a,b,k,nums,n);

    return 0;
}
