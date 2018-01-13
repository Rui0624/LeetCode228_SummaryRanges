//
//  main.cpp
//  LeetCode228_SummaryRanges
//
//  Created by Rui on 1/12/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0;
        
        while(i < n)
        {
            int j = 1;
            while(i + j < n && nums[i + j] - nums[i] == j) //if i + j < n which means not over bound, and nums[i + j] - nums[i] ==j means from nums[i] to nums[i + j] is ++1
                j++;
            
            //if j <= 1, which means in the subrange has only one element, just push this element into the result, else means it has more than 1, so that we need to use the -> to connnect the nums to show the ranges
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j -1]));
            
            i += j;
        }
        
        return res;
    }
};
