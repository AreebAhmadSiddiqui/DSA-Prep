2718. Sum of Matrix After Queries

You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].

Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:

if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
Return the sum of integers in the matrix after all queries are applied.
    
Approach

a) Jo Last mein aya hai wohi to final answer mein hoga to reverse se shuru karo
b) Aur agar koi col ya row le liya hai to use Mark kardo ki ye wala ho gaya hai ise na lo
c) Aur dekho row ke sum ki value wahi hogi val ko utne baar add karoge jinte jagah ho
d) matlab agar 2 col pehle bhar chuke hai to is row mein sirf 1 hi jagah bachi ( Ex of n=3) isliye rowSum mein n-colsAlreadyTaken multiply kiya
e) Aur Col wale mein reverse


class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> rowsAndCol(n+n,-1);
        
        long long sum=0;
        
        int size=queries.size();
        
        int rowsAlreadyTaken=0,colsAlreadyTaken=0;
        
        for(int i=size-1;i>=0;i--){
            int type=queries[i][0];
            int idx=queries[i][1];
            int val=queries[i][2];
            
            if(type==0){
                if(rowsAndCol[idx]==-1){
                    sum+=(val*1ll*(n-colsAlreadyTaken));
                    rowsAndCol[idx]++;
                    rowsAlreadyTaken++;
                }
            }else{
                if(rowsAndCol[n+idx]==-1){
                    sum+=(val*1ll*(n-rowsAlreadyTaken));
                    rowsAndCol[n+idx]++;
                    colsAlreadyTaken++;
                }
            }
        }
        return sum;
    }
};