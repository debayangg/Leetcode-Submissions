class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) const
        {
            if(a.first==b.first)return a.second > b.second;
            return a.first > b.first;
        }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size(), m=tasks.size();
        vector<int> ans(m);
        unordered_map<int,vector<pair<int,int>>> mp;
        set<int> time;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for(int i=0;i<n;i++)
        {
            pq.push({servers[i],i});
        }

        queue<int> q;

        for(int i=0;i<m;i++)
        {
            q.push(i);
            time.erase(i);
            for(pair<int,int> server:mp[i])
            {
                pq.push(server);
            }
            while(!q.empty() && !pq.empty())
            {
                int task=q.front();
                int task_time = tasks[task];
                pair<int,int> serv = pq.top();
                //cout<<task<<" "<<serv.first<<" "<<serv.second<<endl;
                //cout<<"HH"<<endl;
                ans[task]=serv.second;
                mp[i+tasks[task]].push_back(serv);
                time.insert(i+tasks[task]);
                q.pop();
                pq.pop();
            }
        }

        while(!q.empty())
        {
            for(int i:time)
            {
                for(pair<int,int> server:mp[i])
                {
                    pq.push(server);
                }
                while(!q.empty() && !pq.empty())
                {
                    int task=q.front();
                    int task_time = tasks[task];
                    pair<int,int> serv = pq.top();
                    //cout<<task<<" "<<serv.first<<" "<<serv.second<<endl;
                    //cout<<"HH"<<endl;
                    ans[task]=serv.second;
                    mp[i+tasks[task]].push_back(serv);
                    time.insert(i+tasks[task]);
                    q.pop();
                    pq.pop();
                }
            }
        }
        return ans;
    }
};