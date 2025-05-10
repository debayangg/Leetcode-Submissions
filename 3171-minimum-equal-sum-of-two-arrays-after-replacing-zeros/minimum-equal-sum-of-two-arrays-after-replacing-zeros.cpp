class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long mn1=0,mn2=0;
        int cnt1=0 , cnt2=0;
        for(int i:nums1)
        {
            if(i==0){
                cnt1++;
                mn1+=1;
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
        if(cnt1 && cnt2)
        {
            return max(mn1,mn2);
        }
        else if(cnt1==0 && cnt2)
        {
            if(mn1>=mn2)return mn1;
            else return -1;
        }
        else if(cnt2==0 && cnt1)
        {
            if(mn2>=mn1)return mn2;
            else return -1;
        }
        else return (mn1==mn2)?(mn1):-1;
    }
};