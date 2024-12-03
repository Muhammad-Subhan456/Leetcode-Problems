class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
    string t ="";
    int index=0;
    bool valid = true;
    int count = spaces.size();
    for(int i=0;i<s.length();){
    if(valid){

        if(i == spaces[index]){
            t += ' ';
            t += s[i];
            index++;
            count--;
            i++;
            if(count==0)
                valid = false;
            continue;
        }
    }
            t += s[i];
        
        i++;
    }
    return t;
    }
};