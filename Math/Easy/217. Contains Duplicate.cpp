//https://leetcode.com/problems/contains-duplicate/

/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        set <int> s;
        for(int x:nums){
            s.insert(x);
        }
        int m = s.size();
        return !(n==m);
    }
};
