#include <stdio.h>
#include <stdlib.h>

int main() {
int w=0;
int inp;

    do{
    printf("Banker's Algorithm Project\n");
    printf("Created by:\nAbrar Alaa Abdulsalam\nHussein Ahmed Saeed");

    printf("\n\n\nStart[0]\n");
    do{
    printf("Enter:");
    scanf("%d",&inp);
    if(inp != 0)
    printf("this command is not exist!\n");
    }while(inp != 0);

    system("cls");

    int processes, resources;
    int R_finished=0;
    int v=0;
    int P_sum=0;
    int P_previous=0;
    int fail=0;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("\nEnter the number of resources: ");
    scanf("%d", &resources);
    system("cls");

    int Allocation[processes][resources];
    int Max[processes][resources];
    int Need[processes][resources];
    int Work[resources];
    int P_check[processes];
    int P_show[processes];
    char R_input[resources];
    char R_transfer;
    int R_int;

    for(int i=0; i < processes; i++){
    P_check[i]=0;
    P_show[i]=0;
    }

    printf("Enter the Allocation elements:\n");
    for (int i = 0; i < processes; i++) {
     printf("P%d:",i);
     scanf("%s",&R_input);
     for (int j = 0; j < resources; j++) {
    R_transfer=R_input[j];
    R_int=((int) R_transfer)-48;
    Allocation[i][j]=R_int;
     }
     }

    printf("\nEnter the Max elements:\n");
    for (int i = 0; i < processes; i++) {
    printf("P%d:",i);
    scanf("%s",&R_input);
     for (int j = 0; j < resources; j++) {
    R_transfer=R_input[j];
    R_int=((int) R_transfer)-48;
    Max[i][j]=R_int;
     }
     }

    printf("\nEnter the Available elements:");
    scanf("%s",&R_input);
    for (int i= 0; i< resources; i++) {
    R_transfer=R_input[i];
    R_int=((int) R_transfer)-48;
    Work[i]=R_int;
    }

    system("cls");

    for (int i = 0; i < processes; i++) {
    for (int j = 0; j < resources; j++) {
    Need[i][j] =Max[i][j] - Allocation[i][j];
    //max smaller than allocation
    if(Need[i][j]<0){
    Need[i][j]=Need[i][j]*-1;
    }
    //max smaller than allocation
    }}

    printf("Allocation Matrix:\n");
    for (int i = 0; i < processes; i++) {
    for (int j = 0; j < resources; j++) {
    printf("%d ", Allocation[i][j]);
    }
    printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (int i = 0; i < processes; i++) {
    for (int j = 0; j < resources; j++) {
    printf("%d ", Max[i][j]);
    }
    printf("\n");
    }

    printf("\nNeed = Max - Allocated:\n");
    for (int i = 0; i < processes; i++) {
    for (int j = 0; j < resources; j++) {
    printf("%d ", Need[i][j]);
    }
    printf("\n");
    }

    printf("\nWork Vector:\n");
    for (int i = 0; i < resources; i++) {
    printf("%d ", Work[i]);
    }
    printf("\n");

    printf("\n\n\nContinue[0]\n");
    do{
    printf("Enter:");
    scanf("%d",&inp);
    if(inp != 0)
    printf("this command is not exist!\n");
    }while(inp != 0);

    system("cls");
    do{
    P_sum=0;

    for(int p=0; p<processes; p++){
    if(P_check[p]==0){
    for(int r=0; r<resources; r++){
    if(Work[r]>=Need[p][r]){
    R_finished++;}}

    if(R_finished==resources){
    printf("P%d will be executed\n",p);
    printf("New Work=Present Work+Allocation of P%d\n",p);
    printf("New Work=");
    for(int r=0; r<resources; r++){
    Work[r]=Work[r]+Allocation[p][r];
    printf("%d ",Work[r]);
    }
    printf("\n\n");
    P_show[v]=p;
    v++;
    P_check[p]=1;}}
    R_finished=0;
    }

    for(int s=0; s<processes ; s++){
    P_sum=P_sum+P_check[s];}

    if(P_sum==P_previous) {fail=1; P_sum=processes;}
    else {P_previous=P_sum;}
    }while(P_sum != processes);

    if(fail==1){
    printf("The system is not in a safe state!");}

    else{
    printf("The system is in a safe state and the processes will be executed in the following order:\n\n");
    printf("<");
    for(int i=0; i<processes; i++){
    printf("P%d,",P_show[i]);}
    printf("\b>");}

    printf("\n\n\nMain Menu[0]:");
    scanf("%d",&w);
    system("cls");
    }while(w==0);

    printf("Exit!");
    return 0;
}
