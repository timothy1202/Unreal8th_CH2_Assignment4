#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"PotionRecipe.h"

class RecipeManager
{
private:
	std::vector<PotionRecipe> recipes;

public:
	PotionRecipe* addRecipe(std::string name, std::vector<std::string> ingredients)
	{

	}

	PotionRecipe* findRecipeByName(std::string name)
	{

	}

	std::vector<PotionRecipe> findRecipesByIngredient(std::string ingredient)
	{

	}

	const std::vector<PotionRecipe>& getAllRecipes()
	{

	}
};