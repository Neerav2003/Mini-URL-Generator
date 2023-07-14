#include <bits/stdc++.h>
using namespace std;
class MiniUrlGenerator {
private:
    string allpossible;
    unordered_map<std::string, std::string> urlMap;
    unsigned long long counter;

public:
    MiniUrlGenerator() : allpossible("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"),
                         counter(0) {}
    string generateMiniUrl(const string& longUrl) {
        std::string miniUrl = encode(counter++);
        for (int i=0;i<6;i++)
            miniUrl+=encode(counter++);
        urlMap[miniUrl] = longUrl;
        return miniUrl;
    }

    string decodeMiniUrl(const std::string& miniUrl) {
        if (urlMap.count(miniUrl)) {
            return urlMap[miniUrl];
        }
        return "";
    }

private:
    string encode(unsigned long long num) {
        string encodedUrl;
        do {
            encodedUrl.push_back(allpossible[num % allpossible.length()]);
            num /= allpossible.length();
        } while (num > 0);

        return encodedUrl;
    }
};

int main() {
    MiniUrlGenerator generator;
    string longUrl1 = "https://www.example.com/page1";
    string miniUrl1 = generator.generateMiniUrl(longUrl1);
    cout<< "Generated Mini URL 1: "<<miniUrl1<<endl;
    cout << "Decoded Mini URL 1: " << generator.decodeMiniUrl(miniUrl1) << std::endl;
    return 0;
}
