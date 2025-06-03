#include "Bank_account.h"

Bank_account::Bank_account(int id, float initial_balance, float overdraft)
    : Account(id, initial_balance), authorized_overdraft(overdraft) {
}

bool Bank_account::withdraw(const float& amount) {
    if (balance + authorized_overdraft >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Bank_account::display(std::ostream& os) const {
    os << "Account #" << account_id << " (Bank Account) - Balance: " << balance
        << " - Authorized Overdraft: " << authorized_overdraft;
}
