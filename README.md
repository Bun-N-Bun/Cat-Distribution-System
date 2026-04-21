# Cat Distribution System: A Cat Gacha Simulator

<img width="1400" height="800" alt="background" src="https://github.com/user-attachments/assets/e2603bd0-c12a-4063-9747-b4d19f32bcb5" />

## Overview
Cat Distribution System is a gacha simulator game designed for cat lovers and gacha enthusiasts. Inspired by popular gacha games like Genshin Impact and Honkai Star Rail, this project allows players to experience the thrill of gacha mechanics without spending any in-game currency. The game features a variety of cats from popular culture, categorized into different rarities (Common, S, SS, SSS), and incorporates gacha mechanics such as the pity system and guarantee system.

---
## Features

<img width="1187" height="668" alt="image" src="https://github.com/user-attachments/assets/fd07761d-f867-48d7-b53e-347ed5e10301" />

- Gacha Mechanics: Players can perform single or ten pulls to collect cats of varying rarities.
- Rarity System: Cats are categorized into four rarities:
- Common: Low rarity, frequently pulled.
  - S: Slightly rare.
  - SS: Rare.
  - SSS: Extremely rare.
- Pity System: Increases the chances of pulling a rare cat after a certain number of unsuccessful pulls.
- Guarantee System: Ensures players receive a rare cat after a defined number of pulls.
- Cat Collection: Displays all the cats pulled by the player.
- Free-to-Play: No in-game currency is required; players can pull as much as they want.

---
## Objectives

<img width="1196" height="676" alt="image" src="https://github.com/user-attachments/assets/b2132c31-40eb-4ccd-b125-51d22f225933" />

1. To create a gacha game that simulates the mechanics of popular gacha games without requiring in-game currency.
2. To provide a fun and engaging experience for cat lovers by featuring cats from popular culture as collectible characters.
3. To implement gacha systems such as the pity system and guarantee system to replicate the thrill of pulling rare characters.

---
## Scope and Limitations
### Scope
- Implementation of gacha mechanics (pity system, guarantee system).
- A pool of cats with varying rarities (Common, S, SS, SSS).
- A cat collection screen to display pulled cats.
- No limit on the number of pulls; players can pull freely.

### Limitations
- No featured character banners or rate-ups.
- No pull history; players can only view their collection in the cat collection screen.
- Limited interactivity beyond pulling and viewing collected cats.

---
## How to Use
### Prerequisites
1. Install Raylib:  
Raylib is required to compile and run the project. Follow the official installation guide for your operating system:
    - [Raylib Installation Guide](https://github.com/raylib-extras/raylib-quickstart)
2. Install a C++ Compiler:
    - Ensure you have a C++ compiler installed:
      - Windows: Install MinGW or use MSYS2.
      - Linux: Use g++ (usually pre-installed or available via sudo apt install g++).
      - macOS: Install Xcode Command Line Tools (xcode-select --install).
3. Clone the Repository:
    - Clone or download the project files from the repository:
      ```  
      git clone https://github.com/your-repo/cat-distribution-system.git
      cd cat-distribution-system`
      ```
4. Compile the Code:
    - Use the following command to compile the project with Raylib:  
    ```
    g++ main.cpp gacha.cpp music.cpp screen.cpp text.cpp -o cat_gacha -lraylib -lopengl32 -lgdi32 -lwinmm
    Replace -lopengl32 -lgdi32 -lwinmm with the appropriate libraries for your OS (e.g., -lGL -lm -lpthread -ldl on Linux).
    ```
5. Run the Executable:
    - After compiling, run the generated executable:
    ```
    ./cat_gacha
    ```

### Running on an IDE
If you prefer using an IDE like Visual Studio Code
1. Set Up the IDE:
    - Configure your IDE to use Raylib. Follow the official Raylib setup guide for your IDE:
      - [Raylib IDE Setup](https://github.com/raylib-extras/raylib-quickstart)
2. Load the Project:
    - Open the project folder in your IDE.
    - Ensure the Raylib library is linked correctly in your IDE's build settings.
3. Build and Run:
    - Use the IDE's build and run functionality to compile and execute the project.

---
## Gameplay:

<img width="1350" height="766" alt="image" src="https://github.com/user-attachments/assets/b4820e0a-6b00-4e09-9a60-e6934a569bce" />

- Follow the on-screen instructions to perform single or ten pulls.
- View your pulled cats in the cat collection screen.
- Enjoy the thrill of pulling rare cats without any cost!

---
## Acknowledgment
This project is submitted in partial fulfillment of the requirements for CS121 Computer Programming 2 at the University of Science and Technology of Southern Philippines, June 2023.

## Developers
- Krystal Heart M. Bacalso
- Javier M. Raut
