#include "Restaurant.h"
#include <gtest/gtest.h>

TEST(RestaurantTest, GenerateBillEmptyOrder) {
    Restaurant r;
    r.clearOrder();

    testing::internal::CaptureStdout();
    r.generateBill();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("No items ordered yet"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
