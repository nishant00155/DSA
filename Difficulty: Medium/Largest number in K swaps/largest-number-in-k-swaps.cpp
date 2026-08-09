

// class Solution {
//   public:
//     // Function to find the largest number after k swaps.
//     void findLargest(int i,char& num,int& idx ,string& s){
        
        
//         for(int p=i;p<s.size();p++){
//             if((s[p]-'0')>(num -'0')){
//                 num = s[p];
//                 idx = p;
//             }
//         }
//     }
//     string findMaximumNum(string& s, int k) {
       
        
//         int rev = 0;
//         priority_queue<int> pq;
//         priority_queue<int, vector<int>, greater<int>> rs;
//         vector<int>arr;
//         for(int l = 0;l<=k;l++){
//             int idx = l;
//              char num = '0';
//             findLargest(l,num,idx,s);
            
            
//             if(l!=idx){
                
//                 pq.push(s[l]-'0');
//                 pq.push(num-'0');
//                 rs.push(l+rev);
//                 rs.push(idx+rev);
//                 s.erase(idx,1);
//                 s.erase(l,1);
                
//                 l--;
//                 k--;
//                 rev++;
//             }else{
//                 k++;
//             }
//         }
//         for(int i = 0;i<2*rev;i++){
//             s.insert(rs.top(),to_string(pq.top()));
//             rs.pop();
//             pq.pop();
            
//         }
        
        
//         return s;
//     }
// };


class Solution {
public:

    void solve(int i, int k, string &s, string &ans) {

        // If current number is larger, save it
        if (s > ans) {
            ans = s;
        }

        // No swaps left
        if (k == 0 || i == s.size()) {
            return;
        }

        // Find the maximum digit from i onwards
        char mx = s[i];

        for (int j = i + 1; j < s.size(); j++) {
            mx = max(mx, s[j]);
        }

        // If current digit is already maximum,
        // no useful swap is needed here.
        if (mx == s[i]) {
            solve(i + 1, k, s, ans);
            return;
        }

        // Try swapping with every occurrence
        // of the maximum digit
        for (int j = i + 1; j < s.size(); j++) {

            if (s[j] == mx) {

                swap(s[i], s[j]);

                solve(i + 1, k - 1, s, ans);

                // Undo swap (backtracking)
                swap(s[i], s[j]);
            }
        }
    }

    string findMaximumNum(string &s, int k) {

        string ans = s;

        solve(0, k, s, ans);

        return ans;
    }
};
