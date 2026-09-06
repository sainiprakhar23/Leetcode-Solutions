class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.length();
        int num = 0;
        int prev = 0;

        for (int i = n - 1; i >= 0; i--) {
            int curr = mp[s[i]];

            if (curr < prev)
                num -= curr;
            else
                num += curr;

            prev = curr;
        }

        return num;
    }
};