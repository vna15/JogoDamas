#include <iostream>
#define linhas 19
#define colunas 35


using namespace std;


void tabuleiro(char pecastab[9][9]){

       cout << "     a   b   c   d   e   f   g   h  " << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "1  ||||| "<<pecastab[1][2]<<" ||||| "<<pecastab[1][4]<<" ||||| "<<pecastab[1][6]<<" ||||| "<<pecastab[1][8]<<" |" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "2  | "<<pecastab[2][1]<<" ||||| "<<pecastab[2][3]<<" ||||| "<<pecastab[2][5]<<" ||||| "<<pecastab[2][7]<<" |||||" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "3  ||||| "<<pecastab[3][2]<<" ||||| "<<pecastab[3][4]<<" ||||| "<<pecastab[3][6]<<" ||||| "<<pecastab[3][8]<<" |" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "4  | "<<pecastab[4][1]<<" ||||| "<<pecastab[4][3]<<" ||||| "<<pecastab[4][5]<<" ||||| "<<pecastab[4][7]<<" |||||" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "5  ||||| "<<pecastab[5][2]<<" ||||| "<<pecastab[5][4]<<" ||||| "<<pecastab[5][6]<<" ||||| "<<pecastab[5][8]<<" |" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "6  | "<<pecastab[6][1]<<" ||||| "<<pecastab[6][3]<<" ||||| "<<pecastab[6][5]<<" ||||| "<<pecastab[6][7]<<" |||||" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "7  ||||| "<<pecastab[7][2]<<" ||||| "<<pecastab[7][4]<<" ||||| "<<pecastab[7][6]<<" ||||| "<<pecastab[7][8]<<" |" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "8  | "<<pecastab[8][1]<<" ||||| "<<pecastab[8][3]<<" ||||| "<<pecastab[8][5]<<" ||||| "<<pecastab[8][7]<<" |||||" << endl;
       cout << "   |---|---|---|---|---|---|---|---|" << endl;
       cout << "     a   b   c   d   e   f   g   h  " << endl;


}
int main()
{
      char coluna, nova_coluna;
      int linha, colunaint, nova_colunaint, nova_linha;
    char pecastab[9][9]  =  {' ',' ',' ',' ',' ',' ',' ',' ',' ',
                             ' ',' ','x',' ','x',' ','x',' ','x',
                             ' ','x',' ','x',' ','x',' ','x',' ',
                             ' ',' ','x',' ','x',' ','x',' ','x',
                             ' ',' ',' ',' ',' ',' ',' ',' ',' ',
                             ' ',' ',' ',' ',' ',' ',' ',' ',' ',
                             ' ','o',' ','o',' ','o',' ','o',' ',
                             ' ',' ','o',' ','o',' ','o',' ','o',
                             ' ','o',' ','o',' ','o',' ','o',' '};
      tabuleiro(pecastab);
   //char tabdama[linhas][colunas];
   //int menu_choice;
   //cout << "            MENU" << endl;
   //cout << "Digite 1 para jogar contra outro jogador" << endl << "Digite 2 para jogar contra o computador" << endl << "Digite 3 para sair" << endl;
   //cin >> menu_choice;
       cout << "Vez do Jogador 1" << endl;
       cout << "Digite  a posição da peça que deseja mover (Exemplo: b 2):" << endl;
       cin >> coluna >> linha;
       colunaint = (int)coluna - 96;
       cout << "Digite a posição final da peça (Exemplo: d 4):" << endl;
       cin >> nova_coluna >> nova_linha;
       nova_colunaint = (int)nova_coluna - 96;

       pecastab[linha][colunaint] = ' ';
       pecastab[nova_linha][nova_colunaint] = 'x';

       tabuleiro(pecastab);
   return 0;
}
