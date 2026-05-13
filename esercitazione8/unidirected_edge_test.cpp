#include <iostream>
#include <string>
#include "unidirected_edge.h"

int main()
{
	// TEST SU ARCHI DI INTERI
	unidirected_edge<int> e1(2,1);
	unidirected_edge<int> e2(1,4);
	unidirected_edge<int> e3(3,5);
	unidirected_edge<int> e4(1,2);
	if (e1.from() != 1 || e1.to() != 2){    // controllo che i nodi vengano salvati correttamente
		std::cout << "test fallito a riga 13" << std::endl;
		return EXIT_FAILURE;
	}
	if (!(e1 == e4)){        // testo l'operatore di uguaglianza
		std::cout << "test fallito a riga 17" << std::endl;
		return EXIT_FAILURE;
	}
	if (!(e1 < e2 ) || !(e1 < e3)){    // testo l'operatore di disuguaglianza
		std::cout << "test fallito a riga 21" << std::endl;
		return EXIT_FAILURE;
	}   
	std::cout << e1 << "\n";     // testo l'operatore di stampa
	
	// TEST SU ARCHI DI STRINGHE
	unidirected_edge<std::string> s1("Torino", "Milano");
	unidirected_edge<std::string> s2("Milano", "Torino");
	unidirected_edge<std::string> s3("Milano", "Verona");
	unidirected_edge<std::string> s4("Salerno", "Venezia");
	if (s1.from() != "Milano" || s1.to() != "Torino"){
		std::cout << "test fallito a riga 32" << std::endl;
		return EXIT_FAILURE;
	}
	if (!(s1 == s2)){
		std::cout << "test fallito a riga 36" << std::endl;
		return EXIT_FAILURE;
	}
	if (!(s1 < s3) || !(s1 < s4)){
		std::cout << "test fallito a riga 40" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << s1 << "\n";
	std::cout << "Il test ha avuto successo!" << "\n";
	return EXIT_SUCCESS;
}
	