/*
 * SampleChildModel.h
 *
 *  Created on: 16 Eyl 2024
 *      Author: ACER
 */


#ifndef SRC_MODEL_SAMPLECHILDMODEL_H_
#define SRC_MODEL_SAMPLECHILDMODEL_H_

#include <string>
#include <iostream>


class SampleChildModel {
private :
	std::string parentId;
	std::string strProperty1;
	std::string strProperty2;
	int intProperty;


public:
	SampleChildModel();
	SampleChildModel(const std::string& parentId, const std::string& strProperty1, const std::string& strProperty2, int intProperty1);

	virtual ~SampleChildModel();

	 // Helper functions
	void display() const;
};

#endif /* SRC_MODEL_SAMPLECHILDMODEL_H_ */
