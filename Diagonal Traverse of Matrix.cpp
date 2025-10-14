class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m=mat.size();
        int n=mat[0].size();
        int cnt=0;
        //traverse rows
        for(int col=0 ; col<n ; col++){
            int i=0,j=col;
            if(cnt%2==0){
                //bottom to top
                stack<int> st;
                while(i<m && j>=0){
                    st.push(mat[i][j]);
                    i++;
                    j--;
                }
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            else{
                //top to bottom
                while(i<m && j>=0){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
            cnt++;
        }
        //traverse columns
        for(int rows=1 ; rows<m ; rows++){
            int i=rows,j=n-1;
            if(cnt%2==0){
                //bottom to top
                stack<int> st;
                while(i<m && j>=0){
                    st.push(mat[i][j]);
                    i++;
                    j--;
                }
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            else{
                //top to bottom
                while(i<m && j>=0){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
            cnt++;
        }
        return ans;
    }
};
