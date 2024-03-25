#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        vector<int> ans;
        for (int i = 0;i<n;i++){
            int a = nums[i];
            if (a<0){
                a*=-1;
            }
            if (nums[a]<0){
                ans.push_back(a);
            }
            else{
                nums[a] = -1*nums[a];
            }
            // cout<<nums[a];
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    Solution obj;
    vector<int> ans = obj.findDuplicates(nums);
    for (int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}