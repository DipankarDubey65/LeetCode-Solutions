class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>allInterval;
       bool insert = false;
       int n = intervals.size();
       int newstart = newInterval[0];
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            
            if(insert==false && newstart<=start){
                allInterval.push_back(newInterval);
                insert=true;
            }
                allInterval.push_back(intervals[i]);
        }
        if (!insert) {
            allInterval.push_back(newInterval);
        }
        vector<vector<int>>res;

        int start1 = allInterval[0][0];
        int end1 = allInterval[0][1];
        for(int i=1;i<allInterval.size();i++){
            int start2 = allInterval[i][0];
            int end2 = allInterval[i][1];
            if(end1>=start2){
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            res.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        }
        res.push_back({start1, end1});
        
        
        return res;
    }
};