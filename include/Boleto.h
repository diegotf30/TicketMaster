#ifndef BOLETO_H
#define BOLETO_H

#include "Evento.h"

class Boleto
{
	public:
		//Constructores
		Boleto();
		Boleto(Evento* evento, long long int iBarcode, int iAsiento, string sFechaCompra);
        //Destructor
		virtual ~Boleto();

		//Setters
        void setEvento(Evento* evento);
        void setBarcode(long long int iBarcode);
        void setAsiento(int iAsiento);
        void setFechaCompra(string sFechaCompra);
        //Getters
        Evento* getEvento();
        long long int getBarcode();
        int getAsiento();
        string getFechaCompra();

	protected:

	private:
		Evento* evento;
		long long int iBarcode;
        int iAsiento;
        string sFechaCompra;
};

#endif // BOLETO_H
