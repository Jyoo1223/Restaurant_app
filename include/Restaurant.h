#pragma once
#include <vector>
#include <string>
#include "MenuItem.h"
#include "OrderItem.h"

class Restaurant {
private:
    std::vector<MenuItem> menu;
    std::vector<OrderItem> currentOrder;
    int nextId = 1;
    std::string customerName;

public:
    Restaurant();

    void showMenu() const;
    void takeOrder();
    void generateBill();
    
    // For tests
    const std::vector<MenuItem>& getMenu() const;
    const std::vector<OrderItem>& getCurrentOrder() const;
    void clearOrder();
    void setCustomerName(const std::string&);
    std::string getCustomerName() const;
    bool isValidItemId(int id) const;
    void addOrderItem(int itemId, int quantity);
};
