class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        long long cont=0;
        for(int i=0;i<seats.size();i++)
        {
            cont+=abs(students[i]-seats[i]);
        }    
        return cont;
    }
};