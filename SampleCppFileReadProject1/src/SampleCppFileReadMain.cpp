/*
 * SampleCppFileReadMain.cpp
 *
 *  Created on: 4 Ağu 2024
 *      Author: ACER
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <direct.h>
#include "SampleModel.h"

int main() {

	std::vector<SampleModel> sampleModels;

	 char cwd[1024];
	    _getcwd(cwd, sizeof(cwd));
	    std::cout << "Current Directory: " << cwd << std::endl;

    std::ifstream inputFile("./resources/example.txt");

    // Dosya açılmadıysa hata mesajı ver
    if (!inputFile.is_open()) {
        std::cerr << "Dosya açılamadı." << std::endl;
        return 1;
    }

    std::string line;
    // Dosyadan satır satır okuma
    while (std::getline(inputFile, line)) {
    	int intValue = std::stoi(line.substr(0, 3));
    	std::string strValue1 = line.substr(3, 3);
    	std::string strValue2 = line.substr(6, 3);
    	SampleModel sampleModel1(strValue1, strValue2, intValue);
    	sampleModels.push_back(sampleModel1);
    	//sampleModel1.display();

        std::cout << line << std::endl;
    }

    // Dosyayı kapat
    inputFile.close();

    for (const auto& sampleModel : sampleModels) {
            sampleModel.display();
        }

    return 0;
}



