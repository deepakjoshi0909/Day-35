class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>mp;
        for(char ch : s){
            mp[ch]++;
        }

        vector<int>freqArr;
        for(auto it: mp){
            freqArr.push_back(it.second);
        }

        sort(freqArr.begin(),freqArr.end(),greater<int>());

        int deleteCnt = 0;
        unordered_set<int>seen;

        for(int freq: freqArr){
            while(freq > 0 && seen.find(freq) != seen.end()){
                freq--;
                deleteCnt++;
            }
            seen.insert(freq);
        }
        return deleteCnt;


    }
};
