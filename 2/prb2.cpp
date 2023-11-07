#include <bits/stdc++.h>
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

int main(int argc, char const *argv[])
{
    cout<<"HI\n";
    return 0;
}
