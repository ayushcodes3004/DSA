class Solution {
private:
    int rec(int i,int j,vector<int>& nums,int n,vector<vector<int>>& dp){
        if(i==n)    return 0;
        int ans=0;
        if(dp[i][j+1]!=-1)    return dp[i][j+1];

        int leave=rec(i+1,j,nums,n,dp);
        ans=max(ans,leave);

        if(j==-1 || nums[i]>nums[j]){
            int take=1+rec(i+1,i,nums,n,dp);
            ans=max(ans,take);
        }

        return dp[i][j+1]=ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    dp[i]=max(dp[i],dp[prev]+1);
                }
            }
        }
        int maxi=0;
        for(auto el: dp)    maxi=max(maxi,el);
        return maxi;
        
    }
};