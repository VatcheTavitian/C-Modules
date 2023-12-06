#include "Serializer.hpp"

int main() {



    Data data = {5, 2.11, "Hello"};
  
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized value = " << serialized << std::endl;
  
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized value = " << deserialized << std::endl;
    std::cout << "x = "  << deserialized->x << std::endl;
    std::cout << "y = "  << deserialized->y << std::endl;
    std::cout << "text = "  << deserialized->text << std::endl;

}