class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int l =0;
        
        for(int i=0; i<arr.size()-2; i++){
            if(arr[i]==arr[i-1]) i++;
            int j=i+1;
            int k=arr.size()-1;
            while(j<k){
                arr[i]+arr[j]+arr[k];
                if(arr[i]+arr[j]+arr[k]>=sum){
                    k--;
                } 
                if(arr[i]+arr[j]+arr[k]<sum){
                    l+= k-j;
                    j++;
                }
            }
            
        }
        return l;
    }
};