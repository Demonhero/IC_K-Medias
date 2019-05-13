//Jose Maria Gomez-Trabadela Garcia

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <Windows.h>
#include "K-Medias.h"

using namespace std;


int main() {
	std::cout << "Se va ha entrenar el sistema mediante el algoritmo K-medias";
	KMedias kmedias = KMedias();
	kmedias.ejecutarAlgoritmo();
	std::cout << "Ha terminado el algoritmo de K-medias/n";

	std::cout << "Ejecutando Test01/n";
	std::cout << "Pertenece a la clase " << kmedias.test("Test01.txt")<<"/n";

	std::cout << "Ejecutando Test02/n";
	std::cout << "Pertenece a la clase " << kmedias.test("Test02.txt") << "/n";

	std::cout << "Ejecutando Test03/n";
	std::cout << "Pertenece a la clase " << kmedias.test("Test03.txt") << "/n";


	system("pause");
	return 0;
}