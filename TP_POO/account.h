#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
protected:
    int account_id;
    float balance;
public:
    Account(int id, float initial_balance);
    virtual bool withdraw(const float& amount);
    void deposit(const float& amount);
    float get_balance() const;
    int get_account_id() const;
    virtual void display(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

#endif // ACCOUNT_H