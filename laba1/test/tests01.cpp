#include <gtest/gtest.h>
#include "../include/converter.h"

TEST(TimeConverterTest, AM_Times)
{
    EXPECT_EQ(convertTo24("12:00 am"), "0000");
    EXPECT_EQ(convertTo24("01:15 am"), "0115");
    EXPECT_EQ(convertTo24("11:59 am"), "1159");
}

TEST(TimeConverterTest, PM_Times)
{
    EXPECT_EQ(convertTo24("12:00 pm"), "1200");
    EXPECT_EQ(convertTo24("01:00 pm"), "1300");
    EXPECT_EQ(convertTo24("11:45 pm"), "2345");
}

TEST(TimeConverterTest, EdgeCases)
{
    EXPECT_EQ(convertTo24("12:01 am"), "0001");
    EXPECT_EQ(convertTo24("01:00 am"), "0100");
    EXPECT_EQ(convertTo24("12:59 pm"), "1259");
}

TEST(TimeConverterTest, InvalidInputs) {
    EXPECT_EQ(convertTo24(""), "ERROR");         
    EXPECT_EQ(convertTo24("25:00 pm"), "ERROR"); 
    EXPECT_EQ(convertTo24("00:30 am"), "ERROR"); 
    EXPECT_EQ(convertTo24("10:60 am"), "ERROR"); 
    EXPECT_EQ(convertTo24("10:-1 pm"), "ERROR"); 
    EXPECT_EQ(convertTo24("10:30 xm"), "ERROR"); 
    EXPECT_EQ(convertTo24("1030 pm"), "ERROR");  
    EXPECT_EQ(convertTo24("10:30pm"), "ERROR");  
    EXPECT_EQ(convertTo24("abc"), "ERROR");      
}