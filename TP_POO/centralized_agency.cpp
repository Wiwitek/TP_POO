#include "Centralized_agency.h"
#include <iostream>

const int MAX_DECENTRALIZED_AGENCIES = 5;

Centralized_agency::~Centralized_agency() {
    for (Decentralized_agency* agency : agencies) {
        delete agency;
    }
}

void Centralized_agency::add_decentralized_agency(const std::string& name) {
    if (agencies.size() >= MAX_DECENTRALIZED_AGENCIES) {
        std::cout << "Erreur: Nombre maximum d'agences décentralisées atteint : " << name << std::endl;
        return;
    }
    agencies.push_back(new Decentralized_agency(name));
}

void Centralized_agency::process_transaction(const std::string& transaction) {
    transactions.push_back(transaction);
}

void Centralized_agency::display(std::ostream& os) const {
    os << "--- Agence centrale ---" << std::endl;
    for (size_t i = 0; i < agencies.size(); ++i) {
        os << "Agence #" << (i + 1) << " ";
        os << *agencies[i];
    }

    os << "----------------------------------------" << std::endl;
    os << "--- Transactions enregistrées par l'agence centrale ---" << std::endl;
    for (const std::string& transaction : transactions) {
        os << transaction << std::endl;
    }
    os << "Total des transactions: " << transactions.size() << std::endl;
    os << "----------------------------------------" << std::endl;
}
Decentralized_agency* Centralized_agency::get_agency(int index) {
    if (index >= 0 && index < agencies.size()) {
        return agencies[index];
    }
    return nullptr;
}


std::ostream& operator<<(std::ostream& os, const Centralized_agency& agency) {
    agency.display(os);
    return os;
}
