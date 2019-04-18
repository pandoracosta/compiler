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

int cont,coluna, linha;
string buffer;

void fail() {
  cout<<"ARQUIVO INVALIDO\n";
}

void erro() {
  cout << linha << " " <<coluna << endl;
}

void getNextChar() {
  cont++;
  coluna++;
}
void retract() {
  cont--; coluna--;
}
void verificaLinha() {
  int verifica = (int)buffer[cont];
  if (verifica==10) {
    linha++;
    coluna=0;
  }
}

int main() {
  int i, state=0,r=32; bool flag = false;
  coluna = -1;
  cont = -1; linha =1;
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
  string s;

  while(!feof(fp)) {
    fscanf(fp,"%c",&cy);
    int tabela = (int)cy;
    if (range.count(tabela) <= 0) {
      fail();
      state=-1;
      break;
    }
    else
      buffer.push_back(cy);
  }

  buffer.resize(buffer.size()-1);
  while (cont != buffer.size()) {
    if (state==-1) break;
    switch (state) {
      case 0: 
         {
          getNextChar();  
         if (isalpha(buffer[cont]) != 0){
           s.push_back(buffer[cont]);
           if (cont == buffer.size()-1) {
              for (i=0; i<reservadas.size(); i++) {
                if (reservadas[i].compare(s)==0) {
                  flag = true; 
                } 
              }
              if (flag== true) {
                TOKENS.push_back(make_pair(0,s));
                s.clear(); flag = false; state = 0; retract();
                break;
              }
              else{
                TOKENS.push_back(make_pair(1,s));
                s.clear();
                break;
               }
            }
           else
             state = 1;
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
         else if (buffer[cont] =='*'){ 
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
            if (cont == buffer.size()-1) {
              erro();
              s.clear();
            }
          else
           state = 8;
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
           s.push_back(buffer[cont]);
            if (cont == buffer.size()-1) {
              TOKENS.push_back(make_pair(2,s));
              s.clear();
            }
          else
           state = 5;
         }
         else {
          int temp = int(buffer[cont]);
          if(temp == 32 || temp == 10 || temp == 9) {
            verificaLinha();
            state= 6;
          }   
          else if(cont < buffer.size()-1) {
            cout <<"nao esquecer colunas e linhas" << endl;
            state =0;
          }  
          else 
            break;
         }
       }break;

     case 1: //identificador
      {
        int aux = (int)buffer[cont];
       getNextChar();
       if (isalpha(buffer[cont]) != 0 || buffer[cont]=='0' || buffer[cont]=='1' || buffer[cont]=='2' || buffer[cont]=='3' || buffer[cont]=='4' || buffer[cont]=='5' || buffer[cont]=='6' || buffer[cont]=='7' || buffer[cont]=='8' || buffer[cont]=='9') {
              if(s.size()==512) {
                  state=0;
                  s.clear();
                  retract();
                  erro();
                }
              else {
                    state = 1; s.push_back(buffer[cont]);
              }               
          } 
        else if (buffer[cont]==' '|| aux==10 || aux==9){
          verificaLinha();
          state = 6;
          for (i=0; i<reservadas.size(); i++) {
            if (reservadas[i].compare(s)==0) {
                flag = true; 
              } 
            }
          if (flag== true) {
            TOKENS.push_back(make_pair(0,s));
            s.clear(); flag = false; state = 0; retract();
            break;
          }
          else{
            TOKENS.push_back(make_pair(1,s));
            state=0; retract(); s.clear();
          }
        }
       else {
        for (i=0; i<reservadas.size(); i++) {
           if (reservadas[i].compare(s)==0) {
               flag = true; 
            } 
         }
        if (flag== true) {
          TOKENS.push_back(make_pair(0,s));
          s.clear(); flag = false; state = 0; retract();
          break;
        }
        else{
          TOKENS.push_back(make_pair(1,s));
          state=0; retract(); s.clear();
         }
        }
      }break; 
     case 2:
      {
        getNextChar();
        if(buffer[cont]=='-' || buffer[cont]=='=' || buffer[cont]=='>') {
          s.push_back(buffer[cont]); state =0;
          TOKENS.push_back(make_pair(0,s)); s.clear(); 
        }
        else {
          TOKENS.push_back(make_pair(0,s)); state = 0; s.clear(); retract();
        }
      }break;
      case 3: 
      {
        getNextChar();
        if(buffer[cont]=='=') {
          s.push_back(buffer[cont]); state =0;
          TOKENS.push_back(make_pair(0,s)); s.clear(); 
        }
        else {
          TOKENS.push_back(make_pair(0,s)); state = 0; s.clear(); retract();
        }
      }break;
      case 4: // multiplicação ou potencia
      {
        getNextChar();
        if(buffer[cont]=='*') {
          s.push_back(buffer[cont]); state =0;
          TOKENS.push_back(make_pair(0,s)); s.clear(); 
        }
        else {
          TOKENS.push_back(make_pair(0,s)); state = 0; s.clear(); retract();
        }
      }break;
      case 5: // numeros
      {
        getNextChar();
         if (buffer[cont]=='0' || buffer[cont]=='1' || buffer[cont]=='2' || buffer[cont]=='3' || buffer[cont]=='4' || buffer[cont]=='5' || buffer[cont]=='6' || buffer[cont]=='7' || buffer[cont]=='8' || buffer[cont]=='9') {
           if(s.size()==3) {
                  state=0;
                  s.clear();
                  retract();
                  erro();
                }
            else {
                state = 5; 
                s.push_back(buffer[cont]);  
            }        
          }
        else if(isalpha(buffer[cont]) != 0) {
          state=0; s.clear(); retract(); erro(); 
        }
        else if(buffer[cont]==',') {
          s.push_back(buffer[cont]); state = 7;
        }
        else { 
          TOKENS.push_back(make_pair(2,s));
          state=0;
          s.clear(); retract();
        }
      }break;
      case 6: // tratando espaço, tab e quebra de linha
      {
        //cout<<"estado 6"<<endl;
        getNextChar();
        if(buffer[cont]==' ')
          state = 6;
        else {
          state = 0;
          retract();
        }
   
      }break;
      case 7:
      {
        getNextChar();
        if (buffer[cont]=='0' || buffer[cont]=='1' || buffer[cont]=='2' || buffer[cont]=='3' || buffer[cont]=='4' || buffer[cont]=='5' || buffer[cont]=='6' || buffer[cont]=='7' || buffer[cont]=='8' || buffer[cont]=='9') {
          if(s.size()==3) {
                  state=0;
                  s.clear();
                  retract();
                  erro();
                }
          else {
              state = 7; s.push_back(buffer[cont]);
            }     
        }
        else if (buffer[cont]==',') {
            state=0; s.clear(); fail();
        }
        else {
          state=0; TOKENS.push_back(make_pair(2,s)); s.clear(); retract();
        }
      }break;

      case 8: //string
      {
        getNextChar();
        if (s.size()==3) {
          s.clear(); retract(); erro(); state=0; 
        }
        else {
          if(buffer[cont] != '"') {
            s.push_back(buffer[cont]);
            state=8;
          }
          else {
            TOKENS.push_back(make_pair(1,s));
          }
        }
        
      }break;
    }
  } 
  for(it=TOKENS.begin();it != TOKENS.end();it++) {
    pair <int,string> p = *it;
    cout<< (*it).first<<" "<<(*it).second<<" "; 
    } 
    cout << endl;
}
