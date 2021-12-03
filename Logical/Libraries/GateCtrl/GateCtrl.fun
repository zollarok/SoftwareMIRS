
FUNCTION_BLOCK FBLed
	VAR_OUTPUT
		s1 : BOOL;
		s2 : BOOL;
		s3 : BOOL;
		s4 : BOOL;
	END_VAR
	VAR_INPUT
		State : {REDUND_UNREPLICABLE} GateState;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FBGate (* *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		sw0 : BOOL; (*инпут датчиков*)
		sw1 : BOOL;
		sw2 : BOOL;
		sw3 : BOOL;
		State : {REDUND_UNREPLICABLE} GateState;
		direction : BOOL;
	END_VAR
	VAR_OUTPUT
		Speed : INT;
	END_VAR
	VAR
		DriveBlk : FBX64Inverter;
	END_VAR
END_FUNCTION_BLOCK
