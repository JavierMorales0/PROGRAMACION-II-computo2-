 #include <iostream>

using namespace std;

class Empleado{
	private: 	string nombre;
				string apellido;
				
	public:
			Empleado();
			void setNombre(string a){
				this->nombre=a;
			}
			string getNombre(){
				return this->nombre;
			}
			void setApellido(string a){
				this->apellido=a;
			}
			string getApellido(){
				return this->apellido;
			}
			
			
			virtual void imprimir();
};

class Horarios: public Empleado{
	private:	string horaEntrada;
				string horaSalida;
				Horarios *ptrsig;
	public:
				void setHoraEntrada(string a){
					this->horaEntrada=a;
				}
				string getHoraEntrada(){
					return this->horaEntrada;
				}
				void setHoraSalida(string a){
					this->horaSalida=a;
				}
				string getHoraSalida(){
					return this->horaSalida;
				}
				void setPtrsig(Horarios *x){
					this->ptrsig=x;
				}
				Horarios* getPtrsig(){
					return this->ptrsig;
				}
				virtual void imprimir();
};

class Fabrica{
	public:
		Horarios* agregarHoraEntrada(string a, Horarios *x){
			Horarios *e=new Horarios();
			e->setHoraEntrada(a);
			x=e;
			return x;
		}
		Horarios* agregarHoraSalida(string a, Horarios *x){
			Horarios *f=new Horarios();
			f->setHoraSalida(a);
			f->setPtrsig(x);
			x=f;
			return x;
		}
};

int main(int argc, char** argv) {
	Horarios *ant=NULL;
	Horarios *act=NULL;
	do{
		c();
		cout<<"\n\t\t         ¿Que operacion desea realizar?"<<endl;
		cout<<"\n\t\t\t         1- Agregar Hora de entrada."<<endl;
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
	return 0;
}
