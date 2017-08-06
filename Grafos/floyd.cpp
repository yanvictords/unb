#include <bits/stdc++.h>
using namespace std;
double matriz[100][100];
//int pred[100][100];

int main(){
	int n,m,a,b;
	double p;
	scanf("%d", &n);
	while(n > 0){
		scanf("%d", &m);
//inicializa matriz
		for(int i=0; i<n;++i)	
			for(int j=0;j<n;++j){
					matriz[i][j]=0;	
					//pred[i][j]=-1;
			}
//preenche matriz
		for(int i=0;i<m;++i){
			scanf("%d %d %lf", &a, &b, &p);
			a--;b--;
			matriz[a][b]=p/100;
			matriz[b][a]=p/100;
		}	
//floyd warshall
		for(int k=0; k<n; ++k)
			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j){
					if(matriz[i][j] < matriz[i][k]*matriz[k][j]){
						matriz[i][j]=matriz[i][k]*matriz[k][j];
						//pred[i][j]=pred[k][j];
					}	
				}
//fim floyd warshall
//print matriz de probabilidades atualizada 
/*cout << "Matriz de probabilidades após floyd Warshall...\n\n";
	for(int i=0; i<n;++i){
		for(int j=0;j<n;++j){
			printf("%.1lf ", matriz[i][j]);
		}	
		cout << endl;
	}
	cout << endl;*/
//print matriz predecessor
/*cout << "Matriz predecessor após floyd Warshall...\n\n";
	for(int i=0; i<n;++i){
		for(int j=0;j<n;++j){
			printf("%.1lf ", pred[i][j]);
		}	
		cout << endl;
	}
	cout << endl;*/
//print caminho mais seguro entre 1 e n-1
		printf("%.6lf percent\n", matriz[0][n-1]*100);
		scanf("%d", &n);
}
	return 0;
}
