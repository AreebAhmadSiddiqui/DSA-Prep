1386. Cinema Seat Allocation

A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.
    

Thought Process

a) Agar tum dhyan se dekho to sirf atmost 2 hi possible families ko baitha sakte ho tum
b) [2,5][6,9] mein 2 ( in dono ko preference kyunki agar ye hua to ham log 2 family baitha sakte hai isliye) ya fir [2,5],[6,9],[4,7] mein agar koi hai to 1 family otherwise 0 family
c) bas har row ko hash map mein store kar lo aur jitne col hai us row main unhe check karlo ki kahin upar wale mein se to ni hai koi aur us hisab se answer le ao
d) lekin ek bada catch bhi hai ho sakta hai n rows hun lekin jo tumhari mp mein rows hai wo n se kam ho tum us case mein jitne rows ni hai matlab (n-map.size()) utni rows main 2 bande baitha sakte ho to baitha dena unhe aur kya

class Solution {
private:
    int getGroupQnt(vector<int> &col){
        
//         vector<int> row(11,1);
//         for(int i=0;i<col.size();i++) row[col[i]]=0;
        
//         // Check if 2 to 5 is present
//         bool op1=true,op2=true,op3=true;
//         for(int i=2;i<=5;i++) if(row[i]==0) op1=false;
        
//         // Check if 6 to 9 is present
//         for(int i=6;i<=9;i++) if(row[i]==0) op2=false;
        
//         // Check if 4 to 7 is present
//         for(int i=4;i<=7;i++) if(row[i]==0) op3=false;
        
        
//         if(op1 && op2) return 2;
//         if(op1 && !op2 || !op1 && op2 || !op1 && !op2 && op3) return 1;
//         return 0;
        
        
        // Optimised Version
        
        
        bool op1=true,op2=true,op3=true;
        for(int i=0;i<col.size();i++) {
            
            // Check if 2 to 5 is present
            if(col[i]>=2 && col[i]<=5) op1=false;
            
            // Check if 6 to 9 is present    
            if(col[i]>=6 && col[i]<=9) op2=false;
            
            // Check if 4 to 7 is present    
            if(col[i]>=4 && col[i]<=7) op3=false;
        }
        
        
        if(op1 && op2) return 2;
        if(op1 || op2 || op3) return 1;
        return 0;   
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0];
            int col=reservedSeats[i][1];
            
            mp[row].push_back(col);
        }
        
        
        // for all the rows in mp check for only
        
        // [2,5],[6,9],[4,7] range because itne mein hi tum baitha sakte ho
        int cnt=0;
        for(auto &it:mp){
            int row=it.first;
            vector<int> col=it.second; // at most 10
            
            cnt+=getGroupQnt(col);
        }
        
        int remainingRows=n-mp.size();
        return cnt+remainingRows*2;
    }
};