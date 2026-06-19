class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_altitude = 0, Highest_altitude = 0;
        for(int i=0; i < gain.size(); i++){
             current_altitude += gain[i];
             if( current_altitude >  Highest_altitude)
                 Highest_altitude = current_altitude;
        }
        return  Highest_altitude;
        
    }
};