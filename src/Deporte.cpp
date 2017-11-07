#include "Deporte.h"

//Constructor Default
Deporte::Deporte()
{
    sNomDeporte = "";
    sEquipos = "";
}
//Constructoes
Deporte::Deporte(string sNomDeporte, string sEquipos)
{
	this->sNomDeporte = sNomDeporte;
	this->sEquipos = sEquipos;
}
Deporte::Deporte(string sNombre, string sFecha, double dPrecio, int iCapacidad,
				 string sLugar, string sType, string sNomDeporte, string sEquipos)
{
	//Att. superclase
	this->sNombre = sNombre;
	this->sFecha = sFecha;
	this->dPrecio = dPrecio;
	this->iCapacidad = iCapacidad;
	this->sLugar = sLugar;
	this->sType = sType;
	//Att. subclase
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
