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

int cont,coluna, linha, last=0, bug=0;
string buffer;

void fail() {
  cout<<"ARQUIVO INVALIDO"<<endl;
}

void erro() {
  bug=1;
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
    last = coluna;
    linha++;
    coluna=0;
  }
}

int main() {
  int i, state=0,r=32; bool flag = false, abriu=false, fechou=false;
  coluna = 0;
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
  bool arqv_inv = false, ok = false;
  while(!feof(fp)) {
    fscanf(fp,"%c",&cy);
    int tabela = (int)cy;
    if (range.count(tabela) <= 0) {
        arqv_inv = true;
      }
    else
      buffer.push_back(cy);
  }
  if (buffer.size()== 0) {
      cout<<"OK"<<endl;
      ok= true;
  }
  else {
    if (arqv_inv== true) {
      fail();
    }
    else {
        buffer.resize(buffer.size()-1);
  while (cont != buffer.size()) {
    if (state==-1) break;
    switch (state) {
      case 0: 
         {
          getNextChar();
          int temp = int(buffer[cont]);  
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
            //abriu = true;
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
         else if (temp == 32 || temp == 10 || temp == 9){
              verificaLinha();
              state= 6;  
            } 
         else {
            if(cont < buffer.size()) {
              erro(); state=0;
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
      case 4: // multiplicaÃ§Ã£o ou potencia
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
      case 6: // tratando espaÃ§o, tab e quebra de linha
      {
        //cout<<"estado 6"<<endl;
        getNextChar();
        int temp2 = int(buffer[cont]);
        if(temp2 ==32 || temp2 == 10 || temp2==9)
          state = 6;
        else {
          state = 0;
          retract();
        }
   
      }break;
      case 7: // virgula
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
        else  {
            state=0; s.clear(); retract(); erro();
        }
      }break;

      case 8: //string
      {
        int temp3 = int(buffer[cont]);
        getNextChar();
        if (buffer[cont]=='"') {
            TOKENS.push_back(make_pair(1,s));
            state=0;
          }
        else {
          if (s.size()==3) {
            if (temp3==10) {
              linha--; coluna= last; s.clear(); state=0; 
              erro(); last=0; linha++; coluna=1;
            }
            else {
              s.clear(); retract(); erro(); state=0;
            }    
          }
          else {
              if (cont < buffer.size()) {
                  verificaLinha();
                  s.push_back(buffer[cont]);
                  state=8;
              }
              else {
                if (temp3==10) {
                    linha--; coluna= last; s.clear(); state=0; 
                    erro(); last=0; linha++; coluna=1;
                  }
                else {
                   s.clear(); state = 0; erro();
                  }        
                }
              }
            }
        }break;
      }
    }
    }
  } 
  if (bug==0 && ok== false)
    cout<<"OK"<<endl;
  //cout<<endl;
}
