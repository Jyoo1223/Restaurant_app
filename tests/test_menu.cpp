#include "Restaurant.h"
#include <gtest/gtest.h>

TEST(RestaurantTest, MenuLoads) {
    Restaurant r;
    auto menu = r.getMenu();
    EXPECT_FALSE(menu.empty());

    for (const auto& item : menu) {
        EXPECT_FALSE(item.name.empty());
        EXPECT_GT(item.price, 0);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
