class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        if(stones > n) return false;
        
        int turn = 1; //alice turn, -1(bob turn)
        while(true){
            n = n-stones;
            stones--;
            turn = -turn;
            if(n < stones || stones==0) break;
        }

        if(turn == 1) return false;
        else return true;
    }
};

// class Solution {
// public:
//     bool canAliceWin(int n) {
//         int stones = 10;
//         bool alice = true;

//         while (n >= stones) {
//             n -= stones;
//             stones--;
//             alice = !alice;
//         }

//         return !alice;
//     }
// };