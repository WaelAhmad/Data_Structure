#include <iostream>
using namespace std;
#include<iostream>
class stack {
	int stk[500];
	int top;
public:
	stack() {
		top = -1;
	}
	void push(int x)
	{
		if (top > 500)
		{
			cout << "stack is full";
			return;
		}
		stk[++top] = x;
		cout << "successfulyy inserted:" << x;
	}
	void pop() {
		if (top < 0)
		{
			cout << "stack is empty";
			return;
		}
		cout << "the deleted element is: " << stk[top--];
	}
	void display() {
		if (top < 0)
		{
			cout << "stack is empty";
			return;
		}
		for (int i = top; i >= 0; i--)
			cout << stk[i] << "";
	}
};
int main()
{
	int ch;
	stack st;
	while (1)
	{
		cout << "\n press 1 to push \n press 2 to pop \n press 3 to display \n press 4 to exit";
		cin >> ch;
		switch (ch) {
		case 1:cout << "enter the element:";
			cin >> ch;
			st.push(ch);
			break;
		case 2:st.pop();
			break;
		case 3:st.display();
			break;
		}
	}
	return (0);
}