class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int value =-1;
        for(int i=0 ;i< arr.size();i++){
            if(arr[i]>=x){
                value = i;
                return value;
            }
        }
        return value;
    }
};