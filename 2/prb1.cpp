#include<bits/stdc++.h>
using namespace std;

struct State{
public:
	vector<char>symbol;
	vector<State*> next;
	bool isFinal;
};

char operators[]={'+', '-', '*', '/', '&', '|', '^', '%', '='};

State * dfa(){
	State* q[4];

	for(int i{};i<4;i++){
		q[i]=(State*)malloc(sizeof(State));
		q[i]->isFinal=true;
	}

	for(char c{'a'};c<='z';c++){
		for(int i{};i<4;i++){
			q[i]->symbol.push_back(c);
			q[i]->next.push_back(q[1]);
		}
	}

	for(char c{'0'};c<='9';c++){
		for(int i{};i<4;i++){
			q[i]->symbol.push_back(c);
			q[i]->next.push_back(i==1?q[1]:q[2]);
		}
	}

	for(char opr: operators){
		for(int i{};i<3;i++){
			q[i]->symbol.push_back(opr);
			q[i]->next.push_back(q[3]);
		}
	}


	q[1]->symbol.push_back('_');
	q[1]->next.push_back(q[1]);


	q[0]->isFinal=false;
	q[3]->isFinal=false;

	return q[0];
}

string s;
int n;

bool dfs(int idx, State* state){
	if(idx==n){
		return state->isFinal;
	}
	
	for(int i{};i<state->symbol.size();i++){
		if(state->symbol[i]==s[idx]){
			return dfs(idx+1, state->next[i]);
		}
	}

	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		State * initial=dfa();
		cin>>s;
		n=s.size();
		bool res{dfs(0, initial)};
		if(res){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}
