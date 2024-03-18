#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int end = points[0][1];
        int ans = 0;
        for (int i = 1;i<points.size();i++){
            if (points[i][0]>end){
                ans++;
                end = points[i][1];
            }
            else{
                end = min(end, points[i][1]);
            }
        }
        ans++;
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0;i<n;i++){
        cin >> points[i][0] >> points[i][1];
    }
    Solution sol;
    cout << sol.findMinArrowShots(points) << endl;
    return 0;
}