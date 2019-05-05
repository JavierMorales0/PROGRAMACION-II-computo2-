#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

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
			Hoja hoja; 	//Agregacion
			Tallo *tallo=new Tallo();	//composicion
		};

class ArbolFrutal:public Arbol{
	void contarfrutos(){
		cout<<"tiene muchos frutos"<<endl;
	}
};

class ArbolOrnamental:public Arbol{

};

class Tamarindo: public ArbolFrutal{

};

class Fabrica {
	public:
		Arbol* crearArbol(int x){
			switch(x){
				case 1: return new ArbolFrutal();
						break;
				case 2: return new ArbolOrnamental();
						break;
			}
		}
};

int main() {

	Fabrica *fab= new Fabrica();
	Arbol *c=fab->crearArbol(1);
		c->setNcomun("Tamarindo");
		c->setNcient("Ftjiolk");
		c->setFamilia("Frutal");
		c->hoja.setForma("Circular");
		c->hoja.setLongitud(15);
		cout<<c->getNcomun()<<"   "<<c->getNcient()<<"	"<<c->getFamilia()<<"	"<<c->hoja.getForma()<<"    "<<c->hoja.getLongitud()<<"     "<<endl;
	Arbol *o=fab->crearArbol(2);
		o->setNcomun("Pino");
		o->setNcient("Gthfdf");
		o->setFamilia("Ornamental");
		cout<<o->getNcomun()<<"   "<<o->getNcient()<<"	"<<o->getFamilia()<<"	"<<endl;
/*	ArbolFrutal *c= new ArbolFrutal();

		c->setNcomun("Tamarindo");
		c->setNcient("Ftjiolk");
		c->setFamilia("Frutal");

	ArbolOrnamental *o= new ArbolOrnamental();
		o->setNcomun("Pino");
		o->setNcient("Gthfdf");
		o->setFamilia("Ornamental");


		cout<<c->getNcomun()<<"   "<<c->getNcient()<<"	"<<c->getFamilia()<<"	"<<endl;
		cout<<o->getNcomun()<<"   "<<o->getNcient()<<"	"<<o->getFamilia()<<"	"<<endl;*/
}
