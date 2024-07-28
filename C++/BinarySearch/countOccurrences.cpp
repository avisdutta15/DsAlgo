#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int findFirstOccurence(vector<int> &A, int x){
            int lo = 0, hi = A.size()-1, mid = 0, ans = -1;
            while(lo <= hi){
                mid = lo + (hi - lo) / 2;
                if(A[mid] == x){
                    ans = mid; 
                    hi = mid - 1;
                }
                if(A[mid] < x)
                    lo = mid + 1;
                else 
                    hi = mid - 1;
            }
            return ans;
        }

        int findLastOccurence(vector<int> &A, int x){
            int lo = 0, hi = A.size()-1, mid = 0, ans = A.size();
            while(lo <= hi){
                mid = lo + (hi - lo) / 2;
                if(A[mid] == x){
                    ans = mid; 
                    lo = mid + 1;
                }
                if(A[mid] < x)
                    lo = mid + 1;
                else 
                    hi = mid - 1;
            }
            return ans;
        }

    public:
        int countOccurences(vector<int> &A, int x){
            if(A.size() == 0 || x < A[0] || x > A[A.size()-1])
                return 0;
            
            int first = findFirstOccurence(A, x);
            if(first == -1)
                return 0;
            int last = findLastOccurence(A, x);
            return (last - first) + 1;
        }
};

int main(){
    Solution obj;
    vector<int> A = {5, 7, 7, 8, 8, 10};

    cout<<obj.countOccurences(A, 8)<<endl;
    cout<<obj.countOccurences(A, 7)<<endl;
    cout<<obj.countOccurences(A, 11)<<endl;
    cout<<obj.countOccurences(A, 4)<<endl;
    cout<<obj.countOccurences(A, 6)<<endl;
    cout<<obj.countOccurences(A, 10)<<endl;
}