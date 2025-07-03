class Solution {
public:
    char charc(int k,string word){
        
        if(word.length() >= k) return word[k-1];
        string emp = "";
        for(auto c : word) emp += (char)c+1;
        word += emp;
        cout << word << endl;
        return charc(k,word);
    }

    char kthCharacter(int k) {
    string word = "a";
    return charc(k,word);
    }
};