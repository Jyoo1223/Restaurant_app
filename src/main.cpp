#include "Restaurant.h"
#include <iostream>

int main() {
    Restaurant r;
    int choice;

    do {
        std::cout << "\n🍽️ --- Welcome to Foodir Restaurant ---\n";
        std::cout << "1. Show Menu\n2. Place Order\n3. Generate Bill\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                r.showMenu();
                break;
            case 2:
                r.takeOrder();
                break;
            case 3:
                r.generateBill();
                break;
            case 4:
                std::cout << "👋 Thank you! Visit again.\n";
                break;
            default:
                std::cout << "❌ Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
