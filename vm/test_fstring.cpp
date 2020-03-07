// include google test
#include "fstring.h"
#include <gtest/gtest.h>

char* string1 = "%d\n";
char* string2 = "%c\n";
char* string3 = "%s\n";
char* string4 = "%%\n";
char* string5 = "%2.2d\n";
char* string6 = "%2.2c\n";
char* string7 = "%2.2s\n";
char* string8 = "%%%d %s\n";
char* string9 = "arg1 %s %s %s %s %s\n";
char c = '\n';
char* s = "YALEYALE\tYou make me angry!!!!!!\n DIO!!!!!\nOLAOLAOLAOLAOLOLAOLAOLAOLAOLA\n";

TEST(FstringTest, TestInt1)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    int a = 100;
    args[0] = (intptr_t)&a;
    EXPECT_EQ(sprintf(str1, string1, a), fstring(str2, 2048, string1, args, 1));
    EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestInt2)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    int b = 20000;
    args[0] = (intptr_t)&b;
    EXPECT_EQ(sprintf(str1, string5, b), fstring(str2, 2048, string5, args, 1));
    EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestChar1)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    args[0] = (intptr_t)&c;
    EXPECT_EQ(sprintf(str1, string2, c), fstring(str2, 2048, string2, args, 1));
    EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestChar2)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    EXPECT_EQ(sprintf(str1, string4), fstring(str2, 2048, string4, args, 0));
    EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestChar3)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    args[0] = (intptr_t)s;
    EXPECT_EQ(sprintf(str1, string6, s), fstring(str2, 2048, string6, args, 1));
    // EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestString1)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    args[0] = (intptr_t)s;
    EXPECT_EQ(sprintf(str1, string3, s), fstring(str2, 2048, string3, args, 1));
    EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestString2)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    args[0] = (intptr_t)s;
    EXPECT_EQ(sprintf(str1, string7, s), fstring(str2, 2048, string7, args, 1))
        << "Test string2 failed";
    EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestIntAndString1)
{
    char str1[2048];
    char str2[2048];
    intptr_t args[5];

    int a = -1024;
    args[0] = (intptr_t)&a;
    args[1] = (intptr_t)s;
    EXPECT_EQ(sprintf(str1, string8, a, s), fstring(str2, 2048, string8, args, 2));
    EXPECT_STREQ(str1, str2);
}

TEST(FstringTest, TestLongString9)
{
    char str1[2048];
    char str2[2048];
    char* arg0 = "arg2";
    char* arg1 = "arg3";
    char* arg2 = "arg4";
    char* arg3 = "arg5";
    char* arg4 = "arg6";
    intptr_t args[5];

    args[0] = (intptr_t)arg0;
    args[1] = (intptr_t)arg1;
    args[2] = (intptr_t)arg2;
    args[3] = (intptr_t)arg3;
    args[4] = (intptr_t)arg4;
    EXPECT_EQ(sprintf(str1, string9, arg0, arg1, arg2, arg3, arg4), fstring(str2, 2048, string9, args, 5));
    EXPECT_STREQ(str1, str2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
