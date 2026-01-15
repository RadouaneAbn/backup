#include "Serializer.hpp"

int main()
{
	Data data;
	data.setValue(42);

	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Original Data Value: " << data.getValue() << std::endl;
	std::cout << "Deserialized Data Value: " << deserializedData->getValue() << std::endl;

	if (&data == deserializedData)
		std::cout << "Success." << std::endl;
	else
		std::cout << "Failure." << std::endl;

	return 0;
}
