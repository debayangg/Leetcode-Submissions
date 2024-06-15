class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> p;
        for(int i=0;i<profits.size();i++)
        {
            p.push_back({capital[i],profits[i]});
        }
        sort(p.begin(),p.end());
        priority_queue<pair<int,int>> max_heap;
        int i=0;
        while(k>0)
        {
            while(i<profits.size() && p[i].first<=w)
            {
                max_heap.push({p[i].second,p[i].first});
                i++;
            }
            if(max_heap.size()==0)
            break;

            w+=max_heap.top().first;
            max_heap.pop();
            k--;
        }
        return w;
    }
};