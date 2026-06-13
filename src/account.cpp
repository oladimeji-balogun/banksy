#include <stdexcept>
#include "account.h"

Account::Account(const std::string& account_id, const std::string& owner_name, double balance, AccountType type) : account_id(account_id), owner_name(owner_name), balance(balance), type(type) {}

// the getters
std::string Account::getAccountID() const {
    return account_id;
}
std::string Account::getOwnerName() const {
    return owner_name;
}
double Account::getBalance() const {
    return balance;
}
AccountType Account::getAccountType() const {
    return type;
}

// operation functions
void Account::deposit(double amount) {
    
    if (amount <= 0) {
        throw std::invalid_argument("the amount to deposit must be greater than zero.");
    }
    balance += amount;
    
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("the amount to be withdrawn must be greater than zero");
    }

    if (amount > balance) {
        throw std::runtime_error("insufficient funds");
    }
    // process the funds
    balance -= amount;
}

std::string Account::type_to_string(AccountType type) {
    if (type == AccountType::CURRENT) return "CURRENT";
    else if (type == AccountType::SAVINGS) return "SAVINGS";
    else throw std::runtime_error("unknown account type.");
}

AccountType Account::string_to_type(const std::string& type_str) {
    if (type_str == "SAVINGS") return AccountType::SAVINGS;
    else if (type_str == "CURRENT") return AccountType::CURRENT;
    else throw std::runtime_error("input must be either SAVINGS or CURRENT.");
}