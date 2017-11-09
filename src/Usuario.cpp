#include "Usuario.h"

//Constructor Default
Usuario::Usuario()
{
	sNombre = "";
	sCorreo = "";
	iNumCuenta = 0;
	compras = vector<Boleto>();
}
//Constructor
Usuario::Usuario(string sNombre, string sCorreo, int iNumCuenta, vector<Boleto> compras)
{
    this->sNombre = sNombre;
    this->sCorreo = sCorreo;
    this->iNumCuenta = iNumCuenta;
    this->compras = compras;
}
//Destructor
Usuario::~Usuario()
{
	//dtor
}

//Setters
void Usuario::setNombre(string sNombre)
{
	this->sNombre = sNombre;
}
void Usuario::setCorreo(string sCorreo)
{
	this->sCorreo = sCorreo;
}
void Usuario::setNumCuenta(int iNumCuenta)
{
	this->iNumCuenta = iNumCuenta;
}
void Usuario::setCompras(vector<Boleto> compras)
{
	this->compras = compras;
}
//Getters
string Usuario::getNombre()
{
	return sNombre;
}
string Usuario::getCorreo()
{
	return sCorreo;
}
int Usuario::getNumCuenta()
{
	return iNumCuenta;
}
vector<Boleto> Usuario::getCompras()
{
	return compras;
}

//Metodos
void Usuario::verCompras()
{
	cout << "Fecha\tEvento\tTipo\tPrecio" << endl;
	cout << "----------------------------------------" << endl;
    for(int i = 0; i < compras.size(); i++) {
        cout << compras[i].getFechaCompra() << '\t';
        cout << compras[i].getEvento().getNombre() << '\t';
        cout << compras[i].getEvento().getType() << '\t';
        cout << compras[i].getEvento().getPrecio() << '\t';
		cout << "----------------------------------------" << endl;
    }
}
void Usuario::verBoleto(Boleto boleto)
{
	cout << "----------------------------------------" << endl;
	cout << "Boleto para: " << boleto.getEvento().getNombre() << endl;
    cout << "\tID: " << boleto.getBarcode() << endl;
    cout << "\tFecha: " << boleto.getEvento().getFecha() << endl;
    cout << "\tLugar: " << boleto.getEvento().getLugar() << endl;
    cout << "\tAsiento: " << boleto.getAsiento() << endl;
    cout << "\tCosto: " << boleto.getEvento().getPrecio() << endl;
	cout << "----------------------------------------" << endl;
}
void Usuario::compraBoleto(Evento evento)
{
	if(evento.getCapacidad() + 1 < )
}
