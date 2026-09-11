class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(), s.rend());

        int i;
        for(i = s.size(); i >= 0; i--){
            if(s[i] == '1') break;
        }

        swap(s[i], s[s.size() - 1]);

        return s;
    }
};