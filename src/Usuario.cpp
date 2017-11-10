#include "Usuario.h"

//Regresa str con formato: "YYYY-MM-DD"
string getFechaActual() {
	stringstream ss;
	time_t t = time(0);   // get time now
	struct tm *now = localtime(&t);

	ss << (now->tm_year + 1900) << '-';
	ss << (now->tm_mon + 1) << '-';
    ss <<  now->tm_mday;
	return ss.str();
}

//Regresa un codigo de barras random de 12 digitos
//	Los primeros 2 digitos son en base al asiento
long long int getBarcode(int iAsiento) {
	int iResto = 1000000000;
	int iBC = iAsiento * iResto; //80|000 000 0000
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		int digit = rand() % 10;
		iResto /= 10;
		iBC += digit * iResto;
	}
	return iBC;
}

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
	if(evento.getBoletosComprados() + 1 <= evento.getCapacidad()) {
		//Actualizamos la cant. de boletos comprados
		evento.setBoletosComprados(evento.getBoletosComprados() + 1);
        //Agregamos el boleto al historial de compras
        long long int iBC = getBarcode(evento.getBoletosComprados());
        string sFecha = getFechaActual();
        compras.push_back(Boleto(evento, iBC, evento.getBoletosComprados(), sFecha));
	}
	else {
		cout << "Error en compra: Evento lleno!" << endl;
	}
}
