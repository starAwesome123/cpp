#include <iostream>
#include <string>


void respondToInput(const std::string& input) {
    if (input.find("how are you")!= std::string::npos) {
        std::cout << "Chatbot: I'm just code, but I'm functioning perfectly!\n";}
    else if (input.find("happy") != std::string::npos || input.find("good") != std::string::npos) {
            std::cout << "Chatbot: I'm glad you're feeling good!\n";}
    else if (input.find("sad") != std::string::npos || input.find("bad") != std::string::npos) {
            std::cout << "Chatbot: I'm sorry to hear that. I hope things get better!\n";
        }

    else if (input.find("programming") != std::string::npos) {
        std::cout << "Chatbot: Programming is fun and creative!\n";
    } else if (input.find("C++") != std::string::npos) {
        std::cout << "Chatbot: C++ is a great language for system programming.\n";
    } else {
        std::cout << "Chatbot: Sorry, I don't understand that.\n";
    }
}

int main() {
    std::string input;

    std::cout << "Chatbot: Hi! I can answer basic questions. Type 'exit' to quit.\n";

 while (true) {
        std::cout << "You: ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Chatbot: Goodbye!\n";
            break;
        } else {
            respondToInput(input);
        }
    }
    return 0;
}