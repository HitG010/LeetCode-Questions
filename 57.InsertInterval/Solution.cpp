#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool flag = true;
        for (int i = 0;i<intervals.size();i++){
            if (flag && (newInterval[0]<=intervals[i][0] || newInterval[0]<=intervals[i][1])){
                vector<int> interval;
                interval.push_back(min(newInterval[0], intervals[i][0]));
                if (newInterval[1]<intervals[i][0] && newInterval[1]<intervals[i][1]){
                    interval.push_back(newInterval[1]);
                    ans.push_back(interval);
                    ans.push_back(intervals[i]);
                    flag = false;
                    continue;
                }
                while(i<intervals.size()-1 && intervals[i+1][0]<=newInterval[1]){
                    i++;
                }
                interval.push_back(max(newInterval[1], intervals[i][1]));
                ans.push_back(interval);
                flag = false;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        if (flag){
            ans.push_back(newInterval);
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0;i<n;i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    Solution sol;
    vector<vector<int>> ans = sol.insert(intervals, newInterval);
    for (int i = 0;i<ans.size();i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}