#pragma once
#include <iostream>
#include <vector>
#include <string>
#include"PotionRecipe.h"


// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop 
{
private:
    std::vector<PotionRecipe> recipes;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::unordered_set<std::string>& ingredients) 
    {
        recipes.push_back(PotionRecipe(name, ingredients));

        std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
    }

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const
    {
        if (recipes.empty())
        {
            std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
            return;
        }

        std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;

        for (const auto& recipe : recipes)
        {
            std::cout << "- 물약 이름: " << recipe.potionName << std::endl;
            std::cout << "  > 필요 재료: ";

            // unordered_set은 인덱스가 없으므로 범위 기반 for 문을 사용합니다.
            bool first = true;
            for (const auto& ingredient : recipe.ingredients)
            {
                if (!first) std::cout << ", ";
                std::cout << ingredient;
                first = false;
            }
            std::cout << std::endl;
        }

        std::cout << "---------------------------\n";
    }

    PotionRecipe SearchRecipeByName(std::string potion)
    {
        for (int i = 0; i < recipes.size(); ++i)
        {
            if (potion == recipes[i].potionName)
            { return recipes[i];}
        }
        
        std::cout << potion << "이라는 포션은 존재하지 않습니다" << std::endl;
    }

    std::vector<PotionRecipe> searchRecipeByIngredient(std::string ingredient)
    {
        std::vector<PotionRecipe> foundRecipes;

        for (const auto& recipe : recipes)
        {
            if (recipe.ingredients.count(ingredient) > 0)
            {
                foundRecipes.push_back(recipe);
            }
        }

        return foundRecipes;
    }

};
