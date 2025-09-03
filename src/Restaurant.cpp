#include "Restaurant.h"
#include <iostream>
#include <iomanip>
#include <limits>

using std::cout;
using std::endl;

Restaurant::Restaurant() {
    // Add predefined items
    menu.reserve(30); // Optional: reserve space for efficiency
    auto addPredefinedMenuItem = [this](const std::string& name, double price) {
        menu.push_back({nextId++, name, price});
    };

    addPredefinedMenuItem("Margherita Pizza", 150);
    addPredefinedMenuItem("Pepperoni Pizza", 200);
    addPredefinedMenuItem("Cheeseburger", 250);
    addPredefinedMenuItem("Chicken Wings", 300);
    addPredefinedMenuItem("Tandoori Chicken", 200);
    addPredefinedMenuItem("Grilled Chicken Sandwich", 270);
    addPredefinedMenuItem("Chicken Biryani", 200);
    addPredefinedMenuItem("Egg Biryani", 100);
    addPredefinedMenuItem("Mutton Biryani", 250);
    addPredefinedMenuItem("Chicken Lollipop", 230);
    addPredefinedMenuItem("Veggie Burger", 90);
    addPredefinedMenuItem("Salad", 120);
    addPredefinedMenuItem("French Fries", 70);
    addPredefinedMenuItem("Sandwich", 80);
    addPredefinedMenuItem("Pasta", 68);
    addPredefinedMenuItem("Chocolate Brownie", 40);
    addPredefinedMenuItem("Mango Shake", 125);
    addPredefinedMenuItem("Cold Coffee", 80);
    addPredefinedMenuItem("Lemonade", 69);
    addPredefinedMenuItem("Garlic Bread", 100);
    addPredefinedMenuItem("Paneer Tikka", 180);
    addPredefinedMenuItem("Veg Biryani", 200);
    addPredefinedMenuItem("Aloo fry", 60);
    addPredefinedMenuItem("Egg fry", 90);
    addPredefinedMenuItem("Masala Dosa", 79);
    addPredefinedMenuItem("Samosa (2 pcs)", 60);
    addPredefinedMenuItem("Aloo Paratha", 90);
    addPredefinedMenuItem("Veg Manchurian", 100);
    addPredefinedMenuItem("Maggii", 70);
}

void Restaurant::showMenu() const {
    if (menu.empty()) {
        cout << "\n📭 Menu is empty.\n";
        return;
    }
    cout << "\n📋 --- MENU ---\n";
    for (const auto& item : menu) {
        cout << item.id << ". " << item.name << " - ₹" 
             << std::fixed << std::setprecision(2) << item.price << endl;
    }
}

void Restaurant::takeOrder() {
    if (menu.empty()) {
        cout << "\n⚠️ No items available to order.\n";
        return;
    }

    currentOrder.clear();
    cout << "\nEnter your name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, customerName);

    int id, qty;
    showMenu();

    cout << "\nEnter item ID to order (0 to finish): ";
    while (std::cin >> id && id != 0) {
        if (!isValidItemId(id)) {
            cout << "❌ Invalid item ID. Try again.\n";
        } else {
            cout << "Enter quantity for item " << id << ": ";
            std::cin >> qty;
            if (qty <= 0) {
                cout << "❌ Invalid quantity.\n";
            } else {
                addOrderItem(id, qty);
            }
        }
        cout << "\nEnter next item ID (0 to finish): ";
    }
}

void Restaurant::generateBill() {
    if (currentOrder.empty()) {
        cout << "\n🧾 No items ordered yet.\n";
        return;
    }

    int totalItems = 0;
    double subtotal = 0;

    cout << "\n🧾 --- BILL for " << customerName << " ---\n";
    cout << "Item\tQuantity\tPrice\tTotal\n";
    cout << "-------------------------------------------\n";

    for (const auto& order : currentOrder) {
        double itemTotal = order.item.price * order.quantity;
        subtotal += itemTotal;
        totalItems += order.quantity;

        cout << order.item.name << "\t" 
             << order.quantity << "\t\t₹" 
             << std::fixed << std::setprecision(2) << order.item.price << "\t₹" 
             << itemTotal << endl;
    }

    cout << "-------------------------------------------\n";
    cout << "Total Items: " << totalItems << "\n";
    cout << "Subtotal: ₹" << std::fixed << std::setprecision(2) << subtotal << "\n";

    double tax = subtotal * 0.05;
    double total = subtotal + tax;

    cout << "Tax (5%): ₹" << std::fixed << std::setprecision(2) << tax << "\n";
    cout << "Total Amount: ₹" << std::fixed << std::setprecision(2) << total << "\n";

    currentOrder.clear();
}

// Helper for adding order with merging quantities
void Restaurant::addOrderItem(int itemId, int quantity) {
    for (auto& order : currentOrder) {
        if (order.item.id == itemId) {
            order.quantity += quantity;
            return;
        }
    }
    for (const auto& item : menu) {
        if (item.id == itemId) {
            currentOrder.push_back({item, quantity});
            return;
        }
    }
}

bool Restaurant::isValidItemId(int itemId) const {
    for (const auto& item : menu) {
        if (item.id == itemId) return true;
    }
    return false;
}

void Restaurant::clearOrder() {
    currentOrder.clear();
}

void Restaurant::setCustomerName(const std::string& name) {
    customerName = name;
}

std::string Restaurant::getCustomerName() const {
    return customerName;
}

const std::vector<MenuItem>& Restaurant::getMenu() const {
    return menu;
}

const std::vector<OrderItem>& Restaurant::getCurrentOrder() const {
    return currentOrder;
}
