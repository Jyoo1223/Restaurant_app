#include "Restaurant.h"
#include <gtest/gtest.h>

TEST(RestaurantTest, AddLargeQuantity) {
    Restaurant r;
    int largeQty = 1000000;
    r.clearOrder();
    r.addOrderItem(1, largeQty);
    ASSERT_EQ(r.getCurrentOrder().size(), 1);
    EXPECT_EQ(r.getCurrentOrder()[0].quantity, largeQty);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
