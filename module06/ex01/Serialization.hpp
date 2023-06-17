#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

struct Data
{
	int index;
	std::string str;
};

class Serialization
{
private:
	Serialization();
	Serialization(const Serialization &ref);
	Serialization& operator=(const Serialization &ref);
	~Serialization();

	static Serialization instance;
	
public:
	static Serialization* getInstance()
	{
		return (&instance);
	};
//It takes a pointer and converts it to the unsigned integer type uintptr_t.
	uintptr_t serialize(Data* ptr);
//It takes an unsigned integer parameter and converts it to a pointer to Data.
	Data* deserialize(uintptr_t raw);
};

#endif
