#include <iostream>
#include "rational.hpp"

int main()
{   int a,b,c,d;

    std::cout << "Inserisci numeratore e denominatore, separati da uno spazio:\n";
    if(!(std::cin >>a >>b))
    {
        std::cout << "Non hai inserito degli interi.\n";
        return 1;
    }
    rational<int> r1(a,b);
    
    std::cout << "Inserisci numeratore e denominatore, separati da uno spazio:\n";
    if(!(std::cin >>c >>d))
    {
        std::cout << "Non hai inserito degli interi.\n";
        return 1;
    }
    rational<int> r2(c,d);
    
    rational<int> add = r1+r2;
    rational<int> diff = r1-r2;
    rational<int> molt = r1*r2;
    rational<int> div = r1/r2;
    
    std::cout << "\nStampo i due numeri razionali:\n"<< r1 << " " << r2 <<"\n\nStampo le operazioni:\nSomma: "
    << add << "\nDifferenza: " << diff << "\nMoltiplicazione: " << molt << "\nDivisione: " << div << "\n";
    return 0;
}

