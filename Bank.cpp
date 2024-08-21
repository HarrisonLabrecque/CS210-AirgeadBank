#include "Investment.h"
#include <iomanip>
#include <cmath>

// Constructor
Investment::Investment(double initialInvestment, double monthlyDeposit, double annualInterestRate, int years)
    : m_initialInvestment(initialInvestment), m_monthlyDeposit(monthlyDeposit), m_annualInterestRate(annualInterestRate), m_years(years) {
}

// Setter methods
void Investment::setInitialInvestment(double initialInvestment) {
    m_initialInvestment = initialInvestment;
}

void Investment::setMonthlyDeposit(double monthlyDeposit) {
    m_monthlyDeposit = monthlyDeposit;
}

void Investment::setInterestRate(double annualInterestRate) {
    m_annualInterestRate = annualInterestRate;
}

void Investment::setYears(int years) {
    m_years = years;
}

// Getter methods
double Investment::getInitialInvestment() const {
    return m_initialInvestment;
}

double Investment::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double Investment::getInterestRate() const {
    return m_annualInterestRate;
}

int Investment::getYears() const {
    return m_years;
}

// Method to calculate balances without monthly deposits
void Investment::BalanceWithoutDeposit(double initialInvestment, double annualInterestRate, double years) {
    balancesNoDeposit.clear();
    interestsNoDeposit.clear();

    double balance = m_initialInvestment;
    double totalInterest = 0.0;

    for (int year = 1; year <= m_years; ++year) {
        double interestEarned = balance * (m_annualInterestRate / 100.0);
        totalInterest += interestEarned;
        balance += interestEarned;

        balancesNoDeposit.push_back(balance);
        interestsNoDeposit.push_back(totalInterest);
    }
}

// Method to calculate balances with monthly deposits
void Investment::BalanceWithDeposit(double initialInvestment, double monthlyDeposit, double annualInterestRate, double years) {
    balancesWithDeposit.clear();
    interestsWithDeposit.clear();

    double balance = m_initialInvestment;
    double totalInterest = 0.0;

    for (int year = 1; year <= m_years; ++year) {
        for (int month = 0; month < 12; ++month) {
            // Calculate monthly interest for the current balance before adding the monthly deposit
            double interestEarned = balance * (m_annualInterestRate / 100.0 / 12.0);
            totalInterest += interestEarned;
            balance += interestEarned + m_monthlyDeposit;
        }

        balancesWithDeposit.push_back(balance);
        interestsWithDeposit.push_back(totalInterest);
    }
}

// Getter methods for vectors
const std::vector<double>& Investment::getBalancesNoDeposit() const {
    return balancesNoDeposit;
}

const std::vector<double>& Investment::getInterestsNoDeposit() const {
    return interestsNoDeposit;
}

const std::vector<double>& Investment::getBalancesWithDeposit() const {
    return balancesWithDeposit;
}

const std::vector<double>& Investment::getInterestsWithDeposit() const {
    return interestsWithDeposit;
}

// Method to display results
void Investment::displayResults() const {
    // Display results for balances without deposit
    if (!balancesNoDeposit.empty()) {
        std::cout << std::endl;
        std::cout << "     Balance and Interest Without Additional Monthly Deposits" << std::endl;
        std::cout << std::string(66, '=') << std::endl;
        std::cout << "Year          Year End Balance          Year End Earned Interest" << std::endl;
        std::cout << std::string(66, '-') << std::endl;

        for (size_t i = 0; i < balancesNoDeposit.size(); ++i) {
            std::cout << " " << std::left << std::setw(5) << (i + 1) << "\t\t$" 
                      << std::fixed << std::setprecision(2) << balancesNoDeposit[i] << "\t\t\t\t$" 
                      << interestsNoDeposit[i] << std::endl;
        }
    }

    // Display results for balances with deposit
    if (!balancesWithDeposit.empty()) {
        std::cout << std::endl;
        std::cout << "     Balance and Interest With Additional Monthly Deposits" << std::endl;
        std::cout << std::string(66, '=') << std::endl;
        std::cout << "Year          Year End Balance          Year End Earned Interest" << std::endl;
        std::cout << std::string(66, '-') << std::endl;

        for (size_t i = 0; i < balancesWithDeposit.size(); ++i) {
            std::cout << " " << std::left << std::setw(5) << (i + 1) << "\t\t$" 
                      << std::fixed << std::setprecision(2) << balancesWithDeposit[i] << "\t\t\t\t$" 
                      << interestsWithDeposit[i] << std::endl;
        }
    }
}