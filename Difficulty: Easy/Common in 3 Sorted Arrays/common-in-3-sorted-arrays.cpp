class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        unordered_map<int, int> map;
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            if(i<a.size()-1){
               if(a[i+1]!=a[i]){
                map[a[i]]++; 
            } 
            }else{
                map[a[i]]++; 
            }
            
           
        }
        for(int i=0;i<b.size();i++){
            if(i<b.size()-1){
               if(b[i+1]!=b[i]){
                map[b[i]]++; 
            } 
            }else{
                map[b[i]]++; 
            }
            
           
        }
        
        for(int i=0;i<c.size();i++){
            if(i<c.size()-1){
              if(c[i+1]!=c[i]){
                map[c[i]]++;
            }  
            }else{
                map[c[i]]++; 
            }
            
           
        }
        
        for(auto &i:map){
            if(i.second >=3){
                ans.push_back(i.first);
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};