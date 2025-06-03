#include "Decentralized_agency.h"
#include "Bank_account.h"
#include "Savings_account.h"

int Decentralized_agency::next_id = 1;

Decentralized_agency::Decentralized_agency(const std::string& name)
    : agency_id(next_id++), name(name) {
}

Decentralized_agency::~Decentralized_agency() {
    for (Client* client : clients) {
        delete client;
    }
}

void Decentralized_agency::add_client(const std::string& first_name, const std::string& last_name, const std::string& address) {
    Client* client = new Client(first_name, last_name, address);

    // Ajout automatique de deux comptes : un courant et un épargne
    client->add_account("bank", 0.0f, 1000.0f);   // découvert autorisé
    client->add_account("saving", 0.0f, 2.0f);    // taux d’intérêt

    clients.push_back(client);
}

void Decentralized_agency::display(std::ostream& os) const {
    os << "Agency #" << agency_id << " (" << name << ")" << std::endl;
    if (clients.empty()) {
        os << "No customer" << std::endl;
    }
    else {
        for (const Client* client : clients) {
            os << *client << std::endl;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Decentralized_agency& agency) {
    agency.display(os);
    return os;
}
