#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "kv.h"

KeyValue::KeyValue() {


}

bool KeyValue::check_file_exists(const char * file) {
    std::ifstream infile(file);
    return infile.good();
}

void KeyValue::read_file(const char * file) {
    int pos;

    std::ifstream infile(file);

    for(std::string line; getline(infile, line);) {
        pos = line.find("=");
        values[line.substr(0, pos)] = line.substr(pos + 1, line.size());
    }
}

void KeyValue::set(std::string key, std::string value) {
    values[key] = value;
}

void KeyValue::write_file(const char * file) {
    std::ofstream f;
    f.open(file);

    for(auto & kv : values) {
        f << kv.first << "=" << kv.second << "\n";
    }

    f.close();
}
