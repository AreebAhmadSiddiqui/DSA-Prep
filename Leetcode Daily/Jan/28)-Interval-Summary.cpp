// tumhe stream of integers dega aur tumhe unhe intervals mein merge karna hai intervals mein merge tabhi kar paoge jab diff 1 ka hoga kyunki consecutive hai

// Example

stream      Interval
1           [1,1]
1,3         [1,1][3,3]
1,3,7       [1,1][3,3][7,7] yahan 1 aur 3 ko merge ni kar sakte as 2 ni hai
1,3,7,2     [1,3][7,7]  kyunki 2 aur 3 ke beech mein ata hai

in streams ko sort karne ke liye set use kar lo aur jab tak consecutive ka diff 1 hai tab tak interval mein add karte jao aur jaise hi khatam ho jae naya interval start kar do
class SummaryRanges {
    set<int> st;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        
        int start=*st.begin();
        int end=*st.begin();
        for(auto it=++st.begin();it!=st.end();it++){
            auto curr=*it;
            if(curr-end==1){
                end=curr;
            }else{
                ans.push_back({start,end});
                start=curr;
                end=curr;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */