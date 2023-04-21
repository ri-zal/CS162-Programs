#include <iostream>
#include <vector>
using namespace std;

// Loot struct
// contains 2 member variables: the name of the loot and its rarity
struct Loot {
    string name;
    string rarity;
};

// Monster struct
// contains 4 member variables describing the monster
// and a vector that contains what each monster drops from Loot struct
struct Monster {
    string name;
    int health;
    int defense;
    int damage;
    vector<Loot> drops;
};

int main() {

    // vector of monsters from Monster struct that
    // contains 3 monsters with each of their own properties
    vector<Monster> monsters = {
            {"Dragon of Time", 500, 20, 50,
              {{"Diamond", "Super Rare"},
              {"Legendary Sword", "Super Rare"}}},
            {"Skeleton", 30, 0, 20,
              {{"Gold", "Rare"},
              {"Magic Sword", "Rare"}}},
            {"Zombie", 50, 0, 10,
              {{"Iron", "Common"},
              {"Average Sword", "Common"}}}
    };

    cout << "Overview: \n";

    // output each monster's description and what they drop using range-based for loop,
    // iterates through monsters vector using the monster reference variable of type Monster
    // avoided auto just for clarity
    for (Monster& monster : monsters) {
        cout << "\tMonster: " << monster.name << "\n";
        cout << "\t\tHealth: " << monster.health << "\n"
             << "\t\tDefense: " << monster.defense << "\n"
             << "\t\tDamage: " << monster.damage << "\n";
        cout << "\t\tLoot dropped: " << monster.drops[0].name
             << " (" << monster.drops[0].rarity << "), "
             << monster.drops[1].name << " (" << monster.drops[1].rarity
             << ")\n\n";
    }

    return 0;
}
