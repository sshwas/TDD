#include "pch.h"
#include "../GildedRose/GildedRose.cpp"


TEST(GildedRoseTest, should_be_nothing_when_no_item)
{
	// given (arrange)
    vector<Item> items;
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(0, items.size());
}

TEST(GildedRoseTest, noname_sellin_0_quality_0)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::NONAME, 0, 0) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(0, items[0].quality);
}

TEST(GildedRoseTest, noname_sellin_0_quality_1)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::NONAME, 0, 1) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(0, items[0].quality);
}

TEST(GildedRoseTest, noname_sellin_0_quality_3)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::NONAME, 0, 3) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(1, items[0].quality);
}

TEST(GildedRoseTest, sulfuras_sellin_0_quality_80)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::SULFURAS, 0, 80) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(0, items[0].sellIn);
    EXPECT_EQ(80, items[0].quality);
}

TEST(GildedRoseTest, agedBrie_sellin_0_quality_0)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::AGED_BRIE, 0, 0) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(2, items[0].quality);
}

TEST(GildedRoseTest, backstage_pass_sellin_0_quality_0)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::BACKSTAGE_PASS, 0, 0) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(0, items[0].quality);
}

TEST(GildedRoseTest, backstage_pass_sellin_0_quality_49)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::BACKSTAGE_PASS, 0, 49) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(0, items[0].quality);
}

TEST(GildedRoseTest, backstage_pass_sellin_12_quality_0)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::BACKSTAGE_PASS, 12, 0) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(11, items[0].sellIn);
    EXPECT_EQ(1, items[0].quality);
}

TEST(GildedRoseTest, sulfuras_sellin_m2_quality_80)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::SULFURAS, -2, 80) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-2, items[0].sellIn);
    EXPECT_EQ(80, items[0].quality);
}

TEST(GildedRoseTest, agedBrie_sellin_0_quality_50)
{
    // given (arrange)
    vector<Item> items = { Item(ITEM::AGED_BRIE, 0, 50) };
    GildedRose app(items);

    // When (act)
    app.updateQuality();

    // then (assert)
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(50, items[0].quality);
}