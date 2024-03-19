#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for (int i = 0;i<tasks.size();i++){
            freq[tasks[i] - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0;i<26;i++){
            if (freq[i]>0){
                pq.push(freq[i]);
            }
        }
        // delete freq;

        queue<pair<int, int>> cooling;
        
        int time = 0;

        while (!(pq.empty() && cooling.empty())){
            time++;
            if (!cooling.empty()){
                pair<int, int> p = cooling.front();
                if (p.second == time){
                    cooling.pop();
                    pq.push(p.first);
                }
            }
            if (!pq.empty()){
                int a = pq.top();
                pq.pop();
                if (a>1)
                    cooling.push({a-1, time+n+1});
            }
        }
        return time;
    }
};

int main(){
    int n;
    cin >> n;
    vector<char> tasks(n);
    for (int i = 0;i<n;i++){
        cin >> tasks[i];
    }
    Solution sol;
    int coolDown;
    cin >> coolDown;
    cout << sol.leastInterval(tasks, coolDown);
}