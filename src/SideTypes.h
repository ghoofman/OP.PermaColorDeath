#ifndef SIDE_TYPES
#define SIDE_TYPES

#include "./src/Colors.h"

#define SIDE_WIDTH 7
#define SIDE_HEIGHT 7

ui16 GreenGrassLeft[SIDE_WIDTH * SIDE_HEIGHT] = {
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN,
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_9_3_GREY, C_2_4_GREEN, C_9_3_GREY, C_2_4_GREEN,
	C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY,
	C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY,
	C_9_3_GREY, C_9_3_GREY, C_9_4_GREY, C_9_3_GREY, C_9_3_GREY, C_9_4_GREY, C_9_3_GREY,
	C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_4_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY,
	C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY, C_9_3_GREY
};

ui16 GreenGrassTop[SIDE_WIDTH * SIDE_HEIGHT] = {
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN,
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN,
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN,
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN,
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN,
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN,
	C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN, C_2_4_GREEN
};

ui16 GreenGrassFront[SIDE_WIDTH * SIDE_HEIGHT] = {
	C_2_5_GREEN, C_2_5_GREEN, C_2_5_GREEN, C_2_5_GREEN, C_2_5_GREEN, C_2_5_GREEN, C_2_5_GREEN,
	C_2_5_GREEN, C_2_5_GREEN, C_2_5_GREEN, C_9_4_GREY, C_2_5_GREEN, C_9_4_GREY, C_2_5_GREEN,
	C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY,
	C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY,
	C_9_5_GREY, C_9_4_GREY, C_9_4_GREY, C_9_5_GREY, C_9_4_GREY, C_9_5_GREY, C_9_4_GREY,
	C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_5_GREY, C_9_4_GREY, C_9_4_GREY,
	C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY, C_9_4_GREY
};

ui16 TestSide[SIDE_WIDTH * SIDE_HEIGHT] = {
	C_2_5_GREEN, C_9_5_GREY, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0
};

#endif