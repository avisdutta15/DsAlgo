#include<bits/stdc++.h>

using namespace std;

/*
    Upper Bound:
    Smallest index 'i' such that arr[i] > x

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
    ans =  6. Because 6 is the smallest index in arr such that arr[6] = which is outside arr >= 19
 */


class Solution{
    public:
        int upperBoundSTL(vector<int> &A, int x){
            return upper_bound(A.begin(), A.end(), x) - A.begin();
        }

        int upperBoundSTLArray(int A[], int n, int x){
            return upper_bound(A, A+n, x) - A;
        }

        int upperBound(vector<int> &A, int x){
            if(A.size()==0) return -1;

            int lo = 0, hi = A.size()-1, mid = 0;
            int ans = A.size();

            while(lo <= hi){
                mid = lo + (hi - lo) / 2;

                if(A[mid] > x){
                    ans = mid;
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }
            return ans;
        }
};

int main(){
    Solution obj;
    
    vector<int> A = {3, 5, 8, 15, 19, 19};

    cout<<obj.upperBound(A, 8)<<endl;
    cout<<obj.upperBound(A, 9)<<endl;
    cout<<obj.upperBound(A, 20)<<endl;
    cout<<obj.upperBound(A, 19)<<endl;

    cout<<endl;
    
    cout<<obj.upperBoundSTL(A, 8)<<endl;
    cout<<obj.upperBoundSTL(A, 9)<<endl;
    cout<<obj.upperBoundSTL(A, 20)<<endl;
    cout<<obj.upperBoundSTL(A, 19)<<endl;

    cout<<endl;

    int B[] = {3, 5, 8, 15, 19, 19};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<obj.upperBoundSTLArray(B, n, 8)<<endl;
    cout<<obj.upperBoundSTLArray(B, n, 9)<<endl;
    cout<<obj.upperBoundSTLArray(B, n, 20)<<endl;
    cout<<obj.upperBoundSTLArray(B, n, 19)<<endl;
}