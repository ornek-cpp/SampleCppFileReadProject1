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
#include "model/SampleModel.h"
#include "SampleMemoryMappedFileSerialization.h"

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
    	int count = std::stoi(line.substr(9, 2));
    	for ( int i=0; i < count; i++){
    		int nBgn = 11 + (4 * i);
    		std::string strChildValue1 = line.substr(nBgn, 2);
    		std::string strChildValue2 = line.substr(nBgn+2, 2);
    		SampleChildModel sampleChildModel1(strChildValue1, strChildValue2, i);
    		sampleModel1.getSampleChildModels().push_back(sampleChildModel1);
    	}
    	//sampleModel1.display();

        std::cout << line << std::endl;
    }

    // Dosyayı kapat
    inputFile.close();

    std::cout << "Vector read from file." << std::endl;
    for (const auto& sampleModel : sampleModels) {
            sampleModel.display();
    }

    SampleMemoryMappedFileSerialization mmapFileSerializer;

    mmapFileSerializer.saveTofile(sampleModels);
    mmapFileSerializer.readFromFile();

    return 0;
}



