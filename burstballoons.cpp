class Solution {
public:
    int dp[502][502];
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        n=nums.size();
        memset(dp,0,sizeof(dp));
        
        
        int current=0, remaining=0;
        for(int left=n-2;left>=1;left--){
            for(int right=left;right<=n-2;right++){
                for(int i=left;i<=right;i++){
                    current=nums[left-1]*nums[i]*nums[right+1];
                    remaining = dp[left][i-1] + dp[i+1][right];
                    dp[left][right]=max(dp[left][right], remaining+current);
                }
            }
        }
        return dp[1][n-2];
    }
};
