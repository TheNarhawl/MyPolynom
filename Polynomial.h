#pragma once
#include <unordered_map>
#include <string>
#include <vector>

class Polynomial {
public:
    struct Term {
        std::unordered_map<std::string, int> variables;
        double coefficient;

        Term();
        explicit Term(double coeff);
    };

private:
    std::vector<Term> terms;
    double constant;

public:
    Polynomial();

    void addTerm(const Term& term);
    void clear();
    void setConstant(double value);

    std::vector<Term>& getTerms();
    const std::vector<Term>& getTerms() const;
    double getConstant() const;

    Polynomial multiply(const Polynomial& other) const;
    Polynomial divide(const Polynomial& other) const;
    double evaluate(const std::unordered_map<std::string, double>& variableValues) const;
    void print() const;
};

