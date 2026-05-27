#include <iostream> 
#include <Eigen/Dense>
#include "gradiente_coniugato.hpp"

int main() {
	const double tol_pcd = 1.0e-12;
	const double tol_test = 1.0e-7;
	const unsigned int it_max = 10000;
	for (unsigned int n = 2; n < 20; n++) {
		Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

		while (abs(B.determinant()) < tol_test) {
			B = Eigen::MatrixXd::Random(n, n);
		}

		Eigen::MatrixXd A = B.transpose() * B;    // ottengo A simmetrica e definita positiva
		
		Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);
		
		Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

		Eigen::VectorXd b = A * x_ex;
		
		auto [x, it] = gradiente_coniugato(x0, A, b, tol_pcd, it_max);
		const double err_rel = (x - x_ex).norm() / x_ex.norm();
		if (err_rel > tol_test) {
			std::cout << "Tolleranza sul test: " << tol_test << "\n";
			std::cout << "Test fallito, Errore relativo tra soluzione numerica e soluzione teorica: " << err_rel;
			return EXIT_FAILURE;
		}
	}
	std::cout << "Tutti i test hanno avuto successo.\n";
	return EXIT_SUCCESS;
}