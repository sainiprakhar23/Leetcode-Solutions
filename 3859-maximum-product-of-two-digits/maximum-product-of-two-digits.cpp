class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n>0){
            int x = n%10;
            v.push_back(x);
            n/=10;
        }
        int size = v.size();
        sort(v.begin(),v.end());
        int max_element = v[size-1];
        int second_max_element = v[size-2];

       long long result = max_element * second_max_element;

        return (int)(result); 

    }
};