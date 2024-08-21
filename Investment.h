#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <vector>


class Investment {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_years;

    std::vector<double> balancesNoDeposit;
    std::vector<double> interestsNoDeposit;
    std::vector<double> balancesWithDeposit;
    std::vector<double> interestsWithDeposit;

public:
    // Constructor
    Investment(double initialInvestment, double monthlyDeposit, double annualInterestRate, int years);

    // Setter methods
    void setInitialInvestment(double initialInvestment);
    void setMonthlyDeposit(double monthlyDeposit);
    void setInterestRate(double annualInterestRate);
    void setYears(int years);

    // Getter methods
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getInterestRate() const;
    int getYears() const;

    // Methods to calculate balances
    void BalanceWithoutDeposit(double initialInvestment, double annualInterestRate, double years);
    void BalanceWithDeposit(double initialInvestment, double monthlyDeposit, double annualInterestRate, double years);

    // Getter methods for vectors
    const std::vector<double>& getBalancesNoDeposit() const;
    const std::vector<double>& getInterestsNoDeposit() const;
    const std::vector<double>& getBalancesWithDeposit() const;
    const std::vector<double>& getInterestsWithDeposit() const;

    // Method to display results
    void displayResults() const;
};

#endif // INVESTMENT_H
