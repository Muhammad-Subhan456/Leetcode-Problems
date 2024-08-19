class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int lo=0,hi=people.size()-1,count=0;
        sort(people.begin(),people.end());
        while(lo<=hi){
            if(people[lo]+people[hi]>limit)
                hi--,count++;
            else if(people[lo]+people[hi]<=limit)
                count++,hi--,lo++;
        }
        return count;
    }
};