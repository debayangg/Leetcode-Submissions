class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long mn1=0,mn2=0, n1=nums1.size(), n2=nums2.size();
        int cnt1=0 , cnt2=0;
        for(int i:nums1)
        {
            if(i==0)
            {
                mn1+=1;
                cnt1++;
            }
            else mn1+=i;
        }
        for(int i:nums2)
        {
            if(i==0)
            {
                mn2+=1;
                cnt2++;
            }
            else mn2+=i;
        }
        if((cnt1==0 && mn2>mn1) || (cnt2==0 && mn1>mn2))
        return -1;

        return max(mn1,mn2);
    }
};