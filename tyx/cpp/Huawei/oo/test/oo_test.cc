#include "gtest/gtest.h"
#include "person.h"

TEST(PersonTest, Case001)
{
    Person person;
    EXPECT_EQ(person.Introduce(), "My name is Tom. I am 21 years old.");
}