#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

// the transaction type enum class
enum class TransactionType {
    WITHDRAWAL,
    DEPOSIT
};

// the transaction class
class Transaction {
    private:
        std::string transaction_id;
        std::string account_id;
        double amount;
        TransactionType type;
        std::string timestamp;
    
    public:
        // the constructor
        Transaction(
            const std::string& transaction_id,
            const std::string& account_id,
            double amount,
            TransactionType type,
            const std::string& timestamp
        );

        std::string getTransactionID() const;
        std::string getAccountID() const;
        double getAmount() const;
        TransactionType getTransactionType() const;
        std::string getTimestamp() const;

        // public static helpers
        static TransactionType string_to_type(const std::string& type_str);
        static std::string type_to_string(TransactionType type_t);
    
};
#endif