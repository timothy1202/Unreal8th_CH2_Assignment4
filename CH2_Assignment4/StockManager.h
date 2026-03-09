#pragma once
#include<map>
#include<iostream>
#include<vector>
#include<string>


class StockManager
{
private:
	std::map<std::string, int> potionStock;
	const int MAX_STOCK = 3;

public:
	void initializeStock(const std::string& potionName)
	{
		potionStock[potionName] = 3;
	}

	bool dispensePotion(const std::string& potionName)
	{
		if (potionStock[potionName] > 0)
		{
			potionStock[potionName]--;
			return true;
		}
		else return false;
	}

	void returnPotion(const std::string& potionName)
	{
		if (potionStock[potionName] > 3)
			return;
		else
			potionStock[potionName]++;
	}

	int getStock(const std::string& potionName)
	{
		if (potionStock[potionName] > 0)
			return potionStock[potionName];
		else return 0;
	}


};