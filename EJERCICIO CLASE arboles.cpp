/*Arbol 		2
			7		5
		2  	6			9
			5	11		4
*/
#include <iostream>

using namespace std;

struct nodo{
	int nro;
	struct nodo *izq, *der;	
};
typedef struct nodo *ABB;

void insertar (ABB &arbol, int x){
	if(arbol==NULL){
		ABB nuevonodo= new (struct nodo);
		nuevonodo->nro=x;
		nuevonodo->izq=NULL;
		nuevonodo->der=NULL;
		arbol=nuevonodo;
	} else if(x<arbol->nro){
		insertar (arbol->izq, x);
		}
		else if(x>arbol->nro,x){
			insertar(arbol->der,x);
	}
}

void verarbol(ABB arbol, int n){
	if(arbol==NULL)
	return;
	verarbol(arbol->der, n+1);
	for(int i=0; i<n; i++){
		cout<<"	";
	}
	cout<<arbol->nro<<endl;
	verarbol(arbol->izq, n+1);
}

void preorden (ABB arbol){
	if(arbol!=NULL){
	
	cout<<arbol->nro<<"	";
	preorden(arbol->izq);
	preorden(arbol->der);
}
}

void postorden(ABB arbol){
	if(arbol!=NULL)
	{
		postorden (arbol->der);
		postorden (arbol->izq);
		cout<<arbol->nro<<"		";
	}
}

int main() {
	ABB arbol = NULL;
	int x;		//dato a insertar en el nodo
	int n;		//numero de nodos
	cout<<"ARBOL BINARIO"<<endl;
	cout<<"Ingrese el numero de nodos del arbol: "<<endl;
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"Ingrese el valor del nodo"<<endl;
		cin>>x;
		insertar (arbol,x);
	}
	cout<<"Mostrando el arbol"<<endl;
	verarbol(arbol, n);
	cout<<"Mostrando el arbol en preorden"<<endl;
	preorden(arbol);
	system("pause");
	return 0;
}
