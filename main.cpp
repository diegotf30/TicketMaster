#include <cstdlib> //Para system()
#include <fstream>
#include <map> //Para compras
#include <sstream> //Para istringstream

#include "Evento.h"
#include "Deporte.h"
#include "Concierto.h"
#include "Festival.h"

#include "Usuario.h"
#include "Boleto.h"

using namespace std;

void despliegaOpciones(string sEventType, vector<Evento*> eventos, map<int, string> &compras) {
	int iCount = 1;
	for(int i = 0; i < eventos.size(); i++) {
		if(eventos[i]->getType() == sEventType) {
			compras[iCount] = eventos[i]->getNombre();
			int iBolDisp = eventos[i]->getCapacidad() - eventos[i]->getBoletosComprados();

			cout << "     " << iCount << ". " << eventos[i]->getNombre() << " - ";
			if(sEventType == "Festival") {
				cout << eventos[i]->getFecha() << endl;
			}
			else if(sEventType == "Concierto") {
				//Hacemos cast para que arreglo de Superclase nos de acceso a metodos de Subclase
				cout << ((Concierto*)eventos[i])->getBanda() << endl;
			}
			else { //sEventType == "Deporte"
				cout << ((Deporte*)eventos[i])->getEquipos();
				cout << '(' << ((Deporte*)eventos[i])->getDeporte() << ')' << endl;
			}
			cout << "\tFecha: " << eventos[i]->getFecha() << endl;
			cout << "\tLugar: " << eventos[i]->getLugar() << endl;
			cout << "\tBoletos a $" << eventos[i]->getPrecio();
			cout << " | DISPONIBLES: " << iBolDisp << endl;

			if(sEventType == "Festival") {
				vector<string> auxBandasFestival = ((Festival*)eventos[i])->getBandas();
				for(int i = 0; i < auxBandasFestival.size(); i++) {
					cout << "\t  • " << auxBandasFestival[i] << endl;
				}
			}
			cout << "----------------------------------------------------" << endl;
			iCount++;
		}
	}
}

void showOptions(char cOption, Usuario &user, vector<Evento*> eventos) {
	map<int, string> compras; //Lo usamos para ligar numero desplegado con el Evento
	system("cls");
	switch(cOption) {
		case '1':
			cout << "Conciertos:" << endl;
			despliegaOpciones("Concierto", eventos, compras);
			break;
		case '2':
			cout << "Deportes:" << endl;
			despliegaOpciones("Deporte", eventos, compras);
			break;
		case '3':
			cout << "Festivales:" << endl;
			despliegaOpciones("Festival", eventos, compras);
			break;
		case '4':
		{
			int iBoleto = -1;
			while(iBoleto != 0) {
				cout << "Cuenta ID: #" << user.getNumCuenta() << endl;
				cout << "Nombre: " << user.getNombre() << endl;
				cout << "Correo: " << user.getCorreo() << endl << endl;
				cout << "Historial de compras:" << endl;
				user.verCompras();
				cout << "Desea examinar algun boleto? (Si ninguno ingrese 0)" << endl;
				cin >> iBoleto;
				if(iBoleto > 0 && iBoleto <= user.getCompras().size()) {
					user.verBoleto(user.getCompras()[iBoleto - 1]);
					cout << "\nPresione ENTER para volver a la pantalla pasada" << endl;
                    cin.ignore(); //Para ignorar primer ENTER (gracias al cin pasado)
                    cin.ignore();
					system("cls");
				}
				else if(iBoleto > user.getCompras().size()) {
					system("cls");
					cout << "---------------------------------------------------------" << endl;
					cout << "ERROR: Indice invalido! Seleccione un boleto de la lista" << endl;
					cout << "---------------------------------------------------------" << endl;
				}
			}
			break;
		}
	}
	if(cOption != '4') {
		int iBoleto = 0;
		bool bPrimeraCompra = true;
		cout << "Que boleto desea comprar? (Si ninguno ingrese 0)" << endl;
		cin  >> iBoleto;

		while(iBoleto != 0) {
			if(!bPrimeraCompra) {
				cout << "Desea hacer otra compra? (Si quiere salir ingrese 0)" << endl;
				cin >> iBoleto;
			}
			else
				bPrimeraCompra =  false;

			if(iBoleto > 0) {
				int i = 0;
				//Encuentra boleto con Num a comprar
				while(i < eventos.size() && compras[iBoleto] != eventos[i]->getNombre()) {i++;}
				if(i < eventos.size()) {
					user.compraBoleto(eventos[i]);
				}
				else
					cout << endl << "ERROR! No existe un evento con ese numero" << endl << endl;
			}
		}
	}
	system("cls");
}

