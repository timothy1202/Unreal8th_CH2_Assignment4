#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

#include"PotionRecipe.h"

class RecipeManager
{
private:
	std::vector<PotionRecipe> recipes;

public:
	PotionRecipe* AddRecipe(const std::string& name, const std::unordered_set<std::string>& ingredients) // 파라미터 타입 수정
	{
		if (findRecipeByName(name) != nullptr)
		{
			return nullptr;
		}

		recipes.emplace_back(name, ingredients);
		return &recipes.back();
	}

	std::vector<PotionRecipe> findRecipesByIngredient(const std::string& ingredient)
	{
		std::vector<PotionRecipe> founded_recipes;
		for (const PotionRecipe& recipe : recipes)
		{
			// unordered_set의 count 함수 활용
			if (recipe.ingredients.count(ingredient) > 0)
			{
				founded_recipes.push_back(recipe);
			}
		}
		return founded_recipes;
	}

	const PotionRecipe* findRecipeByName(const std::string& name)
	{
		for (PotionRecipe& find_name : recipes)
		{
			if (find_name.potionName == name)
				return &find_name;
		}

		return nullptr;
	}


	const std::vector<PotionRecipe>& getAllRecipes() const
	{
		return recipes;
	}
};