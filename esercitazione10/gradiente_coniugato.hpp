#include <Eigen/Dense>
#include <utility>

std::pair<Eigen::VectorXd, unsigned int> gradiente_coniugato(const Eigen::VectorXd& x0, const Eigen::MatrixXd& A, const Eigen::VectorXd& b, const double& tol, const unsigned int& it_max)
{
	Eigen::VectorXd r = b - A * x0;
	Eigen::VectorXd p = r;
	unsigned int k = 0;
	double alfa;   
	double beta;
	Eigen::VectorXd x = x0;
	Eigen::VectorXd prod;
	while (r.norm() >= tol && k < it_max) { // metto come parametri d'uscita la norma del residuo e il numero massimo di iterazioni.
		prod = A * p;
		alfa = (p.dot(r)) / (p.dot(prod));
		x += alfa * p;
		r = b - A * x;
		beta = (p.dot(A * r)) / (p.dot(prod));
		p = r - beta * p;
		k++;
	}
	return {x, k};     // restituisco la soluzione data dall'algoritmo e il numero di iterazioni eseguite.
}
		
		