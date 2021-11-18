#pragma once
#include<iostream>
#include<string>
using namespace std;
string change(string s);
struct treeNode
{
	char element;
	treeNode* leftNode;
	treeNode* rightNode;
public:
	treeNode(char e)
	{
		element = e;
		leftNode = rightNode = nullptr;
	}
};
class expressionTree
{
private:
	treeNode* root= NULL;
	int treeNodeNumber;
public:
	expressionTree() {};
	expressionTree(string s);
	void output(ostream& o);
	void output(treeNode* p,ostream& o);
	
};
