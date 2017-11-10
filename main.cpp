#include <fstream>

#include "Evento.h"
#include "Deporte.h"
#include "Concierto.h"
#include "Festival.h"

#include "Usuario.h"
#include "Boleto.h"

using namespace std;

void showOptions(string sOption) {

}

void llenaEvento(Evento &event) {
	string sAux = "";
	//Nombre de evento
	getline(cin, sAux);
	event.setNombre(sAux);
	//Fecha
	getline(cin, sAux);
	event.setFecha(sAux);
	//Lugar
	getline(cin, sAux);
	event.setLugar(sAux);
	//Capacidad
	getline(cin, sAux);
	int iCap = 0;
	istringstream(sAux) >> iCap;
	event.setCapacidad(iCap);
	//Precio
	getline(cin, sAux);
	double dPrecio = 0;
	stringstream(sAux) >> dPrecio;
	event.setPrecio(dPrecio);
	//Boletos Comprados
	getline(cin, sAux);
	int iBol = 0;
	istringstream(sAux) >> iBol;
	event.setBoletosComprados(iBol);
}

vector<Evento> getEventos() {
	vector<Evento> eventos;
	ifstream ifInput;
	ifInput.open("events.txt");
	if(ifInput.bad()) {
		cout << "ERROR 404: Events.txt not found" << endl;
		return vector<Evento>();
	}

    string sCantEventos;
    getline(cin, sCantEventos);

    string sAux, sType;
    for(int i = 0; i < sCantEventos[0] - '0'; i++) {
		getline(cin, sAux); //Linea basura, descartada
		getline(cin, sType);

		Evento eventoAux;
		eventoAux.setType(sType);
		if(sType == "Concierto") {
			llenaEvento(eventoAux);

			string sNomBanda = "";
			getline(cin, sNomBanda);
            eventos.push_back(Concierto(eventoAux, sNomBanda)); //Guardamos concierto
		}
		else if(sType == "Deporte") {
			llenaEvento(eventoAux);

			string sEquipos = "";
			getline(cin, sEquipos);
			eventos.push_back(Deporte(eventoAux, sEquipos)); //Guardamos Deporte
		}
		else { //Festival
			llenaEvento(eventoAux);

			vector<string> vsBandas;
			getline(cin, sAux);
			while(sAux[0] != '-') {
				vsBandas.push_back(sAux);
				getline(cin, sAux);
			}
			eventos.push_back(Festival(eventoAux, vsBandas)); //Guardamos Festival
		}
    }
}

int main()
{
    Usuario user("Ian Sommerville", "ian@gmail.com", 8182551681, vector<Boleto>());
    vector<Evento> eventos = getEventos();
	string keyPress = "";
	while(keyPress != "9") {
		cout << "~~~~~~~~~~~BIENVENIDO A TICKET MASTER!~~~~~~~~~~~" << endl;
		cout << "Eventos:" << endl;
		cout << "     1. Conciertos" << endl;
		cout << "     2. Partidos" << endl;
		cout << "     3. Festivales" << endl;
		cout << "--------------------------" << endl;
		cout << "     4. Cuenta" << endl;
		cout << "--------------------------" << endl;
		cout << "     9. SALIR" << endl;
		getline(cin, keyPress);
		showOptions(keyPress);
	}
	cout << "\nGracias, vuelva pronto" << endl;
    return 0;
}
