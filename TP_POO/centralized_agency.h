#ifndef CENTRALIZED_AGENCY_H
#define CENTRALIZED_AGENCY_H

#include <iostream>
#include <vector>
#include <string>
#include "Decentralized_agency.h"

class Centralized_agency {
private:
    std::vector<Decentralized_agency*> agencies;
    std::vector<std::string> transactions;
public:
    ~Centralized_agency();
    void add_decentralized_agency(const std::string& name);
    void process_transaction(const std::string& transaction);
    void display(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Centralized_agency& agency);
    Decentralized_agency* get_agency(int index);

};

#endif // CENTRALIZED_AGENCY_H

