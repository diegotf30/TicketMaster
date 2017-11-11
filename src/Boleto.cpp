#include "Boleto.h"
//Constructor Default
Boleto::Boleto()
{
*    evento = Evento();
    iBarcode = 0;
    iAsiento = 0;
    sFechaCompra = "";
}
//Constructor
Boleto::Boleto(Evento* evento, long long int iBarcode, int iAsiento, string sFechaCompra)
{
    this->evento = evento;
    this->iBarcode = iBarcode;
    this->iAsiento = iAsiento;
    this->sFechaCompra = sFechaCompra;
}
//Destructor
Boleto::~Boleto()
{
	//dtor
}

//Setters
void Boleto::setEvento(Evento* evento)
{
	this->evento = evento;
}
void Boleto::setBarcode(long long int iBarcode)
{
	this->iBarcode = iBarcode;
}
void Boleto::setAsiento(int iAsiento)
{
    this->iAsiento = iAsiento;
}
void Boleto::setFechaCompra(string sFechaCompra)
{
	this->sFechaCompra = sFechaCompra;
}
//Getters
Evento* Boleto::getEvento()
{
	return evento;
}
long long int Boleto::getBarcode()
{
	return iBarcode;
}
int Boleto::getAsiento()
{
	return iAsiento;
}
string Boleto::getFechaCompra()
{
	return sFechaCompra;
}
