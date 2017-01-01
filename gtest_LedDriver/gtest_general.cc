//
//  gtest_general.cc
//  myTDDC2
//
//  Created by Hodohara Norifumi on 2017/01/01.
//  Copyright (c) 2017年 Hodohara Norifumi. All rights reserved.
//

#include "gtest/gtest.h"

#include "type.h"

TEST(GeneralTest, サイズ調査)
{
    EXPECT_EQ(1, sizeof(int8_t));
    EXPECT_EQ(2, sizeof(int16_t));
    EXPECT_EQ(4, sizeof(int32_t));
    EXPECT_EQ(8, sizeof(int64_t));
    EXPECT_EQ(1, sizeof(uint8_t));
    EXPECT_EQ(2, sizeof(uint16_t));
    EXPECT_EQ(4, sizeof(uint32_t));
    EXPECT_EQ(8, sizeof(uint64_t));
}