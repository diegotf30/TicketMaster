#include "Deporte.h"

//Constructores
Deporte::Deporte() : Evento()
{
	//Constructor Default
}
//Event -> Deporte
Deporte::Deporte(Evento event, string sNomDeporte, string sEquipos)
{
	//Atributos de Evento
	sNombre = event.getNombre();
	sFecha = event.getFecha();
	dPrecio = event.getPrecio();
	iBoletosComprados = event.getBoletosComprados();
	iCapacidad = event.getCapacidad();
	sLugar = event.getLugar();
	sType = event.getType();

	//Atributos de Deporte
	this->sNomDeporte = sNomDeporte;
	this->sEquipos = sEquipos;
}
Deporte::Deporte(string sNombre, string sFecha, double dPrecio, int iCapacidad, int iBoletosComprados,
				 string sLugar, string sType, string sNomDeporte, string sEquipos)
{
	this->sNomDeporte = sNomDeporte;
	this->sEquipos = sEquipos;
}
//Destructor
Deporte::~Deporte()
{
	//dtor
}

//Setters
void Deporte::setDeporte(string sNomDeporte)
{
	this->sNomDeporte = sNomDeporte;
}
void Deporte::setEquipos(string sEquipos)
{
	this->sEquipos = sEquipos;
}
//Getters
string Deporte::getEquipos()
{
	return sEquipos;
}
string Deporte::getDeporte()
{
	return sNomDeporte;
}
