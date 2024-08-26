class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        int maxFreq = 0;

        for(int task: tasks){
            mp[task]++;
            maxFreq = max(maxFreq,mp[task]);
        }

        int maxCount = 0;
        for(auto it: mp){
            if(it.second == maxFreq){
                maxCount++;
            }
        }

        int partCount = maxFreq - 1;
        int partLength = n - (maxCount -1);
        int empty = partCount * partLength;
        int available = tasks.size() - maxFreq * maxCount;
        int idel = max(0,empty -  available);

        return tasks.size() + idel;
    }
};
