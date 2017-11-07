#include "Concierto.h"

//Constructores
Concierto::Concierto() : Evento()
{
	//Constructor Default
}

Concierto::Concierto(string sNombre, string sFecha, double dPrecio,
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
