#ifndef SIDE_GENERATOR
#define SIDE_GENERATOR

#include "./src/SideTypes.h"
#include "./OPengine.h"

struct MeshBuilderVert {
	OPvec3 pos;
	OPvec3 col;
};

void GenerateFrontSide(OPmeshBuilder* builder, ui16* side) {
	MeshBuilderVert verts[4];

	for(OPint i = 0; i < SIDE_WIDTH; i++) {
		for(OPint j = 0; j < SIDE_HEIGHT; j++) {
			ui16 sideColor = side[(SIDE_HEIGHT - j - 1) * SIDE_WIDTH + i];
			for(OPint k = 0; k < 4; k++) {
				verts[k].col = COLORS[sideColor];
			}
			verts[0].pos = OPvec3Create(i-3.5f,j,7.0f);
			verts[1].pos = OPvec3Create(i+1-3.5f,j,7.0f);
			verts[2].pos = OPvec3Create(i+1-3.5f,j+1,7.0f);
			verts[3].pos = OPvec3Create(i-3.5f,j+1,7.0f);
			OPmeshBuilderAdd(builder, &verts[0], &verts[1], &verts[2], &verts[3]);
		}
	}
}

void GenerateFrontSide(OPmeshBuilder* builder, ui16 color) {

	MeshBuilderVert verts[4];

	for(OPint i = 0; i < SIDE_WIDTH; i++) {
		for(OPint j = 0; j < SIDE_HEIGHT; j++) {
			for(OPint k = 0; k < 4; k++) {
				verts[k].col = COLORS[color];
			}
			verts[0].pos = OPvec3Create(i-3.5f,j,7.0f);
			verts[1].pos = OPvec3Create(i+1-3.5f,j,7.0f);
			verts[2].pos = OPvec3Create(i+1-3.5f,j+1,7.0f);
			verts[3].pos = OPvec3Create(i-3.5f,j+1,7.0f);
			OPmeshBuilderAdd(builder, &verts[0], &verts[1], &verts[2], &verts[3]);
		}
	}
}

void GenerateLeftSide(OPmeshBuilder* builder, ui16* side) {
	MeshBuilderVert verts[4];

	for(OPint i = 0; i < SIDE_WIDTH; i++) {
		for(OPint j = 0; j < SIDE_HEIGHT; j++) {
			ui16 sideColor = side[(SIDE_HEIGHT - j - 1) * SIDE_WIDTH + i];
			for(OPint k = 0; k < 4; k++) {
				verts[k].col = COLORS[sideColor];
			}
			verts[0].pos = OPvec3Create(-3.5f,j, i);
			verts[1].pos = OPvec3Create(-3.5f,j,i+1);
			verts[2].pos = OPvec3Create(-3.5f,j+1,i+1);
			verts[3].pos = OPvec3Create(-3.5f,j+1,i);
			OPmeshBuilderAdd(builder, &verts[0], &verts[1], &verts[2], &verts[3]);
		}
	}
}

void GenerateLeftSide(OPmeshBuilder* builder, ui16 color) {
	MeshBuilderVert verts[4];

	for(OPint i = 0; i < SIDE_WIDTH; i++) {
		for(OPint j = 0; j < SIDE_HEIGHT; j++) {
			for(OPint k = 0; k < 4; k++) {
				verts[k].col = COLORS[color];
			}
			verts[0].pos = OPvec3Create(-3.5f,j, i);
			verts[1].pos = OPvec3Create(-3.5f,j,i+1);
			verts[2].pos = OPvec3Create(-3.5f,j+1,i+1);
			verts[3].pos = OPvec3Create(-3.5f,j+1,i);
			OPmeshBuilderAdd(builder, &verts[0], &verts[1], &verts[2], &verts[3]);
		}
	}
}

void GenerateTopSide(OPmeshBuilder* builder, ui16* side) {

	MeshBuilderVert verts[4];

	for(OPint i = 0; i < SIDE_WIDTH; i++) {
		for(OPint j = 0; j < SIDE_HEIGHT; j++) {
			ui16 sideColor = side[(SIDE_HEIGHT - j - 1) * SIDE_WIDTH + i];
			for(OPint k = 0; k < 4; k++) {
				verts[k].col = COLORS[sideColor];
			}
			verts[0].pos = OPvec3Create(j-3.5f, 7.0f, i);
			verts[1].pos = OPvec3Create(j-3.5f, 7.0f,i+1);
			verts[2].pos = OPvec3Create(j+1-3.5f, 7.0f,i+1);
			verts[3].pos = OPvec3Create(j+1-3.5f, 7.0f,i);
			OPmeshBuilderAdd(builder, &verts[0], &verts[1], &verts[2], &verts[3]);
		}
	}
}

void GenerateTopSide(OPmeshBuilder* builder, ui16 color) {
	MeshBuilderVert verts[4];

	for(OPint i = 0; i < SIDE_WIDTH; i++) {
		for(OPint j = 0; j < SIDE_HEIGHT; j++) {
			for(OPint k = 0; k < 4; k++) {
				verts[k].col = COLORS[color];
			}
			verts[0].pos = OPvec3Create(j-3.5f, 7.0f, i);
			verts[1].pos = OPvec3Create(j-3.5f, 7.0f,i+1);
			verts[2].pos = OPvec3Create(j+1-3.5f, 7.0f,i+1);
			verts[3].pos = OPvec3Create(j+1-3.5f, 7.0f,i);
			OPmeshBuilderAdd(builder, &verts[0], &verts[1], &verts[2], &verts[3]);
		}
	}
}

OPmesh GenerateBox(ui16 color) {
	
	OPmeshBuilder* builder = OPmeshBuilderCreate(sizeof(MeshBuilderVert));

	GenerateLeftSide(builder, color);
	GenerateTopSide(builder, color);
	GenerateFrontSide(builder, color + 1);

	OPmesh result = OPmeshBuilderGen(builder);
	OPmeshBuilderDestroy(builder);

	return result;
}

OPmesh GenerateBox(ui16* left, ui16* top, ui16* front) {
	
	OPmeshBuilder* builder = OPmeshBuilderCreate(sizeof(MeshBuilderVert));

	GenerateLeftSide(builder, left);
	GenerateTopSide(builder, top);
	GenerateFrontSide(builder, front);

	OPmesh result = OPmeshBuilderGen(builder);
	OPmeshBuilderDestroy(builder);

	return result;
}

#endif