#include<stack>
class MinStack
{
public:
    MinStack();
    ~MinStack();
    std::stack<int> st,stm;
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            stm.push(x);
        }
        else {
            st.push(x);
            if (x <= stm.top())
                stm.push(x);
        }
    }
    void pop() {
        if (st.top() == stm.top()) {
            st.pop();
            stm.pop();
        }
        else
            st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return stm.top();
    }
private:

};

MinStack::MinStack()
{
}

MinStack::~MinStack()
{
}