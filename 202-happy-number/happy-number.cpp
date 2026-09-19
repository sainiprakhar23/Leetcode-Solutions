class Solution {
public:
    int newNumber(int& n){
        int newNum=0;
        while(n>0){
            int num = n%10;
            newNum += num*num;
            n=n/10;
        }
        return newNum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            if(s.count(n)) return false;
            s.insert(n);
            n=newNumber(n);
        }
        return true;
    }
};