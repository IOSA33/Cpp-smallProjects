#include <unordered_map>
#include <string>

class Redis {
private:
    std::unordered_map<std::string, std::string> m_umap{};
    
public:
    // TODO: textfile constructor
    Redis() = default;
    ~Redis() {
    //    writeToLog();
    }

    void run();
};