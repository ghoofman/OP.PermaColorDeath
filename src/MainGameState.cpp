#include "./src/MainGameState.h"
#include "./src/SideGenerator.h"
#include "./src/Player.h"
#include "./Pipeline/include/Loaders/OPloaderVoxels.h"

#define MODEL_COUNT 6

struct VoxelMesh {
	OPmodel model;
};

struct MainGameData {
	OPcam Camera;
	OPmesh playerMesh;
	OPmesh TestMesh[3];
	OPmodel TestModel[MODEL_COUNT];
	OPeffect SimpleModelEffect;
	OPmaterial TestMaterial;
	OPgamePad* gamePad1;
	Player player1;
	OPtexture2D* bg;
	OPvoxels* voxels;
	OPvector* voxelVector;
};

MainGameData mainGame;

void MainGameStateInit(OPgameState* last) {
	Setup();

	mainGame.voxels = (OPvoxels*)OPcmanLoadGet("TestLevel.qb");
	OPlog("TestLevel: %d %d %d", mainGame.voxels->size.x, mainGame.voxels->size.y, mainGame.voxels->size.z);

	mainGame.voxelVector = OPvectorCreate(sizeof(VoxelMesh));

	for(OPint i = 0; i < mainGame.voxels->size.x; i++) {		
		for(OPint j = 0; j < mainGame.voxels->size.y; j++) {			
			for(OPint k = 0; k < mainGame.voxels->size.z; k++) {
				OPvecInt3 p = OPvoxelsGet(mainGame.voxels, i, j, k);
				OPmesh* m = (OPmesh*)OPalloc(sizeof(OPmesh));
				if(p.x == 255 && p.y == 0 && p.z == 0) {
					*m = GenerateBox(C_2_2_GREEN);
				} else if(p.x == 153 && p.y == 204 && p.z == 255) {
					*m = GenerateBox(C_9_4_GREY);
				} else if(p.x == 0 && p.y == 0 && p.z == 10) {
					OPfree(m);
					mainGame.player1.Position = OPvec3Create(i * 7, j * 7, k * 7);
					continue;
				}
				else {
					OPfree(m);
					continue;
				}
				VoxelMesh voxelMesh;
				voxelMesh.model.mesh = m;
				voxelMesh.model.world = OPmat4Translate(i * 7, j * 7, k * 7);
				OPvectorPush(mainGame.voxelVector, (ui8*)&voxelMesh);
				OPlog("Vox: %d, %d, %d", p.x, p.y, p.z);
			}
		}
	}

	mainGame.bg = OPtexture2DCreate((OPtexture*)OPcmanLoadGet("background.png"), NULL);
	mainGame.bg->Scale = OPvec2Create(2, 2);

	mainGame.playerMesh = OPcubeCreate(COLORS[C_7_5_MAGENTA]);
	mainGame.player1.Model.mesh = &mainGame.playerMesh;

	mainGame.gamePad1 = OPgamePadGet(OPGAMEPAD_ONE);

	mainGame.TestMesh[0] = GenerateBox(GreenGrassLeft, GreenGrassTop, GreenGrassFront);
	mainGame.TestMesh[1] = GenerateBox(C_2_2_GREEN);
	mainGame.TestMesh[2] = GenerateBox(C_2_4_GREEN);

	OPglError("MainGameState clear errors %d");
	for(OPint i = 0; i < MODEL_COUNT; i++) {
		mainGame.TestModel[i].world = OPMAT4IDENTITY;
	}

	mainGame.TestModel[0].mesh = &mainGame.TestMesh[0];
	mainGame.TestModel[1].mesh = &mainGame.TestMesh[1];
	mainGame.TestModel[2].mesh = &mainGame.TestMesh[2];
	mainGame.TestModel[3].mesh = &mainGame.TestMesh[0];
	mainGame.TestModel[4].mesh = &mainGame.TestMesh[0];
	mainGame.TestModel[5].mesh = &mainGame.TestMesh[0];

	mainGame.TestModel[1].world = OPmat4Translate(7,7,0);
	mainGame.TestModel[2].world = OPmat4Translate(7,0,7);
	mainGame.TestModel[3].world = OPmat4Translate(0,0,7);
	mainGame.TestModel[4].world = OPmat4Translate(7,7,-7);
	mainGame.TestModel[5].world = OPmat4Translate(14,14,-14);

	mainGame.SimpleModelEffect = OPeffectGen(
		"SimpleModel.vert", 
		"SimpleModel.frag", 
		OPATTR_POSITION | OPATTR_COLOR, 
		"Colored Effect", 
		mainGame.TestModel[0].mesh->VertexSize);

	OPmaterialInit(&mainGame.TestMaterial, &mainGame.SimpleModelEffect);

	i32 scale = 30;

	mainGame.Camera = OPcamOrtho(
		OPvec3Create(-50.0f,50.0f,50.0f),
		OPVEC3_ZERO,
		OPVEC3_UP,
		10.0f, 200.0f,
		-OPRENDER_WIDTH / scale, OPRENDER_WIDTH / scale, -OPRENDER_HEIGHT / scale, OPRENDER_HEIGHT / scale
		);

	mainGame.Camera = OPcamPersp(
		OPvec3Create(-50.0f,50.0f,50.0f),
		OPVEC3_UP,
		OPVEC3_UP,
		1.0f,
		100.0f,
		45.0f,
		OPRENDER_WIDTH / (f32)OPRENDER_HEIGHT
		);

	OPrenderDepth(1);
	OPrenderDepthWrite(1);
	OPrenderCull(0);
}

