#ifndef KMEDIAS_H_
#define KMEDIA_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <string>
#include "CalculosKMedias.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class KMedias {

private:
	const float TOLERANCIA = 0.01;
	std::vector<std::string> nombreClase;
	std::vector<std::vector<float>> U;
	std::vector<std::vector<float>> centros;
	std::vector<std::vector<float>> centrosAnteriores;
	std::vector<std::vector<float>> muestras;



public:
	KMedias(){
		leerFicherosMuestras();
		inicializarCentros();
		inicializarU();
	}

	void inicializarCentros() {
		std::vector<float> v1;
		v1.push_back((float)4.6);
		v1.push_back((float)3.0);
		v1.push_back((float)4.0);
		v1.push_back((float)0.7);

		centros.push_back(v1);

		std::vector<float> v2;
		v1.push_back((float)6.8);
		v1.push_back((float)3.4);
		v1.push_back((float)4.6);
		v1.push_back((float)0.7);

		centros.push_back(v2);
	}

	void inicializarU() {
		vector<float> aux;
		U.push_back(aux);
		U.push_back(aux);
		for (int i = 0; i<muestras.size(); i++) {
			U[0].push_back(CalculosKMedias().calcularPertenencia(0, centros, muestras[i]));
			U[1].push_back(CalculosKMedias().calcularPertenencia(1, centros, muestras[i]));
		}
	}

	void leerFicherosMuestras() {
		std::ifstream file;
		try {
			file.open("ClasesIris2.txt");
			float dato;
			std::vector<float> aux;
			std::string nombre;
			while (!file.eof()) {
				aux.clear();
				for (int i = 0; i < 4; i++) {
					file >> dato;
					aux.push_back(dato);
				}
				muestras.push_back(aux);
				file >> nombre;
				bool encontrado = false;
				for (int i = 0; i<nombreClase.size() && !encontrado; i++) {
					if (nombreClase[i].compare(nombre) == 0) {
						encontrado = true;
					}
				}
				if (!encontrado) {
					nombreClase.push_back(nombre);
				}

			}
			file.close();

		}
		catch (exception e) {
			cout << e.what() << '/n';
		}
	}

	bool criterioFinalizacion() {
		bool terminar = false;
		if (!centrosAnteriores.empty()) {
			terminar = (CalculosKMedias().distanciaEuclidea(centros[0], centrosAnteriores[0]) < TOLERANCIA) && (CalculosKMedias().distanciaEuclidea(centros[1], centrosAnteriores[1]) < TOLERANCIA);
		}
		else {
			centrosAnteriores = centros;
		}
		return terminar;
	}

	void actualizarPertenencias() {
		for (int i = 0; i < U.size(); i++) {
			U[0][i]=CalculosKMedias().calcularPertenencia(0, centros, muestras[i]);
			U[1][i] = CalculosKMedias().calcularPertenencia(1, centros, muestras[i]);
		}
	}

	void actualizarCentros() {
		centrosAnteriores[0] = centros[0];
		centrosAnteriores[1] = centros[1];

		centros[0] = CalculosKMedias().calcularCentro(0, centrosAnteriores[0], muestras, U);
		centros[1] = CalculosKMedias().calcularCentro(1, centrosAnteriores[1], muestras, U);

	}

	void ejecutarAlgoritmo() {
		while (!criterioFinalizacion()) {
			actualizarCentros();
			actualizarPertenencias();
		}
	}

	std::string test(std::string fichero) {
		std::string resultado = "";
		try {
			ifstream file;
			file.open(fichero);
			float dato;
			std::vector<float> aux;
			string nombre;
			while (!file.eof()) {
				for (int i = 0; i < 4; i++) {
					file >> dato;
					aux.push_back(dato);
				}
				muestras.push_back(aux);
				file >> nombre;
				bool encontrado = false;
				
				if (CalculosKMedias().calcularPertenencia(0, centros, aux) > CalculosKMedias().calcularPertenencia(1, centros, aux)) {
					resultado = nombreClase[0];
				}
				else {
					resultado = nombreClase[1];
				}

			}
			file.close();

		}
		catch (exception e) {
			cout << e.what() << '/n';
		}

		return resultado;
	}


};

#endif
