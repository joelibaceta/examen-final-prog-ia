#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

bool esOperador(char c) {
    return c == '&' || c == '|' || c == '^' || c == '!';
}

bool esOperando(char c) {
    return c == '1' || c == '0';
}

int evaluarOperacion(char operador, int operando1, int operando2 = 0) {
    switch (operador) {
        case '&': return operando1 & operando2;
        case '|': return operando1 | operando2;
        case '^': return operando1 ^ operando2;
        case '!': return !operando1;
        default: return -1;
    }
}

string evaluarExpresion(const string& expresion) {
    stack<int> pila;
    bool error_operadores = false;

    for (size_t i = 0; i < expresion.size(); ++i) {
        char c = expresion[i];
        if (c == ' ') continue;

        if (esOperando(c)) {
            pila.push(c - '0');
        } else if (esOperador(c)) {
            if (c == '!') {
                if (pila.empty()) {
                    return "Expresión Inválida. Insuficientes operandos.";
                }
                int operando = pila.top();
                pila.pop();
                pila.push(evaluarOperacion(c, operando));
            } else {
                if (pila.size() < 2) {
                    return "Expresión Inválida. Insuficientes operandos.";
                }
                int operando2 = pila.top();
                pila.pop();
                int operando1 = pila.top();
                pila.pop();
                pila.push(evaluarOperacion(c, operando1, operando2));
            }
        } else {
            return "Expresión Inválida.";
        }
    }

    if (pila.size() > 1) {
        error_operadores = true;
    }

    if (pila.empty()) {
        return "Expresión Inválida.";
    }

    if (error_operadores) {
        return "Expresión Inválida. Insuficientes operadores.";
    }

    return to_string(pila.top());
}

void ejecutarPruebas() {
    vector<pair<string, string> > pruebas;
    pruebas.push_back(make_pair("1 0 &", "0"));
    pruebas.push_back(make_pair("0 !", "1"));
    pruebas.push_back(make_pair("1 0 | !", "0"));
    pruebas.push_back(make_pair("1", "1"));
    pruebas.push_back(make_pair("0 ! ! !", "1"));
    pruebas.push_back(make_pair("0 1 & ! 0 ^ 1 1 | ^ !", "1"));
    pruebas.push_back(make_pair("0 1 1 0 & | ^ ! ! ! !", "1"));
    pruebas.push_back(make_pair("1 1 ^", "0"));
    pruebas.push_back(make_pair("0 0 ^", "0"));
    pruebas.push_back(make_pair("1 1 ^ 1 ^", "1"));
    pruebas.push_back(make_pair("0 1 ^ 0 ^", "1"));
    pruebas.push_back(make_pair("0 1 ^ 0 ^ !", "0"));
    pruebas.push_back(make_pair("0 ! 1 ^ 0 ^ !", "1"));
    pruebas.push_back(make_pair("0 1 | ! 1 1 & &", "0"));
    pruebas.push_back(make_pair("0 1 & 0 !", "Expresión Inválida. Insuficientes operadores."));
    pruebas.push_back(make_pair("0 1 & &", "Expresión Inválida. Insuficientes operandos."));
    pruebas.push_back(make_pair("2 4 e f", "Expresión Inválida."));
    pruebas.push_back(make_pair("susti", "Expresión Inválida."));

    for (size_t i = 0; i < pruebas.size(); ++i) {
        string resultado = evaluarExpresion(pruebas[i].first);
        cout << "Expresión: " << pruebas[i].first << endl;
        cout << "Esperado: " << pruebas[i].second << endl;
        cout << "Resultado: " << resultado << endl;
        if (resultado == pruebas[i].second) {
            cout << "\033[32m✔ Prueba exitosa\033[0m" << endl;
        } else {
            cout << "\033[31m✘ Prueba fallida\033[0m" << endl;
        }
        cout << "-----------------------------" << endl;
    }
}

int main() {
    ejecutarPruebas();
    return 0;
}