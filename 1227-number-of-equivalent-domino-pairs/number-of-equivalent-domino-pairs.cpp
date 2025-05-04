class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        set<pair<int,int>> s;
        map<pair<int,int>,int> mp;
        int n=dominoes.size();
        for(int i=0;i<n;i++)
        {
            int a=dominoes[i][0], b=dominoes[i][1];
            mp[{a,b}]++;
            cout<<a<<" "<<b<<" "<<mp[{a,b}]<<endl;
            s.insert({a,b});
        }
        int cnt=0;
        for(pair<int,int> val:s)
        {
            int x;
            if(val.first!=val.second)
            x=mp[val]+mp[{val.second,val.first}];
            else
            x=mp[val];
            cout<<val.first<<" "<<val.second<<endl;
            cout<<x<<endl;
            cnt+=x*(x-1);
            mp[val]=0;
            mp[{val.second,val.first}]=0;
        }
        return cnt/2;
    }
};