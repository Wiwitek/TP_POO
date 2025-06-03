#include "Account.h"

Account::Account(int id, float initial_balance) : account_id(id), balance(initial_balance) {}

bool Account::withdraw(const float& amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::deposit(const float& amount) {
    balance += amount;
}

float Account::get_balance() const {
    return balance;
}

int Account::get_account_id() const {
    return account_id;
}

void Account::display(std::ostream& os) const {
    os << "Account #" << account_id << " - Balance: " << balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    account.display(os);
    return os;
}
