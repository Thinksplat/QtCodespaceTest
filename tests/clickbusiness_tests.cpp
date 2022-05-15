#include <gtest/gtest.h>
#include <algorithm>
#include "clickbusiness.h"

// Demonstrate some basic assertions.
TEST(ClickBusiness, BasicInstaination) {
    ClickBusiness clicker(10);
    IClickMsg &c = clicker; // Make sure it is of the right type
    (void)c;
}

TEST(ClickBusiness, MessageStartsEmpty) {
    ClickBusiness clicker(10);
    ASSERT_EQ(clicker.Str(),"");
}

TEST(ClickBusiness, OneClickChangesMessage) {
    ClickBusiness clicker(10);
    auto oldstr = clicker.Str();
    clicker.Click();
    auto newstr = clicker.Str();
    ASSERT_NE(oldstr,newstr);
}

TEST(ClickBusiness, TwoClicksHaveTwoLinesInTheMessage) {
    ClickBusiness clicker(10);
    clicker.Click();
    clicker.Click();
    auto msg = clicker.Str();
    auto newlinecount = std::count(msg.begin(), msg.end(), '\n');
    ASSERT_EQ(newlinecount,2);
}

TEST(ClickBusiness, MessageOverflowProducesOneLineAfterLast) {
    ClickBusiness clicker(5);
    clicker.Click();
    clicker.Click();
    clicker.Click();
    clicker.Click();
    clicker.Click();
    auto msg = clicker.Str();
    auto newlinecount = std::count(msg.begin(), msg.end(), '\n');
    ASSERT_EQ(newlinecount,5);

    clicker.Click();
    msg = clicker.Str();
    newlinecount = std::count(msg.begin(), msg.end(), '\n');
    ASSERT_EQ(newlinecount,1);
}

static std::vector<std::string> splitString(const std::string& str)
{
    std::vector<std::string> tokens;
 
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, '\n')) {
        tokens.push_back(token);
    }
 
    return tokens;
}

TEST(ClickBusiness, LastMessageBeforeOverflowYellsAtMe) {
    const std::string angrymessage = "STOP PUSHING THE BUTTON";
    ClickBusiness clicker(5, angrymessage);
    clicker.Click();
    clicker.Click();
    clicker.Click();
    clicker.Click();
    clicker.Click();
    auto msg = clicker.Str();
    auto newlinecount = std::count(msg.begin(), msg.end(), '\n');
    ASSERT_EQ(newlinecount,5);

    // Split the string on newline
    auto lines = splitString(msg);
    ASSERT_EQ(lines.size(),5);

    // The last line needs to have an angry message
    auto lastline = lines.back();
    // lastline should contain the text angrymessage
    ASSERT_TRUE(lastline.find(angrymessage) != std::string::npos);
}