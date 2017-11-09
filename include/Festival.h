#ifndef FESTIVAL_H
#define FESTIVAL_H

#include "Evento.h"
#include <vector>

class Festival : public Evento
{
	public:
		//Constructores
		Festival();
		Festival(string sNombre, string sFecha, double dPrecio, int iCapacidad,
				 int iBoletosComprados, string sLugar, string sType, vector<string> bandas);
		//Destructor
		virtual ~Festival();

		//Setter
		void setBandas(vector<string> bandas);
		//Getter
		vector<string> getBandas();

	protected:

	private:
		vector<string> bandas;
};

#endif // FESTIVAL_H
