class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        map<int,int> mp;
        int n=arr.size(),mx=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        map<int,int> vis;
        map<int,int> vals;
        for(auto id:arr)
        {
            if(vis[id])continue;

            int i=id,cnt=0;
            cout<<i<<endl;
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
            // for(int x=0;x<=200;x++)
            // {
            //     if(mp[x])cout<<x<<" "<<vis[x]<<endl;
            // }
            mx=max(mx,cnt);
            vals[id]=cnt;
        }
        return mx;
    }
};