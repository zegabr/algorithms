
#include <bits/stdc++.h>
using namespace std;
int tab[9][9], sol[9], fl, fc, t,qsol;

void resettab(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            tab[i][j]=0;
}
void printsol(){
    qsol++;
    printf("%2d",qsol);

    printf("%7d",sol[1]);
    for(int i=2;i<9;i++)
        printf(" %d",sol[i]);
    printf("\n");

}

bool pode(int a, int b){
    for (int j = 1; j < 9; j++) //olha linha
        if (tab[a][j] == 1)
            return false;
    ////diagoinauis
    for (int i = a - 1, j = b - 1; i >= 1 && j >= 1; i--, j--) //pra cima-esquerda
        if (tab[i][j] == 1)
            return false;
    for (int i = a - 1, j = b + 1; i >= 1 && j <= 8; i--, j++) //pra direita cima
        if (tab[i][j] == 1)
            return false;
    for (int i = a + 1, j = b - 1; i <= 8 && j >= 1; i++, j--) //pra esquerda baixo
        if (tab[i][j] == 1)
            return false;
    for (int i = a + 1, j = b + 1; i <= 8 && j <= 8; i++, j++) //pra direita baixo
        if (tab[i][j] == 1)
            return false;

    return true;
}
void putqueen(int coluna){
    if (coluna != fc){
        for (int i = 1, j = coluna; i < 9; i++){
            if(pode(i,j)){
                tab[i][j]=1;//poe rainha
                sol[coluna]=i;//guarda solucao
                
                if(coluna==8){//colocou ultima rainha da solucao
                    printsol();
                    
                }else{//passar pra proxima coluna
                    putqueen(coluna+1);

                }
            }
            tab[i][j]=0;//tira rainha
        }
    }else if(coluna<8){//ainda tem rainhas para colocar
        putqueen(coluna+1);
     }else if(coluna==8){//caso onde a fixa está na ultima coluna (coluna==fc==8), nao tirar rainha daqui
         printsol();
     }
}

int main()
{
    scanf("%d ",&t);
    for(int k=0;k<t;k++){
        scanf("%d %d",&fl,&fc);
        resettab();
        qsol=0;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        tab[fl][fc]=1;
        sol[fc]=fl;
        putqueen(1);
        if(k!=t-1)
            printf("\n");

    }



    return 0;
}
