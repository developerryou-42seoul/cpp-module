#include "Serialization.hpp"

Serialization Serialization::instance = Serialization();

Serialization::Serialization()
{}

Serialization::Serialization(const Serialization &ref)
{
	(void)ref;
}

Serialization& Serialization::operator=(const Serialization &ref)
{
	(void)ref;
	return (*this);
}

Serialization::~Serialization()
{}

uintptr_t Serialization::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
