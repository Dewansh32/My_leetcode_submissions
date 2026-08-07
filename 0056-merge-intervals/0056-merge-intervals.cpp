class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });

        vector<vector<int>> ans;

        int n = intervals.size();

        int min_i = intervals[0][0];
        int max_i = intervals[0][1];

        for (int i = 1; i < n; i++) {

            // Overlapping interval
            if (intervals[i][0] <= max_i) {
                max_i = max(max_i, intervals[i][1]);
            }

            // No overlap
            else {
                ans.push_back({min_i, max_i});

                min_i = intervals[i][0];
                max_i = intervals[i][1];
            }
        }

        // Push the last merged interval
        ans.push_back({min_i, max_i});

        return ans;
    }
};