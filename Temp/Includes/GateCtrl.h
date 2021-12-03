/* Automation Studio generated header file */
/* Do not edit ! */
/* GateCtrl  */

#ifndef _GATECTRL_
#define _GATECTRL_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG4
		#include "X64Lib.h"
#endif
#ifdef _SG3
		#include "X64Lib.h"
#endif
#ifdef _SGC
		#include "X64Lib.h"
#endif

/* Datatypes and datatypes of function blocks */
typedef enum GateState
{	ST_INIT = 0,
	ST_UNKNOWN = 1,
	ST_OPEN = 2,
	ST_CLOSE = 3,
	ST_ACC_POS = 4,
	ST_ACC_NEG = 5,
	ST_POS = 6,
	ST_NEG = 7,
	ST_DEC_POS = 8,
	ST_DEC_NEG = 9
} GateState;

typedef struct FBLed
{
	/* VAR_INPUT (analog) */
	enum GateState State;
	/* VAR_OUTPUT (digital) */
	plcbit s1;
	plcbit s2;
	plcbit s3;
	plcbit s4;
} FBLed_typ;

typedef struct FBGate
{
	/* VAR_INPUT (analog) */
	enum GateState State;
	/* VAR_OUTPUT (analog) */
	signed short Speed;
	/* VAR (analog) */
	struct FBX64Inverter DriveBlk;
	/* VAR_INPUT (digital) */
	plcbit sw0;
	plcbit sw1;
	plcbit sw2;
	plcbit sw3;
	plcbit direction;
} FBGate_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FBLed(struct FBLed* inst);
_BUR_PUBLIC void FBGate(struct FBGate* inst);


#ifdef __cplusplus
};
#endif
#endif /* _GATECTRL_ */

