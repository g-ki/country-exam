#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct Token {
  string data;
  int type;

  Token(string data_, int type_) : data(data_), type(type_) {}
};


bool isChar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}


vector<Token> parse(string str) {
  Token token("", 0);

  vector<Token> tokens;
  for(int i = 0; i < str.size(); i++) {
    if (isChar(str[i]) && token.type == 1) {
      if (token.data != "" ) tokens.push_back(token);
      token.type = 0;
      token.data = "";
    } else if (token.type == 0){
      if (token.data != "" ) tokens.push_back(token);
      token.type = 1;
      token.data = "";
    }
    token.data += str[i];
  }
  tokens.push_back(token);

  return tokens;
}


vector<Token> swapWordTokens(vector<Token> tokens) {
  int a = 0, t = tokens.size() - 1;
  while (a < t) {
    while(tokens[a].type != 0) a++;
    while(tokens[t].type != 0) t--;
    swap(tokens[a], tokens[t]);
    a++;
    t--;
  }
  return tokens;
}


string transform(string str) {
  vector<Token> tokens = swapWordTokens(parse(str));
  string result = "";

  for(Token token : tokens)
    result += token.data;

  return result;
}


int main() {
  string str = "tekst 1.";
  cout << "Input: " << str << endl; // tekst 1.
  cout << "Output: " << transform(str) << endl; // 1 tekst.

  return 0;
}
