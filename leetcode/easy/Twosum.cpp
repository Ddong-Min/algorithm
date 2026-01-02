class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]]=i;
        }
        return {-1, -1};
    }
};


/*

using hash map is about 42ms faster than using double for statement
becuase timecomplexity of double for statement is o(n^2) but hash map is o(n)

the cause of this is unordered_map's hash function's time complexity is o(1).
*/