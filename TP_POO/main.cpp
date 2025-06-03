#include <iostream>
#include "Centralized_agency.h"

int main() {
    Centralized_agency central_agency;

    // Création des agences
    central_agency.add_decentralized_agency("Agence Lille");
    central_agency.add_decentralized_agency("Agence Roubaix");
    central_agency.add_decentralized_agency("Agence Tourcoing");
    central_agency.add_decentralized_agency("Agence Valenciennes");
    central_agency.add_decentralized_agency("Agence Douai");
    central_agency.add_decentralized_agency("Agence Bidon");


    // Ajout de clients dans Agence Lille (index 0)
    auto* agence_lille = central_agency.get_agency(0);
    agence_lille->add_client("Jean", "Dupont", "1 rue de la Gare, Lille");
    agence_lille->add_client("Akim", "El Yamani", "1 rue de Paris, Lille");

    // Ajout de clients dans Agence Tourcoing (index 2)
    auto* agence_tourcoing = central_agency.get_agency(2);
    agence_tourcoing->add_client("Sophie", "Lefevre", "10 place de la Liberté, Lille");
    agence_tourcoing->add_client("Jacques", "Clairefontaine", "10 place de la Liberté, Lille");

    // Transactions simulées
    central_agency.process_transaction("Account #1 deposit amount 1000.00");
    central_agency.process_transaction("Account #2 deposit amount 1500.00");
    central_agency.process_transaction("Account #3 deposit amount 2000.00");
    central_agency.process_transaction("Account #4 deposit amount 2500.00");
    central_agency.process_transaction("Account #5 deposit amount 3000.00");
    central_agency.process_transaction("Account #6 deposit amount 3500.00");
    central_agency.process_transaction("Account #7 deposit amount 4000.00");
    central_agency.process_transaction("Account #8 deposit amount 4500.00");
    central_agency.process_transaction("Account #3 withdrawal amount 500.00");
    central_agency.process_transaction("Account #1 transfer amount 2000.00 to account #2");
    central_agency.process_transaction("Account #2 interest");

    // Affichage final
    std::cout << central_agency;

    return 0;
}
