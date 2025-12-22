#include <iostream>
#include <bits/stdc++.h>

std::string replaceStr(std::string str, std::string s1, std::string s2) {
    int sLen = s1.length();
    if (sLen == 0 || s1 == s2)
        return (str);

    while (true) {
        std::size_t index = str.find(s1, 0);
        if (index == std::string::npos)
            break;
        str.erase(index, sLen);
        str.insert(index, s2);
    }
    return (str);
}


int main(int ac, char *av[]) {
    std::string rStr, wStr, s1, s2, tmp;
    std::string fileOutput, fileInput;

    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " filename s1 s2\n";
        return (1);
    }

    fileInput = av[1];
    fileOutput = av[1];
    fileOutput.append(".replace");
    s1 = av[2];
    s2 = av[3];

    std::ifstream iFile(fileInput.c_str()); //TODO: understand stream
    if (!iFile.is_open()) {
        std::cerr << "Error reading '" << fileInput << "'\n";
        return (1);
    }

    std::ofstream oFile(fileOutput.c_str());
    if (!oFile.is_open()) {
        std::cerr << "Error writing '" << fileOutput << "'\n";
        iFile.close();
        return (1);
    }

    std::getline(iFile, rStr, '\0');

    wStr = replaceStr(rStr, s1, s2);

    oFile << wStr << std::endl;

    oFile.close();
    iFile.close();

    return (0);
}