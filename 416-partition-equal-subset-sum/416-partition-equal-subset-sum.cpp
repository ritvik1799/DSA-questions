class Solution {
public:
    bool solve(vector<int>& nums,int sum)
    {
        int n = nums.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=sum;i++)
        {
            dp[0][i] = false;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = true;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=nums[i-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==0)
        {
            return solve(nums,sum/2);
        }
        else 
            return false;
        
    }
};