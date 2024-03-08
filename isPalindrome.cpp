class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right){
            while (!alphaNum(s[left]) && left < right) left++;
            while (!alphaNum(s[right]) && left < right) right--;
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
    bool alphaNum(char c) {
        if ((c >= '0' && c <= '9') || // number
            (c >= 'A' && c <= 'Z') || // uppercase
            (c >= 'a' && c <= 'z'))   // lowercase
        return true;
        else return false;
    }
};
