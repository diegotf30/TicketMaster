#ifndef EVENTO_H
#define EVENTO_H

#include <string>

using namespace std;

class Evento
{
	public:
		//Constructor
		Evento();
		//Destructor
		virtual ~Evento();

		//Setters
		void setNombre(string sNombre);
		void setFecha(string sFecha);
		void setPrecio(double dPrecio);
		void setCapacidad(int iCapacidad);
		void setBoletosComprados(int iBoletosComprados);
		void setLugar(string sLugar);
		void setType(string sType);
		//Getters
		string getNombre();
		string getFecha();
		double getPrecio();
		int getCapacidad();
		int getBoletosComprados();
		string getLugar();
		string getType();

	protected:
		string sNombre;
		string sFecha;
		double dPrecio;
		int iCapacidad;
		int iBoletosComprados;
		string sLugar;
		string sType;

	private:
};

#endif // EVENTO_H
