#include "PhoneBook.hpp"

Contact* PhoneBook::add(Contact contact) {
    book[front] = &contact;
    front++;
    return (&contact);
}

void print_contact_list(Contact* book[8], int front) {
    std::cout << "   index  | first name | last name | nickname " << std::endl;
    for (int i = 0; i <= front; i++) {
        std::cout <<  i << " | " << book[i]->get_firstname() << " | "
            << book[i]->get_lastname() << " | " << book[i]->get_nickname() << std::endl;
    }
}


Contact* PhoneBook::search(void) {
    int index;

    print_contact_list(book, front);
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index > front)
    {
        std::cin.ignore(1000, '\n');
        std::cin.clear();
        return (NULL);
    }
    return (book[index]);
}