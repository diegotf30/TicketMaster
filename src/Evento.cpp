#include "Evento.h"

//Constructor Default
Evento::Evento()
{
	sNombre = "";
	sFecha = "";
	dPrecio = 0;
	iCapacidad = 0;
	sLugar = "";
	sType = "";
}
//Destructor
Evento::~Evento()
{
	//dtor
}

//Setters
void Evento::setNombre(string sNombre)
{
	this->sNombre = sNombre;
}
void Evento::setFecha(string sFecha)
{
	this->sFecha = sFecha;
}
void Evento::setPrecio(double dPrecio)
{
	this->dPrecio = dPrecio;
}
void Evento::setCapacidad(int iCapacidad)
{
	this->iCapacidad = iCapacidad;
}
void Evento::setLugar(string sLugar)
{
	this->sLugar = sLugar;
}

//Getters
string Evento::getNombre()
{
	return sNombre;
}
string Evento::getFecha()
{
	return sFecha;
}
double Evento::getPrecio()
{
	return dPrecio;
}
int Evento::getCapacidad()
{
	return iCapacidad;
}
string Evento::getLugar()
{
	return sLugar;
}
string Evento::getType()
{
	return sType;
}
