// LEDドライバのテスト
// ・ドライバを初期化したら全てのLEDがオフになる
// ・1つのLEDをオンできる
// ...etc


#include <iostream>
#include "LedDriver.c"
#include "gtest/gtest.h"

class LedDriverTest : public ::testing::Test{
protected:
    LedDriverTest(){
    }
    virtual ~LedDriverTest(){
    }
    virtual void SetUp(){
        LedDriver_Create(&virtualLeds);
    }
    virtual void TearDown(){
        
    }
    uint16_t virtualLeds = ALL_LEDS_ON;
};


TEST_F(LedDriverTest, LEDドライバ作成後は初期化される)
{
	uint16_t virtualLeds2 = ALL_LEDS_ON;

    LedDriver_Create(&virtualLeds2);
	ASSERT_EQ(ALL_LEDS_OFF, virtualLeds2);
}

TEST_F(LedDriverTest, LED点灯)
{
    LedDriver_TurnOn(1);
	ASSERT_EQ(1, virtualLeds);
}

TEST_F(LedDriverTest, LED点灯2つ)
{
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(9);
	ASSERT_EQ(0x180, virtualLeds);
}

TEST_F(LedDriverTest, 全LED点灯)
{
    LedDriver_TurnAllOn();
	ASSERT_EQ(0xffff, virtualLeds);
}

TEST_F(LedDriverTest, LED消灯)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
	ASSERT_EQ(0, virtualLeds);
}

TEST_F(LedDriverTest, LED消灯1つだけ)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
	ASSERT_EQ(0xff7f, virtualLeds);
}

TEST_F(LedDriverTest, 境界条件)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    ASSERT_EQ(0x8001, virtualLeds);
}

TEST_F(LedDriverTest, TurnOn範囲外入力は無視する)
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(10000);
    ASSERT_EQ(ALL_LEDS_OFF, virtualLeds);
}

TEST_F(LedDriverTest, TurnOff範囲外入力は無視する)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(17);
    LedDriver_TurnOff(10000);
    ASSERT_EQ(ALL_LEDS_ON, virtualLeds);
}

TEST_F(LedDriverTest, ONOFF状態取得)
{
    LedDriver_TurnOn(1);
    ASSERT_EQ(true, LedDriver_isON(1));
}

TEST_F(LedDriverTest, DISABLED_絶対失敗テスト)
{
    FAIL();
}

TEST_F(LedDriverTest, 絶対成功テスト)
{
    SUCCEED();
}

