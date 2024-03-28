#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int temp = 1;
        while(end<nums.size()){
            temp*=nums[end];
            while(start<=end && temp>=k){
                temp/=nums[start];
                start++;
            }

            ans += (end-start)+1;
            end++;
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
    int k;
    cin >> k;
    Solution obj;
    cout << obj.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}