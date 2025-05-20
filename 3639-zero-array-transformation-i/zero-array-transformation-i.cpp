class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> delta(n);
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0], b=queries[i][1];
            delta[a]+=1;
            if(b+1<n)
            delta[b+1]-=1;
        }
        vector<int> cnt(n,0);
        cnt[0]=delta[0];
        bool flag=true;
        if(cnt[0]<nums[0])flag=false;
        for(int i=1;i<n;i++)
        {
            delta[i]+=delta[i-1];
            cnt[i]=delta[i];
            if(cnt[i]<nums[i]){
                flag=false;
                break;
            }
        }

        return (flag)?true:false;
    }
};