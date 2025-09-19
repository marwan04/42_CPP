#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 42;
    data.name = "Hello Serialization";

    std::cout << "Original Data:\n";
    std::cout << "  id: " << data.id << "\n";
    std::cout << "  name: " << data.name << "\n\n";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << "\n\n";

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "After Deserialization:\n";
    std::cout << "  id: " << ptr->id << "\n";
    std::cout << "  name: " << ptr->name << "\n";

    if (ptr == &data)
        std::cout << "\nPointer restored successfully" << std::endl;
    else
        std::cout << "\nPointer mismatch" << std::endl;

    return 0;
}
