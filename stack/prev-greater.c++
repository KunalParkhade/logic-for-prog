// Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.

// Examples: 

// Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
// Output :         -1, 10, 4, -1, -1, 40, 40

class Solution {
  public:
    vector<int> prevGreater(vector<int>& arr) {
      stack<int> s;
      vector<int> res;
      s.push(arr[0]);
      res.push_back(-1);

      for(int i=1;i<arr.size();i++){
        while(!s.empty() && s.top()<=arr[i]){
          s.pop();
        }
        if(s.empty()){
          return false;
        }
        else{
          res.push_back(s.top());
        }
        s.push(arr[i]);
      }
      return res;
    }
};
