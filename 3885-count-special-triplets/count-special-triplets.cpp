class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int,long long> mp1, mp2;
        int n=nums.size();
        long long cnt=0;

        for(int i=n-1;i>=1;i--)mp2[nums[i]]++;

        mp1[nums[0]]++;

        for(int i=1;i<n-1;i++)
        {
            mp2[nums[i]]--;
            cnt+=mp1[2*nums[i]]*mp2[2*nums[i]];
            mp1[nums[i]]++;
        }
        cnt%=(long long)1e9+7;
        return (int)cnt;
    }
};