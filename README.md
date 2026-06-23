# Banksy: Simple Bank Account System

A command-line bank account management system built in C++17. Banksy simulates core banking operations: account creation, deposits, withdrawals, and transaction history across multiple accounts with CSV-based persistence.

Built as a structured C++ learning project focusing on OOP design, class composition, file I/O, and clean separation of concerns.

---

## Features

- Create multiple bank accounts (Savings or Current)
- Deposit and withdraw funds with validation
- View real-time account balances
- Full transaction history per account
- Persistent storage via CSV: data survives between sessions
- Clean layered architecture: persistence layer designed for future database migration

---

## Tech Stack

- **Language:** C++17
- **Build System:** CMake 3.20+
- **Persistence:** CSV flat files (SQLite migration planned)
- **Tooling:** vcpkg

---

## Project Structure
```
banksy/

├── CMakeLists.txt

├── include/

│   ├── account.h

│   ├── transaction.h

│   ├── bank.h

│   └── file_store.h

├── src/

│   ├── account.cpp

│   ├── transaction.cpp

│   ├── bank.cpp

│   ├── file_store.cpp

│   └── main.cpp

└── data/

├── accounts.csv

└── transactions.csv
```

---

## Build Instructions

**Prerequisites:** CMake 3.20+, a C++17 compiler (GCC 11+ or Clang 13+)

```bash
git clone https://github.com/oladimeji-balogun/banksy.git
cd banksy
mkdir build && cd build
cmake ..
cmake --build .
./banksy
```

---

## Architecture

Banksy follows a layered architecture with strict separation of concerns:

- **`Account`** : models a bank account with balance operations and validation
- **`Transaction`** : models a single deposit or withdrawal event with a timestamp
- **`FileStore`** : isolated persistence layer handling all CSV reads and writes
- **`Bank`** : orchestrates account management, coordinates between `Account` and `FileStore`
- **`main.cpp`** : CLI loop, user input, delegates to `Bank`

The `FileStore` class is intentionally isolated — swapping to SQLite or PostgreSQL only requires replacing this class.

---

## Roadmap

- [ ] SQLite persistence via vcpkg
- [ ] Account-to-account transfers
- [ ] Input validation and error handling improvements
- [ ] Unit tests with gtest

---

## License

MIT