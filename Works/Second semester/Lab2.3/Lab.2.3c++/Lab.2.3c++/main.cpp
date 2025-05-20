#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cctype>


class IDigitOperations {
public:
    virtual ~IDigitOperations() = default;
    virtual double getDigitPercentage() const = 0;
    virtual int getDigitCount() const = 0;
};


class StringLine : public IDigitOperations {
private:
    std::string content;

public:
    explicit StringLine(const std::string& str) : content(str) {}

    const std::string& getContent() const { return content; }
    size_t getLength() const { return content.length(); }

    double getDigitPercentage() const override {
        if (content.empty()) return 0.0;
        int digitCount = std::count_if(content.begin(), content.end(),
            [](char c) { return std::isdigit(c); });
        return (static_cast<double>(digitCount) / content.length()) * 100;
    }

    int getDigitCount() const override {
        return std::count_if(content.begin(), content.end(),
            [](char c) { return std::isdigit(c); });
    }
};


class TextContainer {
private:
    std::vector<std::unique_ptr<StringLine>> lines;

public:
    void addLine(std::unique_ptr<StringLine> line) {
        lines.push_back(std::move(line));
    }

    void removeLine(size_t index) {
        if (index < lines.size()) {
            lines.erase(lines.begin() + index);
        }
    }

    void clear() {
        lines.clear();
    }

    const StringLine* getLongestLine() const {
        if (lines.empty()) return nullptr;

        auto it = std::max_element(lines.begin(), lines.end(),
            [](const auto& a, const auto& b) {
                return a->getLength() < b->getLength();
            });

        return it->get();
    }

    double getOverallDigitPercentage() const {
        if (lines.empty()) return 0.0;

        size_t totalChars = getTotalCharacterCount();
        int totalDigits = std::accumulate(lines.begin(), lines.end(), 0,
            [](int sum, const auto& line) {
                return sum + line->getDigitCount();
            });

        return (static_cast<double>(totalDigits) / totalChars) * 100;
    }

    size_t getTotalCharacterCount() const {
        return std::accumulate(lines.begin(), lines.end(), 0,
            [](size_t sum, const auto& line) {
                return sum + line->getLength();
            });
    }

    void displayAllLines() const {
        for (size_t i = 0; i < lines.size(); ++i) {
            std::cout << "[" << i << "] " << lines[i]->getContent() << std::endl;
        }
    }
};

int main() {
    TextContainer text;

  
    text.addLine(std::make_unique<StringLine>("RCHP"));
    text.addLine(std::make_unique<StringLine>("This is a the best work"));
    text.addLine(std::make_unique<StringLine>("Another line with 789 digits"));
    text.addLine(std::make_unique<StringLine>("No digits here"));
    text.addLine(std::make_unique<StringLine>("2025 year"));

    std::cout << "=== All lines in text ===\n";
    text.displayAllLines();
    std::cout << std::endl;

   
    const StringLine* longestLine = text.getLongestLine();
    if (longestLine) {
        std::cout << "Longest line: " << longestLine->getContent()
            << " (" << longestLine->getLength() << " characters)\n";
    }

  
    std::cout << "Overall digit percentage: " << text.getOverallDigitPercentage() << "%\n";

    
    std::cout << "Total character count: " << text.getTotalCharacterCount() << "\n";

   
    text.removeLine(1);
    std::cout << "\n=== After removing line 1 ===\n";
    text.displayAllLines();

    
    text.clear();
    std::cout << "\n=== After clearing the text ===\n";
    std::cout << "Total lines: " << text.getTotalCharacterCount() << "\n";

    return 0;
}