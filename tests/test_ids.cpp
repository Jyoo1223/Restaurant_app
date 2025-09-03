#include "Restaurant.h"
#include <gtest/gtest.h>

TEST(RestaurantTest, IsValidItemId) {
    Restaurant r;
    EXPECT_TRUE(r.isValidItemId(1));
    EXPECT_FALSE(r.isValidItemId(0));
    EXPECT_FALSE(r.isValidItemId(999));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
