#include <filesystem>
#include <fstream>
#include <ctime>

namespace fs = std::filesystem;

void readmeInit(std::ofstream &out);
bool bojStats(std::ofstream &out, std::ofstream &err);
void copy(std::string source, std::ofstream &out);

int main(int argc, char const *argv[])
{
    bool exception = false;

    std::ofstream out;
    out.open("readme.md");

    std::ofstream err;
    err.open("error.log");

    readmeInit(out);
    exception |= bojStats(out, err);

    out.close();
    err.close();

    if (!exception)
    {
        fs::remove("error.log");
    }
    else
    {
        out.open("readme.md");
        out << "Error Occured.\n\nPlease See The Error Log\n";
    }

    return 0;
}

void readmeInit(std::ofstream &out)
{
    out << "# 대충 레포 제목\n\n";
}

bool bojStats(std::ofstream &out, std::ofstream &err)
{
    fs::path BOJ("Baekjoon Online Judge");

    if (!fs::exists(BOJ))
    {
        err << "Fatal Error : Directory \"" + BOJ.string() + "\" Does Not Exist\n";
        return true;
    }
    if (!fs::is_directory(BOJ))
    {
        err << "Fatal Error : \"" + BOJ.string() + "\" Is Not A Directory\n";
        return true;
    }

    int cnt = 0;

    for (auto &p : fs::directory_iterator(BOJ))
    {
        if (fs::is_directory(p))
        {
            cnt++;
        }
    }

    out << "BOJ Problem Count = " << cnt << "\n\n";

    out << "---\n\n";

    out << "## 최근 푼 문제 (BaekJoon)\n";

    copy("recent.md", out);

    out << "\n\n---\n\n";

    time_t t;
    time(&t);

    out << "last updated : " << asctime(localtime(&t));

    return false;
}

void copy(std::string source, std::ofstream &out)
{
    std::ifstream src;
    src.open(source);
    
    std::string line;
    while (std::getline(src, line))
    {
        out << line << "\n";
    }

    src.close();
}