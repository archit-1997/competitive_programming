/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

Solution :

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> storage;
        vector<int> dummy;
        for(int i=0;i<nums.size();i++){
            cout<<target-nums[i]<<" ";
            if(storage.find(nums[i])!=storage.end()){
                // found
                vector<int> ans = {storage[nums[i]],i};
                return ans;
            }
            else{
                // not found
                storage.insert({target-nums[i],i});
            }
        }
        return dummy;
    }
};
