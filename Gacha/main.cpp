#include <iostream>
#include <string>
#include "raylib.h"
#include "gacha.h"
#include "music.h"
#include "screen.h"
#include "text.h"


int main() {
    const int SCREEN_WIDTH = 1400;
    const int SCREEN_HEIGHT = 800;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cat Distribution System");  //Game Window Name
    SetTargetFPS(60);  //Set FPS to 60
    InitAudioDevice();

    Screen currentScreen = SCREEN_MENU;
    Screen previousScreen = SCREEN_HELP;

    //Loading Sound
    Sound starting = LoadSound("resources/music/starting.ogg");
    Sound pageflip = LoadSound("resources/music/page_flip.wav");
    Sound SFXpull = LoadSound("resources/music/pull_sfx.mp3");
    Sound peebles = LoadSound("resources/music/mr_peebles.wav");
    Sound hapi_sfx = LoadSound("resources/music/hapi_cat.mp3");
    Music bgm1 = LoadMusicStream("resources/music/bgm4.mp3");
    Music bgm2 = LoadMusicStream("resources/music/bgm2.mp3");

    PlayMusicStream(bgm1);
    PlayMusicStream(bgm2);
    SetSoundVolume(starting, 0.3f);
    SetSoundVolume(SFXpull, 2.0f);
    SetSoundVolume(hapi_sfx, 0.3f);
    SetSoundVolume(peebles, 0.3f);
    SetMusicVolume(bgm1, 0.3f);
    SetMusicVolume(bgm2, 0.3f);


    // Bacakground Textures
    Texture2D BG_MENU = LoadTexture("resources/background.png");
    Texture2D BG_GAME = LoadTexture("resources/gacha_bg.png");
    Texture2D BG_HELP = LoadTexture("resources/help_screen.png");
    Texture2D BG_COLLECTION1 = LoadTexture("resources/cat_collection5.png");
    Texture2D BG_COLLECTION2 = LoadTexture("resources/cat_collection3.png");
    Texture2D BG_COLLECTION3 = LoadTexture("resources/cat_collection1.png");

    Texture2D box1 = LoadTexture("resources/resized_box1.png");
    Texture2D box2 = LoadTexture("resources/resized_box5.png");


    // Cat Gacha Textures
    const int CommonTexturesCount = 5;
    Texture2D CommonTextures[CommonTexturesCount];
    CommonTextures[0] = LoadTexture("resources/sprites/ugly_cat.png");
    CommonTextures[1] = LoadTexture("resources/sprites/blink_mf.png");
    CommonTextures[2] = LoadTexture("resources/sprites/mr_peebles.png");
    CommonTextures[3] = LoadTexture("resources/sprites/serious_cat.png");
    CommonTextures[4] = LoadTexture("resources/sprites/gigacat.png");

    Texture2D S_Textures[CommonTexturesCount];
    S_Textures[0] = LoadTexture("resources/sprites/long_cat.png");
    S_Textures[1] = LoadTexture("resources/sprites/el_gato.png");
    S_Textures[2] = LoadTexture("resources/sprites/smudge.png");
    S_Textures[3] = LoadTexture("resources/sprites/bingus.png");
    S_Textures[4] = LoadTexture("resources/sprites/banana.png");

    const int SS_TexturesCount = 3;
    Texture2D SS_Textures[SS_TexturesCount];
    SS_Textures[0] = LoadTexture("resources/sprites/dancing_cat.png");
    SS_Textures[1] = LoadTexture("resources/sprites/popcat.png");
    SS_Textures[2] = LoadTexture("resources/sprites/maxwell.png");

    const int SSS_TexturesCount = 1;
    Texture2D SSS_Textures[SSS_TexturesCount];
    SSS_Textures[0] = LoadTexture("resources/sprites/happy_cat.png");


    // Collection Textures
    Texture2D _ugly_cat = LoadTexture("resources/Collection/ugly_cat.png");
    Texture2D _blink_mf = LoadTexture("resources/Collection/blink_mf.png");
    Texture2D _mr_peebles = LoadTexture("resources/Collection/mr_peebles.png");
    Texture2D _serious_cat = LoadTexture("resources/Collection/serious_cat.png");
    Texture2D _gigacat = LoadTexture("resources/Collection/gigacat.png");

    Texture2D _long_cat = LoadTexture("resources/Collection/long_cat.png");
    Texture2D _el_gato = LoadTexture("resources/Collection/elgato.png");
    Texture2D _smudge = LoadTexture("resources/Collection/smudge.png");
    Texture2D _bingus = LoadTexture("resources/Collection/bingus.png");
    Texture2D _banana = LoadTexture("resources/Collection/banana_cat.png");

    Texture2D _dancing_cat = LoadTexture("resources/Collection/dancing_cat.png");
    Texture2D _popcat = LoadTexture("resources/Collection/popcat.png");
    Texture2D _maxwell = LoadTexture("resources/Collection/maxwell.png");

    Texture2D _happy_cat = LoadTexture("resources/Collection/happy_cat.png");


    // Main sprite texture
    Texture sprite = S_Textures[0];

    // Rectangle Array for animation frames
    Rectangle frames[6] = {
        { 0, 0, 400, 400 },
        { 400, 0, 400, 400 },
        { 800, 0, 400, 400 },
        { 1200, 0, 400, 400 },
        { 1600, 0, 400, 400 },
        { 2000, 0, 400, 400 }
    };

    //Frames variables
    float frameTime = 0.1f;
    int currentFrame = 0;
    float timer = 0.0f;

    double Common_chance = 0, S_chance = 0, SS_chance = 0, SSS_chance = 0;

    int randomIndex;
    int pull_counter = 0, S_counter = 0;   // counters
    bool common_rarity = false, S_rarity = false, SS_rarity = false, SSS_rarity = false;
    bool indexToggle = true;

    float text_timer = 0;  // frame timer
    bool showText = true;
    bool muted = false;
    bool bgm_changer = false;
    bool checker = true;  // Condition Checker

    bool ugly_cat = false, blink_mf = false, mr_peebles = false, serious_cat = false, gigacat = false, // Cat Collection switch
        long_cat = false, el_gato = false, smudge = false, bingus = false, banana = false,
        dancing_cat = false, popcat = false, maxwell = false, happy_cat = false;  

    bool tenPulls = false;
    bool peebles_switch = true;

    bool prompt_common = false, prompt_S = false, prompt_SS = false, prompt_SSS = false;

    int space_counter = 0;

    // Start of Game
    while (!WindowShouldClose()) {
        WindowDisplay(currentScreen, previousScreen, starting, pageflip, indexToggle, pull_counter, checker, space_counter);
        PlayMusic(bgm1, bgm2, muted, bgm_changer);

        BeginDrawing();
        
        // Main Menu
        if (currentScreen == SCREEN_MENU) {
            DrawTexture(BG_MENU, 0, 0, WHITE);
            Text(text_timer, showText, currentScreen, SCREEN_WIDTH, SCREEN_HEIGHT);
        }

        // Help Screen
        else if (currentScreen == SCREEN_HELP) {
            DrawTexture(BG_HELP, 0, 0, WHITE);
            Text(text_timer, showText, currentScreen, SCREEN_WIDTH, SCREEN_HEIGHT);
        }

        // Main Game Screen
        else if (currentScreen == SCREEN_GAME) {
            bgm_changer = true;

            DrawTexture(BG_GAME, 0, 0, WHITE);
            DrawTexture(box1, (SCREEN_WIDTH / 2 - (box1.width / 2)), SCREEN_HEIGHT / 2 - 20, WHITE);
            TextCounter(pull_counter, SCREEN_WIDTH);

            // Gacha System & Text Prompt based on rarity toggle
            PullChance(pull_counter, Common_chance, S_chance, SS_chance, SSS_chance);
            TextRarityToggle(prompt_common, prompt_S, prompt_SS, prompt_SSS);

            if (IsKeyPressed(KEY_TWO)) {
                tenPulls = true;
                currentScreen = SCREEN_PULL;
            }
        }

        // 10 pulls Screen
        else if (tenPulls) {
            for (int i = 0; i < 10; i++) {
                PullChance(pull_counter, Common_chance, S_chance, SS_chance, SSS_chance);
                TextCounter(pull_counter, SCREEN_WIDTH);
                AnimationTimer(timer, frameTime, currentFrame);

                indexToggle = true;
                checker = true;
                currentScreen = SCREEN_PULL;

                // Gacha System
                // Note: checker bool is present to avoid random number to continue 
                // generating and stop repeating actions
                if (checker) {
                    PullToggle(SSS_chance, SS_chance, S_chance, S_counter, SSS_rarity, SS_rarity, S_rarity, common_rarity);
                    checker = false;
                }

                // Rarity switch
                if (common_rarity) {
                    HandleRarity(indexToggle, common_rarity, randomIndex, prompt_common, sprite, CommonTexturesCount, pull_counter,
                        CommonTextures, ugly_cat, blink_mf, mr_peebles, serious_cat, gigacat);
                }
                else if (S_rarity) {
                    HandleRarity(indexToggle, S_rarity, randomIndex, prompt_S, sprite, CommonTexturesCount, pull_counter,
                        S_Textures, long_cat, el_gato, smudge, bingus, banana);
                }
                else if (SS_rarity) {
                    HandleRarity(indexToggle, SS_rarity, randomIndex, prompt_SS, sprite, SS_TexturesCount, pull_counter,
                        SS_Textures, dancing_cat, popcat, maxwell, maxwell, maxwell);
                    pull_counter = 0;
                }
                else if (SSS_rarity) {
                    HandleRarity(indexToggle, SSS_rarity, randomIndex, prompt_SSS, sprite, SSS_TexturesCount, pull_counter,
                        SSS_Textures, dancing_cat, popcat, maxwell, maxwell, maxwell);
                    happy_cat = true;
                }

                // Draw the pull animation
                DrawTexture(BG_GAME, 0, 0, WHITE);
                PlaySound(SFXpull);


                while (IsSoundPlaying(SFXpull)) {  //Allows animation to play for each sprite for each sound
                    AnimationTimer(timer, frameTime, currentFrame);

                    BeginDrawing();
                    ClearBackground(RAYWHITE);

                    // Draw the pull animation
                    Animation(BG_GAME, box2, sprite, SCREEN_WIDTH, SCREEN_HEIGHT, frames, currentFrame);
                    TextCounter(pull_counter, SCREEN_WIDTH);
                    RarityText(SCREEN_WIDTH, SCREEN_HEIGHT, currentScreen,
                        prompt_common, prompt_S, prompt_SS, prompt_SSS);

                    // Update the display
                    WindowDisplay(currentScreen, previousScreen, starting, pageflip, indexToggle, pull_counter, checker, space_counter);
                    PlayMusic(bgm1, bgm2, muted, bgm_changer);
                    EndDrawing();

                }

                // Mr Peebles switch
                MR_PEEBLES(mr_peebles, peebles_switch, peebles, BG_GAME,
                    box2, sprite, SCREEN_WIDTH, SCREEN_HEIGHT, frames, currentFrame);
                TextRarityToggle(prompt_common, prompt_S, prompt_SS, prompt_SSS);
            }

            tenPulls = false;
        }

        // Pull Screen
        else if (currentScreen == SCREEN_PULL) {
            AnimationTimer(timer, frameTime, currentFrame);
            
            // Gacha System
            // Note: checker bool is present to avoid random number to continue 
            // generating and stop repeating actions
            if (checker) {
                PullToggle(SSS_chance, SS_chance, S_chance, S_counter,
                    SSS_rarity, SS_rarity, S_rarity, common_rarity);

                if (SSS_rarity) {
                    PlaySound(hapi_sfx);
                } 
                else {
                    PlaySound(SFXpull);
                }

                checker = false;
            }

            // Rarity switch
            if (common_rarity) {
                HandleRarity(indexToggle, common_rarity, randomIndex, prompt_common, sprite, CommonTexturesCount, pull_counter,
                    CommonTextures, ugly_cat, blink_mf, mr_peebles, serious_cat, gigacat);
            }
            else if (S_rarity) {
                HandleRarity(indexToggle, S_rarity, randomIndex, prompt_S, sprite, CommonTexturesCount, pull_counter,
                    S_Textures, long_cat, el_gato, smudge, bingus, banana);
            }
            else if (SS_rarity) {
                HandleRarity(indexToggle, SS_rarity, randomIndex, prompt_SS, sprite, SS_TexturesCount, pull_counter,
                    SS_Textures, dancing_cat, popcat, maxwell, maxwell, maxwell);
                pull_counter = 0;
            }
            else if (SSS_rarity) {
                HandleRarity(indexToggle, SSS_rarity, randomIndex, prompt_SSS, sprite, SSS_TexturesCount, pull_counter,
                    SSS_Textures, dancing_cat, popcat, maxwell, maxwell, maxwell);
                happy_cat = true;
            }

            // Draw the pull animation
            Animation(BG_GAME, box2, sprite, SCREEN_WIDTH, SCREEN_HEIGHT, frames, currentFrame);
            TextCounter(pull_counter, SCREEN_WIDTH);
            RarityText(SCREEN_WIDTH, SCREEN_HEIGHT, currentScreen,
                prompt_common, prompt_S, prompt_SS, prompt_SSS);
            
            // Mr Peebles switch
            MR_PEEBLES(mr_peebles, peebles_switch, peebles, BG_GAME,
                box2, sprite, SCREEN_WIDTH, SCREEN_HEIGHT, frames, currentFrame);
        }


        // Cat Collection Screen
        else if (currentScreen == SCREEN_CATCOLLECTION1) {
            DrawTexture(BG_COLLECTION1, 0, 0, WHITE);
            Collection(SCREEN_WIDTH, SCREEN_HEIGHT, ugly_cat, blink_mf, mr_peebles, serious_cat, gigacat,
                _ugly_cat, _blink_mf, _mr_peebles, _serious_cat, _gigacat);

        }
        else if (currentScreen == SCREEN_CATCOLLECTION2) {
            DrawTexture(BG_COLLECTION1, 0, 0, WHITE);
            Collection(SCREEN_WIDTH, SCREEN_HEIGHT, long_cat, el_gato, smudge, bingus, banana,
                _long_cat, _el_gato, _smudge, _bingus, _banana);
        }
        else if (currentScreen == SCREEN_CATCOLLECTION3) {
            DrawTexture(BG_COLLECTION2, 0, 0, WHITE);
            Collection2(SCREEN_WIDTH, SCREEN_HEIGHT, dancing_cat, popcat, maxwell,
                _dancing_cat, _popcat, _maxwell);
        }
        else if (currentScreen == SCREEN_CATCOLLECTION4) {
            DrawTexture(BG_COLLECTION3, 0, 0, WHITE);
            if (happy_cat) {
                DrawTexture(_happy_cat, (SCREEN_WIDTH / 2 - 210), SCREEN_HEIGHT / 2 - 280, WHITE);
            }
        }

        EndDrawing();

    }

    CloseWindow();

    // Unloading Textures

    for (int i = 0; i < CommonTexturesCount; i++) {
        UnloadTexture(CommonTextures[i]);
        UnloadTexture(S_Textures[i]);
    }
    for (int i = 0; i < SS_TexturesCount; i++) {
        UnloadTexture(SS_Textures[i]);
    }

    UnloadTexture(SSS_Textures[0]);
    UnloadTexture(BG_MENU);
    UnloadTexture(BG_GAME);
    UnloadTexture(BG_HELP);
    UnloadTexture(BG_COLLECTION1);
    UnloadTexture(BG_COLLECTION2);
    UnloadTexture(BG_COLLECTION3);
    UnloadTexture(box1);
    UnloadTexture(box2);
    UnloadTexture(_ugly_cat);
    UnloadTexture(_blink_mf);
    UnloadTexture(_mr_peebles);
    UnloadTexture(_serious_cat);
    UnloadTexture(_gigacat);
    UnloadTexture(_long_cat);
    UnloadTexture(_el_gato);
    UnloadTexture(_smudge);
    UnloadTexture(_bingus);
    UnloadTexture(_banana);
    UnloadTexture(_dancing_cat);
    UnloadTexture(_popcat);
    UnloadTexture(_maxwell);
    UnloadTexture(_happy_cat);

    return 0;
}
