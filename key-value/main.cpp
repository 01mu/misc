#include <iostream>
#include "kv.cpp"

int main()
{
    KeyValue kv = KeyValue();

    kv.read_file("input");
    kv.set("z", "3");

    std::cout << kv.values["z"];

    kv.write_file("output");
}

