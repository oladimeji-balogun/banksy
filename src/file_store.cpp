#include "file_store.h"
#include <fstream>
#include <iostream>
#include <sstream>

FileStore::FileStore(
    const std::string& accounts_file,
    const std::string& transactions_file
) : accounts_file(accounts_file), transactions_file(transactions_file) {}

void FileStore::save_account(const Account& account) {
    std::ofstream file(accounts_file, std::ios::app);
    if (!file.is_open()) {
        std::cout << "encountered an error when opening file.\n";
        return;
    }
    file << account.get_account_id() << ","
        << account.get_owner_name() << ","
        << account.get_balance() << ","
        << account.type_to_string(account.get_account_type()) << "\n";
    std::cout << "account: " << account.get_account_id() << " has been added successfully.";
}

std::vector<Account> FileStore::load_accounts() {
    std::ifstream file(accounts_file);

    if (!file.is_open()) {
        std::cout << "error when opening file.\n";
        return {};
    }

    std::vector<Account> accounts;
    // create a variable for every linw in the csv file
    std::string line;
    while (std::getline(file, line)) {
        // convert the line to a string stream
        std::stringstream ss(line);

        std::string account_id, owner_name, balance, type;
        std::getline(ss, account_id, ',');
        std::getline(ss, owner_name, ',');
        std::getline(ss, balance, ',');
        std::getline(ss, type, ',');

        // call the Account constructor 
        Account account(account_id, owner_name, std::stod(balance), Account::string_to_type(type));
        // push account to the accounts vector
        accounts.push_back(account);
    }

    if (accounts.empty()) {
        std::cout << "no registered accounts to load.\n";
        return {};
    }
    return accounts;
}

void FileStore::save_transaction(const Transaction& transaction) {
    // open the file
    std::ofstream file(transactions_file, std::ios::app);
    if (!file.is_open()){
        std::cout << "failed to open file.\n";
        return;
    }

    file << transaction.get_transaction_id() << ","
        << transaction.get_account_id() << ","
        << transaction.get_amount() << ","
        << Transaction::type_to_string(transaction.get_transaction_type()) << ","
        << transaction.get_timestamp() << "\n";

    std::cout << "transaction: " << transaction.get_account_id() << " has been saved successfully.";
}

std::vector<Transaction> FileStore::load_transactions(const std::string& account_id) {
    // open the file
    std::ifstream file(transactions_file);
    if (!file.is_open()) {
        std::cout << "error encountered when opening file.\n";
        return {};
    }

    std::vector<Transaction> transactions;
    std::string line; // variable to store each line of the file

    // loop through each line in the file
    while (std::getline(file, line)) {
        // convert each line to a string stream
        std::stringstream ss(line);
        // identifiers to store each field
        std::string t_id, t_account_id, t_amount, t_type, t_timestamp;

        std::getline(ss, t_id, ',');
        std::getline(ss, t_account_id, ',');
        std::getline(ss, t_amount, ',');
        std::getline(ss, t_type, ',');
        std::getline(ss, t_timestamp, ',');

        // call the Transaction constructor
        Transaction transaction(
            t_id, 
            t_account_id,
            std::stod(t_amount),
            Transaction::string_to_type(t_type),
            t_timestamp
        );
        // add transaction to transactions vector
        transactions.push_back(transaction);
    }

    // applying the filter
    // auto it = std::find_if(transactions.begin(), transactions.end(), [&accound_id](const Transaction& t) {
    //     return t.getAccountID() == accound_id;
    // });

    // if (it == transactions.end()) {
    //     std::cout << "account id " << accound_id << " not found.\n";
    //     return;
    // } 

    std::vector<Transaction> result;
    for (auto transaction : transactions) {
        if (transaction.get_account_id() == account_id) {
            result.push_back(transaction);
        }
    }
    if (result.empty()) {
        std::cout << "no transactions exist with the account id: " << account_id << "\n";
        return {};
    }
    return result;
}

int FileStore::count_transactions() const {
    std::ifstream file(transactions_file);

    if (!file.is_open()) {
        std::cout << "error in opening the file.\n";
        return 0;
    }

    std::string line;
    int line_count = 0;

    while (std::getline(file, line)) {
        line_count++;
    }
    file.close();

    return line_count;

}