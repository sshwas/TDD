#include "GildedRose.h"

GildedRose::GildedRose(vector<Item>& items) : items(items)
{}

void Item::updateForAgedBrie()
{
	if (quality < 50)
	{
		quality = quality + (sellIn < 1 ? 2 : 1);
	}
}

void Item::updateForBackstagePass()
{
	if (quality < 50)
	{
		quality = quality + 1;

		if (sellIn < 11)
		{
			quality = quality + 1;
		}
		if (sellIn < 6)
		{
			quality = quality + 1;
		}
	}
	if (sellIn < 1)
	{
		quality = 0;
	}
}

void Item::DecreaseSellIn()
{
	sellIn = sellIn - 1;
}

void Item::UpdateForNoname()
{
	quality = quality - 1;
	if (sellIn < 1 && quality > 0)
	{
		quality = quality - 1;
	}
}

bool Item::HasQuality()
{
	return quality > 0;
}


void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
		auto& item = items[i];

		if (item.name == ITEM::SULFURAS)
			continue;

        if (item.name == ITEM::AGED_BRIE)
        {
			item.updateForAgedBrie();
        }
		else if (item.name == ITEM::BACKSTAGE_PASS)
		{
			item.updateForBackstagePass();
		}
        else if (item.HasQuality())
        {
			item.UpdateForNoname();
        }

		item.DecreaseSellIn();
    }
}
