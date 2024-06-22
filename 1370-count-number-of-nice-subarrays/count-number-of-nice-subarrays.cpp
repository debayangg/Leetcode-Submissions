class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int vec[n+1];
        fill(vec,vec+n+1,0);
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