#include <iostream>
#include "kv.cpp"

int main()
{
    KeyValue kv = KeyValue();
    kv.read("input");
    kv.set("z", "3");
    printf("%s", kv.get("a").c_str());
    kv.update("output");
}
