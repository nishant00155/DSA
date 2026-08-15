class Solution {
public:
    bool findPair(vector<int> &arr, int x) {
        sort(arr.begin(), arr.end());
        

        
        for(int k=arr.size()-1 ; arr[k]>=x && k>=0 ; k--){
         int target = arr[k] -x;   
         int i=0;
         int j=arr.size()-1;
            if(x==0){
                while(i<arr.size()){
                  if(arr[i]==arr[i+1])return true;
                i++;  
                }
                if(i==arr.size()) return false;
                
            }else{
               while(j>=i){
            int m = i + (j-i)/2;
             if(target == arr[m]){
                 return true;
                 
             }
             if(target > arr[m]){
                 i = m+1;
                 
             }if(target < arr[m]){
                 j = m-1;
                 
             }
         } 
            }
         
        }
        return false;
    }
};

