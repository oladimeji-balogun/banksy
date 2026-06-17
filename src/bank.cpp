#include <iostream>
#include "bank.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

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

Account* Bank::find_account(const std::string& account_id) {
    auto it = std::find_if(accounts.begin(), accounts.end(), [&account_id](Account account) {
        return account_id == account.get_account_id();
    });

    if (it == accounts.end()) {
        std::cout << "no accounts found for this account ID: " << account_id << "\n";
        return nullptr;
    }

    return &(*it);
} 

void Bank::list_accounts() const {
    for (Account account : accounts) {
        // print all the variables to stdout 
        std::cout << "account_id: " << account.get_account_id() << " | " 
            << "owner_name: " << account.get_owner_name() << " | "
            << "balance: " << account.get_balance() << " | "
            << "type: " << Account::type_to_string(account.get_account_type());
    }
}

// deposit method 
void Bank::deposit(const std::string& account_id, double amount) {

    Account* account = Bank::find_account(account_id);

    // check if the account is a null pointer 
    if (account == nullptr) {
        std::cout << "no account with this ID found\n";
        return;
    }

    // deposit the amount through the account oject
    try {
        account->deposit(amount);
    } catch (std::invalid_argument& e) {
        std::cout << "deposit failed: " << e.what() << "\n";
        return;
    }

    
    int next_num = store.count_transactions() + 1;
    std::ostringstream ss;
    ss << "TXN-" << std::setw(4) << std::setfill('0') << next_num;

    std::string transaction_id = ss.str();

    // get the timestamp
    // get current time
    std::time_t now = std::time(nullptr);

    // convert to local time struct
    std::tm* local_time = std::localtime(&now);

    // format it into a string
    std::ostringstream ts;
    ts << (1900 + local_time->tm_year) << "-"
    << std::setw(2) << std::setfill('0') << (1 + local_time->tm_mon) << "-"
    << std::setw(2) << std::setfill('0') << local_time->tm_mday << " "
    << std::setw(2) << std::setfill('0') << local_time->tm_hour << ":"
    << std::setw(2) << std::setfill('0') << local_time->tm_min << ":"
    << std::setw(2) << std::setfill('0') << local_time->tm_sec;

    std::string timestamp = ts.str();
    // produces: 2024-01-15 10:30:00

    Transaction transaction(transaction_id, account_id, amount, TransactionType::DEPOSIT, timestamp);
    store.save_transaction(transaction);
}


void Bank::withdraw(const std::string& account_id, double amount) {
    Account* account = Bank::find_account(account_id);

    if (account == nullptr) {
        std::cout << "no account found with this ID: " << account_id;
        return;
    }

    try {
        account->withdraw(amount);
    } catch(std::invalid_argument& e) {
        std::cout << "withdrawal failed: " << e.what() << "\n";
        return;
    } catch (std::runtime_error& e) {
        std::cout << "withdrawal failed: " << e.what() << "\n";
        return;
    }


    int next_num = store.count_transactions() + 1;
    std::ostringstream ss;
    ss << "TXN-" << std::setw(4) << std::setfill('0') << next_num;

    std::string transaction_id = ss.str();

    // get the timestamp
    // get current time
    std::time_t now = std::time(nullptr);

    // convert to local time struct
    std::tm* local_time = std::localtime(&now);

    // format it into a string
    std::ostringstream ts;
    ts << (1900 + local_time->tm_year) << "-"
        << std::setw(2) << std::setfill('0') << (1 + local_time->tm_mon) << "-"
        << std::setw(2) << std::setfill('0') << local_time->tm_mday << " "
        << std::setw(2) << std::setfill('0') << local_time->tm_hour << ":"
        << std::setw(2) << std::setfill('0') << local_time->tm_min << ":"
        << std::setw(2) << std::setfill('0') << local_time->tm_sec;

    std::string timestamp = ts.str();
    // produces: 2024-01-15 10:30:00

    // creation a transaction
    Transaction transaction(
        transaction_id, 
        account_id,
        amount, 
        TransactionType::WITHDRAWAL,
        timestamp
    );
    store.save_transaction(transaction);


}
