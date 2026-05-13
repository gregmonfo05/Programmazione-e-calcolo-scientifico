#pragma once
#include <iostream>
#include <algorithm>


template<typename T>
class unidirected_edge {
private:
    T node_from;
    T node_to;

public:
    unidirected_edge(const T& node1, const T& node2) {
        node_from = std::min(node1, node2);
        node_to = std::max(node1, node2);
    }

    T from() const { return node_from; }
    T to() const { return node_to; }

    bool operator<(const unidirected_edge<T>& other) const {     // controlla se l'arco è minore secondo questo criterio di ordinamento
        if (node_from != other.node_from) {
            return (node_from < other.node_from);
        }
        return (node_to < other.node_to);
    }

    bool operator==(const unidirected_edge<T>& other) const {       // controlla se i due archi sono uguali
        return (node_from == other.node_from && node_to == other.node_to);
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& e) {
    os << e.from() << " --- " << e.to();
    return os;
}
		
		
	
	
	
	
	
	
