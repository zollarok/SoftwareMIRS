/********************************************************************
 * COPYRIGHT -- Microsoft
 ********************************************************************
 * Library: X64Lib
 * File: FBX64Inverter.c
 * Author: chuh
 * Created: April 02, 2015
 ********************************************************************
 * Implementation of library X64Lib
 ********************************************************************/

#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif

	#include "X64Lib.h"

#ifdef __cplusplus
	};
#endif

//***************���������� ������ ��������� ����������  ********************
#define	ACPIX64_STATE_NOT_READY_TO_SWITCH_ON	0x0000 /* */
#define	ACPIX64_STATE_SWITCH_ON_DISABLED		0x0040 /* */
#define	ACPIX64_STATE_READY_TO_SWITCH_ON		0x0064 /* */
#define	ACPIX64_STATE_SWITCHED_ON				0x0021 /* */
#define	ACPIX64_STATE_OPERATION_ENABLED			0x0027 /* */
#define	ACPIX64_STATE_QUICK_STOP_ACTIVE			0x0007/* */
#define	ACPIX64_STATE_MALFUNCTION				0x0008/* */

#define	ACPIX64_CMD_DISABLE_VOLTAGE				0x0000/* */
#define	ACPIX64_CMD_SHUTDOWN					0x0006/* */
#define	ACPIX64_CMD_SWITCH_ON					0x0006/* */
#define	ACPIX64_CMD_ENABLE_OPERATION			0x000F/* */
#define ACPIX64_CMD_GO                          0x0007
#define	ACPIX64_CMD_FAULT_RESET					0x0080/* */

/* X64 Acopos Inverter Control Lib */
void FBX64Inverter(struct FBX64Inverter* inst)
{
	UINT MSK;			//���������� ��� �������� ����� ����� ��������� �����
	MSK = inst->ETAD_Input & 0x006F;
	inst->mask = MSK;/* */ // ����� �� �������� ���������� ������� ����������
	if(!inst->enable){
		inst->CMDD_Output = ACPIX64_CMD_DISABLE_VOLTAGE;		//	 ��������� ������� � ��������� ������
	} else {
		switch(MSK)
		{
			case ACPIX64_STATE_SWITCH_ON_DISABLED:		inst->CMDD_Output = ACPIX64_CMD_SHUTDOWN;				break;
			case ACPIX64_STATE_READY_TO_SWITCH_ON:		inst->CMDD_Output = ACPIX64_CMD_SWITCH_ON;				break;
			case ACPIX64_STATE_SWITCHED_ON:				inst->CMDD_Output = ACPIX64_CMD_ENABLE_OPERATION;		break;
		}
	}	
}	