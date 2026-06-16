#include <iostream>
#include "bank.h"
#include <sstream>
#include <iomanip>

Bank::Bank(FileStore store) : store(store), accounts(store.load_accounts()) {}

void Bank::create_account(const std::string& owner_name, AccountType type) {
    // create the unique account ids 
    int next_num = accounts.size() + 1;
    std::ostringstream ss;
    ss << "ACC-" << std::setw(4) << std::setfill('0') << next_num;

    std::string account_id = ss.str();

    // create a new account object 
    Account account(account_id, owner_name, 0.0, type);
    accounts.push_back(account);

    store.save_account(account);
    // account created successfully
    std::cout << "account created successfully.\n";



}