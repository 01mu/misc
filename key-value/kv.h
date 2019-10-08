class KeyValue
{
private:
    std::unordered_map<std::string, std::string> values;

public:
    KeyValue();
    KeyValue(const char * file);

    void set(std::string key, std::string value);
    std::string get(std::string key);

    void update(const char * file);
    void read(const char * file);
};
