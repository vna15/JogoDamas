#include <iostream>
#include <locale>
#include <cstdlib>

using namespace std;

void tabuleiro(char pecastab[9][9]){

       cout << endl;
       cout << "          a   b   c   d   e   f   g   h  " << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     1  ||||| "<<pecastab[1][2]<<" ||||| "<<pecastab[1][4]<<" ||||| "<<pecastab[1][6]<<" ||||| "<<pecastab[1][8]<<" |" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     2  | "<<pecastab[2][1]<<" ||||| "<<pecastab[2][3]<<" ||||| "<<pecastab[2][5]<<" ||||| "<<pecastab[2][7]<<" |||||" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     3  ||||| "<<pecastab[3][2]<<" ||||| "<<pecastab[3][4]<<" ||||| "<<pecastab[3][6]<<" ||||| "<<pecastab[3][8]<<" |" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     4  | "<<pecastab[4][1]<<" ||||| "<<pecastab[4][3]<<" ||||| "<<pecastab[4][5]<<" ||||| "<<pecastab[4][7]<<" |||||" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     5  ||||| "<<pecastab[5][2]<<" ||||| "<<pecastab[5][4]<<" ||||| "<<pecastab[5][6]<<" ||||| "<<pecastab[5][8]<<" |" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     6  | "<<pecastab[6][1]<<" ||||| "<<pecastab[6][3]<<" ||||| "<<pecastab[6][5]<<" ||||| "<<pecastab[6][7]<<" |||||" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     7  ||||| "<<pecastab[7][2]<<" ||||| "<<pecastab[7][4]<<" ||||| "<<pecastab[7][6]<<" ||||| "<<pecastab[7][8]<<" |" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "     8  | "<<pecastab[8][1]<<" ||||| "<<pecastab[8][3]<<" ||||| "<<pecastab[8][5]<<" ||||| "<<pecastab[8][7]<<" |||||" << endl;
       cout << "        |---|---|---|---|---|---|---|---|" << endl;
       cout << "          a   b   c   d   e   f   g   h  " << endl;


}
void computador(char pecastab[9][9], bool &fim_de_jogo){
       bool posicao_correta = false;
       int linha, colunaint, nova_colunaint, nova_linha;

       // Verificação posição inicial
       do{
       linha = 1 + rand()%8;
       colunaint = 1 + rand()%8;
       if(pecastab[linha][colunaint]=='o'){
            if(pecastab[linha-1][colunaint-1]==' ' || pecastab[linha-1][colunaint+1] ==' '){
                if((colunaint == 2||4||6||8 && linha == 1||3||5||7) || (colunaint == 1||3||5||7 && linha == 2||4||6||8)){
                    posicao_correta = true;
                }
            }
       }
       }while(posicao_correta == false);
       // Verificação posição final
       do{
       nova_colunaint = 1 + rand()%8;
       nova_linha = 1 + rand()%8;
       if((pecastab[nova_linha][nova_colunaint]=='1') || (pecastab[nova_linha][nova_colunaint]=='o') || (pecastab[nova_linha][nova_colunaint]=='x')){
          posicao_correta = false;
       }
       else{
            if((nova_colunaint == colunaint-1 || nova_colunaint == colunaint+1) && nova_linha == linha-1){
                if(nova_colunaint == 1||3||5||7 && nova_linha == 2||4||6||8){
                    posicao_correta = true;
                }
                else{
                    posicao_correta = false;
                }
            }
            else{
               posicao_correta = false;
            }
       }
       }while(posicao_correta == false);

       pecastab[linha][colunaint] = ' ';
       pecastab[nova_linha][nova_colunaint] = 'o';

       tabuleiro(pecastab);
       fim_de_jogo = false;
}

