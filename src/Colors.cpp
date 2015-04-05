#include "./src/Colors.h"

OPvec3 COLORS[ColorNames_MAX];

void Setup() {
	struct OPimagePNG result = OPimagePNGLoadData("Textures/palette.png");
	OPlog("%d x %d", result.Width, result.Height);
	ui16 pos = 0;
	f32* data = (f32*)result.Data;
	for(OPint j = 0; j < result.Width; j++) {
		for(OPint i = 0; i < result.Height; i++) {
			ui8 r, g, b, a;
			r = result.Data[4 * (j + i * result.Width) + 0];
			g = result.Data[4 * (j + i * result.Width) + 1];
			b = result.Data[4 * (j + i * result.Width) + 2];
			a = result.Data[4 * (j + i * result.Width) + 3];
			OPlog("%d, %d, %d, %d", r, g, b, a);
			COLORS[pos] = OPvec3Create(r / 255.0f,g / 255.0f,b / 255.0f);
			pos++;
		}	
	}
}