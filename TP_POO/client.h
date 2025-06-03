#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

class Client {
private:
    static int next_id;
    int client_id;
    std::string first_name;
    std::string last_name;
    std::string address;
    std::vector<Account*> accounts;
public:
    Client(const std::string& first_name, const std::string& last_name, const std::string& address);
    ~Client();
    int add_account(const std::string& type, const float& initial_balance, const float& authorized_overdraft_or_interest_rate);
    void display(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Client& client);
};

#endif // CLIENT_H

