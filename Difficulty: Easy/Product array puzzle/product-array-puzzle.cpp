class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        // find no. of zeroes
        int idx;
        vector<int>output(arr.size(),0);
        int product=1;        
        int zeroes =0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zeroes++;
                idx = i;
            }else{
                product *= arr[i];
            }
            
            
        }

        if(zeroes==0){
            for(int i=0;i<arr.size();i++){
                output[i]=product/arr[i];
            }
            
        }
        
        if(zeroes==1){
            for(int i=0;i<arr.size();i++){
                if(i==idx){
                    output[i] = product;
                }else{
                    output[i]=0;
                }
            }
            
        }

        return output;
            
    }
};
