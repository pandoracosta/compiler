#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <ctype.h>
#include <cctype>
#include <utility> 
using namespace std;
int main() {
  int i, state=0;
  FILE *fp; char c;
  fp = fopen("test.txt","r");
  vector<string> reservadas;
  reservadas.push_back("ATEH"); reservadas.push_back("SE"); reservadas.push_back("BIT"); reservadas.push_back("DE");reservadas.push_back("ENQUANTO"); reservadas.push_back("ESCREVA"); reservadas.push_back("FIM"); reservadas.push_back("FUNCAO"); reservadas.push_back("INICIO"); reservadas.push_back("LEIA"); reservadas.push_back("NULO"); reservadas.push_back("PARA"); reservadas.push_back("INTEIRO"); reservadas.push_back("PARE"); reservadas.push_back("REAL"); reservadas.push_back("RECEBA"); reservadas.push_back("SE"); reservadas.push_back("SENAO"); reservadas.push_back("VAR"); reservadas.push_back("VET");
  vector< pair<int,string> > TOKENS; // 0/reservada, 1/id, 2/num
  int IDS[500];
  std::vector<string> v;
  string buffer;
  string s;
  
  // int bla = (int)porra;

  while(!feof(fp)) {
  	fscanf(fp,"%c",&c);
  	buffer.push_back(c);
  }
  buffer.resize(buffer.size()-1);
  // while (1) {
	 //  switch (state) {
	 //    case 0: 
	 //    {
	 //      if (isalpha(c) != 0){
	 //        state = 1;
	 //        s.push_back(c);
	 //      } 
	        
	 //      else if (c=='!') {
	 //        state = 0;
	 //        s.push_back(c);
	 //        TOKENS.push_back(make_pair(0,s));
	 //        s.clear();
	 //      }
	 //      else if (c=='.') {
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c==':'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c==';') {
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='<') 
	 //        state = 2;
	 //      else if (c== '='){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='>')
	 //        state = 3;
	 //      else if (c == '+'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='-'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c =='*'){ // checar se chegou ao fim
	 //        state = 4;
	 //      }
	 //      else if (c=='/'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='%'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='('){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c==')'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='['){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c==']'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='"'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='&'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='|'){
	 //        state = 0;
	 //        TOKENS.push_back(make_pair(0,c));
	 //      }
	 //      else if (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9') {
	 //        state = 5;
	 //      } 
	 //      // else fail();
	   
	 //    }break;
	 //  case 1:
	 //   {
	 //    fp++;
	 //    fscanf(fp,"%c",&c);
	 //    if (isalpha(c)) {
	 //      temp+=c;
	 //      for (i=0; i<reservadas.size(); i++) {
	 //        if (reservadas[i].compare(temp)==0) {
	 //          TOKENS.push_back(make_pair(0,temp));
	 //          temp="";
	 //          state = 0;
	 //          break;
	 //        }
	 //        else
	 //          state = 1; 
	 //      }    
	 //    }
	 //    else if (c==' ')
	 //      state = 6;
	 //    else {
	 //      TOKENS.push_back(make_pair(1,temp));
	 //      temp="";
	 //      state = 0;
	 //    }
	 //   }break; 
	 //  } 
	//}
}