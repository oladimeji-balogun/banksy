#ifndef FILESTORE_H
#define FILESTORE_H

#include <vector>
#include "transaction.h"
#include "account.h"
#include <string>

class FileStore {
    private:
        std::string accounts_file;
        std::string transactions_file;

    public:
        FileStore(const std::string& accounts_file, const std::string& transactions_file);

        void save_account(const Account& account);
        std::vector<Account> load_accounts();

        void save_transaction(const Transaction& transaction);
        // load tranactions with the account id filter
        std::vector<Transaction> load_transactions(const std::string& account_id) const;
        int count_transactions() const;

};
#endif