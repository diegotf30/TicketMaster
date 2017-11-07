#include "Festival.h"

//Constructor
Festival::Festival() : Evento()
{
	//Constructor Default
}

Festival::Festival(string sNombre, string sFecha, double dPrecio, int iCapacidad,
				 string sLugar, string sType, vector<string>bandas)
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
