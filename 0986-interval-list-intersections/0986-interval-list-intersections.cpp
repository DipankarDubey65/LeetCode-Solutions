class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& firstList,
        vector<vector<int>>& secondList
    ) {
        vector<vector<int>> res;

        int i = 0;
        int j = 0;

        int n = firstList.size();
        int m = secondList.size();

        while (i < n && j < m) {

            int s1 = firstList[i][0];
            int e1 = firstList[i][1];

            int s2 = secondList[j][0];
            int e2 = secondList[j][1];

            // Find intersection
            int start = max(s1, s2);
            int end = min(e1, e2);

            // Intersection exists
            if (start <= end) {
                res.push_back({start, end});
            }

            // Move the interval which ends first
            if (e1 < e2) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};