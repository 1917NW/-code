#include<string>
#include<stack>
#include "expressionTree.h"
bool isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		return true;
	}
	return false;
}

int getPriority(char ch)
{
	int level = 0;

	switch (ch) {
	case '(':
		level = 1;
		break;
	case '+':
	case '-':
		level = 2;
		break;
	case '*':
	case '/':
		level = 3;
		break;
	default:
		break;
	}
	return level;
}

string change(string s)
{
	const char* c = s.c_str();
	char k;
	stack<char> op;
	string e;
	for (int i = 0; i < s.length(); i++)
	{

		if (c[i] == '(')
			op.push(c[i]);
		else if (c[i] == ')')
			while (op.top() != '(') {
				e.push_back(op.top());
				op.pop();
			}

		else if (!isOperator(c[i]))
			e.push_back(c[i]);
		else if (isOperator(c[i]))
		{
			if (op.empty())
			{
				op.push(c[i]);
			}
			else
			{
				while (!op.empty()) {
					k = op.top();
					if (getPriority(c[i]) <= getPriority(k))
					{
						e.push_back(k);
						op.pop();
					}
					else
						break;
				}
				op.push(c[i]);
			}
		}
	
	}
	while (!op.empty())
	{
		if(op.top()!='(')
			e.push_back(op.top());
		op.pop();
	}
	flush(cout);
	return e;
}
expressionTree::expressionTree(string s)
{
	s = change(s);
	const char* c = s.c_str();
	stack<treeNode*> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (!isOperator(c[i]))
		{
			treeNode* p = new treeNode(c[i]);
			st.push(p);
		}
		else
		{
			treeNode* p = new treeNode(c[i]);
			p->rightNode = st.top();
			st.pop();
			p->leftNode = st.top();
			st.pop();
			st.push(p);
		}
	}
	root = st.top();
}

void expressionTree::output(ostream& o)
{
	output(root,o);
}

void expressionTree::output(treeNode* p,ostream& o)
{
	static int i = 0;
	if (p== NULL)
		return;
	i++;

	output(p->rightNode,o);

	for (int j = 0; j <= 10*i; j++)
		o<< " ";
	o << p->element<<endl<<endl;
	

	output(p->leftNode,o);

	i--;
}