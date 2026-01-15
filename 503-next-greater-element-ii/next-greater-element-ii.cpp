class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums[i]>=st.top())
            {
                st.pop();
            }
            st.push(nums[i]);
        }
        stack<int> cp = st;
        while(!cp.empty())
        {
            cout<<cp.top()<<endl;
            cp.pop();
        }

        for(int i = nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums[i]>=st.top())
            {
                st.pop();
            }
            if(!st.empty())ans[i] = st.top();
            else ans[i]=-1;

            st.push(nums[i]);

            // cp = st;
            // cout<<"H"<<endl;
            // while(!cp.empty())
            // {
            //     cout<<cp.top()<<endl;
            //     cp.pop();
            // }
        }

        // vector<int> ans;
        // for(int x:nums)
        // ans.push_back(mp[x]);

        return ans;
    }
};