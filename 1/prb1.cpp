#include<bits/stdc++.h>
using namespace std;

void trim(string& word){
	int i=0;
	while(word[i]=='\t' or word[i]==' ')++i;
	word=word.substr(i);
}

string keywords[]={"auto","break","case","char","const","continue","default","do",
"double","else","enum","extern","float","for","goto","if","int","long","register"
"return","short","signed","sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while", "main"};

bool isKeyWord(string word){
	for(string key: keywords){
		if(word.find(key)!=string::npos)return true;
	}
	return false;
}

int main(){
	ifstream f;

	f.open("source.cpp");
	// freopen("output.txt", "w", stdout);	

	string line;

	int lines=0, char_count=0, word_count=0, keyword_count=0;
	
	while(getline(f, line)){
		lines++;
		stringstream ss(line);
		string word;
		trim(line);
		while(getline(ss, word,' ')){
			char_count+=word.size();
			word_count++;
			trim(word);
			if(isKeyWord(word)){
				cout<<word<<"\n";
				keyword_count++;
			}
		}
	}

	cout<<"Lines: "<<lines<<"\n";
	cout<<"Words: "<<word_count<<"\n";
	cout<<"Characters: "<<char_count<<"\n";
	cout<<"Keywords: "<<keyword_count<<"\n";

	f.close();
	return 0;
}
