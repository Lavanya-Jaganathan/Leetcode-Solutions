class Solution {
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map<char,int> freq;
        for( char c: s)
        {
            freq[c]++;
        }

        int reference_count = freq[s[0]];
        for( auto[f,c] : freq)
        {
            if( reference_count != c)
                return false;
        }
        return true;
    }
};