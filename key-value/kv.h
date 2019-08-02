class KeyValue
{
public:
    std::unordered_map<std::string, std::string> values;
    KeyValue();
    bool check_file_exists(const char * file);
    void read_file(const char * file);
    void set(std::string key, std::string value);
    void write_file(const char * file);
};
