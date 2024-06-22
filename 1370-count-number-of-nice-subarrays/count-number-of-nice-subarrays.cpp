class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=nums.size();
        vector<int> vec(n+1);
        int prev=0;
        vec[0]=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int t=nums[i]&1;
            vec[prev+t]++;
            if(prev+t-k>=0)
            sum+=vec[prev+t-k];
            prev=prev+t;
        }
        return sum;
    }
};