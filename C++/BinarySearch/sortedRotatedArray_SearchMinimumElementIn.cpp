#include <bits/stdc++.h>

using namespace std;

/*
    Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
    For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array 
    [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the minimum element of this array.

    Example 1:
    Input: nums = [3,4,5,1,2]
    Output: 1
    Explanation: The original array was [1,2,3,4,5] rotated 3 times.
    
    Example 2:

    Input: nums = [4,5,6,7,0,1,2]
    Output: 0
    Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
    
    Example 3:
    Input: nums = [11,13,15,17]
    Output: 11
    Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 */

class Solution{
    public:
        //Dont use this as it is a bit hacky (we need to check the right portion first to check the sorted condition). 
        //From Aditya Verma: https://www.youtube.com/watch?v=4WmTRFZilj8&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=7
        int minimumElementInSortedRotatedArrayApproach1(vector<int> &A){
            if(A.size() == 0)
                return -1;

            int N = A.size();

            //Edge case: if the array is sorted
            if(A[0] <= A[N-1])
                return A[0];

            //minimum element will be smaller than elements at index-1 and index+1
            int lo = 0, hi = N-1, mid = 0;
            while(lo <= hi){
                mid = lo + (hi - lo)/2;
                int prev_elem = (mid - 1 + N) % N;
                int next_elem = (mid + 1) % N;

                if(A[mid] < A[prev_elem] && A[mid] < A[next_elem]){
                    return A[mid];
                }

                //if A[mid...hi] is sorted and mid is not the smallest element, then discard A[mid..hi] and search left.
                if(A[mid] < A[hi])
                    hi = mid - 1;                    
                else //if A[lo...mid] is sorted then the smallest element cannot lie in this range, so discard A[lo..mid] and search right.
                     //we are sure that A[lo..mid] will not contain the smallest element as the array is rotated more than 0 number of times.
                     //The case where the array is rotated 0 number of times, i.e. sorted, is handled above the while loop.
                    lo = mid + 1;
            }
            return -1;
        }
        

        /*
            The trick in the below approach is we divide the array into 2 parts.
            Then check which part is sorted. Take the smallest element from the sorted part and store it in ans if it is smallest till now.
            Then we can safely ignore this sorted part as we have already processed the smallest from this part.
            Hence we go to the unsorted part and continue.

            Atlast we return the smallest element till now stored in ans.
            From Striver: https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=7
         */
        int minimumElementInSortedRotatedArrayApproach2(vector<int> &A){
            if(A.size() == 0)
                return -1;

            int lo = 0, hi = A.size()-1, mid = 0, ans = INT_MAX;

            while(lo <= hi){
                mid = lo + (hi - lo) / 2;

                if(A[lo] <= A[mid]) {   //why '=' ? Because when lo == mid 
                    ans = min(ans, A[lo]);
                    lo = mid + 1;
                }else{
                    ans = min(ans, A[mid]);
                    hi = mid - 1;
                }
            }
            return ans;
        }

};

int main(){
    Solution obj;
    vector<int> A = {11, 12, 15, 18, 2, 5, 6, 8};

    cout<<obj.minimumElementInSortedRotatedArrayApproach1(A)<<endl;
    cout<<obj.minimumElementInSortedRotatedArrayApproach2(A)<<endl;


    A = {3,4,5,1,2};
    cout<<obj.minimumElementInSortedRotatedArrayApproach2(A)<<endl;

    A = {4,5,6,7,0,1,2};
    cout<<obj.minimumElementInSortedRotatedArrayApproach2(A)<<endl;

    A = {11,13,15,17};
    cout<<obj.minimumElementInSortedRotatedArrayApproach2(A)<<endl;

    A = {2, 1}; //For this example we can debug to find the ans why '=' during sorted part consideration.
                //here lo = mid. So we need to check A[lo] <= A[mid] and not lo < mid.
    cout<<obj.minimumElementInSortedRotatedArrayApproach2(A)<<endl;
}