void jogador2(char pecastab[9][9], bool &fim_de_jogo){
       bool posicao_correta = false;
       char coluna, nova_coluna;
       int linha, colunaint, nova_colunaint, nova_linha;
       cout << endl << "     Vez do Jogador 2" << endl;
       // Verificação posição inicial
       do{
       cout << "     Digite  a posição da peça que deseja mover (Exemplo: b 2): ";
       cin >> coluna >> linha;
       colunaint = (int)coluna - 96;

       if(pecastab[linha][colunaint]=='o'){
            if(pecastab[linha-1][colunaint-1]==' ' || pecastab[linha-1][colunaint+1] ==' '){
                if((colunaint == 2||4||6||8 && linha == 1||3||5||7) || (colunaint == 1||3||5||7 && linha == 2||4||6||8)){
                    posicao_correta = true;
                }
                else{
                    cout << "     Posição inválida" << endl;
                }
            }
            else{
                cout << "     Posição inválida" << endl;
            }
       }
       else{
         cout << "     Posição inválida" << endl;
       }

       }while(posicao_correta == false);
       // Verificação posição final
       do{
       cout << "     Digite a posição final da peça (Exemplo: d 4): ";
       cin >> nova_coluna >> nova_linha;
       nova_colunaint = (int)nova_coluna - 96;

       if((pecastab[nova_linha][nova_colunaint]=='1') || (pecastab[nova_linha][nova_colunaint]=='o') || (pecastab[nova_linha][nova_colunaint]=='x')){
          posicao_correta = false;
          cout << "     Posição final inválida" << endl;
       }
       else{
            if((nova_colunaint == colunaint-1 || nova_colunaint == colunaint+1) && nova_linha == linha-1){
                if(nova_colunaint == 1||3||5||7 && nova_linha == 2||4||6||8){
                    posicao_correta = true;
                }
                else{
                    posicao_correta = false;
                    cout << "     Posição final inválida" << endl;
                }
            }
            else{
                posicao_correta = false;
                cout << "     Posição final inválida" << endl;
            }
       }

       }while(posicao_correta == false);

       pecastab[linha][colunaint] = ' ';
       pecastab[nova_linha][nova_colunaint] = 'o';

       tabuleiro(pecastab);
       fim_de_jogo = false;
}
void jogador1(char pecastab[9][9], bool &fim_de_jogo, int um_ou_dois){
       bool posicao_correta = false;
       char coluna, nova_coluna;
       int linha, colunaint, nova_colunaint, nova_linha;
       if(um_ou_dois == 1){
          cout << endl << "     Vez do Jogador 1" << endl;
       }
       else{
          cout << endl << "     Sua vez" << endl;
       }
       // Verificação posição inicial
       do{
       cout << "     Digite  a posição da peça que deseja mover (Exemplo: b 2): ";
       cin >> coluna >> linha;
       colunaint = (int)coluna - 96;

       if(pecastab[linha][colunaint]=='x'){
            if(pecastab[linha+1][colunaint-1]==' ' || pecastab[linha+1][colunaint+1] ==' '){
                if((colunaint == 1||3||5||7 && linha == 2||4||6||8) || (colunaint == 2||4||6||8 && linha == 1||3||5||7)){
                    posicao_correta = true;
                }
                else{
                    cout << "     Posição inválida" << endl;
                }
            }
            else{
                cout << "     Posição inválida" << endl;
            }
       }
       else{
          cout << "     Posição inválida" << endl;
       }

       }while(posicao_correta == false);
       // Verificação posição final
       do{
       cout << "     Digite a posição final da peça (Exemplo: d 4): ";
       cin >> nova_coluna >> nova_linha;
       nova_colunaint = (int)nova_coluna - 96;

       if((pecastab[nova_linha][nova_colunaint]=='1')||(pecastab[nova_linha][nova_colunaint]=='x') || (pecastab[nova_linha][nova_colunaint]=='o')){
          posicao_correta = false;
          cout << "     Posição final inválida" << endl;
       }
       else{
            if((nova_colunaint == colunaint+1 || nova_colunaint == colunaint-1) && nova_linha == linha+1){
                if((nova_colunaint == 1||3||5||7 && nova_linha == 2||4||6||8) || (nova_colunaint == 2||4||6||8 && nova_linha == 1||3||5||7)){
                    posicao_correta = true;
                }
                else{
                    posicao_correta = false;
                    cout << "     Posição final inválida" << endl;
                }
            }
            else{
                posicao_correta = false;
                cout << "     Posição final inválida" << endl;
            }
       }

       }while(posicao_correta == false);

       pecastab[linha][colunaint] = ' ';
       pecastab[nova_linha][nova_colunaint] = 'x';

       tabuleiro(pecastab);
       fim_de_jogo = false;
}
int main()
{
      setlocale(LC_ALL, "Portuguese");
      bool fim_de_jogo = false;
      int menu_choice, um_ou_dois;

      char pecastab[9][9]  =  {'1','1','1','1','1','1','1','1','1',
                               '1','1','x','1','x','1','x','1','x',
                               '1','x','1','x','1','x','1','x','1',
                               '1','1','x','1','x','1','x','1','x',
                               '1',' ','1',' ','1',' ','1',' ','1',
                               '1','1',' ','1',' ','1',' ','1',' ',
                               '1','o','1','o','1','o','1','o','1',
                               '1','1','o','1','o','1','o','1','o',
                               '1','o','1','o','1','o','1','o','1'};

      cout << "                    MENU" << endl;
      cout << "     Digite 1 para jogar contra outro jogador" << endl;
      cout << "     Digite 2 para jogar contra o computador" << endl;
      cout << "     Digite 3 para sair" << endl;
      cin >> menu_choice;
      if(menu_choice == 1){
          tabuleiro(pecastab);
          cout << endl << "      Jogador 1: peça x" << endl << "      Jogador 2: peça o" << endl;
          um_ou_dois = 1;
          do{
             jogador1(pecastab, fim_de_jogo, um_ou_dois);
             jogador2(pecastab, fim_de_jogo);
          }while(fim_de_jogo == false );
      }
      else{
          if(menu_choice == 2){
             tabuleiro(pecastab);
             cout << "     Você jogará com as peças x" << endl;
             um_ou_dois = 2;
             do{
               jogador1(pecastab, fim_de_jogo, um_ou_dois);
               computador(pecastab, fim_de_jogo);
             }while(fim_de_jogo == false);
          }
          else{
             return 0;
          }
      }

      return 0;
}
