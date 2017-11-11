#include "Concierto.h"

//Constructores
Concierto::Concierto() : Evento()
{
	//Constructor Default
}

//Event -> Concierto
Concierto::Concierto(Evento event, string sNomBanda)
{
	//Atributos de Evento
	sNombre = event.getNombre();
	sFecha = event.getFecha();
	dPrecio = event.getPrecio();
	iBoletosComprados = event.getBoletosComprados();
	iCapacidad = event.getCapacidad();
	sLugar = event.getLugar();
	sType = event.getType();

	//Atributos de Concierto
	this->sNomBanda = sNomBanda;
}

Concierto::Concierto(string sNombre, string sFecha, double dPrecio, int iBoletosComprados,
					 int iCapacidad, string sLugar, string sType, string sNomBanda)
{
	this->sNomBanda = sNomBanda;
}
//Destructor
Concierto::~Concierto()
{
	//dtor
}

//Setter
void Concierto::setBanda(string sNomBanda)
{
	this->sNomBanda = sNomBanda;
}
//Getter
string Concierto::getBanda()
{
	return sNomBanda;
}
