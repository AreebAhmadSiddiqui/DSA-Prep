class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> probableAnswer(n+1,0); // -1 means he is not a judge
        
        for(int i=0;i<trust.size();i++){
            int a=trust[i][0];
            int b=trust[i][1];
            
            // a is definitely not a judge
            // b can be a judge
            probableAnswer[a]=-1; // mark a as not a judge
            if(probableAnswer[b]!=-1) // -1 means he is not a judge so dont increase its value
                probableAnswer[b]++;
        }
        
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(probableAnswer[i]==n-1){ // he should be known to every n-1 persons
                ans=i;
                break;
            }
        }
    
        return ans;
    }
};

class Solution 
{
    
    public:
    int knows(int a,int b,vector<vector<int>> &M){
        return M[a][b];
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int> st;
       
       for(int i=0;i<n;i++) st.push(i);
       
       while(st.size()!=1){
           int a=st.top();
           st.pop();
           int b=st.top();
           st.pop();
           
           if(knows(a,b,M)){ // a knows b , a cannot be a celeb
               st.push(b);
           }else{
               st.push(a);
           }
       }
       
       int probAns=st.top();
       st.pop();
       // last Check
       for(int j=0;j<n;j++){
           if(probAns!=j && (knows(probAns,j,M) || !knows(j,probAns,M))){
               return -1;
           }
       }
       
       return probAns;
    }
};