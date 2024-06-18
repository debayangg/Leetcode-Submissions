class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr;
        int n=profit.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back({profit[i],difficulty[i]});
        }
        sort(arr.rbegin(),arr.rend());
        sort(worker.begin(),worker.end());
        int mx=worker.size()-1,ans=0;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(worker.begin(),worker.end(),arr[i].second);
            if(it!=worker.end() && distance(worker.begin(),it)<=mx)
            {
                auto en=worker.begin();
                advance(en,mx);
                ans+=(arr[i].first)*(distance(it,en)+1);
                mx=distance(worker.begin(),it)-1;
            }
        }
        return ans;
    }
};