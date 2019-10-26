#include<iostream>
#include<queue>
using namespace std;
class MyStack {
	queue<int> qu1;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		qu1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		queue<int> qu2;
		if (qu1.empty()) {
			return 0;
		}
		int tmp;
		while (1)
		{
			tmp = qu1.front();
			qu1.pop();
			if (qu1.empty()) {
				break;
			}
			qu2.push(tmp);
		}
		qu1 = qu2;
		return tmp;
	}

	/** Get the top element. */
	int top() {
		queue<int> qu2;
		if (qu1.empty()) {
			return 0;
		}
		int tmp;
		while (1)
		{
			tmp = qu1.front();
			qu1.pop();
			if (qu1.empty()) {
				break;
			}
			qu2.push(tmp);
		}
		qu2.push(tmp);
		qu1 = qu2;
		return tmp;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return qu1.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
	MyStack St;
	St.push(1);
	St.push(2);
	St.push(3);
	St.push(4);
	St.push(5);
	St.push(6);
	cout << St.pop() << endl;
	cout << St.top() << endl;
	return 0;
}