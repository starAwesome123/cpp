#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void listDirectory(const fs::path& path) {
    std::cout << "Listing files in: " << path << "\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << (entry.is_directory() ? "[DIR] " : "      ") << entry.path().filename() << '\n';
    }
}

void viewFile(const fs::path& filepath) {
    std::ifstream file(filepath);
    if (file.is_open()) {
        std::cout << "\n--- Viewing file: " << filepath.filename() << " ---\n";
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        std::cout << "\n--- End of file ---\n";
        file.close();
    } else {
        std::cerr << "Unable to open file.\n";
    }
}

void createDirectory(const fs::path& path) {
    if (fs::create_directory(path)) {
        std::cout << "Directory created: " << path << "\n";
    } else {
        std::cerr << "Failed to create directory.\n";
    }
}

void copyFile(const fs::path& src, const fs::path& dest) {
    try {
        fs::copy(src, dest, fs::copy_options::overwrite_existing);
        std::cout << "File copied to " << dest << "\n";
    } catch (fs::filesystem_error& e) {
        std::cerr << "Error copying file: " << e.what() << '\n';
    }
}

void moveFile(const fs::path& src, const fs::path& dest) {
    try {
        fs::rename(src, dest);
        std::cout << "File moved to " << dest << "\n";
    } catch (fs::filesystem_error& e) {
        std::cerr << "Error moving file: " << e.what() << '\n';
    }
}

int main() {
    fs::path currentPath = fs::current_path();
    std::string command, argument1, argument2;

    std::cout << "Welcome to C++ File Manager\n";
    std::cout << "Commands: list, view <file>, mkdir <directory>, copy <src> <dest>, move <src> <dest>, exit\n";

    while (true) {
        std::cout << "\nCurrent Path: " << currentPath << "\n";
        std::cout << "> ";
        std::cin >> command;

        if (command == "list") {
            listDirectory(currentPath);
        } else if (command == "view") {
            std::cin >> argument1;
            viewFile(currentPath / argument1);
        } else if (command == "mkdir") {
            std::cin >> argument1;
            createDirectory(currentPath / argument1);
        } else if (command == "copy") {
            std::cin >> argument1 >> argument2;
            copyFile(currentPath / argument1, currentPath / argument2);
        } else if (command == "move") {
            std::cin >> argument1 >> argument2;
            moveFile(currentPath / argument1, currentPath / argument2);
        } else if (command == "exit") {
            std::cout << "Exiting File Manager.\n";
            break;
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}
