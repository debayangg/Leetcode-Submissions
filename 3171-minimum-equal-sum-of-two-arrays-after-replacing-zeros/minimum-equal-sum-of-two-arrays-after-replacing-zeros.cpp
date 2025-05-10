class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long mn1=0,mn2=0, n1=nums1.size(), n2=nums2.size();
        int cnt1=0 , cnt2=0;
        bool f1=true, f2=true;
        for(int i=0,j=0;i<n1 && j<n2;)
        {
            if(!(f1 || f2))break;
            if(f1)
            {
                if(nums1[i]==0)
                {
                    cnt1++;
                    mn1+=1;
                }
                else mn1+=nums1[i];
                i++;
            }
            if(f2)
            {
                if(nums2[j]==0)
                {
                    cnt2++;
                    mn2+=1;
                }
                else mn2+=nums2[j];
                j++;
            }
            if(i==n1)
            {
                i--;
                f1=false;
            }
            if(j==n2)
            {
                j--;
                f2=false;
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