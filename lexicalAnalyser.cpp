#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <ctype.h>
#include <cctype>
#include <utility>
#include <set> 
using namespace std;
void fail() {
  cout<<"ARQUIVO INVALIDO!\n";
}
int main() {
  int i, state=0,r=32; bool flag = false;
  FILE *fp; char cy;
  fp = fopen("test.txt","r");
  vector<string> reservadas;
  set<int> range;
  range.insert(9); range.insert(10);
  for (i=0;i<94; i++) {
    range.insert(r);
    r++;
  }
  reservadas.push_back("ATEH"); reservadas.push_back("SE"); reservadas.push_back("BIT"); reservadas.push_back("DE");reservadas.push_back("ENQUANTO"); reservadas.push_back("ESCREVA"); reservadas.push_back("FIM"); reservadas.push_back("FUNCAO"); reservadas.push_back("INICIO"); reservadas.push_back("LEIA"); reservadas.push_back("NULO"); reservadas.push_back("PARA"); reservadas.push_back("INTEIRO"); reservadas.push_back("PARE"); reservadas.push_back("REAL"); reservadas.push_back("RECEBA"); reservadas.push_back("SE"); reservadas.push_back("SENAO"); reservadas.push_back("VAR"); reservadas.push_back("VET");
  vector< pair<int,string> > TOKENS;
  vector< pair<int,string> >:: iterator it; // 0/reservada, 1/id, 2/num
  string buffer;
  string s;
  
  // int bla = (int)porra;
  while(!feof(fp)) {
  	fscanf(fp,"%c",&cy);
    int tabela = (int)cy;
    if (range.count(tabela) <= 0) {
      fail();
      break;
    }
    else
  	  buffer.push_back(cy);
  }
  buffer.resize(buffer.size()-1);
  int cont=-1;
  while (cont != buffer.size()) {
    cont++;
	  switch (state) {
      case 0: 
         {
	       if (isalpha(buffer[cont]) != 0){
	         state = 1;
	         s.push_back(buffer[cont]);
	       } 
	        
	       else if (buffer[cont]=='!') {
	         state = 0;
           s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='.') {
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear(); 
	       }
	       else if (buffer[cont]==':'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]==';') {
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='<'){
           s.push_back(buffer[cont]);
           if (cont == buffer.size()-1) {
            TOKENS.push_back(make_pair(0,s));
            s.clear();
            }
           else
            state = 2;
         } 
	       
	       else if (buffer[cont]== '='){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	        }
	       else if (buffer[cont]=='>'){
           s.push_back(buffer[cont]);
           if (cont == buffer.size()-1) {
            TOKENS.push_back(make_pair(0,s));
            s.clear();
            }
           else{
             state = 3;
           }
            
         }  
	       else if (buffer[cont] == '+'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='-'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont] =='*'){ // checar se chegou ao 
         s.push_back(buffer[cont]);
          if (cont == buffer.size()-1) {
            TOKENS.push_back(make_pair(0,s));
            s.clear();
          }
          else
	         state = 4;
	       }
	       else if (buffer[cont]=='/'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
	         s.clear();
	       }
	       else if (buffer[cont]=='%'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
	         s.clear();
	       }
	       else if (buffer[cont]=='('){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]==')'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='['){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]==']'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='"'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='&'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='|'){
	         state = 0;
	         s.push_back(buffer[cont]);
	         TOKENS.push_back(make_pair(0,s));
           s.clear();
	       }
	       else if (buffer[cont]=='0' || buffer[cont]=='1' || buffer[cont]=='2' || buffer[cont]=='3' || buffer[cont]=='4' || buffer[cont]=='5' || buffer[cont]=='6' || buffer[cont]=='7' || buffer[cont]=='8' || buffer[cont]=='9') {
	         state = 5;
	       } 
	       else if (cont != buffer.size()) {
           fail();
           cont= buffer.size();
           break;
         }
	     }break;

	   case 1:
	    {

	     if (isalpha(buffer[cont]) != 0 || buffer[cont]=='0' || buffer[cont]=='1' || buffer[cont]=='2' || buffer[cont]=='3' || buffer[cont]=='4' || buffer[cont]=='5' || buffer[cont]=='6' || buffer[cont]=='7' || buffer[cont]=='8' || buffer[cont]=='9') {
         state = 1; s.push_back(buffer[cont]); 
         //cout<<"ENTREIES"; 
       } 
	     else if (buffer[cont]==' ' || buffer[cont]=='\n')
	       state = 6;
	     else {
        for (i=0; i<reservadas.size(); i++) {
	         if (reservadas[i].compare(s)==0) {
               flag = true; 
           } 
	            
	      }
        if (flag== true) {
          TOKENS.push_back(make_pair(0,s));
	        s.clear(); flag = false; state = 0; cont--;
	        break;
        }
        else{
          TOKENS.push_back(make_pair(1,s));
          state=0; cont--; s.clear();
         }
	      }
	    }break; 
     case 2:
      {
        if(buffer[cont]=='-' || buffer[cont]=='=' || buffer[cont]=='>') {
          s.push_back(buffer[cont]); state =0;
          TOKENS.push_back(make_pair(0,s)); s.clear(); 
        }
        else {
          TOKENS.push_back(make_pair(0,s)); state = 0; s.clear(); cont--;
        }
      }break;
      case 3: 
      {
        if(buffer[cont]=='=') {
          s.push_back(buffer[cont]); state =0;
          TOKENS.push_back(make_pair(0,s)); s.clear(); 
        }
        else {
          TOKENS.push_back(make_pair(0,s)); state = 0; s.clear(); cont--;
        }
      }break;
      case 4:
      {
        if(buffer[cont]=='*') {
          s.push_back(buffer[cont]); state =0;
          TOKENS.push_back(make_pair(0,s)); s.clear(); 
        }
        else {
          TOKENS.push_back(make_pair(0,s)); state = 0; s.clear(); cont--;
        }
      }break;
      case 5: 
      {
         if (buffer[cont]=='0' || buffer[cont]=='1' || buffer[cont]=='2' || buffer[cont]=='3' || buffer[cont]=='4' || buffer[cont]=='5' || buffer[cont]=='6' || buffer[cont]=='7' || buffer[cont]=='8' || buffer[cont]=='9') {
         state = 5; s.push_back(buffer[cont]);  
        }
        else if(isalpha(buffer[cont])) {
          state=0; s.clear(); fail(); 
        }
        else if(buffer[cont]==',') {
          s.push_back(buffer[cont]); state = 7;
        }
        else {
          state=0; TOKENS.push_back(make_pair(2,s)); s.clear(); cont--;
        }
      }break;
      case 7:
      {
        if (buffer[cont]=='0' || buffer[cont]=='1' || buffer[cont]=='2' || buffer[cont]=='3' || buffer[cont]=='4' || buffer[cont]=='5' || buffer[cont]=='6' || buffer[cont]=='7' || buffer[cont]=='8' || buffer[cont]=='9') {
          state = 7; s.push_back(buffer[cont]);  
        }
        else if (buffer[cont]==',') {
            state=0; s.clear(); fail();
        }
        else {
          state=0; TOKENS.push_back(make_pair(2,s)); s.clear(); cont--;
        }
      }break;
	  }
  } 
  for(it=TOKENS.begin();it != TOKENS.end();it++) {
    pair <int,string> p = *it;
    cout<< (*it).first<<" "<<(*it).second<<endl; 
    } 
}