#include <iostream>
#include <locale>
#include <cstdlib>
#include <cmath>

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

       // Verifica��o posi��o inicial
       do{
       linha = 1 + rand()%8;
       colunaint = 1 + rand()%8;
       if(pecastab[linha][colunaint]=='o'){
                if((colunaint == 2||4||6||8 && linha == 1||3||5||7) || (colunaint == 1||3||5||7 && linha == 2||4||6||8)){
                    posicao_correta = true;
                }
       }
       }while(posicao_correta == false);
       // Verifica��o posi��o final
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
       bool posicao_correta = false, posicao_final_correta = false;
       char coluna, nova_coluna;
       int linha, colunaint, nova_colunaint, nova_linha, linha_intermediaria, linha_intermediaria2, coluna_intermediaria, coluna_intermediaria2, cont=0;
       cout << endl << "     Vez do Jogador 2" << endl;
       // Verifica��o posi��o inicial
       do{
       cout << "     Digite  a posi��o da pe�a que deseja mover (Exemplo: b 2): ";
       cin >> coluna >> linha;
       colunaint = (int)coluna - 96;

       if(pecastab[linha][colunaint]=='o'){
            if(pecastab[linha-1][colunaint-1]==' ' || pecastab[linha-1][colunaint+1] ==' '){
                if((colunaint == 2||4||6||8 && linha == 1||3||5||7) || (colunaint == 1||3||5||7 && linha == 2||4||6||8)){
                    posicao_correta = true;
                }
                else{
                    cout << "     Posi��o inv�lida" << endl;
                }
            }
            else{
                cout << "     Posi��o inv�lida" << endl;
            }
       }
       else{
         cout << "     Posi��o inv�lida" << endl;
       }

       }while(posicao_correta == false);
       // Verifica��o posi��o final
       do{
       cout << "     Digite a posi��o final da pe�a (Exemplo: d 4): ";
       cin >> nova_coluna >> nova_linha;
       nova_colunaint = (int)nova_coluna - 96;

       if((pecastab[nova_linha][nova_colunaint]=='1')||(pecastab[nova_linha][nova_colunaint]=='x') || (pecastab[nova_linha][nova_colunaint]=='o')){
          cout << "     Posi��o final inv�lida" << endl;
       }
       else{
            if((nova_colunaint == colunaint+1 || nova_colunaint == colunaint-1) && nova_linha == linha-1){
                if((nova_colunaint == 1||3||5||7 && nova_linha == 2||4||6||8) || (nova_colunaint == 2||4||6||8 && nova_linha == 1||3||5||7)){
                    pecastab[linha][colunaint] = ' ';
                    pecastab[nova_linha][nova_colunaint] = 'o';
                    posicao_final_correta = true;
                }
                else{
                    cout << "     Posi��o final inv�lida" << endl;
                }
            }
            else if(abs(nova_linha-linha)==2 && abs(nova_colunaint-colunaint)==2){
                    if(nova_linha>linha){
                        linha_intermediaria = nova_linha-1;
                    }
                    else{
                        linha_intermediaria = nova_linha+1;
                    }
                    if(nova_colunaint>colunaint){
                        coluna_intermediaria = nova_colunaint-1;
                    }
                    else{
                        coluna_intermediaria = nova_colunaint+1;
                    }
                    if(pecastab[linha_intermediaria][coluna_intermediaria]=='x'){
                        pecastab[linha][colunaint] = ' ';
                        pecastab[linha_intermediaria][coluna_intermediaria] = ' ';
                        pecastab[nova_linha][nova_colunaint] = 'o';
                        posicao_final_correta = true;
                    }
                    else{
                        cout << "     Posi��o final inv�lida" << endl;
                    }
            }
            else if((abs(nova_linha-linha)==4 && abs(nova_colunaint-colunaint)==4)||(nova_linha-linha==0 && abs(nova_colunaint-colunaint)==4)||(abs(nova_linha-linha)==4 && nova_colunaint-colunaint==0)){
                    if(nova_linha>linha){
                        if(nova_colunaint>colunaint){
                            linha_intermediaria2 = nova_linha-1;
                            linha_intermediaria = nova_linha-3;
                            coluna_intermediaria2 = nova_colunaint-1;
                            coluna_intermediaria = nova_colunaint-3;
                        }
                        else{
                            linha_intermediaria2 = nova_linha-1;
                            linha_intermediaria = nova_linha-3;
                            coluna_intermediaria2 = nova_colunaint+1;
                            coluna_intermediaria = nova_colunaint+3;
                        }
                    }
                    else if(nova_linha<linha){
                        if(nova_colunaint>colunaint){
                            linha_intermediaria2 = nova_linha+1;
                            linha_intermediaria = nova_linha+3;
                            coluna_intermediaria2 = nova_colunaint-1;
                            coluna_intermediaria = nova_colunaint-3;
                        }
                        else{
                            linha_intermediaria2 = nova_linha+1;
                            linha_intermediaria = nova_linha+3;
                            coluna_intermediaria2 = nova_colunaint+1;
                            coluna_intermediaria = nova_colunaint+3;
                        }
                    }
                    else if(nova_linha==linha){
                           if(pecastab[nova_linha-1][nova_colunaint-1]=='x' && pecastab[nova_linha-2][nova_colunaint-2]==' ' && pecastab[nova_linha-1][nova_colunaint-3]=='x'){
                              linha_intermediaria2 = nova_linha-1;
                              linha_intermediaria = nova_linha-1;
                              coluna_intermediaria2 = nova_coluna-1;
                              coluna_intermediaria = nova_coluna-3;
                           }
                           if(pecastab[nova_linha+1][nova_colunaint-1]=='x' && pecastab[nova_linha+2][nova_colunaint-2]==' ' && pecastab[nova_linha+1][nova_colunaint-3]=='x'){
                              linha_intermediaria2 = nova_linha+1;
                              linha_intermediaria = nova_linha+1;
                              coluna_intermediaria2 = nova_coluna-1;
                              coluna_intermediaria = nova_coluna-3;
                           }
                    }
                    if(pecastab[linha_intermediaria][coluna_intermediaria]=='x' && pecastab[linha_intermediaria2][coluna_intermediaria2]=='x'){
                        pecastab[linha][colunaint] = ' ';
                        pecastab[linha_intermediaria][coluna_intermediaria] = ' ';
                        pecastab[linha_intermediaria2][coluna_intermediaria2] = ' ';
                        pecastab[nova_linha][nova_colunaint] = 'o';
                        posicao_final_correta = true;
                    }
                    else{
                        cout << "     Posi��o final inv�lida" << endl;
                    }
            }
        }

       }while(posicao_final_correta == false);

       tabuleiro(pecastab);

       for(int i=1;i<9;i++){
         for(int j=1;j<9;j++){
            if(pecastab[i][j]=='x'){
                cont++;
            }
         }
       }
       if(cont==0){
         cout << "JOGADOR 2 VENCEU" << endl;
         fim_de_jogo = true;
       }

}
void jogador1(char pecastab[9][9], bool &fim_de_jogo, int um_ou_dois){
       bool posicao_correta = false, posicao_final_correta = false;
       char coluna, nova_coluna;
       int linha, colunaint, nova_colunaint, nova_linha, linha_intermediaria, coluna_intermediaria, linha_intermediaria2, coluna_intermediaria2, cont=0;
       if(um_ou_dois == 1){
          cout << endl << "     Vez do Jogador 1" << endl;
       }
       else{
          cout << endl << "     Sua vez" << endl;
       }
       // Verifica��o posi��o inicial
       do{
       cout << "     Digite  a posi��o da pe�a que deseja mover (Exemplo: b 2): ";
       cin >> coluna >> linha;
       colunaint = (int)coluna - 96;

       if(pecastab[linha][colunaint]=='x'){
            if((pecastab[linha+1][colunaint-1]==' ' || pecastab[linha+1][colunaint+1] ==' ')||(pecastab[linha+1][colunaint-1]=='o' || pecastab[linha+1][colunaint+1] =='o')){
                if((colunaint == 1||3||5||7 && linha == 2||4||6||8) || (colunaint == 2||4||6||8 && linha == 1||3||5||7)){
                    posicao_correta = true;
                }
                else{
                    cout << "     Posi��o inv�lida" << endl;
                }
            }
            else{
                cout << "     Posi��o inv�lida" << endl;
            }
       }
       else{
          cout << "     Posi��o inv�lida" << endl;
       }

       }while(posicao_correta == false);
       // Verifica��o posi��o final
       do{
       cout << "     Digite a posi��o final da pe�a (Exemplo: d 4): ";
       cin >> nova_coluna >> nova_linha;
       nova_colunaint = (int)nova_coluna - 96;

       if((pecastab[nova_linha][nova_colunaint]=='1')||(pecastab[nova_linha][nova_colunaint]=='x') || (pecastab[nova_linha][nova_colunaint]=='o')){
          cout << "     Posi��o final inv�lida" << endl;
       }
       else{
            if((nova_colunaint == colunaint+1 || nova_colunaint == colunaint-1) && nova_linha == linha+1){
                if((nova_colunaint == 1||3||5||7 && nova_linha == 2||4||6||8) || (nova_colunaint == 2||4||6||8 && nova_linha == 1||3||5||7)){
                    pecastab[linha][colunaint] = ' ';
                    pecastab[nova_linha][nova_colunaint] = 'x';
                    posicao_final_correta = true;
                }
                else{
                    cout << "     Posi��o final inv�lida" << endl;
                }
            }
            else if(abs(nova_linha-linha)==2 && abs(nova_colunaint-colunaint)==2){
                    if(nova_linha>linha){
                        linha_intermediaria = nova_linha-1;
                    }
                    else{
                        linha_intermediaria = nova_linha+1;
                    }
                    if(nova_colunaint>colunaint){
                        coluna_intermediaria = nova_colunaint-1;
                    }
                    else{
                        coluna_intermediaria = nova_colunaint+1;
                    }
                    if(pecastab[linha_intermediaria][coluna_intermediaria]=='o'){
                        pecastab[linha][colunaint] = ' ';
                        pecastab[linha_intermediaria][coluna_intermediaria] = ' ';
                        pecastab[nova_linha][nova_colunaint] = 'x';
                        posicao_final_correta = true;
                    }
                    else{
                        cout << "     Posi��o final inv�lida" << endl;
                    }
            }
            else if((abs(nova_linha-linha)==4 && abs(nova_colunaint-colunaint)==4)||(nova_linha-linha==0 && abs(nova_colunaint-colunaint)==4)||(abs(nova_linha-linha)==4 && nova_colunaint-colunaint==0)){
                    if(nova_linha>linha){
                        if(nova_colunaint>colunaint){
                            linha_intermediaria2 = nova_linha-1;
                            linha_intermediaria = nova_linha-3;
                            coluna_intermediaria2 = nova_colunaint-1;
                            coluna_intermediaria = nova_colunaint-3;
                        }
                        else{
                            linha_intermediaria2 = nova_linha-1;
                            linha_intermediaria = nova_linha-3;
                            coluna_intermediaria2 = nova_colunaint+1;
                            coluna_intermediaria = nova_colunaint+3;
                        }
                    }
                    else if(nova_linha<linha){
                        if(nova_colunaint>colunaint){
                            linha_intermediaria2 = nova_linha+1;
                            linha_intermediaria = nova_linha+3;
                            coluna_intermediaria2 = nova_colunaint-1;
                            coluna_intermediaria = nova_colunaint-3;
                        }
                        else{
                            linha_intermediaria2 = nova_linha+1;
                            linha_intermediaria = nova_linha+3;
                            coluna_intermediaria2 = nova_colunaint+1;
                            coluna_intermediaria = nova_colunaint+3;
                        }
                    }
                    else if(nova_linha==linha){
                           if(pecastab[nova_linha-1][nova_colunaint-1]=='o' && pecastab[nova_linha-2][nova_colunaint-2]==' ' && pecastab[nova_linha-1][nova_colunaint-3]=='o'){
                              linha_intermediaria2 = nova_linha-1;
                              linha_intermediaria = nova_linha-1;
                              coluna_intermediaria2 = nova_coluna-1;
                              coluna_intermediaria = nova_coluna-3;
                           }
                           if(pecastab[nova_linha+1][nova_colunaint-1]=='o' && pecastab[nova_linha+2][nova_colunaint-2]==' ' && pecastab[nova_linha+1][nova_colunaint-3]=='o'){
                              linha_intermediaria2 = nova_linha+1;
                              linha_intermediaria = nova_linha+1;
                              coluna_intermediaria2 = nova_coluna-1;
                              coluna_intermediaria = nova_coluna-3;
                           }
                    }
                    if(pecastab[linha_intermediaria][coluna_intermediaria]=='o' && pecastab[linha_intermediaria2][coluna_intermediaria2]=='o'){
                        pecastab[linha][colunaint] = ' ';
                        pecastab[linha_intermediaria][coluna_intermediaria] = ' ';
                        pecastab[linha_intermediaria2][coluna_intermediaria2] = ' ';
                        pecastab[nova_linha][nova_colunaint] = 'x';
                        posicao_final_correta = true;
                    }
                    else{
                        cout << "     Posi��o final inv�lida" << endl;
                    }
            }
        }

       }while(posicao_final_correta == false);

       tabuleiro(pecastab);

       for(int i=1;i<9;i++){
         for(int j=1;j<9;j++){
            if(pecastab[i][j]=='o'){
                cont++;
            }
         }
       }
       if(cont==0){
          cout << "JOGADOR 1 VENCEU" << endl;
          fim_de_jogo = true;
       }
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
          cout << endl << "      Jogador 1: pe�a x" << endl << "      Jogador 2: pe�a o" << endl;
          um_ou_dois = 1;
          do{
             jogador1(pecastab, fim_de_jogo, um_ou_dois);
             jogador2(pecastab, fim_de_jogo);
          }while(fim_de_jogo == false );
      }
      else{
          if(menu_choice == 2){
             tabuleiro(pecastab);
             cout << "     Voc� jogar� com as pe�as x" << endl;
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
