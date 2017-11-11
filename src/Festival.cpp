#include "Festival.h"

//Constructor
Festival::Festival() : Evento()
{
	//Constructor Default
}
//Evento -> Festival
Festival::Festival(Evento event, vector<string>bandas)
{
	//Atributos de Evento
	sNombre = event.getNombre();
	sFecha = event.getFecha();
	dPrecio = event.getPrecio();
	iBoletosComprados = event.getBoletosComprados();
	iCapacidad = event.getCapacidad();
	sLugar = event.getLugar();
	sType = event.getType();

	//Atributos de Festival
	this->bandas = bandas;
}
Festival::Festival(string sNombre, string sFecha, double dPrecio, int iCapacidad,
				 int iBoletosComprados, string sLugar, string sType, vector<string>bandas)
{
	this->bandas = bandas;
}
//Destructor
Festival::~Festival()
{
	//dtor
}

//Setter
void Festival::setBandas(vector<string> bandas)
{
	this->bandas = bandas;
}
//Getter
vector<string> Festival::getBandas()
{
	return bandas;
}
