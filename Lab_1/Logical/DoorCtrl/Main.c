
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	Open  = 0;
	Close = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	Speed = DoorBlock.Speed;
	DoorBlock.DriveBlk.ETAD_Input = ETAD;
	CMD = DoorBlock.DriveBlk.CMDD_Output;
	if (Open == 1){
		DoorBlock.direction = 1;
	}
	if (Close == 1) {
		DoorBlock.direction = 0;
	}
	FBGate(&DoorBlock);
	if ((DoorBlock.State == ST_OPEN) || (DoorBlock.State == ST_CLOSE)){
		Open  = 0;
		Close = 0;
	}
	LedBlock.State = DoorBlock.State;
	FBLed(&LedBlock);
	sw0 = LedBlock.s1;
	sw1 = LedBlock.s2;
	sw2 = LedBlock.s3;
	sw3 = LedBlock.s4;
	
}

void _EXIT ProgramExit(void)
{

}

