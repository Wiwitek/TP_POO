#include "Client.h"
#include "Bank_account.h"
#include "Savings_account.h"

int Client::next_id = 1;

Client::Client(const std::string& first_name, const std::string& last_name, const std::string& address)
    : client_id(next_id++), first_name(first_name), last_name(last_name), address(address) {
}

Client::~Client() {
    for (Account* account : accounts) {
        delete account;
    }
}

int Client::add_account(const std::string& type, const float& initial_balance, const float& authorized_overdraft_or_interest_rate) {
    int id = accounts.size() + 1;
    if (type == "bank") {
        accounts.push_back(new Bank_account(id, initial_balance, authorized_overdraft_or_interest_rate));
    }
    else if (type == "saving") {
        accounts.push_back(new Savings_account(id, initial_balance, authorized_overdraft_or_interest_rate));
    }
    return accounts.back()->get_account_id();
}

void Client::display(std::ostream& os) const {
    os << "Client ID: " << client_id << ", First Name: " << first_name
        << ", Last Name: " << last_name << ", Address: " << address << "\\n";
    for (const Account* account : accounts) {
        os << *account << "\\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
    client.display(os);
    return os;
}
