#include <iostream>
#include <fstream>
#include <exception>
#include <unistd.h>
#include "calculator.h"

/// Constructor
/// Initilize data members to 0 doubles
Calculator::Calculator() : result(0.0), mem(0.0), a("1"), b("2") {}

void Calculator::add()
{
    // std::string a, b;
    // std::cout << "Enter the first number: ";
    // std::cin >> a;
    // std::cout << "Enter the second number: ";
    // std::cin >> b;
    result = parseInput(a) + parseInput(b);
    std::cout << "The result is " << result;
}
void Calculator::subtract()
{
    // std::string a, b;
    // std::cout << "Enter the first number: ";
    // std::cin >> a;
    // std::cout << "Enter the second number: ";
    // std::cin >> b;
    result = parseInput(a) - parseInput(b);
    std::cout << "The result is " << result;
}
void Calculator::multiply()
{
    // std::string a, b;
    // std::cout << "Enter the first number: ";
    // std::cin >> a;
    // std::cout << "Enter the second number: ";
    // std::cin >> b;
    result = parseInput(a) * parseInput(b);
    std::cout << "The result is " << result;
}
void Calculator::divide()
{
    // std::string a, b;
    // std::cout << "Enter the first number: ";
    // std::cin >> a;
    // std::cout << "Enter the second number: ";
    // std::cin >> b;
    result = parseInput(a) / parseInput(b);
    std::cout << "The result is " << result;
}
void Calculator::square()
{
    // std::string a;
    // std::cout << "Enter a number: ";
    // std::cin >> a;
    double parsedA = parseInput(a);
    result = parsedA * parsedA;
    std::cout << "The result is " << result;
}
void Calculator::sqrt()
{
    // std::string a;
    // std::cout << "Enter a number: ";
    // std::cin >> a;
    result = std::sqrt(parseInput(a));
    std::cout << "The result is " << result;
}
void Calculator::setMem()
{
    // std::string a;
    // std::cout << "Enter a number: ";
    // std::cin >> a;
    mem = parseInput(a);
    std::cout << "The mem is " << mem;
}
void Calculator::printMem() const
{
    std::cout << "The mem is " << mem;
}
/// subs in number value when strings result or mem are entered
double Calculator::parseInput(const std::string& input) const
{
    if (input == "result")
    {
        return result;
    }
    else if (input == "mem")
    {
        return mem;
    }
    else
    {
        return std::stod(input);
    }
}
void Calculator::welcome() const
{
    std::cout << "\n\nEnter an operation (+, -, /, *, sqrt, square, change, setmem, printmem) or exit\n";
}
/// parse input and decide which member func to call
void Calculator::parseOperation(const std::string& input)
{
    if (input == "+" || input == "add" || input == "addition" || input == "sum")
    {
        add();
    }
    else if (input == "-" || input == "sub" || input == "subtraction" || input == "minus")
    {
        subtract();
    }
    else if (input == "/" || input == "divide" || input == "div")
    {
        divide();
    }
    else if (input == "*" || input == "mul" || input == "multiply" || input == "times")
    {
        multiply();
    }
    else if (input == "sqrt")
    {
        sqrt();
    }
    else if (input == "square")
    {
        square();
    }
    else if (input == "setmem")
    {
        setMem();
    }
    else if (input == "printmem")
    {
        printMem();
    }
}
void Calculator::setA(const std::string& val)
{
    this->a = val;
}
void Calculator::setB(const std::string& val)
{
    this->b = val;
}

bool Calculator::writeResultToFile(const std::string& filename, const double& res)
{
    try
    {
        std::ofstream of(filename, std::ofstream::out | std::ofstream::app);

        of << "The result is " << res << std::endl;
        sleep(5);
        of.close();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}