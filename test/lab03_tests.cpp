#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"


class Lab03Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        testVec = new lab3::fifo;
        testVec->enqueue("Test 1");




    }

    virtual void TearDown() {
    }

public:
    lab3::fifo * testVec;
};

TEST_F(Lab03Fixture, constructor){
    lab3::fifo ct;
    EXPECT_TRUE(ct.is_empty());
    EXPECT_ANY_THROW(ct.size());

}

TEST_F(Lab03Fixture, Top){
    EXPECT_EQ("Test 1", testVec->top());
}
