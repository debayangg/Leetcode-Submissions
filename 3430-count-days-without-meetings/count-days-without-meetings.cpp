class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort the meetings based on the start day
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> mergedMeetings;
        mergedMeetings.push_back(meetings[0]);

        // Merge overlapping meetings
        for(int i = 1; i < meetings.size(); i++) {
            if(meetings[i][0] <= mergedMeetings.back()[1]) {
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meetings[i][1]);
            } else {
                mergedMeetings.push_back(meetings[i]);
            }
        }

        int count = 0;
        // Count the number of free days
        for(int i = 0; i < mergedMeetings.size(); i++) {
            if(i == 0) {
                count += mergedMeetings[i][0] - 1;
            } else {
                count += mergedMeetings[i][0] - mergedMeetings[i - 1][1] - 1;
            }
        }
        // Add the days after the last meeting
        count += days - mergedMeetings.back()[1];

        return count;
    }
};
