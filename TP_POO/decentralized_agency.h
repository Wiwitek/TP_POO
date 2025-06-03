#ifndef DECENTRALIZED_AGENCY_H
#define DECENTRALIZED_AGENCY_H

#include <iostream>
#include <string>
#include <vector>
#include "Client.h"

class Decentralized_agency {
private:
    static int next_id;
    int agency_id;
    std::string name;
    std::vector<Client*> clients;

public:
    Decentralized_agency(const std::string& name);
    ~Decentralized_agency();

    void add_client(const std::string& first_name, const std::string& last_name, const std::string& address);
    void display(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Decentralized_agency& agency);
};

#endif // DECENTRALIZED_AGENCY_H

