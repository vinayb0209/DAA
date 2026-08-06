#include<iostream>
#include<stack>
using namespace std;
bool PC(string str){
	stack<int> s;
	for(char ch: str){
		if (ch=='{'|| ch=='['||ch=='(')
			s.push(ch);
		else {
			if (s.empty()) 	
				return 0;
			char top=s.top();
			s.pop();
			if(ch==']'&& top!='['||ch=='}' && top!='{'||ch==')'&& top!='(')
			return 0;
		}
	}
	return s.empty();
}
int main(){
	string str;
	cout<<"Enter Parenthesis:";
	cin>>str;
	if(PC(str)){
		cout<<"Valid";
	} else {
		cout <<"Invalid";
	}
	
	return 0;
}
