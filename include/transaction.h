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

        std::string get_transaction_id() const;
        std::string get_account_id() const;
        double get_amount() const;
        TransactionType get_transaction_type() const;
        std::string get_timestamp() const;

        // public static helpers
        static TransactionType string_to_type(const std::string& type_str);
        static std::string type_to_string(TransactionType type_t);
    
};
#endif