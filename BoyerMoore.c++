class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        
        if(n == 0) return result;
        
        //Boyer Moore
        int cand1=0, cand2=1;
        int count1=0, count2=0;
        
        //Find candidates for majority
        for(int num:arr){
            if(num==cand1){
                count1++;
            }
            else if(num==cand2){
                count2++;
            }
            else if(count1==0){
                cand1=num;
                count1=1;
            }
            else if(count2==0){
                cand2=num;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        //Verify the candidates
        count1=0, count2=0;
        
        for(int num:arr){
            if(num==cand1) count1++;
            else if(num==cand2) count2++;
        }
        
        if(count1>n/3) result.push_back(cand1);
        if(count2>n/3) result.push_back(cand2);
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
