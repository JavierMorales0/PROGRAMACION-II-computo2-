/*Arbol 		2				hay que hacerle el menu
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
		postorden (arbol->izq);
		postorden (arbol->der);
		cout<<arbol->nro<<"		";
	}
}

void inorden(ABB arbol){
	if(arbol!=NULL)
	{
		inorden (arbol->izq);
		cout<<arbol->nro<<"		";
		inorden (arbol->der);
	}
		
		
}

int contarhojas(ABB arbol){
	if (arbol==NULL){
		return 0; //arbol vacio
	} 
	if ((arbol->der ==NULL)&&(arbol->izq==NULL)){
		return 1; //si es hoja retorna el valor 1
	}
	else {
		//si no es hoja manda los hijos izquierdo y derecho
		return contarhojas(arbol->izq) + contarhojas(arbol->der);
	}
}

ABB unirABB(ABB izq, ABB der){
	if(izq==NULL) return der;
	if(der==NULL) return izq;
	
	ABB centro = unirABB(izq->der, der->izq);
	izq->der=centro;
	der->izq= izq;
	return der;
}

void eliminar (ABB &arbol, int x){
	if(arbol==NULL) return;
	if (x<arbol->nro)
	eliminar (arbol->izq, x);
	else if (x>arbol->nro)
	eliminar (arbol->der,x);
	else{
		ABB p= arbol;
		arbol=unirABB(arbol->izq, arbol->der);
		delete p;
	}
}

int main() {
	ABB arbol = NULL;
	int x;		//dato a insertar en el nodo
	int n;		//numero de nodos
	int aux;
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
	cout<<endl;
	cout<<"Mostrando el arbol en preorden"<<endl;
	preorden(arbol);
	cout<<endl;
	cout<<"Mostrando el arbol en postorden"<<endl;
	postorden(arbol);
	cout<<endl;
	cout<<"Mostrando el arbol en inorden"<<endl;
	inorden(arbol);
	cout<<endl;
	cout<<"Contar hojas"<<contarhojas(arbol)<<endl;
	cout<<endl;
	cout<<"Ingrese el valor de un nodo a eliminar: "<<endl;
	cin>>aux;
	eliminar(arbol, aux);
	cout<<endl;
	verarbol(arbol, n);
	system("pause");
	
	return 0;
}
