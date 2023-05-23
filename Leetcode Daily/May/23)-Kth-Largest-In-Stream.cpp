703. Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

// Approach

a) Agar tu min heap banaega to min se end tak aenge pq mein
b) aur tumhe kth largest chahiye to wo right se k peeche hoga
c) Agar k=3 aur pq main abhi 1,2,3 hai isi order mein
d) Lekin agar ek aur banda pq mein add kardiya to 1,2,3,4 ho gaya lekin tumhe to 3 hi bande rakhne hai to jo smallest hai use hata do kyunki uski need ni ab 1,2,3,4 mein right se kth largest will be 2 , 1 ki zarurat ni


class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto &it:nums){
            minHeap.push(it);
            if(minHeap.size()>k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>size) minHeap.pop();
        
        return minHeap.top();
    }
};