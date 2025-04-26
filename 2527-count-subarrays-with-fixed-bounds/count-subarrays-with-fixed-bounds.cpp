class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int lastMin = -1, lastMax = -1, lastInvalid = -1;
        long long ans = 0;

        for(int i = 0; i < n; ++i) {
            // Update last index where number is invalid
            if(nums[i] < minK || nums[i] > maxK) lastInvalid = i;

            // Update last index where nums[i] == minK
            if(nums[i] == minK) lastMin = i;

            // Update last index where nums[i] == maxK
            if(nums[i] == maxK) lastMax = i;
            
            // The earliest valid start must be after last invalid
            int validStart = min(lastMin, lastMax);
            if(validStart > lastInvalid) ans += validStart - lastInvalid;
        }
        return ans;
    }
};