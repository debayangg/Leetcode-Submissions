class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size(),mx=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        unordered_map<int,int> vis;
        unordered_map<int,int> vals;
        for(auto id:arr)
        {
            if(vis[id])continue;

            int i=id,cnt=0;
            while(mp[i])
            {
                vis[i]=1;
                if(vals[i])
                {
                    cnt+=vals[i];
                    break;
                }
                cnt++;
                i--;
            }
            mx=max(mx,cnt);
            vals[id]=cnt;
        }
        return mx;
    }
};