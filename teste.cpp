#include <cmath>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "integral.cpp"
using namespace std;
const double pi = 3.14159265358979323846;
const double margem = 5.0*1e-5;

double linear1(double x) {
    return x;
}
double linear2(double x) {
    return x + 5;
}
double quadratic1(double x) {
    return x * x;
}
double quadratic2(double x) {
    return x * x + 2 * x - 1;
}
double cubic1(double x) {
    return x * x * x;
}
double seno1(double x) {
    return sin(x);
}
double cosseno1(double x) {
    return cos(x);
}
double exponential1(double x) {
    return pow(10, x);
}
double logarithm1(double x) {
    return log(x);
}

// --Testes--
void teste_linear() {
    double valor = riemann(linear1, 0, 5);
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = 25.0/2.0;
    assert(fabs(valor - correto) <= margem);
}

void teste_linear2() {
    double valor = riemann(linear2, -2, 3);
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = 55.0 / 2.0;
    assert(fabs(valor - correto) < margem);
}

void teste_quadratic() {
    double valor = riemann(quadratic1, 0, 5);
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = 125.0 / 3.0;
    assert(fabs(valor - correto) <= margem);
}

void teste_quadratic2() {
    double valor = riemann(quadratic2, -1, 8);
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = 225;
    assert(fabs(valor - correto) <= margem);
}

void teste_cubic() {
    double valor = riemann(cubic1, -2, 3);
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = 65.0 / 4.0;
    assert(fabs(valor - correto) <= margem);
}

void teste_seno() {
    double valor = riemann(seno1, 0, pi);
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = 2;
    assert(fabs(valor - correto) <= margem);
}

void teste_cosseno() {
    double valor = riemann(cosseno1, 0, (pi / 2));
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = 1;
    assert(fabs(valor - correto) <= margem);
}

void teste_exponential() {
    double valor = riemann(exponential1, 0, 1);
    cout << fixed << "valor exato :"<<valor << endl;
    double correto = (pow(10,1) - pow(10,0)) / log(10);
    assert(fabs(valor - correto) <= margem);
}

void teste_logarithm() {
    double valor = riemann(logarithm1, 0.1, 1);
    cout << fixed << "valor exato :"<<valor << endl;
    auto F = [](double x){ return x*log(x) - x; };
    double correto = F(1) - F(0.1);
    assert(fabs(valor - correto) <= margem);
}

int main() {
    teste_linear();
    teste_linear2();
    teste_quadratic();
    teste_quadratic2();
    teste_cubic();
    teste_seno();
    teste_cosseno();
    teste_exponential();
    teste_logarithm();

    cout << "Todos os testes passaram!" << endl;
    return 0;
}
