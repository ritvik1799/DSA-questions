class Solution {
public:
    int solve(vector<int>& arr,int n,int s)
    {
        int dp[n+1][s+1];
        for(int i=0;i<=s;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
            
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(j>=arr[i-1])
                {
                    dp[i][j] = dp[i-1][j] +dp[i-1][j-arr[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        target =abs(target);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int s = (sum+target)/2;
        if(sum<target || (sum+target)%2!=0) return 0;
        else
        {
            return solve(nums,nums.size(),s);
        }
        
    }
};