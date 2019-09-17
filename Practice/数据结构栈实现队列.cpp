#include<stack>

class MyQueue
{
public:
    MyQueue();
    ~MyQueue();

    std::stack<int> a, b;

    void push(int x) {
        if (a.empty())
            a.push(x);
        else {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
            b.push(x);
            while (!b.empty()) {
                a.push(b.top());
                b.pop();
            }
        }
    }

    int pop() {
        int ans = a.top();
        a.pop();
        return ans;
    }
    int peek() {
        return a.top();
    }
    bool empty() {
        return a.empty();
    }

private:
    
};

MyQueue::MyQueue()
{
}

MyQueue::~MyQueue()
{
}

void MyQueueTest() {
    MyQueue* queue = new MyQueue();

    queue->push(1);
    queue->push(2);
    int a = queue->peek();  // ·µ»Ø 1
    a = queue->pop();   // ·µ»Ø 1
    a = queue->peek();  //
    a = queue->empty(); //

}