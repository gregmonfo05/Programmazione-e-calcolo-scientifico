#include <iostream>
#include <string>
#include "unidirected_edge.h"
#include "unidirected_graph.h"
#include "containers.hpp"
#include "graph_visit.hpp"
#include "algoritmo_dijkstra.hpp"


template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
	unidirected_graph<int> g;
	unidirected_edge<int> e1(1,2);
	unidirected_edge<int> e2(1,3);
	unidirected_edge<int> e3(3,4);
	unidirected_edge<int> e4(3,5);
	unidirected_edge<int> e5(4,5);
	unidirected_edge<int> e6(4,6);
	unidirected_edge<int> e7(5,6);
	unidirected_edge<int> e8(2,3);
	g.add_edge(e1);
	g.add_edge(e2);
	g.add_edge(e3);
	g.add_edge(e4);
	g.add_edge(e5);
	g.add_edge(e6);
	g.add_edge(e7);
	g.add_edge(e8);
	fifo<unidirected_edge<int>> q;
	lifo<unidirected_edge<int>> p;
	unidirected_graph<int> visit_tree_BFS = graph_visit(g,1,q);
	unidirected_graph<int> visit_tree_DFS = graph_visit(g,1,p);
	unidirected_graph<int> visit_tree_DFS_recursive = recursive_DFS_support(g,1);
	std::set<unidirected_edge<int>> set_edges_BFS = visit_tree_BFS.all_edges();
	std::cout << "Gli archi dell'albero risultante della BFS sono: " << "\n";
	for (const auto& edge:set_edges_BFS) {
		std::cout << edge << "\n";
	}
	std::set<unidirected_edge<int>> set_edges_DFS = visit_tree_DFS.all_edges();
	std::cout << "Gli archi dell'albero risultante della DFS sono: " << "\n";
	for (const auto& edge:set_edges_DFS) {
		std::cout << edge << "\n";
	}
	std::set<unidirected_edge<int>> set_edges_DFS_recursive = visit_tree_DFS_recursive.all_edges();
	std::cout << "Gli archi dell'albero risultante della DFS ricorsiva sono: " << "\n";
	for (const auto& edge:set_edges_DFS_recursive) {
		std::cout << edge << "\n";
	}
	int node_source = 1;
	std::map<int,std::vector<int>> shortest_paths = algoritmo_dijkstra(g,node_source);
	for (const auto& [node,path_node]:shortest_paths) {
		std::cout << "Percorso minimo da " << 1 << " a " << node << " : " << "\n";
		print_vector(path_node);
	}
	
	unidirected_graph<std::string> h;
	unidirected_edge<std::string> f1("Torino","Milano");
	unidirected_edge<std::string> f2("Milano","Bergamo");
	unidirected_edge<std::string> f3("Torino","Genova");
	unidirected_edge<std::string> f4("Bergamo","Verona");
	unidirected_edge<std::string> f5("Genova","Firenze");
	unidirected_edge<std::string> f6("Torino","Sestriere");
	unidirected_edge<std::string> f7("Milano","Bologna");
	unidirected_edge<std::string> f8("Bologna","Rimini");
	unidirected_edge<std::string> f9("Verona","Rimini");
	unidirected_edge<std::string> f10("Genova","Milano");
	unidirected_edge<std::string> f11("Firenze","Bologna");
	h.add_edge(f1);
	h.add_edge(f2);
	h.add_edge(f3);
	h.add_edge(f4);
	h.add_edge(f5);
	h.add_edge(f6);
	h.add_edge(f7);
	h.add_edge(f8);
	h.add_edge(f9);
	h.add_edge(f10);
	h.add_edge(f11);
	fifo<unidirected_edge<std::string>> qs;
	lifo<unidirected_edge<std::string>> ps;
	unidirected_graph<std::string> visit_tree_BFS_string = graph_visit(h,std::string("Torino"),qs);
	unidirected_graph<std::string> visit_tree_DFS_string = graph_visit(h,std::string("Torino"),ps);
	unidirected_graph<std::string> visit_tree_DFS_recursive_string = recursive_DFS_support(h,std::string("Torino"));
	std::set<unidirected_edge<std::string>> set_edges_BFS_string = visit_tree_BFS_string.all_edges();
	std::cout << "Gli archi dell'albero risultante della BFS sono: " << "\n";
	for (const auto& edge:set_edges_BFS_string) {
		std::cout << edge << "\n";
	}
	std::set<unidirected_edge<std::string>> set_edges_DFS_string = visit_tree_DFS_string.all_edges();
	std::cout << "Gli archi dell'albero risultante della DFS sono: " << "\n";
	for (const auto& edge:set_edges_DFS_string) {
		std::cout << edge << "\n";
	}
	std::set<unidirected_edge<std::string>> set_edges_DFS_recursive_string = visit_tree_DFS_recursive_string.all_edges();
	std::cout << "Gli archi dell'albero risultante della DFS ricorsiva sono: " << "\n";
	for (const auto& edge:set_edges_DFS_recursive_string) {
		std::cout << edge << "\n";
	}
	std::string node_source_string = "Torino";
	std::map<std::string,std::vector<std::string>> shortest_paths_string = algoritmo_dijkstra(h,node_source_string);
	for (const auto& [node,path_node]:shortest_paths_string) {
		std::cout << "Percorso minimo da " << "Torino" << " a " << node << " : " << "\n";
		print_vector(path_node);
	}
}
	
	