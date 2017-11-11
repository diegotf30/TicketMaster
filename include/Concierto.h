#ifndef CONCIERTO_H
#define CONCIERTO_H

#include "Evento.h"

class Concierto : public Evento
{
	public:
		//Constructores
		Concierto();
		Concierto(Evento event, string sNomBanda);
		Concierto(string sNombre, string sFecha, double dPrecio, int iCapacidad,
				 int iBoletosComprados, string sLugar, string sType, string sNomBanda);
		//Destructor
		virtual ~Concierto();

		//Setter
		void setBanda(string sNomBanda);
		//Getter
		string getBanda();

	protected:

	private:
		string sNomBanda;
};

#endif // CONCIERTO_H
