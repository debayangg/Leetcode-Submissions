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
        for(int i = nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums[i]>=st.top())
            {
                st.pop();
            }
            if(!st.empty())ans[i] = st.top();
            else ans[i]=-1;

            st.push(nums[i]);
        }

        return ans;
    }
};