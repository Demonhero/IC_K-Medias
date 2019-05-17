//Jose Maria Gomez-Trabadela Garcia

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "K-Medias.h"

using namespace std;


int main() {
	std::cout << "Se va a entrenar el sistema mediante el algoritmo K-medias"<<endl;
	KMedias kmedias = KMedias();
	kmedias.ejecutarAlgoritmo();
	std::cout << "Ha terminado el algoritmo de K-medias"<<endl<<endl;

	std::cout << "Ejecutando Test01"<<endl;
	std::cout << "Pertenece a la clase " << kmedias.test("Test01.txt")<<endl<<endl;

	std::cout << "Ejecutando Test02"<<endl;
	std::cout << "Pertenece a la clase " << kmedias.test("Test02.txt") <<endl<<endl;

	std::cout << "Ejecutando Test03"<<endl;
	std::cout << "Pertenece a la clase " << kmedias.test("Test03.txt") <<endl<<endl;


	system("pause");
	return 0;
}