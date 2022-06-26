class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum =0;
        for(auto i:cardPoints)
        {
            sum+=i;
        }
        int n = cardPoints.size();
        int w = n-k;
        int i=0,j=0;
        int mn = INT_MAX;
        int rs =0;
        while(j<w)
        {
            rs += cardPoints[j];
            j++;
        }
        mn = rs;
        while(j<n)
        {
            rs=rs-cardPoints[i];
            rs+=cardPoints[j++];
            i++;
            mn = min(rs,mn);
        }
        return sum-mn;
    }
};