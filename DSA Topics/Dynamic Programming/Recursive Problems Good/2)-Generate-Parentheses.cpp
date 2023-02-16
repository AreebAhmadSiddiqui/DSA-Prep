Maine ye socha ki recursion se solve karte hai

a) Dekho hamare paas kuch no of ( , ) honge
b) to kya kya case ban sakte unhe likh do agar ( , ) in dono ka cnt barabar hua to tumhe ( kholna hi padega
c) baaki mein tumhare paas choice hai ki (,  ya to ye ) khol do
d) lekin agar kisi bhi waqt ( zero ho jae to samjh lena ab tumhe sab band kar na hai 
e) To kya ) kabhi ( isse pehle khatam ni hoga?? answer is no kyunki jab bhi wo kam ho raha hoga ( iske barabar a jaega to fir se ( open ho jaega

class Solution {
private:
    void help(int rightOpen,int leftOpen,vector<string> &ans,string s){
        if(rightOpen==0 ){ // it means you need to close all the brackets
            while(leftOpen--){
                s+=")";
            }
            ans.push_back(s);
            return;
        }

        if(rightOpen==leftOpen){ // it means you have to open a new bracket
            help(rightOpen-1,leftOpen,ans,s+"(");
        }else{
            // Two choices
            // Open
            help(rightOpen-1,leftOpen,ans,s+"(");
            
            // Close
            help(rightOpen,leftOpen-1,ans,s+")");
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        help(n,n,ans,""); // {cnt of (, cnt of ), ans, ""}
        
        return ans;
    }
};