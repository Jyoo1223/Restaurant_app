#include "Restaurant.h"
#include <gtest/gtest.h>

TEST(RestaurantTest, ClearOrderEmptiesOrder) {
    Restaurant r;
    r.addOrderItem(1, 2);
    r.addOrderItem(2, 3);
    ASSERT_FALSE(r.getCurrentOrder().empty());
    r.clearOrder();
    EXPECT_TRUE(r.getCurrentOrder().empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
