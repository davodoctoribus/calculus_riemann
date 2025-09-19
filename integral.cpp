#include <vector>
using namespace std;

vector<double> intervalo(double (*fn)(double), double a, double b, double largura) {
    double inter[2] = {a, b};
    vector<double> valorx;
    vector<double> valory;
    for (double i = inter[0]; i < inter[1]; i += largura) {
        valorx.push_back(i);
        valory.push_back(fn(i));
    }
    return valory;
}

double riemann(double (*fn)(double), double a, double b) {
    double largura = 1e-6;
    vector<double> valory;
    double integral = 0;
    valory = intervalo(fn, a, b, largura);
    for (size_t i = 0; i < valory.size(); ++i) {
        integral += valory[i] * largura;
    }

    return integral;
}