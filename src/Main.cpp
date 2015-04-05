//////////////////////////////////////
// Application Entry Point
//////////////////////////////////////

#include "./OPengine.h"
#include "./src/MainGameState.h"
#include "./Pipeline/include/Loaders/OPloaderVoxels.h"

//////////////////////////////////////
// Application Methods
//////////////////////////////////////


OPgamePad* playerOne;

void ApplicationInit() {
	OPloadersAddDefault();
	OPcmanAddLoader(OPvoxelsLoader());
	OPcmanInit(OPIFEX_ASSETS);

	OPrenderInit();

	OPgamePadSetDeadzones(0.15);
	playerOne = OPgamePadGet(OPGAMEPAD_ONE);

	OPint present = glfwJoystickPresent(GLFW_JOYSTICK_1);
	OPlog("Joystick %d", present);

	OPgameStateChange(&GS_MAIN);
}

int ApplicationUpdate(OPtimer* timer) {
	OPcmanUpdate(timer);
	OPinputSystemUpdate(timer);

	if (OPkeyboardWasPressed(OPKEY_ESCAPE) || OPgamePadIsDown(playerOne, OPGAMEPADBUTTON_BACK)) return 1;

	return ActiveState->Update(timer);
}

void ApplicationDestroy() {
	ActiveState->Exit(NULL);
}

//////////////////////////////////////
// Application Entry Point
//////////////////////////////////////

OP_MAIN {
	OPlog("Starting up OPengine");

	OPinitialize = ApplicationInit;
	OPupdate = ApplicationUpdate;
	OPdestroy = ApplicationDestroy;

	OP_MAIN_START
	OP_MAIN_END
	OP_MAIN_SUCCESS
}