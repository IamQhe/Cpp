#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    std::string dirPath = (argc > 1) ? argv[1] : ".";

    if (!fs::exists(dirPath)) {
        std::cerr << "目录不存在: " << dirPath << std::endl;
        return 1;
    }

    if (!fs::is_directory(dirPath)) {
        std::cerr << "路径不是目录: " << dirPath << std::endl;
        return 1;
    }

    std::vector<std::pair<std::string, std::time_t>> matchedFiles;

    try {
        for (const auto& entry : fs::recursive_directory_iterator(
                 dirPath, fs::directory_options::skip_permission_denied)) {
            if (!entry.is_regular_file()) continue;

            auto ftime = fs::last_write_time(entry);

            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
            );
            std::time_t tt = std::chrono::system_clock::to_time_t(sctp);

            std::tm* localTime = std::localtime(&tt);

            // 关键改动：>= 2025
            if (localTime->tm_year + 1900 >= 2025) {
                matchedFiles.push_back({entry.path().string(), tt});
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "遍历目录时出错: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "在目录 [" << dirPath << "] 下，最后修改日期在 2025 年及之后的文件：" << std::endl;
    std::cout << std::string(60, '-') << std::endl;

    for (const auto& [path, tt] : matchedFiles) {
        std::tm* localTime = std::localtime(&tt);
        std::cout << std::put_time(localTime, "%Y-%m-%d %H:%M:%S")
                  << "  " << path << std::endl;
    }

    std::cout << std::string(60, '-') << std::endl;
    std::cout << "共找到 " << matchedFiles.size() << " 个文件。" << std::endl;

    return 0;
}