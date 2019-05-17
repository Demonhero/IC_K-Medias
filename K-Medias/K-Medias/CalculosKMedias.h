#ifndef CALCULOSKMEDIAS_H_
#define CALCULOSKMEDIA_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <math.h>


class CalculosKMedias {

private:
	const float B = 2;
	



public:
	CalculosKMedias() {
	}

	std::vector<float> calcularCentro(int c, std::vector<float> v, std::vector<std::vector<float>> x, std::vector<std::vector<float>> u) {
		
		std::vector<float> centroNuevo;
		float a = 0, den = 0, aux = 0;
		centroNuevo=x[0];

		for (int i = 0; i < x.size(); i++) {
			den = den + (float)pow(u[c][i], B);
			for (int j = 0; j < x[i].size(); j++) {
				a = centroNuevo[j];
				a = a + (float)pow(u[c][i], B)*x[i][j];
				centroNuevo[j] = a;
			}

		}

		for (int i = 0; i < centroNuevo.size(); i++) {
			aux = centroNuevo[i];
			aux = aux / den;
			centroNuevo[i] = aux;
		}

		return centroNuevo;

	}

	float distanciaEuclideaAlCuadrado(std::vector<float>a, std::vector<float>b) {
		float r = 0;
		
		for (int i = 0; i < a.size() && i<b.size(); i++) {
			r = r + (float)pow((a[i] - b[i]), 2);
		}

		return r;
	}

	float distanciaEuclidea(std::vector<float>a, std::vector<float>b) {
		float r = 0;
		r = (float)sqrt(distanciaEuclideaAlCuadrado(a, b));
		return r;
	}

	float calcularPertenencia(int claseActual, std::vector<std::vector<float>> centros, std::vector<float> muestra) {
		float r = 0;
		float numerador, denominador = 0;

		numerador = (float)(1 / pow(distanciaEuclidea(muestra, centros[claseActual]), 1 / B - 1));

		for (int i = 0; i < 2; i++) {
			denominador = denominador + (float) pow(1 / (distanciaEuclidea(muestra, centros[i])), (1 / B - 1));
		}

		r = numerador / denominador;

		return r;

	}
	
};

#endif
