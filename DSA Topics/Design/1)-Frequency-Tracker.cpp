Frequency Tracker

Design a data structure that keeps track of the values in it and answers some queries regarding their frequencies.

Implement the FrequencyTracker class.

FrequencyTracker(): Initializes the FrequencyTracker object with an empty array initially.
void add(int number): Adds number to the data structure.
void deleteOne(int number): Deletes one occurence of number from the data structure. The data structure may not contain number, and in this case nothing is deleted.
bool hasFrequency(int frequency): Returns true if there is a number in the data structure that occurs frequency number of times, otherwise, it returns false.
    

class FrequencyTracker {
private:
    unordered_map<int,int> mp;
    unordered_map<int,int> freq; // for finding freq
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        freq[mp[number]]--; // ye freq wala banda ek kam ho gaya
        mp[number]++;
        freq[mp[number]]++; // ye freq wala banda ek zyada ho gaya
    } 
    
    void deleteOne(int number) {
        
        if(mp.find(number)!=mp.end()){
            freq[mp[number]]--;  // ye freq wala banda ek kam ho gaya
            mp[number]--;
            freq[mp[number]]++; // ye freq wala banda ek zyada ho gaya
        }
        
        if(mp[number]==0) mp.erase(number);
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency]>0;
    }
};