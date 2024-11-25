#include "Serializer.hpp"
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data obj_1(3, "banana");
	Data obj_2(12, "blue pen");
	Data *ptr_1 = &obj_1; 
	Data *ptr_2 = &obj_2;

	std::cout << "\n*ptr_1 :" << std::endl;
	std::cout << *ptr_1;
	std::cout << "\n*ptr_2 :" << std::endl;
	std::cout << *ptr_2;

	uintptr_t val_1 = Serializer::serialize(ptr_1);
	uintptr_t val_2 = Serializer::serialize(ptr_2);
	
	std::cout << "Using serialize function to convert Data * to uintptr_t" << std::endl;

	std::cout << "\nFirst pointer serialized value : " << val_1 << std::endl;
	std::cout << "Second pointer serialized value : " << val_2 << std::endl;
	
	Data *ptr_3 = Serializer::deserialize(val_1); 
	Data *ptr_4 = Serializer::deserialize(val_2);

	std::cout << "\nUsing deserialize function to convert uintptr_t to Data *" << std::endl;
	if (ptr_1 != ptr_3 || ptr_2 != ptr_4)
		std::cerr << "Something went wrong!" << std::endl;

	std::cout << "\nchecking data : " << std::endl;
	std::cout << "\n*ptr_3 :" << std::endl;
	std::cout << *ptr_3;
	std::cout << "\n*ptr_4 :" << std::endl;
	std::cout << *ptr_4;
	return (0);
};
