#include	"Data.hpp"

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

int	main(void)
{
	Data	*data = new Data();

	std::cout << "address of data: " << data << std::endl;
	std::cout << "value of data serialized: " << std::showbase << std::hex << serialize(data) << std::endl;
	Data	*data_deserialized = deserialize(serialize(data));
	std::cout << "address of data deserialized: " << data_deserialized << std::endl;
	std::cout << "value of data: " << data->getValue() << std::endl;
	std::cout << "value of data deserialized: " << data_deserialized->getValue() << std::endl;
	delete data;
	return (0);
}