void llenaEvento(Evento &event, ifstream& ifInput) {
	string sAux = "";
	//Nombre de evento
	getline(ifInput, sAux);
	event.setNombre(sAux);
	//Fecha
	getline(ifInput, sAux);
	event.setFecha(sAux);
	//Lugar
	getline(ifInput, sAux);
	event.setLugar(sAux);
	//Capacidad
	getline(ifInput, sAux);
	int iCap = 0;
	istringstream(sAux) >> iCap;
	event.setCapacidad(iCap);
	//Precio
	getline(ifInput, sAux);
	double dPrecio = 0;
	stringstream(sAux) >> dPrecio;
	event.setPrecio(dPrecio);
	//Boletos Comprados
	getline(ifInput, sAux);
	int iBol = 0;
	istringstream(sAux) >> iBol;
	event.setBoletosComprados(iBol);
}

vector<Evento*> getEventos() {
	vector<Evento*> eventos; //Arreglo apunta a clases hijo
	ifstream ifInput;
	ifInput.open("events.txt");
	if(ifInput.bad()) {
		cout << "ERROR 404: Events.txt not found" << endl;
		return vector<Evento*>();
	}

    string sCantEventos;
    getline(ifInput, sCantEventos);

    string sAux, sType;
    for(int i = 0; i < sCantEventos[0] - '0'; i++) {
        //Festival hara getline hasta llegar a separador ("--------")
        //	  por lo que no es necesario descartar otra linea.
		if(eventos.size() == 0 || eventos[eventos.size() - 1]->getType() != "Festival")
			getline(ifInput, sAux); //Linea basura, descartada
		getline(ifInput, sType);

		Evento eventoAux;
		eventoAux.setType(sType);
		if(sType == "Concierto") {
			llenaEvento(eventoAux, ifInput);

			string sNomBanda = "";
			getline(ifInput, sNomBanda);
            eventos.push_back(new Concierto(eventoAux, sNomBanda)); //Guardamos concierto
		}
		else if(sType == "Deporte") {
			llenaEvento(eventoAux, ifInput);

			string sNomDeporte = "";
			getline(ifInput, sNomDeporte);
			string sEquipos = "";
			getline(ifInput, sEquipos);
			eventos.push_back(new Deporte(eventoAux, sNomDeporte, sEquipos)); //Guardamos Deporte
		}
		else { //Festival
			llenaEvento(eventoAux, ifInput);

			vector<string> vsBandas;
			getline(ifInput, sAux);
			while(sAux[0] != '-') {
				vsBandas.push_back(sAux);
				getline(ifInput, sAux);
			}
			eventos.push_back(new Festival(eventoAux, vsBandas)); //Guardamos Festival
		}
    }
    ifInput.close();

    return eventos;
}

int main()
{
    Usuario user("Ian Sommerville", "ian@gmail.com", 83152000, vector<Boleto>());
    vector<Evento*> eventos = getEventos();
	string keyPress = "";
	while(keyPress[0] != '9') {
		cout << "~~~~~~~~~~~BIENVENIDO A TICKET MASTER!~~~~~~~~~~~" << endl;
		cout << "Eventos:" << endl;
		cout << "     1. Conciertos" << endl;
		cout << "     2. Deportes" << endl;
		cout << "     3. Festivales" << endl;
		cout << "--------------------------" << endl;
		cout << "     4. Cuenta" << endl;
		cout << "--------------------------" << endl;
		cout << "     9. SALIR" << endl;
		getline(cin, keyPress);
		if(keyPress[0] == '1' || keyPress[0] == '2' || keyPress[0] == '3' || keyPress[0] == '4') {
			showOptions(keyPress[0], user, eventos);
			getline(cin, keyPress); // Para eliminar '\0', por usar cin
		}
		else if(keyPress[0] != '9') {
			system("cls");
			cout << "------------------------" << endl;
			cout << "ERROR: Opcion invalida!" << endl;
			cout << "------------------------" << endl;
		}
	}
	cout << "\nGracias, vuelva pronto" << endl;
    return 0;
}
