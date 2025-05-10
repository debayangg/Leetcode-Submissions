class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long mn1=0,mn2=0, n1=nums1.size(), n2=nums2.size();
        int cnt1=0 , cnt2=0;
        bool f1=true, f2=true;
        auto it1=nums1.begin();
        auto it2=nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
    if (!(f1 || f2)) break;

    if (f1) {
        if (*it1 == 0) {
            cnt1++;
            mn1 += 1;
        } else {
            mn1 += *it1;
        }
        ++it1;
        if (it1 == nums1.end()) {
            --it1;
            f1 = false;
        }
    }

    if (f2) {
        if (*it2 == 0) {
            cnt2++;
            mn2 += 1;
        } else {
            mn2 += *it2;
        }
        ++it2;
        if (it2 == nums2.end()) {
            --it2;
            f2 = false;
        }
    }
}
        // cout<<mn1<<" "<<cnt1<<endl;
        // cout<<mn2<<" "<<cnt2<<endl;
        // for(int i:nums1)
        // {
            
        // }
        // for(int i:nums2)
        // {
        //     if(i==0)
        //     {
        //         mn2+=1;
        //         cnt2++;
        //     }
        //     else mn2+=i;
        // }
        if((cnt1==0 && mn2>mn1) || (cnt2==0 && mn1>mn2))
        return -1;

        return max(mn1,mn2);
    }
};