#include <iostream>
#include <string>
#include "unidirected_edge.h"
#include "unidirected_graph.h"

int main()
{
	// TEST SU GRAFO D'INTERI
	unidirected_graph<int> g;
	unidirected_edge<int> e1(1,2);
	unidirected_edge<int> e2(1,4);
	unidirected_edge<int> e3(4,3);
	unidirected_edge<int> e4(1,3);
	g.add_edge(e1);
	g.add_edge(e2);
	g.add_edge(e3);
	g.add_edge(e4);
	
	if (g.neighbours(1).size() != 3) {     // test di neighbours
		std::cout << "test fallito a riga 20" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (g.all_edges().size() != 4) {       // test di all_edges
		std::cout << "test fallito a riga 26" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (g.all_nodes().size() != 4) {    // test di all_nodes
		std::cout << "test fallito a riga 32" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (g.edge_number(e1) != 0) {   // test di edge_number
		std::cout << "test fallito a riga 38" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (g.edge_at(1) != e4) {     // test di edge_at
		std::cout << "test fallito a riga 44" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		g.edge_at(100);   // verifico il caso out of range in cui il programma dovrebbe lanciare un'eccezione
		std::cout << "test fallito a riga 50" << std::endl;
		return EXIT_FAILURE;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) != "Invalid edge index") {
			std::cout << "test fallito a riga 54" << std::endl;
			return EXIT_FAILURE;
		}
	}
	
	
	try {
		g.edge_at(-2);   // verifico il caso out of range in cui il programma dovrebbe lanciare un'eccezione
		std::cout << "test fallito a riga 62" << std::endl;
		return EXIT_FAILURE;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) != "Invalid edge index") {
			std::cout << "test fallito a riga 66" << std::endl;
			return EXIT_FAILURE;
		}
	}
	
	unidirected_graph<int> h;
	h.add_edge(e1);
	h.add_edge(e2);
	h.add_edge(e3);
	
	unidirected_graph<int> diff = g - h;
	if (diff.all_edges().size() != 1 || diff.neighbours(1).size() != 1 || diff.neighbours(3).size() != 1) {
		std::cout << "test fallito a riga 78" << std::endl;
		return EXIT_FAILURE;
	}

	
	// TEST SU GRAFO DI STRINGHE
	unidirected_graph<std::string> t;
	unidirected_edge<std::string> s1("Torino", "Milano");
	unidirected_edge<std::string> s2("Milano", "Napoli");
	unidirected_edge<std::string> s3("Milano", "Verona");
	unidirected_edge<std::string> s4("Salerno", "Napoli");
	t.add_edge(s1);
	t.add_edge(s2);
	t.add_edge(s3);
	t.add_edge(s4);
	
	if (t.neighbours("Milano").size() != 3) {     // test di neighbours
		std::cout << "test fallito a riga 94" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (t.all_edges().size() != 4) {       // test di all_edges
		std::cout << "test fallito a riga 99" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (t.all_nodes().size() != 5) {    // test di all_nodes
		std::cout << "test fallito a riga 104" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (t.edge_number(s1) != 1) {   // test di edge_number
		std::cout << "test fallito a riga 109" << std::endl;
		return EXIT_FAILURE;
	}

	
	if (t.edge_at(3) != s4) {     // test di edge_at
		std::cout << "test fallito a riga 114" << std::endl;
		return EXIT_FAILURE;
	}

	
	try {
		t.edge_at(100);   // verifico il caso out of range in cui il programma dovrebbe lanciare un'eccezione
		std::cout << "test fallito a riga 120" << std::endl;
		return EXIT_FAILURE;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) != "Invalid edge index") {
			std::cout << "test fallito a riga 123" << std::endl;
			return EXIT_FAILURE;
		}
	}
	
	try {
		t.edge_at(-2);   // verifico il caso out of range in cui il programma dovrebbe lanciare un'eccezione
		std::cout << "test fallito a riga 129" << std::endl;
		return EXIT_FAILURE;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) != "Invalid edge index") {
			std::cout << "test fallito a riga 132" << std::endl;
			return EXIT_FAILURE;
		}
	}
	
	unidirected_graph<std::string> r;
	r.add_edge(s1);
	r.add_edge(s2);
	r.add_edge(s3);
	
	unidirected_graph<std::string> sdiff = t - r;
	if (sdiff.all_edges().size() != 1 || sdiff.neighbours("Salerno").size() != 1 || sdiff.neighbours("Napoli").size() != 1) {
		std::cout << "test fallito a riga 143" << std::endl;
		return EXIT_FAILURE;
	}
	
	std::cout << "Il test ha avuto successo!" << "\n";
	return EXIT_SUCCESS;
}