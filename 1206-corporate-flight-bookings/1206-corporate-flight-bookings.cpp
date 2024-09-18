class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int>freq(n+1);
    for(int i=0; i < bookings.size();++i){
        for(int j =bookings[i][0]; j<=bookings[i][1];++j){
            freq[j]+= bookings[i][2];
        }
    }
    freq.erase(freq.begin());
    return freq;
    }
};