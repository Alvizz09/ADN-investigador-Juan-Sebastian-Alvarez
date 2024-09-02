#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

struct Contact {
    std::string name;
    std::string email;
    std::string phone;
    std::string address;
    std::time_t lastContactDate;
};

// Función para crear un nuevo contacto
Contact createContact(const std::string& name, const std::string& email, const std::string& phone, const std::string& address) {
    Contact contact;
    contact.name = name;
    contact.email = email;
    contact.phone = phone;
    contact.address = address;
    contact.lastContactDate = std::time(nullptr);
    return contact;
}

// Función para añadir un contacto al vector de contactos
void addContact(std::vector<Contact>& contacts, const Contact& contact) {
    contacts.push_back(contact);
}

// Función para mostrar todos los contactos 
void showContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No hay contactos para mostrar.\n";
        return;
    }

    std::cout << "----- Lista de Contactos -----\n";
    for (const auto& contact : contacts) {
        std::cout << "Nombre: " << contact.name << '\n';
        std::cout << "Email: " << contact.email << '\n';
        std::cout << "Teléfono: " << contact.phone << '\n';
        std::cout << "Dirección: " << contact.address << '\n';
        std::cout << "Último Contacto: " << std::ctime(&contact.lastContactDate);
        std::cout << "----------------------------\n";
    }
}


// Función para encontrar un contacto por nombre
Contact* findContactByName(std::vector<Contact>& contacts, const std::string& name) {
    for (auto& contact : contacts) {
        if (contact.name == name) {
            return &contact;
        }
    }
    return nullptr;
}

// Función para actualizar la información de un contacto
void updateContact(Contact& contact, const std::string& email, const std::string& phone, const std::string& address) {
    contact.email = email;
    contact.phone = phone;
    contact.address = address;
    contact.lastContactDate = std::time(nullptr);
}

// Función para eliminar un contacto por nombre
void deleteContact(std::vector<Contact>& contacts, const std::string& name) {
    contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
                   [&](const Contact& contact) { return contact.name == name; }),
                   contacts.end());
}

// Función para mostrar el menú
void showMenu() {
  std::cout << "\n";
    std::cout << "----- CRM Básico -----\n";
    std::cout << "1. Añadir nuevo contacto\n";
    std::cout << "2. Mostrar todos los contactos\n";
    std::cout << "3. Actualizar información de un contacto\n";
    std::cout << "4. Eliminar un contacto\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    std::vector<Contact> contacts;
    int option;

    do {
        showMenu();
        std::cin >> option;
        std::cin.ignore(); // Limpiar el buffer de entrada

        switch (option) {
            case 1: {
                std::string name, email, phone, address;
                std::cout << "Ingrese el nombre del contacto: ";
                std::getline(std::cin, name);
                std::cout << "Ingrese el email del contacto: ";
                std::getline(std::cin, email);
                std::cout << "Ingrese el teléfono del contacto: ";
                std::getline(std::cin, phone);
                std::cout << "Ingrese la dirección del contacto: ";
                std::getline(std::cin, address);
                Contact newContact = createContact(name, email, phone, address);
                addContact(contacts, newContact);
                break;
            }
            case 2: {
                showContacts(contacts);
                break;
            }
            case 3: {
                std::string name, email, phone, address;
                std::cout << "Ingrese el nombre del contacto a actualizar: ";
                std::getline(std::cin, name);
                Contact* contact = findContactByName(contacts, name);
                if (contact) {
                    std::cout << "Ingrese el nuevo email: ";
                    std::getline(std::cin, email);
                    std::cout << "Ingrese el nuevo teléfono: ";
                    std::getline(std::cin, phone);
                    std::cout << "Ingrese la nueva dirección: ";
                    std::getline(std::cin, address);
                    updateContact(*contact, email, phone, address);
                } else {
                    std::cout << "Contacto no encontrado.\n";
                }
                break;
            }
            case 4: {
                std::string name;
                std::cout << "Ingrese el nombre del contacto a eliminar: ";
                std::getline(std::cin, name);
                deleteContact(contacts, name);
                break;
            }
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
        }

    } while (option != 5);

    return 0;
}
