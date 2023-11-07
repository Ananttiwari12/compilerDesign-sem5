#include <bits/stdc++.h>
using namespace std;
// Grammer: E->e+t/e-t
// input string =i+i*i
map<char, vector<char>> leading{
	{ 'E', { '+', '-', '*', '/', '^' ,'(', 'i'}},
	{ 'T', {           '*', '/', '^' ,'(', 'i'}},
	{ 'P', {                     '^' ,'(', 'i'}},
	{ 'F', {                          '(', 'i' }}
};

map<char, vector<char>> trailing{
	{ 'E', { '+', '-', '*', '/', '^' ,')', 'i'}},
	{ 'T', {           '*', '/', '^' ,')', 'i'}},
	{ 'P', {                     '^' ,')', 'i'}},
	{ 'F', {                          ')', 'i' }}
};

vector<char> terminals{ 'i', '+', '-', '*', '/', '^', '(', ')', '$'};
map<char, int> idx;

vector<vector<int>> table{
	{-2, +1, +1, +1, +1, +1, -2, +1, +1},
	{-1, +1, +1, -1, -1, -1, -1, +1, +1},
	{-1, +1, +1, -1, -1, -1, -1, +1, +1},
	{-1, +1, +1, +1, +1, -1, -1, +1, +1},
	{-2, +1, +1, +1, +1, -1, -1, +1, +1},
	{-1, +1, +1, +1, +1, -1, -1, +1, +1},
	{-1, -1, -1, -1, -1, -1, -1, +0, -2},
	{-2, +1, +1, +1, +1, +1, -2, +1, +1},
	{-1, -1, -1, -1, -1, -1, -1, -2, +1},
};

void print(stack<char> st){
	string str;
	while(!st.empty()){
		str+=st.top();
		st.pop();
	}
	reverse(str.begin(), str.end());
	cout<<str<<"\t";
}

bool parseOperatorPrecedence(string s){
	s=s+'$';
	stack<char> st;
	st.push('$');

	cout<<"STACK\tSTRING\n";

	int ptr=0;
	while(!st.empty()){
		int i{idx[st.top()]}, j{idx[s[ptr]]};
		if(table[i][j]==-2){
			return false;
		}
		if(table[i][j]==-1){
			st.push(s[ptr++]);
		}
		if(table[i][j]>=0){
			st.pop();
			if(table[i][j]==0)ptr++;
		}
		print(st);
		cout<<s.substr(ptr)<<"\n";
	}
	return true;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	for(int i{}; i<terminals.size(); i++){
		idx[terminals[i]]=i;
	}

	string s;
	cin>>s;

	bool res{parseOperatorPrecedence(s)};
	if(res){
		cout<<"Accepted\n";
	}
	else{
		cout<<"Failure\n";
	}

	return 0;
}
