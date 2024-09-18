class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int>freq(n+2,0);
    for(int i=0; i < bookings.size(); ++i){
        freq[bookings[i][0]] += bookings[i][2];
        freq[(bookings[i][1]+1)] -= bookings[i][2];
    }
    for(int i=1; i<freq.size();++i)
        freq[i]+=freq[i-1];
    freq.erase(freq.begin());
    freq.pop_back();
    return freq;
    }
};