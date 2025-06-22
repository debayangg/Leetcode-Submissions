class Solution {
public:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first == b.first)
                return a.second > b.second;  // smaller index preferred
            return a.first > b.first;        // smaller weight preferred
        }
    };

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);

        // Available servers: (weight, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> free;

        // Busy servers: (free_time, (weight, index))
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> busy;

        for (int i = 0; i < n; ++i) {
            free.push({servers[i], i});
        }

        int time = 0;

        for (int i = 0; i < m; ++i) {
            time = max(time, i);

            // Free any servers that are done by current time
            while (!busy.empty() && busy.top().first <= time) {
                auto [_, server] = busy.top(); busy.pop();
                free.push(server);
            }

            // If no server is available, fast-forward time
            if (free.empty()) {
                time = busy.top().first;
                while (!busy.empty() && busy.top().first <= time) {
                    auto [_, server] = busy.top(); busy.pop();
                    free.push(server);
                }
            }

            auto [weight, idx] = free.top(); free.pop();
            ans[i] = idx;
            busy.push({time + tasks[i], {weight, idx}});
        }

        return ans;
    }
};
