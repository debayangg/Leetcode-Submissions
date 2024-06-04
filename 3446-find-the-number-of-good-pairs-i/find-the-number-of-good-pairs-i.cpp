class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count=0;
        for(int i:nums1)
        {
            for(int j:nums2)
            {
                count+=(i%(j*k)==0);
            }
        }
        return count;
    }
};