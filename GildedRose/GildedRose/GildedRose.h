#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ITEM
{
    const string NONAME = "noname";
    const string SULFURAS = "Sulfuras, Hand of Ragnaros";
    const string BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
    const string AGED_BRIE = "Aged Brie";
}

class Item
{
public:
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
    {}

    string name;
    int sellIn;
    int quality;

    void updateForAgedBrie();
    void updateForBackstagePass();
    void DecreaseSellIn();
    void UpdateForNoname();
    bool HasQuality();

    void print_item()
    {
        std::cout << name << ", " << sellIn << ", " << quality << std::endl;
    }

private:
};




class GildedRose
{
public:
    GildedRose(vector<Item>& items);
    void updateQuality();

    vector<Item>& items;

private:
};
#pragma once
