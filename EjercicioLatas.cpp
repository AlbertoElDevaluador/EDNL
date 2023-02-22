#include<stdio.h>
#include<iostream>
#include<vector> 
#global
int Devorador(vector<int> c[]);
int ordenacion(vector<int> c[]);

using namespace std;
using std::vector;

int sumT = 45;
int sum =0;

int main(){
	int s=21, vector<int> c={4,3,6,5,22,10};	
	Devorador(c);	
}

int Devorador (vector<int> *c){
	
	int j= 0, i = 0, vector<int> s, sum = 0;
	
	auto c = ordenacion(&c);
	for(k = 0;k < 5; k++){
		cout<<"El vector candidatos ordenado:"<<c[k]<<", ";
	}
	cout<<endl;
	
	while(Solucion(sum) == false && !c){
		
		p = Seleccion(&c);
		sum = sum + c[i];
		c[i] = 0;
		
		if(Factible(p,sum)){
			s.push_back(i);
			j++;
		}
		
		i++;	
	}
}

bool Solucion (sum){
	
	if(sum >= sumT) return true;
	return false;
} 

int Seleccion(vector<int> *c){
	int i, aux;
	for(i=0; i < c.end(); i++){
		if(aux > c[i]) aux = i;
	}
	return i;//retorna la posicion de la lata que queremos usar
}

bool factible (int p, int s){
	int aux;
	aux =  sum + aux;
	if(aux < sumT) return true;
	return false;
}

vector<int> ordenacion (vector<int> *c){
	
	
	
}

