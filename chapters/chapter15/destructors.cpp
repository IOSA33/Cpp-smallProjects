#include <iostream>

class NetworkData {
    std::string m_serverName{};
    DataStore m_dataQueue{};

public:
    NetworkData(std::string_view serverName) : m_serverName(serverName) {}
    ~NetworkData() {
        sendData();
    }

    void addData(std::string_view data) {
        m_dataQueue.add(data);
    }

    void sendData() {
        // connect to server
        // send all data
        // clear data
    }
};
int main()
{
    NetworkData n("someipAddress");

    n.addData("somedata1");
    n.addData("somedata2");

    return 0;
}