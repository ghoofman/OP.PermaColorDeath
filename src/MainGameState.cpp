#include "./src/MainGameState.h"

struct MainGameData {
	OPcam Camera;
	OPmodel TestModel;
	OPeffect SimpleModelEffect;
	OPmaterial TestMaterial;
};

MainGameData mainGame;

void MainGameStateInit(OPgameState* last) {
	
	mainGame.TestModel.mesh = (OPmesh*)OPcmanLoadGet("testblock.opm");
	mainGame.TestModel.world = OPMAT4IDENTITY;
	mainGame.SimpleModelEffect = OPeffectGen("SimpleModel.vert", "SimpleModel.frag", OPATTR_POSITION | OPATTR_COLOR, "Colored Effect", mainGame.TestModel.mesh->VertexSize);
	OPmaterialInit(&mainGame.TestMaterial, &mainGame.SimpleModelEffect);

	mainGame.Camera = OPcamPersp(
		OPvec3Create(10,10,10),
		OPVEC3_ZERO,
		OPVEC3_UP,
		0.1f, 100.0f,
		OPpi_4,
		OPRENDER_WIDTH / (OPfloat)OPRENDER_HEIGHT
		);

	OPrenderDepth(1);
	OPrenderCull(1);
}

OPint MainGameStateUpdate(OPtimer* timer) {
	OPrenderClear(0,0,0);
	OPmodelDraw(mainGame.TestModel, &mainGame.TestMaterial, mainGame.Camera);
	OPrenderPresent();
	return 0;
}

OPint MainGameStateExit(OPgameState* change) {
	return 0;
}

OPgameState GS_MAIN = {
	MainGameStateInit,
	MainGameStateUpdate,
	MainGameStateExit
};