#include<queue>

class MyStack
{
public:
    MyStack();
    ~MyStack();
    std::queue<int> a, b;
    void push(int x) {
        a.push(x);
    }
    int pop() {
        if (a.size() == 1) {
            int ans = a.front();
            a.pop();
            return ans;
        }
        else {
            int ans = a.back();
            while (!a.empty()) {
                b.push(a.front());
                a.pop();
            }
            while (b.size() > 1) {
                a.push(b.front());
                b.pop();
            }
            b.pop();
            return ans;
        }
    }
    int top() {
        return a.back();
    }
    bool empty() {
        return a.empty();
    }
private:

};

MyStack::MyStack()
{
}

MyStack::~MyStack()
{
}

