#include <iostream>
#include <vector>
#include <queue>
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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue <int, vector<int>,greater<int> > pq;
        for (int i = 0;i<k;i++){
            pq.push(happiness[i]);
        }
        for (int i =k;i<happiness.size();i++){
            if (pq.top()<happiness[i]){
                pq.pop();
                pq.push(happiness[i]);
            }
        }
        
        long long int ans = 0;
        
        for (int i = k-1;i>=0;i--){
            int a = pq.top()-i;
            if (a>=0){
                ans+=pq.top()-i;
            }
            pq.pop();
        }
        return ans;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> happiness = input(n);
    Solution s;
    cout << s.maximumHappinessSum(happiness, k) << endl;
    return 0;
}