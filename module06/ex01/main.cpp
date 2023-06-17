#include <iostream>
#include "Serialization.hpp"

int main(void)
{
	Serialization *ser = Serialization::getInstance();
	Data	dict;

	dict.index = 0;
	dict.str = "APPLE";

	std::cout<<"dict ptr : "<<&dict<< std::endl;

	uintptr_t serialized_ptr = ser->serialize(&dict);

	std::cout<<"serialized dict ptr : "<<serialized_ptr << std::endl;

	Data *ptr = ser->deserialize(serialized_ptr);

	std::cout<<"deserialized dict ptr : "<<ptr<<std::endl;
	std::cout<<"deserialized dict : "<<ptr->index<<" "<<ptr->str<<std::endl;

	return (0);
}
