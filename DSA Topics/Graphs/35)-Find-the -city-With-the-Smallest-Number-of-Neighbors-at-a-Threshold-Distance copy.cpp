// FLoyd Warshal method
class Solution {
    private:
    void floydWarshallAlgorithm(vector<vector<int>> &matrix){

        int n=matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(i==j){
	                matrix[i][j]=0;
	            }
	        }
	    }
	    
        // via k
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	}
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> matrix(n,vector<int> (n,1e9));
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            matrix[u][v]=wt;
            matrix[v][u]=wt;
        }
        
        floydWarshallAlgorithm(matrix);
        
        int minCnt=INT_MAX,ans=0;
        for(int i=0;i<n;i++){
            // for each city check if threshold to ni cross ho gaya
            int cnt=0,flag=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            
            // // For min no of cities
            // if(cnt<minCnt){
            //     minCnt=cnt;
            //     ans=i;
            // }
            // // If equal return maximum vertex
            // else if(cnt==minCnt){
            //     ans=max(ans,i);
            // }
            
            
            //Or ham loop laga rahe hain to naya city agar aega to bada hi hoga so seedhe ye likh do
            
            // For min no of cities
            if(cnt<=minCnt){
                minCnt=cnt;
                ans=i;
            }
        }
        return ans;
    }
};