#include "Restaurant.h"
#include <gtest/gtest.h>

TEST(RestaurantTest, AddOrderItems) {
    Restaurant r;
    r.clearOrder();
    r.addOrderItem(1, 2);
    r.addOrderItem(1, 3);

    auto orders = r.getCurrentOrder();
    ASSERT_GE(orders.size(), 1);

    // If addOrderItem merges quantities, total should be 5
    int totalQty = 0;
    for (auto& order : orders) {
        if (order.item.id == 1) totalQty += order.quantity;
    }
    EXPECT_EQ(totalQty, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
