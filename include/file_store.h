#ifndef FILESTORE_H
#define FILESTORE_H

#include <vector>
#include "transaction.h"
#include "account.h"

class FileStore {
    private:
        std::string accounts_file;
        std::string transactions_file;

    public:
        FileStore(const std::string& accounts_file, const std::string& transactions_file);

        void saveAccount(const Account& account);
        std::vector<Account> loadAccounts();

        void saveTransaction(const Transaction& transaction);
        // load tranactions with the account id filter
        std::vector<Transaction> loadTransactions(const std::string& account_id);

};
#endif