OPint MainGameStateUpdate(OPtimer* timer) {
    mainGame.player1.Position += OPvec3Create(0.5, 0, 0.5) * OPgamePadLeftThumbX(mainGame.gamePad1);
    mainGame.player1.Position += OPvec3Create(0.5, 0, -0.5) * OPgamePadLeftThumbY(mainGame.gamePad1);
    mainGame.player1.Position += OPvec3Create(-0.5, 0, -0.5) * OPkeyboardIsDown(OPKEY_A);
    mainGame.player1.Position += OPvec3Create(0.5, 0, -0.5) * OPkeyboardIsDown(OPKEY_W);
    mainGame.player1.Position += OPvec3Create(0.5, 0, 0.5) * OPkeyboardIsDown(OPKEY_D);
    mainGame.player1.Position += OPvec3Create(-0.5, 0, 0.5) * OPkeyboardIsDown(OPKEY_S);
    mainGame.player1.Position.y += OPgamePadRightThumbY(mainGame.gamePad1);
    mainGame.player1.Position.y += OPkeyboardIsDown(OPKEY_SPACE);
    mainGame.player1.Position.y -= OPkeyboardIsDown(OPKEY_LSHIFT);
	mainGame.player1.Model.world = OPmat4Translate(mainGame.player1.Position) * OPmat4Scl(3.5f) * OPmat4Translate(0.5, 0.5, 0.5);

	mainGame.Camera._pos += OPvec3Create(0.25, 0, 0.25) * OPgamePadLeftThumbX(mainGame.gamePad1);
    mainGame.Camera._pos += OPvec3Create(0.25, 0, -0.25) * OPgamePadLeftThumbY(mainGame.gamePad1);
    mainGame.Camera._pos += OPvec3Create(-0.25, 0, -0.25) * OPkeyboardIsDown(OPKEY_A);
    mainGame.Camera._pos += OPvec3Create(0.25, 0, -0.25) * OPkeyboardIsDown(OPKEY_W);
    mainGame.Camera._pos += OPvec3Create(0.25, 0, 0.25) * OPkeyboardIsDown(OPKEY_D);
    mainGame.Camera._pos += OPvec3Create(-0.25, 0, 0.25) * OPkeyboardIsDown(OPKEY_S);
    mainGame.Camera._targ += OPvec3Create(0.5, 0, 0.5) * OPgamePadLeftThumbX(mainGame.gamePad1);
    mainGame.Camera._targ += OPvec3Create(0.5, 0, -0.5) * OPgamePadLeftThumbY(mainGame.gamePad1);
    mainGame.Camera._targ += OPvec3Create(-0.5, 0, -0.5) * OPkeyboardIsDown(OPKEY_A);
    mainGame.Camera._targ += OPvec3Create(0.5, 0, -0.5) * OPkeyboardIsDown(OPKEY_W);
    mainGame.Camera._targ += OPvec3Create(0.5, 0, 0.5) * OPkeyboardIsDown(OPKEY_D);
    mainGame.Camera._targ += OPvec3Create(-0.5, 0, 0.5) * OPkeyboardIsDown(OPKEY_S);
    mainGame.Camera._viewStale = 1;

	OPrenderClear(COLORS[C_4_1_LIGHT_BLUE]);

	OPtexture2DRender(mainGame.bg);
	OPrenderCull(0);
	OPrenderDepth(1);

	for(OPint i = 0; i < OPvectorSize(mainGame.voxelVector); i++) {
		VoxelMesh* voxelMesh = (VoxelMesh*)OPvectorGet(mainGame.voxelVector, i);
		OPmodelDraw(voxelMesh->model, &mainGame.TestMaterial, mainGame.Camera);		
	}

	for(OPint i = 0; i < MODEL_COUNT; i++) {
		//OPmodelDraw(mainGame.TestModel[i], &mainGame.TestMaterial, mainGame.Camera);
	}	

	OPmodelDraw(mainGame.player1.Model, &mainGame.TestMaterial, mainGame.Camera);
	

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