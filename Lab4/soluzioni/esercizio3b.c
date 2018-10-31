#include<stdio.h>
#define N 4

int valida(int g[N][N], int mossa);
void muovi(int g[N][N], int mossa);
int risolto(int g[N][N]);
void stampa(int g[N][N]);

int main(){
	int gioco[N][N]={{8,5,2,4},{11,1,0,7},{12,10,3,15},{9,13,14,6}};
	//int gioco[N][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,0,15}};
	int m;

	stampa(gioco);
	while(!risolto(gioco)){
		do{
			scanf("%d",&m);
		} while(!valida(gioco,m));
		muovi(gioco,m);
		stampa(gioco);
	}
	
	printf("\nbravo!");
}


int valida(int g[N][N], int mossa){
	int i, j;

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(g[i][j]==mossa){
				if( (i-1>=0 && g[i-1][j]==0) || (i+1<N && g[i+1][j]==0) || (j-1>=0 && g[i][j-1]==0) || (j+1<N && g[i][j+1]==0) )
					return 1;
				else
					return 0;
			}
}


void muovi(int g[N][N], int mossa){
	int i, j;
	int *m, *z;

	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			if(g[i][j]==mossa)
				m=&g[i][j];
			if(g[i][j]==0)
				z=&g[i][j];
		}

	*z=mossa;
	*m=0;
}


int risolto(int g[N][N]){
	int i, j, cont=1;

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(g[i][j]==cont)
				cont++;
			else{
				if(cont==16)
					return 1;
				else
					return 0;
			}
}


void stampa(int g[N][N]){
	int i, j;

	printf("\n\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf(" %3d", g[i][j]);
		}
		printf("\n");
	}
}


