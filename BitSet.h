//#pragma once
//
//#include <cstdlib> // malloc
//
//#define uint32_t unsigned
//
//typedef uint32_t word_t;
//extern const unsigned WORD_SIZE;
//
//
//class BitSet
//{
//protected:
//	word_t* data;
//
//	inline unsigned bindex(int b) { return b / WORD_SIZE; }
//	inline unsigned boffset(int b) { return b % WORD_SIZE; }
//
//public:
//	BitSet();
//	~BitSet();
//
//	inline void set_bit(int b) {
//		data[bindex(b)] |= 1 << (boffset(b));
//	}
//	inline void clear_bit(int b) {
//		data[bindex(b)] &= ~(1 << (boffset(b)));
//	}
//	inline int get_bit(int b) {
//		return data[bindex(b)] & (1 << (boffset(b)));
//	}
//	void clear_all() {
//		*data &= 0;
//	}
//	void set_all() { /* set all elements of data to one */ }
//};
//
//// Version 2
//typedef unsigned int bitword_t
//
