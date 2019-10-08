#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "kv.h"

KeyValue::KeyValue() {

}

KeyValue::KeyValue(const char * file) {
    values.clear();
    read(file);
}

void KeyValue::set(std::string key, std::string value) {
    values[key] = value;
}

std::string KeyValue::get(std::string key) {
    return values[key];
}

void KeyValue::update(const char * file) {
    std::ofstream f;
    f.open(file);

    for(auto & kv : values) {
        f << kv.first << "=" << kv.second << "\n";
    }

    f.close();
}

void KeyValue::read(const char * file) {
    int pos;

    std::ifstream infile(file);

    for(std::string line; getline(infile, line);) {
        pos = line.find("=");
        values[line.substr(0, pos)] = line.substr(pos + 1, line.size());
    }
}
