// 2336. Smallest Number in Infinite Set

// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

// Implement the SmallestInfiniteSet class:

// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
// int popSmallest() Removes and returns the smallest integer contained in the infinite set.
// void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.

Approach

a) Current Counter rakh lo usko increase karte rahna jab bhi call ho
b) lekin agar koi banda current se kam hai to use set mein dal do
c) Aur dekhna ki set empty to ni hai agar empty hai to seedhe return kar sakte counter
d) Otherwise set mein choti value hai use return kar dena
e) Set hi kyun because hame repeated values ni chahiye

class SmallestInfiniteSet {
private:
    set<int> st;
    int currSmallest;
public:
    SmallestInfiniteSet() {
        currSmallest=1;
    }
    
    int popSmallest() {
       if(!st.empty()){
           auto smallest=*st.begin();
           st.erase(smallest);
           return smallest;
        }
        return currSmallest++;
    }
    
    void addBack(int num) {
        if(num<currSmallest){
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */