class Solution {
  public:
  TC-> O(n*n*n)
  SC-> O(n*n)

//   Floyd warshal ek multisource algorith hai
//   disjkstra lagana hai to sabhi nodes se ek ek baar laga dena
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    
	    int n=matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
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
	    
	    // Aur agar negative cycle detect karni hai to ye kardena
	    
	   // Tumne jab via k wala method lagaya to agar koi negative cycle hogi i,i wala negative ho gaya hoga
	   // Are cycle ka matlab kya hai tum usi node pe dobar a gae to negative cycle ka matlba kya hai cycle negative hai 
       // Dijstra laga skate ho sare nodes ko source banake
	   for(int i=0;i<n;i++){
	       if(matrix[i][j]<0) return "Negative Cycle"
	   }
	   
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
};