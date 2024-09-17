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
#include "model/SampleChildModel.h"
#include "SampleMemoryMappedFileSerialization.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>


std::string generate_uuid() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 15);
    std::uniform_int_distribution<int> dist2(8, 11);

    std::stringstream ss;
    ss << std::hex;
    for (int i = 0; i < 8; i++) ss << dist(rd);
    ss << "-";
    for (int i = 0; i < 4; i++) ss << dist(rd);
    ss << "-4";  // UUID versiyon 4
    for (int i = 0; i < 3; i++) ss << dist(rd);
    ss << "-";
    ss << dist2(rd);  // UUID'nın variantı (8, 9, A, B)
    for (int i = 0; i < 3; i++) ss << dist(rd);
    ss << "-";
    for (int i = 0; i < 12; i++) ss << dist(rd);
    return ss.str();
}


int main() {

	std::vector<SampleModel> sampleModels;
	std::vector<SampleChildModel> sampleChildModels;
	int sampleChildModelsCount = 0;


	 char cwd[1024];
	    _getcwd(cwd, sizeof(cwd));
	    std::cout << "Current Directory: " << cwd << std::endl;

    std::ifstream inputFile("./resources/example.txt");

    // Dosya açılmadıysa hata mesajı ver
    if (!inputFile.is_open()) {
        std::cerr << "Cannot open file!" << std::endl;
        return 1;
    }

    std::string line;
    // Dosyadan satır satır okuma
    while (std::getline(inputFile, line)) {
    	std::cout << "line = " << line << std::endl;
    	std::string uuid = generate_uuid();
    	int intValue = std::stoi(line.substr(0, 3));
    	std::string strValue1 = line.substr(3, 3);
    	std::string strValue2 = line.substr(6, 3);
    	int recurSegCount = std::stoi(line.substr(9, 2));
    	std::vector<SampleChildModel> tmpSampleChildModels(0);
    	SampleModel sampleModel1(uuid, strValue1, strValue2, intValue, tmpSampleChildModels);
    	sampleModels.push_back(sampleModel1);
    	for ( int i=0; i < recurSegCount; i++){
    		sampleChildModelsCount++;
    		std::cout << "i = " << i << std::endl;
    		int nBgn = 11 + (4 * i);
    		std::string strChildValue1 = line.substr(nBgn, 2);
    		std::string strChildValue2 = line.substr(nBgn+2, 2);
    		SampleChildModel sampleChildModel1(uuid, strChildValue1, strChildValue2, i);
    		//sampleChildModel1.display();
    		sampleModel1.addSampleChildModel(sampleChildModel1);
    		sampleChildModels.push_back(sampleChildModel1);
    	}
    	sampleModel1.display();

    }

    // Dosyayı kapat
    inputFile.close();

    std::cout << "Vector read from file." << std::endl;
    for (const auto& sampleModel : sampleModels) {
            sampleModel.display();
    }
    for (const auto& sampleChildModel : sampleChildModels) {
              sampleChildModel.display();
      }

    SampleMemoryMappedFileSerialization mmapFileSerializer;

    mmapFileSerializer.saveTofile(sampleModels, sampleChildModels);
    mmapFileSerializer.readFromFile(sampleModels.size(), sampleChildModelsCount);

    return 0;
}




