#ifndef BANK_H
#define BANK_H
#include "account.h"
#include "file_store.h"
#include "transaction.h"

class Bank {
    private: 
        std::vector<Account> accounts;
        FileStore store;
        

    public: 
        Bank(FileStore store);
        // banking methods
        void create_account(const std::string& owner_name, AccountType type);
        Account* find_account(const std::string& account_id);
        std::vector<Account> list_accounts();
        void deposit(const std::string& account_id, double amount);
        void withdraw(const std::string& account_id, double amount);
        void get_transaction_history(const std::string& account_id);
};

#endif