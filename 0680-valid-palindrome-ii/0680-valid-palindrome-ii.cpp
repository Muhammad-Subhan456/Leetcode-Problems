class Solution {
public:
bool isPalind(int l,int r,string&a){
	while(l < r){
		if(a[l] != a[r]) return false;
		l++;
		r--;
	}
	return true;
}
    bool validPalindrome(string a) {
    int l=0, r = a.size()-1;
	while(l < r){
		if(a[l]==a[r]){
			l++;
			r--;
		}
		else{
			if(!isPalind(l+1,r,a) && !isPalind(l,r-1,a)){
				return false;
			}
			return true;
		}
	}
    return true;
        
    }
};