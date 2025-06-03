#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Account.h"

class Bank_account : public Account {
private:
    float authorized_overdraft;
public:
    Bank_account(int id, float initial_balance, float overdraft);
    bool withdraw(const float& amount) override;
    void display(std::ostream& os) const override;
};

#endif // BANK_ACCOUNT_H


