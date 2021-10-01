
{REDUND_ERROR} FUNCTION_BLOCK FB_Motor (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL; (*������� ���������� [B]*)
	END_VAR
	VAR_OUTPUT
		w : REAL; (*������� �������� [��/���]*)
		phi : REAL; (*��������� [���]*)
	END_VAR
	VAR
		integrator : FB_Integrator; (*����������*)
		Tm : REAL; (*������������������� ���������� ������� [�]*)
		ke : REAL; (*���������� ��� ��������� [�*���/��]*)
		dt : REAL; (*��� ������� [�]*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Regulator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL; (*��������������� ����� �������� ������������ � �������� ��������� �������� ���� ��� [��/���]*)
	END_VAR
	VAR_OUTPUT
		u : REAL; (*����������, ���������� �� ���� ��� [B]*)
	END_VAR
	VAR
		k_p : REAL; (*���������������� ����������� ����������*)
		k_i : REAL; (*������������ ����������� ����������*)
		integrator : FB_Integrator; (*����������*)
		ivOld : REAL; (*�������� ����������� �������� ����� �����������������*)
		max_abs_value : REAL; (*������� ����� ����������� [�]*)
		dt : REAL; (*��� ������� [c]*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Integrator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL; (*���� �������������� �����*)
	END_VAR
	VAR_OUTPUT
		out : REAL; (*����� �������������� �����*)
	END_VAR
	VAR
		dt : REAL; (*��� ������� [c]*)
	END_VAR
END_FUNCTION_BLOCK
