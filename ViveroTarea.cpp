/*		PROGRAMA REALIZADO POR JAVIER MORALES
			MM18014
				FECHA: 21 ABRIL 2019
*/
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

void c();
void p();

class Hoja{
	private:
		string Forma;
		float Longitud;

	public:
		void setForma(string a){
			this->Forma=a;
		}
		string getForma(){
			return this->Forma;
		}
		void setLongitud(float b){
			this->Longitud=b;
		}
		float getLongitud(){
			return this->Longitud;
		}
};

class Tallo{
	private:
		float Longitud;

	public:
		void setLongitud(float a){
			this->Longitud=a;
		}
		float getLongitud(){
			return this->Longitud;
		}
};

class Arbol{

	private:
			string Ncomun;
			string Ncient;
			string Familia;
			Arbol *ptrant;
	public:

            Arbol(){
                this->Ncomun="";
                this->Ncient="";
                this->Familia="";
            }

			void setNcomun(string a){
				this->Ncomun=a;
			}
			string getNcomun(){
				return this->Ncomun;
			}
			void setNcient(string b){
				this->Ncient=b;
			}
			string getNcient(){
				return this->Ncient;
			}
			void setFamilia(string c){
				this->Familia=c;
			}
			string getFamilia(){
				return this->Familia;
			}
			void setprtant(Arbol *a){
				this->ptrant=a;
			}
			Arbol* getptrant(){
				return this->ptrant;
			}
			
			Hoja hoja; 	//Agregacion
			Tallo *tallo=new Tallo();	//composicion
		};


class Fabrica {
	public:
		
		Arbol* crearArbol(string a, string b, string c, string d, float x, Arbol *f){
						Arbol *arb= new Arbol();
						arb->setNcomun(a);
						arb->setNcient(b);
						arb->setFamilia(c);
						arb->hoja.setForma(d);
						arb->hoja.setLongitud(x);
						arb->setprtant(f);
						f= arb;
						cout<<endl;
						cout<<"\n\t\t\t         ";
						cout<<"Arbol insertado correctamente."<<endl<<endl;
						return f;	
		}
		void ImprimirR(Arbol *a){
			cout<<"Nombre: "<<"   "<<"Nombre cientifico: "<<"	"<<"Familia: "<<"	"<<"Forma de la hoja: "<<"    "<<"Longitud de la hoja: "<<"     "<<endl;
					while(a!=NULL)
					{
						cout<<a->getNcomun()<<"------------"<<a->getNcient()<<"----------"<<a->getFamilia()<<"-----------"<<a->hoja.getForma()<<"--------------"<<a->hoja.getLongitud()<<"-------"<<endl;
						a=a->getptrant();
					}
		
		}
		
		void BuscarR(string n, Arbol *a){
			while(a!=NULL)
					{
						if(n==a->getNcomun()){
							cout<<endl;
							cout<<"\n\t\t\t\t         ";
							cout<<"Nombre del arbol: "<<a->getNcomun()<<endl<<"\n\t\t\t\t         "<<"Nombre cientifico: "<<a->getNcient()<<endl<<"\n\t\t\t\t         "<<"Familia: "<<a->getFamilia()<<endl<<"\n\t\t\t\t         "<<"Forma de la hoja: "<<a->hoja.getForma()<<endl<<"\n\t\t\t\t         "<<"Longitud de la hoja: "<<a->hoja.getLongitud()<<endl<<endl;
						}
						
						a=a->getptrant();
					}
		}
		
		string EliminarR(string n, Arbol *a){
			Arbol *aux;
			Arbol *auxi;
			Arbol *aw=a;
			string au;
			while(a!=NULL)
					{
						if(n==a->getNcomun()){
							
							aux=a->getptrant();
							auxi=a;
							au=a->getNcomun();
					}
					a=a->getptrant();
		}
		while(aw!=NULL)
					{
						if(auxi==aw->getptrant()){
							
							aw->setprtant(aux);
							cout<<aw->getptrant();
					}
					aw=aw->getptrant();
		}
		delete auxi;
		
		return au;
	}
};

void c(){
	system("cls");
}

void p(){
	system("pause");
}

int main() {
	system ("color 70");
	int select;
	Arbol *pru;
	Arbol *ant= NULL;
	do{
		c();
		cout<<"\n\t\t         ¿Que operacion desea realizar?"<<endl;
		cout<<"\n\t\t\t         1- Agregar arbol."<<endl;
		cout<<"\n\t\t\t         2- Listar arboles."<<endl;
		cout<<"\n\t\t\t         3- Buscar arboles."<<endl;
		cout<<"\n\t\t\t         4- Eliminar arboles."<<endl;
		cout<<"\n\t\t\t         5- Salir."<<endl;
		cout<<"\n\t\t\t         ";cin>>select;
		switch(select){
		case 1: 	{
			
		string Ncom, Ncien, Fam,For;
					float Lon;
					c();
					cout<<"\n\t\t\t         ";
					cout<<"Ingrese nombre del arbol:";
					cin>>Ncom;
					cout<<"\n\t\t\t         ";
					cout<<"Ingrese nombre cientifico del arbol:";
					cin>>Ncien;
					cout<<"\n\t\t\t         ";
					cout<<"Ingrese familia del arbol:";
					cin>>Fam;
					cout<<"\n\t\t\t         ";
					cout<<"Ingrese forma de las hojas:";
					cin>>For;
					cout<<"\n\t\t\t         ";
					cout<<"Ingrese longitud de las hojas:";
					cin>>Lon;
					Fabrica *fab= new Fabrica();
					pru=fab->crearArbol(Ncom, Ncien,  Fam,  For,  Lon, ant);
					ant=pru;
					p();}
			break;
		case 2: { Fabrica *imp= new Fabrica();
					c();
					imp->ImprimirR(ant);
					p();
		}
			break;
		case 3: { 	string busqueda;
					c();
					cout<<"\n\t\t\t         ";
					cout<<"Ingrese nombre a buscar: ";
					cin>>busqueda;
					Fabrica *bus= new Fabrica();
					cout<<"\n\t\t\t         ";
					bus->BuscarR(busqueda, ant);
					p();
		}
			break;
		case 4: {
			string eliminar;
					c();
					cout<<"\n\t\t\t         ";
					cout<<"Ingrese nombre de arbol a eliminar: ";
					cin>>eliminar;
					cout<<endl;
					Fabrica *eli= new Fabrica();
					eliminar=eli->EliminarR(eliminar, ant);
					cout<<"\n\t\t\t         ";
					cout<<"Arbol eliminado fue: "<<eliminar<<endl<<endl;
					p();
		}
			break;	
	}
		
	} while(select!=5);
	

}
