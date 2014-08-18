class Solution {
public:
    bool isSameChar(char& a, char& b) {
        if (a == b ||
            a == b+32 ||
            a == b-32)
            return true;
        return false;
    }
    bool isChar(char& a) {
        return (a>64 && a < 91) || (a>96 && a < 123) || (a>47 && a < 58);
    }
    bool isPalindrome(string s) {
        int size = s.size();
        if (size <= 1)
            return true;
        int i = 0;
        int j = size-1;
        while( i <= j) {
            while (!isChar(s[i])) { 
                i++;
                if (i >= size)
                    return true;
            }
            while (!isChar(s[j])) {
                j--;
                if (j <0)
                    return true;
            }
            if (!(isSameChar(s[i], s[j])))
                return false;
            i++;
            j--;
            
        }
        return true;
            
        
    }
};
