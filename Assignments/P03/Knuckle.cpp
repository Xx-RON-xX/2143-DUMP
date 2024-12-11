// knucklebones_game.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>

// --- Dice Class ---
class Dice {
public:
    Dice() { srand(time(0)); }
    int roll() { return rand() % 6 + 1; } // Roll a six-sided die
};

// --- Grid Class ---
class Grid {
public:
    Grid() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cells[i][j] = 0; // Initialize grid with zeros
            }
        }
    }

    bool place_dice(int col, int value) {
        for (int row = 2; row >= 0; --row) {
            if (cells[row][col] == 0) {
                cells[row][col] = value;
                return true;
            }
        }
        return false; // Column is full
    }

    int get_cell_value(int row, int col) const {
        return cells[row][col];
    }

    void print_grid() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << cells[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int cells[3][3];
};

// --- Player Class ---
class Player {
public:
    Player(std::string player_name) : name(player_name), score(0) {}

    void take_turn(Grid& grid, Dice& dice) {
        int roll = dice.roll();
        std::cout << name << " rolled a " << roll << "!" << std::endl;
        
        int col;
        std::cout << "Select a column (0, 1, or 2) to place the dice: ";
        std::cin >> col;

        while (col < 0 || col > 2 || !grid.place_dice(col, roll)) {
            std::cout << "Invalid column. Choose another (0, 1, or 2): ";
            std::cin >> col;
        }
    }

    void add_to_score(int points) {
        score += points;
    }

    std::string get_name() const { return name; }
    int get_score() const { return score; }

private:
    std::string name;
    int score;
};

// --- Animation Class ---
class Animation {
public:
    Animation(int frameDelayMs = 50) : frameDelay(frameDelayMs), frameIndex(0), isPlaying(false) {}

    void loadFramesFromGif(const std::string& gifFilename, int totalFrames) {
        frames.clear();
        for (int i = 1; i <= totalFrames; ++i) {
            sf::Texture texture;
            std::string filename = "frame" + std::to_string(i) + ".png"; // Extract frames from the gif as PNGs
            if (!texture.loadFromFile(filename)) {
                std::cerr << "Error loading " << filename << std::endl;
                continue;
            }
            frames.push_back(texture);
        }
    }

    void loadDiceFaces(const std::vector<std::string>& faceFilenames) {
        diceFaces.clear();
        for (const auto& filename : faceFilenames) {
            sf::Texture texture;
            if (!texture.loadFromFile(filename)) {
                std::cerr << "Error loading " << filename << std::endl;
                continue;
            }
            diceFaces.push_back(texture);
        }
    }

    void play() {
        isPlaying = true;
        frameIndex = 0;
        clock.restart();
    }

    void update(sf::Sprite& sprite) {
        if (!isPlaying) return;

        if (clock.getElapsedTime().asMilliseconds() > frameDelay) {
            frameIndex++;
            if (frameIndex < frames.size()) {
                sprite.setTexture(frames[frameIndex]);
                clock.restart();
            } else {
                std::mt19937 rng(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
                std::uniform_int_distribution<int> dist(0, diceFaces.size() - 1);
                int finalDiceFace = dist(rng);
                sprite.setTexture(diceFaces[finalDiceFace]);
                isPlaying = false;
            }
        }
    }

    bool isAnimationPlaying() const { return isPlaying; }

private:
    std::vector<sf::Texture> frames;
    std::vector<sf::Texture> diceFaces;
    int frameIndex;
    int frameDelay;
    bool isPlaying;
    sf::Clock clock;
};

// --- Main Function ---
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dice Roll Animation");
    
    Animation diceAnimation(50);
    diceAnimation.loadFramesFromGif("dice_roll.gif", 24);
    diceAnimation.loadDiceFaces({"1.png", "2.png", "3.png", "4.png", "5.png", "6.png"});
    
    sf::Sprite sprite;
    sprite.setPosition(100, 100);

    diceAnimation.play();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        diceAnimation.update(sprite);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
