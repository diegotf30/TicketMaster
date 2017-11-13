#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctime> //sFechaCompra
#include <cstdlib> //srand()
#include <sstream>
#include <string>
#include "Evento.h"
#include "Boleto.h"

class Usuario
{
	public:
		//Constructores
		Usuario();
		Usuario(string sNombre, string sCorreo, int iNumCuenta, vector<Boleto> compras);
		//Destructor
		virtual ~Usuario();

		//Setters
		void setNombre(string sNombre);
		void setCorreo(string sCorreo);
		void setNumCuenta(int iNumCuenta);
		void setCompras(vector<Boleto> compras);
		//Getters
		string getNombre();
		string getCorreo();
		int getNumCuenta();
		vector<Boleto> getCompras();

		//Metodos
        void verCompras();
        void verBoleto(Boleto boleto);
        void compraBoleto(Evento* evento);

	protected:

	private:
		string sNombre;
		string sCorreo;
		int iNumCuenta;
		vector<Boleto> compras;

};

#endif // USUARIO_H
