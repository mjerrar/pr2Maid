#include <gtest/gtest.h>
#include <ros/ros.h>

TEST(DummyTest, test)
{
    EXPECT_EQ(1, 1);
}



int main(int argc, char** argv) {
  ros::init(argc, argv, "talker_test");
  ros::NodeHandle nh;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
