#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class Savings_account : public Account {
private:
    float interest_rate;
public:
    Savings_account(int id, float initial_balance, float rate);
    void apply_interest();
    void display(std::ostream& os) const override;
};

#endif // SAVINGS_ACCOUNT_H
