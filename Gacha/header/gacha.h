#include "raylib.h"
#include "collection.h"

#ifndef GACHA_H
#define GACHA_H

void pullChance(int& pull, double& Common_chance, double& S_chance, double& SS_chance, double& SSS_chance) {

    if (pull <= 74) {
        Common_chance = 894;
        S_chance = 94;
        SS_chance = 6;
        SSS_chance = 1;

    }
    else if (pull >= 75 && pull <= 89) {  //probability to get a 5-star increases
        Common_chance = 575;
        SS_chance = 330;

    }
    else {
        Common_chance = 0;
        S_chance = 0;
        SS_chance = 1000;
        SSS_chance = 0;
    }
}

void PullToggle(double& SSS_chance, double& SS_chance, double& S_chance, int& S_counter,
    bool& SSS_rarity, bool& SS_rarity, bool& S_rarity, bool& common_rarity) {
    int random_num = GetRandomValue(1, 1000);
    std::cout << "Random number: " << random_num << std::endl;

    if (random_num <= SSS_chance) {
        S_counter++;
        SSS_rarity = true;
    }
    else if (random_num <= S_chance) {
        S_counter = 0;
        S_rarity = true;
    }
    else if (random_num <= SS_chance) {
        S_counter++;
        SS_rarity = true;
    }
    else {
        S_counter++;
        if (S_counter == 10) {  // 4-star guarantee system
            S_rarity = true;
            S_counter = 0;
        }
        else {
            common_rarity = true;
        }
    }
}

void HandleRarity(bool& indexToggle, bool& rarityFlag, int& randomIndex,
    Texture& sprite, int TextureCount, int& pull,
    Texture2D Textures[], bool& cat1, bool& cat2,
    bool& cat3, bool& cat4, bool& cat5){
    if (rarityFlag && indexToggle) {
        pull++;
        std::cout << "Pulls: " << pull << std::endl;

        randomIndex = GetRandomValue(0, TextureCount - 1);
        sprite = Textures[randomIndex];
        CatCollection(randomIndex, cat1, cat2, cat3, cat4, cat5);
        indexToggle = false;
        rarityFlag = false;
    }
}

#endif GACHA_H

