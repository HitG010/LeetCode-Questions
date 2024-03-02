#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int i = 0;
        int j = nums.size()-1;
        int k = j;

        while(i<=j){
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];
            if (a<b){
                ans[k] = b;
                j--;
            }
            else{
                ans[k] = a;
                i++;
            }
            k--;
        }
        return ans;
    }
};