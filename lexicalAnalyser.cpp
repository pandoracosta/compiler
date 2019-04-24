
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

int cont,coluna, linha, error=0,lixo=0, last=0, bug=0, slinha, scol;
string buffer;
bool enter = false, para= false;
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
  for (i=32;i<=126; i++) {
    range.insert(i);
  }
  reservadas.push_back("ATEH"); reservadas.push_back("SE"); reservadas.push_back("BIT"); reservadas.push_back("DE");reservadas.push_back("ENQUANTO"); reservadas.push_back("ESCREVA"); reservadas.push_back("FIM"); reservadas.push_back("FUNCAO"); reservadas.push_back("INICIO"); reservadas.push_back("LEIA"); reservadas.push_back("NULO"); reservadas.push_back("PARA"); reservadas.push_back("INTEIRO"); reservadas.push_back("PARE"); reservadas.push_back("REAL"); reservadas.push_back("RECEBA"); reservadas.push_back("SE"); reservadas.push_back("SENAO"); reservadas.push_back("VAR"); reservadas.push_back("VET");
  vector< pair<int,string> > TOKENS;
  vector< pair<int,string> >:: iterator it; // 0/reservada, 1/id, 2/num
  string s;
  bool arqv_inv = false, ok = false;
  char line[10000];
  int oi =0;
  while (fgets(line, 10000, stdin)) {
      buffer+= line;
  }

  for (i=0; i<buffer.size(); i++) {
      int tabela = (int)buffer[i];
      if (range.count(tabela) <= 0) {
          arqv_inv = true;
          bug = 1;
        }
  }
  if (buffer.size()== 0) {
      cout<<"OK"<<endl;
      ok= true;
  }
  else if (buffer.size()>0 && arqv_inv == true)
    fail();
  else {
  while (cont != buffer.size()) {
    //cout<<"linha colunas"<< linha <<" "<<coluna<<endl;
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
            abriu=true;
            if (cont == buffer.size()-1) {
              bug=1;
              if (lixo !=1) {
                  cout<< linha <<" " << coluna<<endl;
                }
              else{
                   cout<< linha <<" " << coluna+1<<endl;
                }
              s.clear();
              }
            else{
              state = 8;
            }
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
              //state= 6;  
            } 
         else {
            if(cont < buffer.size()) {
              erro(); state=0;   
            }
            else{
              break;   
            }
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
        else if (aux == 32 || aux==10 || aux==9){
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
           if(s.size()==512) {
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
        verificaLinha();
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
          if(s.size()==512) {
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
        	if (isalpha(buffer[cont]) != 0){
        		state=0; s.clear(); retract(); erro();
        	}
        	else {
        		state=0; s.clear(); retract();
        	}
            
        }
      }break;

      case 8: //string
      {
        getNextChar(); lixo =0;
        //cout<<linha<<" "<<coluna<<endl;
         int temp4 = int(buffer[cont]);
        if (cont ==  buffer.size()-1) {
          cout<<linha<<" "<<coluna-1<<endl;
          s.clear(); para = true; bug = 1;
        }
        if (buffer[cont]=='"') {
        	if (enter== true){
        		linha++; coluna=1;
        		enter=false;
        	}
            fechou=true;
            TOKENS.push_back(make_pair(1,s));
            s.clear();
            state=0;
          }
        else { // nao fechou
            if (s.size()==512) { // estourou
              if (enter==true) { // teve enter?
                  cout<< slinha <<" "<< scol<< endl;
                  bug=1;
                  linha++;
                  coluna=1;
                  state=0; s.clear();
                  enter=false;
                  lixo = 1;
              }
              else {
                  retract();
                  erro();
                  state=0; s.clear();
              }
              
            }
            else { // nao estourou
                if (enter== true) {
                    linha++; coluna=1; enter=false;
                }
                if (temp4==10) {
                  s.push_back(buffer[cont]);
                  enter= true;
                  scol = coluna; slinha = linha;
                  state=8;
                }
                else {
                    s.push_back(buffer[cont]);
                    state =8;  
                }
            }
          }
        }break;
      }
    }
  } 
  if (s.size() > 0 && para==false) {
    bug=1;
    if (error==1) {
      if (coluna==0) {
        cout<<slinha<<" "<<scol+1<<endl;
      }
      else {
        cout<<slinha<<" "<<scol<<endl;
      }
    }
    else
      cout<<linha<<" "<< coluna+1<<endl;
  }
  if (bug==0 && ok==false)
    cout<<"OK"<<endl;
  //cout<<endl;
}
