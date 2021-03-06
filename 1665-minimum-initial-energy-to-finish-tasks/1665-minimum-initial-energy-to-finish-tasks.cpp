class Solution {
public:
    
int minimumEffort(vector<vector<int>>& tasks) {
    int energy = 0, res = 0;
    sort(begin(tasks), end(tasks), [](vector<int> &t1, vector<int> &t2) 
         { return t1[1] - t1[0] > t2[1] - t2[0]; });
    for (auto &t : tasks) {
        res += max(0, t[1] - energy);
        energy = max(energy, t[1]) - t[0];
    }
    return res;
}
};