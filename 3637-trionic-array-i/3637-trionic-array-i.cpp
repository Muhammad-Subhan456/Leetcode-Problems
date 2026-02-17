class Solution {
public:
    bool isTrionic(vector<int>& a) {
        bool one=false,two=false,three = false;
        int i=0,n = a.size() ;
        while(i < (n-1) && a[i] < a[i+1]){
            i++;
            one = true;
        }
        cout << i << '\n';
        while(i < (n-1) && a[i] > a[i+1]){
            i++;
            two = true;
        }
        cout << i << '\n';

         while(i < (n-1) && a[i] < a[i+1]){
            i++;
            three = true;
        }
        cout << i << '\n';

    return (one && two && three && (i==n-1));

    }
};