#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

enum class AccountType {
    SAVINGS,
    CURRENT
};

class Account {
    private:
        std::string account_id;
        std::string owner_name;
        double balance;
        AccountType type;
        
    public:
        // the constructor
        Account (const std::string& account_id, const std::string& owner_name, double balance, AccountType type);
        // the getters
        std::string getAccountID() const;
        std::string getOwnerName() const;
        double getBalance() const;
        AccountType getAccountType() const;

        // operation methods
        void deposit(double amount);
        void withdraw(double amount);

        // static helpers
        static std::string type_to_string(AccountType type_t);
        static AccountType string_to_type(const std::string& type_str);

};

#endif