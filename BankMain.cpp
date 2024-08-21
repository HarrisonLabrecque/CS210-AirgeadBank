/*
Author: Harrison Labrecque
Date: 7/31/2024
Description: This program can calculate future balances wih deposits and balances without deposits based on user input
that is provided.

*/


#include <iostream>
#include <iomanip>
#include "Investment.h"

// Function prototype for getFinancialInputs()
void getFinancialInputs(double& initialInvestment, double& monthlyDeposit, double& annualInterestRate, int& years);

int main() {
    double initialInvestment = 0.0;
    double monthlyDeposit = 0.0;
    double annualInterestRate = 0.0;
    int years = 0;
    char quit = ' ';

    do {
        getFinancialInputs(initialInvestment, monthlyDeposit, annualInterestRate, years);

        // Create an Investment object
        Investment investment(initialInvestment, monthlyDeposit, annualInterestRate, years);

        // Calculate balances
        investment.BalanceWithoutDeposit(initialInvestment, annualInterestRate, years);
        investment.BalanceWithDeposit(initialInvestment, monthlyDeposit, annualInterestRate, years);

        // Display results
        investment.displayResults();

        std::cout << "Enter 'Q' to quit, or any other key to continue: ";
        std::cin >> quit;

    } while (quit != 'Q' && quit != 'q');

    std::cout << "Program ended." << std::endl;
    return 0;
}

// Function to get financial inputs from the user
void getFinancialInputs(double& initialInvestment, double& monthlyDeposit, double& annualInterestRate, int& years) {
    std::cout << "Enter initial investment amount: $";
    std::cin >> initialInvestment;

    if (initialInvestment < 0) {
        std::cout << "You cannot enter a negative amount!" << std::endl;
        return;
    }

    std::cout << "Enter monthly deposit amount: $";
    std::cin >> monthlyDeposit;

    if (monthlyDeposit < 0) {
        std::cout << "You must enter a positive amount!" << std::endl;
        return;
    }

    std::cout << "Enter annual interest rate (in percentage): ";
    std::cin >> annualInterestRate;

    if (annualInterestRate < 0) {
        std::cout << "You must enter a positive interest rate!" << std::endl;
        return;
    }

    std::cout << "Enter number of years: ";
    std::cin >> years;

    if (years < 0) {
        std::cout << "You can't enter negative years!" << std::endl;
        return;
    }
}
