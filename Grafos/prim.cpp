#include <bits/stdc++.h>

using namespace std;
#define infinito 1000
#define root 2
//DECLARACOES DE VARIAVEIS
int nv, na, aresta,a,b,peso, u;
map<int, vector< pair<int,int> > >  grafo; //[v1] aponta com 'peso' para v2
vector<int> key; //valor do menor vertice chegando em key
vector<int> pai; //[v1] tem 'pai' 
vector<pair <int,int> > q; // v1 e key

//DECLARACAO DE FUNCOES
void MSTPRIM();
bool pertence();
void print();

//FUNCOES
int main(){

	cin >> nv;
	cin >> na;
	for(int i=0;i<na;++i){
		scanf("%d %d %d", &a,&b, &peso);
		grafo[a].push_back(make_pair(peso, b));
		grafo[b].push_back(make_pair(peso, a));
	}		
	MSTPRIM();
	print();
	return 0;
}
//--

bool pertence(int v2){
	for(int i=0;i<q.size();++i){
		if(v2 == q[i].second)
			return true;
	}
	return false;
}
//--

void MSTPRIM(){

	for(int i=0;i<nv;++i){
		key.push_back(infinito);
		pai.push_back(-1);
	}
	key[root]=0;
	for(int i=0;i<nv;++i){
		q.push_back(make_pair(key[i],i));
	}
	//----
	
	while(q.size()){
		sort(q.begin(), q.end());
		u=q[0].second;
		cout << "aqui: "<<u<<endl;
		q.erase(q.begin(), q.begin()+1);
		for(int i=0;i<grafo[u].size();++i){
			if(pertence(grafo[u][i].second) and grafo[u][i].first<key[grafo[u][i].second]){
				pai[grafo[u][i].second]=u;
				key[grafo[u][i].second]=grafo[u][i].first;
			}
		}
	}
}
//-- 	

void print(){
	cout << endl;
	cout << "Grafo: \n";
	for(int i=0;i<nv;++i){
		cout << i <<" -> ";
		for(int j=0; j<grafo[i].size();++j){
			cout << grafo[i][j].second<<"|" << grafo[i][j].first << "|" <<" -> ";
		}
		cout << "/" << endl;
	}
	cout << endl;

	cout << "Arvore gerada: \n";

	for(int i=0;i<nv;++i){
		if(pai[i]==-1)
			cout << "Pai do vértice |" << i << "|: -" <<endl;
		else
			cout << "Pai do vértice |" << i << "|: " << pai[i] << endl;
	}
}