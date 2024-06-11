class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr;
        map<int,int> m;
        for(int i=0;i<arr1.size();i++)
        {
            m[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++)
        {
            while(m[arr2[i]]-->0)
            arr.push_back(arr2[i]);
        }
        for(auto i:m)
        {
            while(m[i.first]-->0)
            arr.push_back(i.first);
        }
        return arr;
    }
};