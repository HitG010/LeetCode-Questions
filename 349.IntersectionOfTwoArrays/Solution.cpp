#include <iostream>
#include <vector>
using namespace std;

vector<int> input(int n){
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0;
        int j = 0;
        vector<int> ans;

        while(i<nums1.size() && j<nums2.size()){
            if (nums1[i] == nums2[j]){
                int a = nums1[i];
                ans.push_back(a);
                while(i<nums1.size() && j<nums2.size() && nums1[i] == a && nums2[j] == a){
                    i++;
                    j++;
                }
            }
            else if (nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums1 = input(n);
    vector<int> nums2 = input(m);
    Solution s;
    vector<int> ans = s.intersection(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}