#include <iostream>
#include <string>		// std::string
#include <string_view>  // C++17

// Possible monster types
enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime,
};

// Struct holding the stats of a Monster
struct Monster
{
	MonsterType type {};
	std::string name {};
	int health {};
};

// Function using (more) efficient switch statement to return string (observe use of type string_view, which need C++17)
constexpr std::string_view getMonsterTypeString(MonsterType type)
{
	switch (type)
	{
	case MonsterType::ogre:				return "Ogre";
	case MonsterType::dragon:			return "Dragon";
	case MonsterType::orc:				return "Orc";
	case MonsterType::giant_spider:		return "Giant Spider";
	case MonsterType::slime:			return "Slime";
	}

	return "Unknown";
}

// Function input argument a reference to avoid copying, which could be expensive due to use of string name (non fundamental type) 
void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) << 
		" is named " << monster.name << " and has " << monster.health << " health.\n";
};

int main()
{
	// Two examples of monsters
	Monster ogre{ MonsterType::ogre, "Torg", 145};
	Monster slime{ MonsterType::slime, "Blurp", 23};

	printMonster(ogre);
	printMonster(slime);
}

