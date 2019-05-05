#include <iostream>
#include <windows.h>
using namespace std;

class Figura{
	
	private: 
			float base;
			float altura;
	public: 
			Figura(){
				this->base=0;
				this->altura=0;
			}
			Figura(float b, float a) //polimorfismo: usar un metodo con dos funcionabilidades diferentes
			{
				this->base=b;
				this->altura=a;
			}
			void setbase(float b){
				this->base=b;
			}
			float getbase(){
				return this->base;
			}
			void setaltura(float a){
				this->altura=a;
			}
			float getaltura(){
				return this->altura;
			}
			virtual float area()=0;		//virtual significa que despues se puede sobreescribir sobre el
			virtual float perimetro()=0;	//cualquier otra clase puede generar modificaciones
};

class Rectangulo:public Figura{  //rectangulo es hijo de figura y recibe todas sus propiedades y metodos
	public:
		float area(){
			return getbase()* getaltura();
		}
		float perimetro(){
			return 2*getbase()+2*getaltura();
		}
	void ImprimirR(){
		for(int i=0; i<getaltura(); i++){
			cout<<endl;
			for(int j=0; j<getbase(); j++){
				cout<<"* ";
			}
		}
		
	}
};


int main() {
	//Figura *t/*declarar*/=new Figura(0,0); //instanciar un objeto
	/*t->setbase(4);
	t->setaltura(2);
	cout<<t->getbase();
	cout<<t->getaltura();*/
	
	Rectangulo *r= new Rectangulo();
	r->setbase(6);
	r->setaltura(4);
	cout<<r->getbase()<<"   "<<r->getaltura()<<endl;
	cout<<"Area: "<<r->area()<<endl;
	cout<<"Perimetro: "<<r->perimetro()<<endl;
	r->ImprimirR();
	return 0;
}
