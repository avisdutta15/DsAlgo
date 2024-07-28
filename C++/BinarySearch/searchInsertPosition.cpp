#include <bits/stdc++.h>

using namespace std;

/*
    Given a sorted array of distinct integers and a target value, return the index if the target is found. 
    If not, return the index where it would be if it were inserted in order.

    Input: nums = [1,3,5,6], target = 5
    Output: 2

    Input: nums = [1,3,5,6], target = 2
    Output: 1

    Input: nums = [1,3,5,6], target = 7
    Output: 4

    Constraints:

        . 1 <= nums.length <= 104
        . -104 <= nums[i] <= 104
        . nums contains distinct values sorted in ascending order.
        . -104 <= target <= 104

    Approach:
    So it basically asks to find 
        if x is present then the index i such that A[i] == x {2 in example 1}
        if x is not present then the smallest index i such that A[i] > x {1 in example 2}
        therefore combining the above 2, it is an index i such that A[i]>=x

    This is a lower bound problem
*/

class Solution{
    public:
        int searchInsertPosition(vector<int> &A, int x){
            return lower_bound(A.begin(), A.end(), x) - A.begin();
        }
};

int main(){
    Solution obj;

    vector<int> nums = {1,3,5,6};
    cout<<obj.searchInsertPosition(nums, 5)<<endl;

    cout<<endl;

    cout<<obj.searchInsertPosition(nums, 2)<<endl;

    cout<<endl;

    cout<<obj.searchInsertPosition(nums, 7)<<endl;
}