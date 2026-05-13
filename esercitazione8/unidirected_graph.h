#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include "unidirected_edge.h"

template<typename T>
class unidirected_graph {
private:
    std::map<T, std::set<T>> data;

public:
    unidirected_graph() {}       // costruttore di default
	
    unidirected_graph(const unidirected_graph& other) : data(other.data) {}    // costruttore di copia

    void add_edge(const unidirected_edge<T>& e) {       // aggiunge l'arco al grafo aggiornando nella mappa i vicini di u e v
        T v = e.from();
        T u = e.to();
        data[u].insert(v);
        data[v].insert(u);
    }

    std::vector<T> neighbours(const T& node) const {   
        std::vector<T> neighbours_list;
        auto it = data.find(node);      
        if (it != data.end()) {    // se il nodo non ha vicini restituisce un vettore vuoto (nel nostro caso non accade perchè posso aggiungere un nodo solo aggiungendo un arco)
            for (const T& vicino : it->second) {
                neighbours_list.push_back(vicino);
            }
        }
        return neighbours_list;
    }

    std::set<unidirected_edge<T>> all_edges() const {  // restituisce tutti gli archi del grafo in un set
        std::set<unidirected_edge<T>> set_edges;         // nel set l'ordinamento è basato sul criterio implementato nella class unidirected_edge
        for (auto const& [node, set_neighbours] : data) {  
            for (auto const& neighbour : set_neighbours) {
                unidirected_edge<T> e(node, neighbour);     
                set_edges.insert(e);
            }
        }
        return set_edges;
    }

    std::set<T> all_nodes() const {   // restituisce tutti i nodi del grafo in un set perchè così quando chiamo edge_number e edge_at ho gli archi ordinati secondo l'ordinamento di unidirected_edge
        std::set<T> set_nodes;
        for (auto const& [node, set_neighbours] : data) {
            set_nodes.insert(node);
        }
        return set_nodes;
    }

    int edge_number(const unidirected_edge<T>& e) const {     // dato un arco restituisce la sua posizione all'interno del set degli archi in base al criterio d'ordinamento di unidirected_edge
        std::set<unidirected_edge<T>> set_edges = all_edges();
        auto it = set_edges.find(e);      
        if (it == set_edges.end()) return -1;   // se l'arco non è presente restituisco -1
        return std::distance(set_edges.begin(), it);    
    }

    unidirected_edge<T> edge_at(const size_t& index) const {    // fa l'inverso di edge_number
        std::set<unidirected_edge<T>> set_edges = all_edges();
		if (index < 0 || index >= set_edges.size()){    // controlla che l'indice sia valido
			throw std::out_of_range("Invalid edge index");  // lancia un'eccezione se non lo è 
		}
		auto it = set_edges.begin();
		std::advance(it, index);     
		
        return *it;       
    }

    unidirected_graph operator-(const unidirected_graph& other) const {
        std::set<unidirected_edge<T>> set_edges1 = this->all_edges();
        std::set<unidirected_edge<T>> set_edges2 = other.all_edges();
        std::set<unidirected_edge<T>> set_edges_difference;
        
        std::set_difference(    // crea un nuovo insieme di archi corrispondente alla differenza insiemistica
            set_edges1.begin(), set_edges1.end(),
            set_edges2.begin(), set_edges2.end(),
            std::inserter(set_edges_difference, set_edges_difference.begin()) 
        );

        unidirected_graph difference;     // crea il nuovo grafo a cui aggiunge gli archi della differenza 
        for (auto const& e : set_edges_difference) {
            difference.add_edge(e);
        }
        return difference;
    }
};
			
			
			
		
	