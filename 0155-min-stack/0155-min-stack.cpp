// 
class MinStack {
public:
    stack<long long> st;
    long long minimum = INT_MAX;

    void push(int value) {
        if(st.empty()) {
            minimum = value;
            st.push(value);
        }
        else if(value >= minimum) {
            st.push(value);
        }
        else {
            st.push(2LL * value - minimum);  // FIX
            minimum = value;
        }
    }

    void pop() {
        if(st.empty())
            return;

        long long x = st.top();
        st.pop();

        if(x < minimum) {
            minimum = 2LL * minimum - x;  // FIX
        }
    }

    int top() {
        if(st.empty())
            return -1;

        long long x = st.top();

        if(x >= minimum)
            return x;
        else
            return minimum;
    }

    int getMin() {
        return minimum;
    }
};
// class MinStack {
// public:
//     stack<int> st;
//     long long minimum = INT_MAX;

//     MinStack() {
//     }

//     void push(int value) {
//         if(st.empty()) {
//             minimum = value;
//             st.push(value);
//         }
//         else if(value >= minimum) {
//             st.push(value);
//         }
//         else {
//             st.push(2 * value - minimum);
//             minimum = value;
//         }
//     }

//     void pop() {
//         if(st.empty())
//             return;

//         long long x = st.top();
//         st.pop();

//         if(x < minimum) {
//             minimum = 2 * minimum - x;
//         }
//     }

//     int top() {
//         if(st.empty())
//             return -1;

//         long long x = st.top();

//         if(x >= minimum)
//             return x;
//         else
//             return minimum;
//     }

//     int getMin() {
//         return minimum;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */