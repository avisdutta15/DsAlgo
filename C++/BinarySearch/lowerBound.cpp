#include <bits/stdc++.h>

using namespace std;

/*
    Lower Bound:
    Smallest index 'i' such that arr[i] >= x

    arr = [3, 5, 8, 15, 19, 19]
    x   =  8
    ans =  2. Because 2 is the smallest index in arr such that arr[2] = 8 >= 8

    arr = [3, 5, 8, 15, 19, 19]
    x   =  9
    ans =  3. Because 3 is the smallest index in arr such that arr[3] = 15 >= 9

    arr = [3, 5, 8, 15, 19, 19]
    x   =  20
    ans =  6. Because 6 is the smallest index in arr such that arr[6] = which is outside arr >= 20

    arr = [3, 5, 8, 15, 19, 19]
    x   =  19
    ans =  4. Because 4 is the smallest index in arr such that arr[4] = 19 >= 19
 */

class Solution{
    public:
        int lowerBoundSTL(vector<int> &A, int x){
            return lower_bound(A.begin(), A.end(), x) - A.begin();
        }

        int lowerBoundSTLArray(int A[], int n, int x){
            auto lb =  lower_bound(A, A+n, x);
            auto arrbegin = A;
            int ans = lb - arrbegin;
            return ans;
        }

        int lowerBound(vector<int> &A, int x){
            if(A.size() == 0) 
                return -1;
            
            int lo = 0, hi = A.size()-1, mid = 0;
            int ans = A.size();

            while(lo <= hi){
                mid = lo + (hi-lo)/2;

                if(A[mid] >= x){
                    ans = mid;
                    hi = mid - 1;
                }
                else if (A[mid] < x)
                    lo = mid + 1;
            }

            return ans;
        }
};

int main(){
    Solution obj;

    vector<int> A = {3, 5, 8, 15, 19, 19};

    cout<<obj.lowerBound(A, 8)<<endl;
    cout<<obj.lowerBound(A, 9)<<endl;
    cout<<obj.lowerBound(A, 20)<<endl;
    cout<<obj.lowerBound(A, 19)<<endl;

    cout<<endl;
    
    cout<<obj.lowerBoundSTL(A, 8)<<endl;
    cout<<obj.lowerBoundSTL(A, 9)<<endl;
    cout<<obj.lowerBoundSTL(A, 20)<<endl;
    cout<<obj.lowerBoundSTL(A, 19)<<endl;

    cout<<endl;

    int B[] = {3, 5, 8, 15, 19, 19};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<obj.lowerBoundSTLArray(B, n, 8)<<endl;
    cout<<obj.lowerBoundSTLArray(B, n, 9)<<endl;
    cout<<obj.lowerBoundSTLArray(B, n, 20)<<endl;
    cout<<obj.lowerBoundSTLArray(B, n, 19)<<endl;
}