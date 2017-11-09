#ifndef BOLETO_H
#define BOLETO_H

#include "Evento.h"

class Boleto
{
	public:
		//Constructores
		Boleto();
		Boleto(Evento evento, long long int iBarcode, string sAsiento, string sFechaCompra);
        //Destructor
		virtual ~Boleto();

		//Setters
        void setEvento(Evento evento);
        void setBarcode(long long int iBarcode);
        void setAsiento(string sAsiento);
        string setFechaCompra(string sFechaCompra);
        //Getters
        Evento getEvento();
        long long int getBarcode();
        string getAsiento();
        string getFechaCompra();

	protected:

	private:
		Evento evento;
		long long int iBarcode;
        string sAsiento;
        string sFechaCompra;
};

#endif // BOLETO_H
