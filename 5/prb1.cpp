#include <bits/stdc++.h>
using namespace std;

map<char, string> productions{
	{'S', "AA"},
	{'A', "aA|b"},
	{'A', "b"}
};

map<char, vector<char>> first{
	{'S', {'a', 'b'}},
	{'A', {'a', 'b'}}
};

map<char, vector<char>> follow{
	{'S', {'$'}},
	{'A', {'$'}}
};

map<char, map<char, string>> table{
	{
		'S', {
			{'a', "AA"},
			{'b', "AA"}
		}
	},

	{
		'A', {
			{'a', "aA"},
			{'b', "b"}
		}	
	}
};

bool isTerminal(char c){
	return (c=='a' or c=='b');
}

void pushIn(stack<char>&st, string s){
	cout<<st.top()<<" -> "<<s;
	st.pop();
	reverse(s.begin(), s.end());
	for(char c: s){
		st.push(c);
	}
}

void print(stack<char> st){
	string s;
	while(!st.empty()){
		s+=st.top();
		st.pop();
	}
	reverse(s.begin(), s.end());
	cout<<s<<"\t";
}

bool parseLL1(string s){
	stack<char> st;
	s=s+'$';
	st.push('$');
	st.push('S');
 
	int i=0;
	cout<<"STACK\tString\tPRODUCTION\n";
	while(st.top()!='$'){
		print(st);
		if(st.top()==s[i]){
			i++;
			st.pop();
			cout<<"\n";
			continue;
		}

		if(isTerminal(st.top())){
			return false;
		}
		cout<<s.substr(i)<<"\t";
		if(table[st.top()].find(s[i])==table[st.top()].end()){
			return false;
		}
		pushIn(st, table[st.top()][s[i]]);
		cout<<"\n";
	}

	cout<<s.substr(i)<<"\n";

	return true;
}

int main(){

	string s;
	cin>>s;

	bool res=parseLL1(s);
	if(res){
		cout<<"\nAccepted\n";
	}else{
		cout<<"\nFailed\n";
	}

	return 0;
}