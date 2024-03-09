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
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        while (i<nums1.size() && j<nums2.size()){
            if (nums1[i] == nums2[j]){
                return nums1[i];
            }
            else if (nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};

int main(){
    int n1;
    cin >> n1;
    vector<int> nums1 = input(n1);
    int n2;
    cin >> n2;
    vector<int> nums2 = input(n2);

    Solution s;
    cout << s.getCommon(nums1, nums2) << endl;
}