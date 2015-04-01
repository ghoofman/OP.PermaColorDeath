#include "./src/MainGameState.h"

void MainGameStateInit(OPgameState* last) {

}

OPint MainGameStateUpdate(OPtimer* timer) {
	OPrenderClear(0,0,0);
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