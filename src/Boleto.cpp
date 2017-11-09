#include "Boleto.h"
//Constructor Default
Boleto::Boleto()
{
    evento = Evento();
    iBarcode = 0;
    sAsiento = "";
}
//Constructor
Boleto::Boleto(Evento evento, long long int iBarcode, string sAsiento, string sFechaCompra)
{
    this->evento = evento;
    this->iBarcode = iBarcode;
    this->sAsiento = sAsiento;
    this->sFechaCompra = sFechaCompra;
}
//Destructor
Boleto::~Boleto()
{
	//dtor
}

//Setters
void Boleto::setEvento(Evento evento)
{
	this->evento = evento;
}
void Boleto::setBarcode(long long int iBarcode)
{
	this->iBarcode = iBarcode;
}
void Boleto::setAsiento(string sAsiento)
{
    this->sAsiento = sAsiento;
}
void Boleto::setFechaCompra(string sFechaCompra)
{
	this->sFechaCompra = sFechaCompra;
}
//Getters
Evento Boleto::getEvento()
{
	return evento;
}
long long int Boleto::getBarcode()
{
	return iBarcode;
}
string Boleto::getAsiento()
{
	return sAsiento;
}
string Boleto::getFechaCompra()
{
	return sFechaCompra;
}
