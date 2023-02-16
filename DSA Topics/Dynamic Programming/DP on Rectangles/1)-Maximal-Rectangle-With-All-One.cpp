class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> nse(heights.size(),0);
        
        
        // Next Smaller Index to The Left;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]= st.empty() ? 0 :st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        // Next Smaller Index to the Right
        
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]= st.empty() ? heights.size()-nse[i] : st.top()-nse[i];
            st.push(i);
        }
        
        int ans=-1;
        for(int i=0;i<heights.size();i++){
            int area=nse[i]*heights[i];
            ans=max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int ans=0;
        vector<int> temp(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    temp[j]++;
                }else{
                    temp[j]=0;
                }        
            }
            int sum=largestRectangleArea(temp);
            ans=max(ans,sum);
        }
        
        return ans;
    }
};