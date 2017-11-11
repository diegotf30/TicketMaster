#ifndef DEPORTE_H
#define DEPORTE_H

#include "Evento.h"

class Deporte : public Evento
{
	public:
		//Constructores
		Deporte();
		Deporte(Evento event, string sNomDeporte, string sEquipos);
		Deporte(string sNombre, string sFecha, double dPrecio, int iCapacidad, int iBoletosComprados,
				string sLugar, string sType, string sNomDeporte, string sEquipos);

		//Destructor
		virtual ~Deporte();

		//Setters
        void setDeporte(string sNomDeporte);
        void setEquipos(string sEquipos);
		//Getters
        string getDeporte();
        string getEquipos();

	protected:

	private:
		string sNomDeporte;
		string sEquipos; //Formato: "EquipoA, EquipoB"
};

#endif // DEPORTE_H
