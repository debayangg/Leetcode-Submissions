class Solution {
public:
    int ans = 0;
    
    void dfs(int i, vector<int> &val, vector<vector<pair<int,int>>> &vec, int time, int timlim, int sum)
    {
        if(time>timlim)return;

        sum+=val[i];
        if(i==0)
        ans=max(ans,sum);

        int v=val[i];
        val[i]=0;
        for(auto edge:vec[i])
        {
            dfs(edge.first,val,vec,time+edge.second,timlim,sum);
        }
        val[i]=v;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) 
    {
        int n=values.size();
        vector<vector<pair<int,int>>> vec(n);
        for(auto edge : edges)
        {
            vec[edge[0]].push_back({edge[1],edge[2]});
            vec[edge[1]].push_back({edge[0],edge[2]});
        }
        dfs(0,values,vec,0,maxTime,0);
        return ans;
    }
};