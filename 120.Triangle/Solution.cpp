#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev = triangle.back();
        vector<int> curr = prev;
        curr.pop_back();
        for (int i = n-2;i>=0;i--){
            for (int j = 0;j<curr.size();j++){
                curr[j] = triangle[i][j] + min(prev[j], prev[j+1]);
            }
            prev = curr;
            curr.pop_back();
        }
        return prev[0];
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for(int i=0; i<n; i++){
        int m = i + 1;
        vector<int> temp(m);
        for (int j = 0;j<m;j++){
            cin >> temp[j];
        }
        triangle[i] = temp;
    }
    Solution obj;
    cout << obj.minimumTotal(triangle) << endl;
    return 0;
}