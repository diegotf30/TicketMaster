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
//	Los primeros 3 digitos son en base al asiento
long long int getBarcode(int iAsiento) {
	int iResto = 100000000;
	long long int iBC = iAsiento * iResto; //800| 000 000 000
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
	cout << endl;
	printf(" %-5s%-15s%-55s%-15s%-15s\n", "#", "Fecha", "Evento", "Tipo", "Precio");
	cout << "-----------------------------------------------------------";
	cout << "----------------------------------------" << endl;

    for(int i = 0; i < compras.size(); i++) {
		string sFechaCompra = compras[i].getFechaCompra();
		string sNombre = compras[i].getEvento()->getNombre();
		string sEventType = compras[i].getEvento()->getType();
		double dPrecio = compras[i].getEvento()->getPrecio();

		printf(" %-5i%-15s%-55s%-15s%-15.2f\n", i + 1, sFechaCompra.c_str(),
			 sNombre.c_str(), sEventType.c_str(), dPrecio);
		cout << "-----------------------------------------------------------";
		cout << "----------------------------------------" << endl;
    }
}
void Usuario::verBoleto(Boleto boleto)
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "Boleto para: " << boleto.getEvento()->getNombre() << endl;
    cout << "\tID: " << boleto.getBarcode() << endl;
    cout << "\tFecha: " << boleto.getEvento()->getFecha() << endl;
    cout << "\tLugar: " << boleto.getEvento()->getLugar() << endl;
    cout << "\tAsiento: " << boleto.getAsiento() << endl;
    cout << "\tCosto: " << boleto.getEvento()->getPrecio() << endl;
	cout << "---------------------------------------------------------------" << endl;
}
void Usuario::compraBoleto(Evento* evento)
{
	if(evento->getBoletosComprados() + 1 <= evento->getCapacidad()) {
		//Actualizamos la cant. de boletos comprados
		evento->setBoletosComprados(evento->getBoletosComprados() + 1);
        //Agregamos el boleto al historial de compras
        long long int iBC = getBarcode(evento->getBoletosComprados());
        string sFecha = getFechaActual();
        compras.push_back(Boleto(evento, iBC, evento->getBoletosComprados(), sFecha));
	}
	else {
		cout << endl << "Error en compra: Evento lleno!" << endl << endl;
	}
}
