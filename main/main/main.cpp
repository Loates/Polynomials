// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <math.h> 


class Polynomial {
    public:
        int degree; // The degree of the polynomial. A quadratic will have a degree of two, a cubic will have a degree of 3 etc.
        Polynomial(int deg);

        std::string getEquation(void) {
            return equation;
        }

        void setEquation() {
            // Uses the variables set in order to set the equation for the polynomial
            equation = "";
            for (int i = (degree + 1); i > 0; i--) {
                double var = variables[(degree + 1) - i];
                int power = i - 1;
                switch (power) {
                    case(0):
                        // If the power is zero, we don't need an x value
                        equation += std::to_string(var);
                        break;
                    case(1):
                        // If the power is 1, we don't need the power, just keep the x
                        equation += std::to_string(var);
                        equation += "x";
                        equation += " + ";
                        break;
                    default:
                        equation += std::to_string(var);
                        equation += "x^";
                        equation += std::to_string(power);
                        equation += " + ";


                };
            };
        }

        void setVariables() {
            // Takes in 'n' amount of variables from the user.
            for (int i = 0; i < (degree + 1); i++) {
                std::cout << "Please enter variable " << char(i+97) << std::endl << ">> ";
                std::cin >> variables[i];
            }
        }

        void solveEquation() {};

        float* getSolutions() {
            return solutions;
        };

    protected:
        float *solutions; 
        float *variables;
        std::string equation; // Printable equation
};

Polynomial::Polynomial(int deg) {
    degree = deg;
    variables = new float[degree + 1]; // Variables = degree + 1. For example, a quadratic has 2 degrees, but 3 variables [a,b,c]
    solutions = new float[degree]; // Max no of solutions = degree of the polynomial
    equation = "No equation currently set";

}

class Quadratic : public Polynomial {
    public:
        Quadratic() : Polynomial(2) {};

        void solveEquation() {
            float a = variables[0];
            float b = variables[1];
            float c = variables[2];
            float discriminator = b*b - (4 * a * c);
            if (discriminator < 0) {
                return;
            }
            else if (discriminator == 0) {
                // b^2 - 4ac is 0, so it can be ignored, simplifying the quadratic to -b / 2a, which only has one solution
                solutions[0] = -b / (2 * a);
            }
            else {
                // b^2 - 4ac / 2a is the quadratic equation.
                solutions[0] = (( -b + sqrt(discriminator) )/ (2 * a));
                solutions[1] = (( -b - sqrt(discriminator) ) / (2 * a));
            }
            

        };
};



int main()
{
    Quadratic quadratic;
    quadratic.setVariables();
    quadratic.setEquation();
    std::cout << quadratic.getEquation() << std::endl;
    quadratic.solveEquation();
    float* solutions = quadratic.getSolutions();
    std::cout << "Memory address of solutions: " << solutions << std::endl;
    std::cout << "Solutions: " << solutions[0] << " and " << solutions[1] <<  std::endl;



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
