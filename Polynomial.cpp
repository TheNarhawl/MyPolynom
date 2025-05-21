#include "Polynomial.h"
#include <iostream>
#include <cmath>

Polynomial::Term::Term() : coefficient(1.0) {}

Polynomial::Term::Term(double coeff) : coefficient(coeff) {}

Polynomial::Polynomial() : constant(0.0) {}

void Polynomial::addTerm(const Term& term) {
    terms.push_back(term);
}

void Polynomial::clear() {
    terms.clear();
    constant = 0.0;
}

void Polynomial::setConstant(double value) {
    constant = value;
}

std::vector<Polynomial::Term>& Polynomial::getTerms() {
    return terms;
}

const std::vector<Polynomial::Term>& Polynomial::getTerms() const {
    return terms;
}

double Polynomial::getConstant() const {
    return constant;
}

Polynomial Polynomial::multiply(const Polynomial& other) const {
    Polynomial result;
    for (const auto& t1 : terms) {
        for (const auto& t2 : other.terms) {
            Term combined;
            combined.coefficient = t1.coefficient * t2.coefficient;

            for (const auto& [var, power] : t1.variables) {
                combined.variables[var] += power;
            }
            for (const auto& [var, power] : t2.variables) {
                combined.variables[var] += power;
            }

            result.addTerm(combined);
        }
    }
    return result;
}

Polynomial Polynomial::divide(const Polynomial& other) const {
    Polynomial result;
    for (const auto& t1 : terms) {
        for (const auto& t2 : other.terms) {
            Term combined;
            combined.coefficient = t1.coefficient / t2.coefficient;

            for (const auto& [var, power] : t1.variables) {
                combined.variables[var] += power;
            }
            for (const auto& [var, power] : t2.variables) {
                combined.variables[var] -= power;
            }

            result.addTerm(combined);
        }
    }
    return result;
}

double Polynomial::evaluate(const std::unordered_map<std::string, double>& variableValues) const {
    double result = constant;
    for (const auto& term : terms) {
        double termValue = term.coefficient;
        for (const auto& [varName, exponent] : term.variables) {
            auto it = variableValues.find(varName);
            if (it != variableValues.end()) {
                termValue *= std::pow(it->second, exponent);
            }
        }
        result += termValue;
    }
    return result;
}

void Polynomial::print() const {
    std::cout << "\033[90m\n[Terms: ";
    bool firstTerm = true;

    for (const auto& term : terms) {
        if (!firstTerm) {
            std::cout << "\t";
        }
        firstTerm = false;
        std::cout << term.coefficient;

        for (const auto& [var, exp] : term.variables) {
            std::cout << "*" << var;
            if (exp != 1) {
                std::cout << "^" << exp;
            }
        }
    }

    std::cout << "]";
    if (constant != 0.0) {
        std::cout << "\n[Constants sum: " << constant << "]";
    }
    std::cout << "\033[0m" << std::endl;
}

