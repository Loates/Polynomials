// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


class Polynomial {
    public:
        int coeffs; // Amount of coefficiants
        std::string getEquation(void);
        void setEquation(std::string entered_equation);
        Polynomial();

    protected:
         double** solutions; // Number of solutions. Length of polynomial is unknown, so just set to a high amount.
         std::string equation; // Printable equation

    
};

Polynomial::Polynomial(void) {
    coeffs = 2;
    equation = "No equation currently set";

}
std::string Polynomial::getEquation(void) {
    return equation;
};

void Polynomial::setEquation(std::string entered_equation) {

    equation = entered_equation;

};


int main()
{
    Polynomial quadratic;
    std::cout << quadratic.getEquation() << std::endl;
    quadratic.setEquation("9x^2 + 6x + 3");
    std::cout << quadratic.getEquation() << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
