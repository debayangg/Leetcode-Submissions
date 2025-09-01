class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        set<pair<long double,int>> s;
        for(int i=0;i<classes.size();i++)
        {
            double a=classes[i][0], b=classes[i][1];
            s.insert({( (a+1)/(b+1) - (a)/(b) ), i});
        }
        while(extraStudents)
        {
            auto val = *s.rbegin();
            double i=classes[val.second][0]+1, j=classes[val.second][1]+1;
            s.erase(val);
            classes[val.second][0]++;
            classes[val.second][1]++;
            s.insert({( (i+1)/(j+1) - (i)/(j) ),val.second});
            extraStudents--;
        }
        long double sum=0, avg;
        for(auto x:s)
        {
            double a=classes[x.second][0] , b=classes[x.second][1];
            sum+=a/b;
        }
        
        return sum/classes.size();
    }
};