// class StockSpanner {
// public:
//     stack<pair<int,int>> st;
//     StockSpanner() {    
//     }
//     int next(int price) {
//         int span = 1;
//         while(!st.empty() && st.top().first <= price){
//             span += st.top().second; //adding the previous consecutove days
//             st.pop();
//         }
//         st.push({price,span});
//         return span;
//     }
// };



class StockSpanner {
public:
    vector<int> ans; //store prices
    stack<int> st; //store indices
    StockSpanner() {    
    }
    int next(int price) {
        ans.push_back(price);
        int i = ans.size() - 1; //cuurent i
        while(!st.empty() && ans[st.top()] <= price){
            st.pop();
        }

        int span;
        if(st.empty()) span = i+1;
        else span = i-st.top();

        st.push(i);
        return span;
    }
};
