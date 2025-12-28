#include <unordered_map>
#include <string>

class Redis {
private:
    std::unordered_map<std::string, std::string> m_umap{};
    
public:
    // TODO: textfile path constructor
    Redis() = default;
    ~Redis() {
    //    writeToLog();
    }

    void run();
    // Returns response code
    const std::string parser(const std::string& input);
    void setValue(const std::string& key, const std::string& value);
    std::string getValue(const std::string& key) const;
};