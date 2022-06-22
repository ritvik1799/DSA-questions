class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        int n = nums.size();
        for(int i=0;i<k;i++)
        {
            q.push(nums[i]);
        }
        for(int i=k;i<n;i++)
        {
            if(q.top()<nums[i])
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
        
    }
};