//#include "BitSet.h"
//
//const unsigned WORD_SIZE = sizeof(word_t) * 8;
//
//
//BitSet::BitSet() {
//	data = static_cast<word_t*>(malloc((WORD_SIZE - 1) / 32 + 1));
//}
//
//BitSet::~BitSet() {
//	delete data;
//}