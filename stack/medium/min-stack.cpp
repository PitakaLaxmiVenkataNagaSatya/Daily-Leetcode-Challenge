//TC - O(1) SC - O(2*N) because of pair stack
// class MinStack {
// public:
//     stack<pair<int, int>> st;

//     MinStack() {}

//     void push(int val) {
//         int minVal = st.empty() ? val : min(val, st.top().second);
//         st.push({val, minVal});
//     }

//     void pop() {
//         st.pop();
//     }

//     int top() {
//         return st.top().first;
//     }

//     int getMin() {
//         return st.top().second;
//     }
// };


//TC - O(1) SC - O(N)
class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {}

    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                st.push((long long)2*val-mini);
                mini=val;
            }
            else st.push(val);
        }
    }

    void pop() {
        long long top=st.top();
        st.pop();
        if(top<mini){
            mini = 2*mini - top;
        } 
    }

    int top() {
        long long top=st.top();
        if(top>mini) return top;
        else return mini;
    }

    int getMin() {
        return mini;
    }
};