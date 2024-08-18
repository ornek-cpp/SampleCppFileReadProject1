/*
 * SampleMemoryMappedFileSerialization.cpp
 *
 *  Created on: 18 Ağu 2024
 *      Author: ACER
 */

#include "SampleMemoryMappedFileSerialization.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include "SampleModel.h"


SampleMemoryMappedFileSerialization::SampleMemoryMappedFileSerialization() {
	// TODO Auto-generated constructor stub

}

SampleMemoryMappedFileSerialization::~SampleMemoryMappedFileSerialization() {
	// TODO Auto-generated destructor stub
}

int SampleMemoryMappedFileSerialization::saveTofile(std::vector<SampleModel>& sampleModels){

    const char* filename = "sample_models.dat";

    // Create adn open file
	HANDLE hFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		std::cerr << "File cannot be opened!" << std::endl;
		return 1;
	}

	// Determine file size
	DWORD filesize = sampleModels.size() * sizeof(SampleModel);
	SetFilePointer(hFile, filesize - 1, NULL, FILE_BEGIN);
	SetEndOfFile(hFile);

	// Create memory map
	HANDLE hMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, filesize, NULL);
	if (hMapping == NULL) {
		std::cerr << "Couldn't create memory mapping!" << std::endl;
		CloseHandle(hFile);
		return 1;
	}

	// Create memory view
	char* pMap = static_cast<char*>(MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, filesize));
	if (pMap == NULL) {
		std::cerr << "Couldn't create memory view!" << std::endl;
		CloseHandle(hMapping);
		CloseHandle(hFile);
		return 1;
	}

	// Write vector data to memory mapped file
	std::memcpy(pMap, sampleModels.data(), filesize);

    // Close map view and file
	UnmapViewOfFile(pMap);
	CloseHandle(hMapping);
	CloseHandle(hFile);

    std::cout << "Vector written to memory mapped file." << std::endl;

    return 0;
}


int SampleMemoryMappedFileSerialization::readFromFile(){
    const char* filename = "sample_models.dat";

    // Open file to read
    HANDLE hFile = CreateFileA(filename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		std::cerr << "Couldn't open file!" << std::endl;
		return 1;
	}

	DWORD filesize = 2 * sizeof(SampleModel);


	// Create memory map
	HANDLE hMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, filesize, NULL);
	if (hMapping == NULL) {
		std::cerr << "Couldn't create memory map!" << std::endl;
		CloseHandle(hFile);
		return 1;
	}

    // Create memory view
	char* pMap = static_cast<char*>(MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, filesize));
	if (pMap == NULL) {
		std::cerr << "Couldn't create memory view!" << std::endl;
		CloseHandle(hMapping);
		CloseHandle(hFile);
		return 1;
	}

	// Copy memory data to vector
	std::vector<SampleModel> sampleModels(filesize / sizeof(SampleModel));
	std::memcpy(sampleModels.data(), pMap, filesize);

	// Close memory view and file
	UnmapViewOfFile(pMap);
	CloseHandle(hMapping);
	CloseHandle(hFile);

    // Display Vector data
	std::cout << "Vector read from memory mapped file." << std::endl;
    for (const auto& sampleModel : sampleModels) {
                sampleModel.display();
    }
    std::cout << std::endl;

    return 0;
}






