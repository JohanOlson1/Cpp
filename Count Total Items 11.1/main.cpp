#include <iostream>
#include <array>
#include <numeric> // std::reduce
#include <typeinfo>


enum ItemTypes
{
	item_health_potion,
	item_torche,
	item_arrow,
	max_items
};

void countTotalItems(const std::array<int, ItemTypes::max_items>& items)
{
	std::cout << "The player has " << std::reduce(items.begin(), items.end()) << " items" << '\n';
}

int main()
{

	std::array<int, ItemTypes::max_items> items{ 2, 5, 10};

	countTotalItems(items);

	std::cout << typeid(items).name();

	return 0;
}