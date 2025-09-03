#include "Restaurant.h"
#include <gtest/gtest.h>

TEST(RestaurantTest, SetAndGetCustomerName) {
    Restaurant r;
    r.setCustomerName("Alice");
    EXPECT_EQ(r.getCustomerName(), "Alice");

    r.setCustomerName("Bob");
    EXPECT_EQ(r.getCustomerName(), "Bob");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
