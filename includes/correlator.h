/*
 * correlator.h
 *
 *  Created on: 04/11/2016
 *      Author: Lucas Teske
 */

#ifndef INCLUDES_CORRELATOR_H_
#define INCLUDES_CORRELATOR_H_

#include <vector>
#include <cstdint>

typedef std::vector<uint8_t> VecU8;

class Correlator {
private:
	std::vector<VecU8> words;
	std::vector<uint32_t> correlation;
	std::vector<uint32_t> tmpCorrelation;
	std::vector<uint32_t> position;
	uint32_t highestCorrelation;
	uint8_t currentWordSize;

	void resetCorrelation();
public:
	static inline bool hardCorrelate(uint8_t dataByte, uint8_t wordByte) { return ((dataByte >= 127) && (wordByte == 0)) || ((dataByte < 127) && (wordByte == 255)); }

	Correlator();

	inline uint32_t getHighestCorrelation() { return correlation[highestCorrelation]; };
	inline uint32_t getHighestCorrelationPosition() { return position[highestCorrelation]; };

	void addWord(uint32_t word);
	void addWord(uint64_t word);

	void correlate(uint8_t *data, uint32_t length);
};



#endif /* INCLUDES_CORRELATOR_H_ */