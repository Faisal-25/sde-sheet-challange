class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&v1, vector<int>&v2){
            return v1[0]<v2[0];
        });
        int prevMax = intervals[0][1];
        int prevMin = intervals[0][0];
        cout<<prevMin<<" ";
        vector<vector<int>> ans;
        for(int i = 1;i<intervals.size();i++){
            cout<<prevMin<<" ";
            if(intervals[i][0]>prevMax){
                ans.push_back({prevMin,prevMax});
                prevMin = intervals[i][0];
                prevMax = intervals[i][1];
            }
            prevMax = max(intervals[i][1],prevMax);
        }
        ans.push_back({prevMin,prevMax});
        return ans;
    }
};