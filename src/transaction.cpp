#include <stdexcept>
#include "transaction.h"

// define the constructor
Transaction::Transaction(
    const std::string& transaction_id,
    const std::string& account_id,
    double amount,
    TransactionType type,
    const std::string& timestamp
) : transaction_id(transaction_id), account_id(account_id), amount(amount), type(type), timestamp(timestamp) {}

// the getters
std::string Transaction::get_transaction_id() const {
    return transaction_id;
}

std::string Transaction::get_account_id() const {
    return account_id;
}

double Transaction::get_amount() const {
    return amount;
}
TransactionType Transaction::get_transaction_type() const {
    return type;
}

std::string Transaction::get_timestamp() const {
    return timestamp;
}

// the static helpers
std::string Transaction::type_to_string(TransactionType type_t) {
    if (type_t == TransactionType::DEPOSIT) return "DEPOSIT";
    else if (type_t == TransactionType::WITHDRAWAL) return "WITHDRAWAL";
    else throw std::invalid_argument("unkown transaction type.");
}

TransactionType Transaction::string_to_type(const std::string& type_str) {
    if (type_str == "DEPOSIT") return TransactionType::DEPOSIT;
    else if (type_str == "WITHDRAWAL") return TransactionType::WITHDRAWAL;
    else throw std::invalid_argument("unknown transactoin type.");
}
