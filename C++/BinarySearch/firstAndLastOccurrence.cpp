#include <bits/stdc++.h>

using namespace std;

/*
    Given an array of integers nums sorted in non-decreasing order, 
    find the starting and ending position of a given target value.

    If target is not found in the array, return [-1, -1].

    You must write an algorithm with O(log n) runtime complexity.
    
    Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
    
    Example 3:
    Input: nums = [], target = 0
    Output: [-1,-1]
    

    Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109
 */

class Solution{
    private:
        int findFirstOccurence(vector<int> &A, int x){
            int lo = 0, hi = A.size()-1, mid = 0;
            int ans = -1;
            while(lo <= hi){
                mid = lo + (hi-lo)/2;

                if(A[mid] == x){
                    ans = mid;
                    hi = mid-1;
                }
                else if(A[mid] < x)
                    lo = mid + 1;
                else 
                    hi = mid - 1;
            }
            return ans;
        }

        int findLastOccurence(vector<int> &A, int x){
            int lo = 0, hi = A.size()-1, mid = 0;
            int ans = -1;
            while(lo <= hi){
                mid = lo + (hi-lo)/2;
                if(A[mid] == x){
                    ans = mid;
                    lo = mid + 1;
                }
                else if(A[mid] < x)
                    lo = mid + 1;
                else 
                    hi = mid - 1;
            }
            return ans;
        }
    public:
        vector<int> findFirstAndLastOccurence(vector<int> &A, int x){
            //if array is empty of element is out side arrays elements range then return -1,-1
            if(A.size()==0 || x < A[0] || x > A[A.size()-1])
                return vector<int>{-1,-1};

            int first = findFirstOccurence(A, x);
            if(first == -1) return vector<int>{-1,-1};
            int last = findLastOccurence(A, x);
            return vector<int>{first, last};
        }

        //TODO: CHECK HOW LOWER_BOUND AND UPPER_BOUND BEHAVE WHEN ELEMENT NOT PRESENT
        // vector<int> findFirstAndLastOccurenceSTL(vector<int> &A, int x){
        //     if(A.size()==0)
        //         return vector<int> {-1,-1};

        //     int first = lower_bound(A.begin(), A.end(), x) - A.begin();
        //     //if x is not present lower_bound will return A.size()
        //     if(first == A.size() || A[first]!=x)
        //         return vector<int> {-1, -1};

        //     int last = upper_bound(A.begin(), A.end(), x) - A.begin();
        //     if(last == A.size() || A[last-1]!=x)
        //         return vector<int> {-1,-1};
        //     return {first, last-1};
        // }
};

int main(){
    Solution obj;
    vector<int> A = {5,7,7,8,8,10};

    auto ans = obj.findFirstAndLastOccurence(A, 8);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans = obj.findFirstAndLastOccurence(A, 7);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans = obj.findFirstAndLastOccurence(A, 6);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans = obj.findFirstAndLastOccurence(A, 11);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans = obj.findFirstAndLastOccurence(A, 4);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    A = {};
    ans = obj.findFirstAndLastOccurence(A, 0);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    cout<<endl;

    // A = {5,7,7,8,8,10};
    // ans = obj.findFirstAndLastOccurenceSTL(A, 8);
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    // ans = obj.findFirstAndLastOccurenceSTL(A, 7);
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    // ans = obj.findFirstAndLastOccurenceSTL(A, 6);
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    // ans = obj.findFirstAndLastOccurenceSTL(A, 11);
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    // ans = obj.findFirstAndLastOccurenceSTL(A, 4);
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    // A = {};
    // ans = obj.findFirstAndLastOccurenceSTL(A, 0);
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    // A= {2,2};
    // ans = obj.findFirstAndLastOccurenceSTL(A, 3);
    // cout<<ans[0]<<" "<<ans[1]<<endl;
}