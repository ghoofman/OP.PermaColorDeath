//////////////////////////////////////
// Application Entry Point
//////////////////////////////////////

#include "./OPengine.h"
#include "./src/MainGameState.h"

//////////////////////////////////////
// Application Methods
//////////////////////////////////////

void ApplicationInit() {
	OPloadersAddDefault();
	OPcmanInit(OPIFEX_ASSETS);

	OPrenderInit();

	OPgamePadSetDeadzones(0.15);

	OPgameStateChange(&GS_MAIN);
}

int ApplicationUpdate(OPtimer* timer) {
	OPcmanUpdate(timer);
	OPinputSystemUpdate(timer);

	if (OPkeyboardWasPressed(OPKEY_ESCAPE)) return 1;

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