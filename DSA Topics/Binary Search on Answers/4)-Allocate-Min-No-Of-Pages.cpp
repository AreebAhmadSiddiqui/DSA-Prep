class Solution 
{
    private:
    bool canAllocate(int pages,int A[],int M,int N){
        int partitions=1;
        int total=0;
        
        for(int i=0;i<N;){
            if(total+A[i]<=pages){
                total+=A[i];
                i++;
            }
            else{
                partitions++;
                total=0;
            }
        }
        return partitions<=M;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int start=A[0],end=0;
        
        if(N<M) return -1;
        
        for(int i=0;i<N;i++){
            start=max(start,A[i]);
            end+=A[i];
        }
        
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(canAllocate(mid,A,M,N)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return ans;
    }
};