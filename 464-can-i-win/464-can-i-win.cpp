class Solution {
public:
    vector<int> dp;
    
    bool changeTurn(int x, int mask, int k) {
        // Base Case - Checking if at this player's turn target becomes <=0 then that player losses
        if(k<=0) return false;
        
        // To Handle Overlapping
        if(dp[mask]!=-1) return dp[mask];
        
        
        // Every Player is going to try combination of all the numbers which he can play with and then he will play with only that number which leads him to victory.
        
        // If he doesn't win then he can go with any possible playable number
        
        for(int j=1;j<=x;j++) {
            //Checking which combination leads him to victory
            dp[mask] = false;
            if(!(mask&(1<<j))) {
                dp[mask] = dp[mask] | !changeTurn(x,mask|(1<<j),k-j);
                if(dp[mask]) return dp[mask] = true;
            }
        }
        
        // If not Combination is found then return false
        return dp[mask] = false;
    }
    
    
    
    bool canIWin(int x, int k) {
        dp = vector<int>(1<<(x+1),-1);
        if(k==0) return true;
        
        // Edge Case not Mentioned in Question - Total Possible Sum < Target
        if((x*(x+1))/2<k) return false;
        
        // Mask to store which numbers are taken
        int mask = 0;
        return changeTurn(x,mask,k);
    }
};