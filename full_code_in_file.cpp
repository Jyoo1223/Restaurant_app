#include <iostream>
#include <vector>
#include <string>       // For std::string and std::getline
#include <iomanip>      // For setprecision
#include <limits>       // For cin.ignore
using namespace std;

struct MenuItem {
    int id;
    string name;
    double price;
};

struct OrderItem {
    MenuItem item;
    int quantity;
};

class Restaurant {
private:
    vector<MenuItem> menu;
    vector<OrderItem> currentOrder;
    int nextId = 1;
    string customerName;

public:
    // Constructor to preload some menu items
    Restaurant() {
        // Predefined items with name and price
        addPredefinedMenuItem("Margherita Pizza", 150);
        addPredefinedMenuItem("Pepperoni Pizza", 200);
        addPredefinedMenuItem("Cheeseburger", 250);
        addPredefinedMenuItem("Chicken Wings", 300);
        addPredefinedMenuItem("Tandoori Chicken",200);
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
        addPredefinedMenuItem("Mango Shake",125);
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

    void addPredefinedMenuItem(const string& name, double price) {
        menu.push_back({nextId++, name, price});
    }

    void showMenu() {
        if (menu.empty()) {
            cout << "\n📭 Menu is empty.\n";
            return;
        }
        cout << "\n📋 --- MENU ---\n";
        for (const auto& item : menu) {
            cout << item.id << ". " << item.name << " - ₹" << fixed << setprecision(2) << item.price << endl;
        }
    }

    void takeOrder() {
        if (menu.empty()) {
            cout << "\n⚠️ No items available to order.\n";
            return;
        }

        currentOrder.clear(); // Reset previous order
        cout << "\nEnter your name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, customerName);

        int id, qty;
        showMenu();
        cout << "\nEnter item ID to order (0 to finish): ";
        while (cin >> id && id != 0) {
            bool found = false;
            for (const auto& item : menu) {
                if (item.id == id) {
                    cout << "Enter quantity for " << item.name << ": ";
                    cin >> qty;
                    currentOrder.push_back({item, qty});
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "❌ Invalid item ID. Try again.\n";
            }
            cout << "\nEnter next item ID (0 to finish): ";
        }
    }

    void generateBill() {
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
                 << fixed << setprecision(2) << order.item.price << "\t₹" 
                 << itemTotal << endl;
        }

        cout << "-------------------------------------------\n";
        cout << "Total Items: " << totalItems << "\n";
        cout << "Subtotal: ₹" << fixed << setprecision(2) << subtotal << "\n";

        double tax = subtotal * 0.05;
        double total = subtotal + tax;

        cout << "Tax (5%): ₹" << fixed << setprecision(2) << tax << "\n";
        cout << "Total Amount: ₹" << fixed << setprecision(2) << total << "\n";

        currentOrder.clear(); // Reset for next customer
    }
};

int main() {
    Restaurant r;
    int choice;
    do {
        cout << "\n🍽️ --- Welcome to Foodir Restaurant ---\n";
        cout << "1. Show Menu\n2. Place Order\n3. Generate Bill\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: r.showMenu(); break;
            case 2: r.takeOrder(); break;
            case 3: r.generateBill(); break;
            case 4: cout << "👋 Thank you! Visit again.\n"; break;
            default: cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
