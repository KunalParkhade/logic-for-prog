// Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// Examples

// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> s;
        vector<int> res;
        s.push(arr[arr.size()-1]);
        res.push_back(-1);
        
        for(int i=arr.size()-2;i>=0;i--){
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            int result = s.empty()?-1:s.top();
            res.push_back(result);
            s.push(arr[i]);
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
