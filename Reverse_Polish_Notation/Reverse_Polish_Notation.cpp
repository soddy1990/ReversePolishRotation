#include<vector>
#include<stack>
#include<iostream>
using namespace std;

bool IsDigit(string& str)
{
	bool flag = true;
	if(str.find("-") == 0){
		for(unsigned int i=1; i<str.length(); i++)
		{
			if(!isdigit(str[i]))
			{
				flag=false;
				break;
			}
		}
	}
	else if(str.find("-") == string::npos){

		for(unsigned int i=0; i<str.length(); i++)
		{
			if(!isdigit(str[i]))
			{
				flag=false;
				break;
			}
		}
	}
	return flag;
}   
bool IsOperator(string& str){

	bool flag=true;
	if(str.compare("+")&&str.compare("-")&&str.compare("*")&&str.compare("/"))
	{
		flag=false;
		return flag;
	}
	return flag;
}
int computation(int a, int b, string operators){
	if(!operators.compare("+"))
		return a+b;
	if(!operators.compare("-"))
		return a-b;
	if(!operators.compare("*"))
		return a*b;
	if(!operators.compare("/")){
		if(b == 0){
			return -1;
		}
		else{
			return a/b;
		}
	}
	else
		return -1;
}

int evalRPN(vector<string> &tokens) {
	vector<string>::iterator iter;
	stack<string> operators;
	stack<int> operands;


	int count = 0;
	for(iter = tokens.begin();iter!=tokens.end();iter++){
		if(IsOperator(*iter)){
			operators.push(*iter);
			if(count<2)
				exit(0);
			else{
				int b = operands.top();
				operands.pop();
				if(operands.empty()){
					return b;
				}
				int a = operands.top();
				operands.pop();
				string operater = operators.top();
				operators.pop();
				operands.push(computation(a,b,operater));
				count--;
			}
		}
		else if(IsDigit(*iter)){
			int operand = atoi((*iter).c_str());
			operands.push(operand);
			count++;
		}
		else{
			exit(0);
		}
	}
	if(operators.empty()){
		return operands.top();
	}/*
	 while(!operators.empty()||!operands.empty()){
	 int b = operands.top();
	 operands.pop();
	 if(operands.empty()){
	 return b;
	 }
	 int a = operands.top();
	 operands.pop();
	 string operater = operators.top();
	 operators.pop();
	 operands.push(computation(a,b,operater));
	 }*/
	return operands.top();
}

void main(){
	vector<string> vstr;
	vstr.push_back("4");

	vstr.push_back("13");
	vstr.push_back("5");
	vstr.push_back("/");
	vstr.push_back("+");
	cout<<evalRPN(vstr);
	getchar();



}