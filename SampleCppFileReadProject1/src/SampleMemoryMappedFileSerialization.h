/*
 * SampleMemoryMappedFileSerialization.h
 *
 *  Created on: 18 Ağu 2024
 *      Author: ACER
 */

#ifndef SRC_SAMPLEMEMORYMAPPEDFILESERIALIZATION_H_
#define SRC_SAMPLEMEMORYMAPPEDFILESERIALIZATION_H_

#include <vector>
#include "model/SampleModel.h"

class SampleMemoryMappedFileSerialization {
public:
	SampleMemoryMappedFileSerialization();
	virtual ~SampleMemoryMappedFileSerialization();

	int saveTofile(std::vector<SampleModel>& sampleModels);

	int readFromFile();

};

#endif /* SRC_SAMPLEMEMORYMAPPEDFILESERIALIZATION_H_ */
