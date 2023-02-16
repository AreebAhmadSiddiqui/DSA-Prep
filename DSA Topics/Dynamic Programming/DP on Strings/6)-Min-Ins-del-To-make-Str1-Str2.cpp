class Solution{
    
	public:
	int spaceOptimised(string s1,string s2){
        vector<int> prev(s2.size()+1,0),curr(s2.size()+1,0);
        
       // Base Case
        for(int j=0;j<s2.size();j++) prev[j]=0;
        
        for(int i=1;i<=s1.size();i++){
            curr[0]=0;
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                   curr[j]=1+prev[j-1];
                }
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        
        return prev[s2.size()];
    }
	int minOperations(string str1, string str2) 
	{ 
	   
	    return str1.size()+str2.size()-2*spaceOptimised(str1,str2);
	} 
};