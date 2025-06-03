#include "Savings_account.h"

Savings_account::Savings_account(int id, float initial_balance, float rate)
    : Account(id, initial_balance), interest_rate(rate) {
}

void Savings_account::apply_interest() {
    balance += balance * interest_rate / 100;
}

void Savings_account::display(std::ostream& os) const {
    os << "Account #" << account_id << " (Savings Account) - Balance: " << balance
        << " - Interest Rate: " << interest_rate << "%";
}
