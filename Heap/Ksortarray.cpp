// https://www.geeksforgeeks.org/problems/k-sorted-array1610/1

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<pair<int,int>> idx;
        for(int i = 0; i < n ; i++) idx.push_back({arr[i],i});
        sort(idx.begin(),idx.end());
        for(int i = 0; i < n ;i++){
            if(abs(idx[i].second - i) > k) return "No";
        }
        return "Yes";
    }
};