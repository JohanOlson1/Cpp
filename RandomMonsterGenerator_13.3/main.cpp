#include <iostream>
#include <string> // std:.string
#include <string_view> //std::string_view
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <array> // std::array


class Monster
{
public:
	enum class Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,

		max_monster_types
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int			m_hitPoints{};

public:
	Monster(Type type, std::string name, std::string roar, int hitPoints) : 
		m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
	{}

	// Use string_view to avoid extra run time cost
	std::string_view getTypeString() const
	{
		switch (m_type)
		{
		case Type::dragon:	return "dragon";
		case Type::goblin:	return "goblin";
		case Type::ogre:	return "ogre";
		case Type::orc:		return "orc";
		case Type::skeleton:return "skeleton";
		case Type::troll:	return "troll";
		case Type::vampire:	return "vampire";
		case Type::zombie:	return "zombie";
		}
	}

	// const to avoid function manipulating data
	void print() const
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
	}
};

class MonsterGenerator
{
private:
	static Monster::Type	m_type;
	static std::string		m_name;
	static std::string		m_roar;
	static int				m_hitPoints;

public:
	// Generate a random number between min and max (inclusive)
	// Assumes std::srand() has already been called
	// Assumes max - min <= RAND_MAX
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}
		
	static Monster generateMonster()
	{
		Monster::Type randomType{ getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1) }; // Random monster type

		int randomHitPoints{ getRandomNumber(0, 100) }; // Random hit points 0-100

		static const std::array<std::string, 6> s_names{ "bert", "nils", "bones" ,"jesper", "tobias", "ludvig" }; 
		// Possible names, const for compile eval, initalized once (static)

		static const std::array<std::string, 6> s_roars{ "*hoho*", "*boo*", "*yada*" ,"*buuu*", "*yihaa*", "*delicious!*" }; 
		// Possible roars!, const for compile eval, initalized once

		std::string randomName{ s_names[ getRandomNumber( 0, std::size(s_names) - 1 ) ] }; // Random name

		std::string randomRoar{ s_roars[ getRandomNumber( 0, std::size(s_names) - 1 ) ] }; // Random roar

		return Monster(randomType , randomName, randomRoar, randomHitPoints);
	}
};

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock 
	std::rand(); // If using Visual Studio, discard first random value

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}