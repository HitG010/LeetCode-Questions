#include <iostream>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = (n*(n+1))/2;
        int sum = 0;
        for(int i = 1;i<=n;i++){
            sum+=i;
            if (sum == totalSum - sum + i){
                return i;
            }
        } 
        return -1;
    }
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol.pivotInteger(n) << endl;
}