#include <stdio.h>
#include <stdlib.h>
int**alloc_tab2d(int ordre)
{
    int**p,i;
    p=(int**)malloc(sizeof(int*)*ordre);
    if(p==NULL)
        {printf("ERREUR D ALLOCATION");
        exit(6);}
    for(i=0;i<ordre;i++){
        p[i]=(int*)malloc(sizeof(int)*ordre);
        if (p[i]==NULL)
        {
            printf("erreur d alllocation ");
            exit(7);
        }
    }
    return p;
}

void give(int **M,int ordre){
int i,j;
for(i=0;i<ordre;i++)
for(j=0;j<ordre;j++)
scanf("%d",&M[i][j]);
}
void show(int **M, int ordre){
int i,j;
for(i=0;i<ordre;i++){
printf("|");
for(j=0;j<ordre;j++)
printf(" %d",M[i][j]);
printf(" |\n");
}
}
int det_mat(int **M,int ordre){
int **com,i,j,k,det=0,b=1,c1,c2;

if(ordre==2){
det=det+(M[0][0]*M[1][1]-M[1][0]*M[0][1]);
return det;
}
else{
com=alloc_tab2d(ordre);
for(i=0;i<ordre;i++){
c1=0,c2=0;
for(j=0;j<ordre;j++)
for(k=0;k<ordre;k++)
if(j!=0 && k!=i){
com[c1][c2]=M[j][k];
c2++;
if(c2==ordre-1)
{
    c1++;
    c2=0;

}
}
det=det+b*(M[0][i]*det_mat(com,ordre-1));
b=-1*b;
}
}
return det;
}
int main(){
int **M,n;
printf("What is your matrix level (enter any intiger >= 2 ): ");
scanf("%d",&n);
M=alloc_tab2d(n);
printf("\nEnter the value of your matrix one by one:\n");
give(M,n);
printf("\nYour matrix is :\n");
show(M,n);
printf("\nThe determinant is %d",det_mat(M,n));

return 0;

}
