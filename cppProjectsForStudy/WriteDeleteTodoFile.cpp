// Basic Text Editor
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function for a detection EOF end of file, aka "No more data available"
// e.g. user presses "Windows (via ctrl-Z + ENTER)"
bool clearFailedExtraction() {
    // If user writes input that cant be converted to a right type, std::cin goes into 'failure' mode.
    // Or you can write !std::cin, because it is a boolean conversion
    if (!std::cin) {
        if (std::cin.eof()) { // If the user entered an EOF
            std::exit(0);
        }
        std::cin.clear(); // Put us back in 'normal' operation mode, from failure mode
        ignoreLine(); // Removing the bad input

        return true;
    }

    return false;
}

class TextEditor {
    std::string m_fileName {};
    std::string m_text {};
    std::string m_currentLineOfText {};
    static inline int m_uniqueID{ 1 };

public:
    explicit TextEditor(const std::string_view fileName) : m_fileName(fileName) {
    }

    void createFile () const {
       if (!std::filesystem::exists(m_fileName)) {
            std::cout << "File created: " << m_fileName << std::endl;
            std::ofstream NewFile(m_fileName);
       }
        std::cout << m_fileName << " file exists, Congrats! :)" << std::endl;
    }

    void readFile () {
        std::ifstream inf(m_fileName);
        if (!inf) {
           std::cerr << "Uh oh, error opening file " << m_fileName << std::endl;
           return;
        }
        while (std::getline (inf, m_text)) {
           std::cout << m_text << '\n';
        }
    }

    void writeFile() const {
        std::cout << "Enter a text to change the text\n";
        std::string inputText{};
        while (inputText.empty()) {
            std::getline(std::cin, inputText);
        }

        std::ofstream outfile(m_fileName, std::ios::app);
        if (!outfile) {
            std::cerr << "Error opening file " << m_fileName << std::endl;
            return;
        }

        outfile << ++m_uniqueID << ": " << inputText << '\n';
    }

    void deleteTodo() const {
        std::cout << "Enter a Text to delete in the file\n";
        std::string deleteLine{};

        while (deleteLine.empty()) {
            getline(std::cin, deleteLine);
        }

        std::ifstream infile{ m_fileName};
        std::ofstream tempfile{"temp.txt"};

        // If we couldn't open iofile, print an error
        if (!infile || !tempfile)
        {
            // Print an error and exit
            std::cerr << "Uh oh, Sample.txt could not be opened!\n";
        }

        std::string line;

        while (getline(infile, line)) {
            if (!line.empty()) {
                size_t pos = line.find(deleteLine);
                if (pos != std::string::npos) {
                    line.replace(line.find(deleteLine), deleteLine.length(), "");
                }
            }

            tempfile << line << '\n';
        }

        infile.close();
        tempfile.close();

        std::remove(m_fileName.c_str());
        std::rename("temp.txt", m_fileName.c_str());
    }
};

int gettingStart() {
    int input{};

    while (input <= 0 || input > 4) {
        std::cout << "Press 1 if you want to see the whole text, 2 to write, 3 for delete a text, and 4 to escape: \n";
        std::cin >> input;

        if (clearFailedExtraction()) {
            std::cout << "Oops, that input is invalid. Please try again.\n";
            continue;
        }

        ignoreLine();  // Remove any extraneous input
    }

    return input;
}

int main() {
    std::cout << "Write a name of the file\n";
    std::string fileName{};
    std::cin >> fileName;

    TextEditor editor{fileName};
    editor.createFile();

    while (true) {
        const int input{gettingStart()};

        if (input == 1) {
            editor.readFile();
        }
        if (input == 2) {
            editor.writeFile();
        }
        if (input == 3) {
            editor.deleteTodo();
        }
        if (input == 4) {
            break;
        }
    }

    return EXIT_SUCCESS;
}