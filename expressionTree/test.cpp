#include<string>
#include<iostream>
#include<fstream>
#include "expressionTree.h"
using namespace std;
int main()
{
	string s = "a+b+c*(d+e)";
	
	expressionTree t(s);

	ofstream fout("output.txt");
	t.output(fout);
}