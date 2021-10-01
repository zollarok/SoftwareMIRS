
{REDUND_ERROR} FUNCTION_BLOCK FB_Motor (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL; (*Входное напряжение [B]*)
	END_VAR
	VAR_OUTPUT
		w : REAL; (*Частота вращения [об/мин]*)
		phi : REAL; (*Положение [рад]*)
	END_VAR
	VAR
		integrator : FB_Integrator; (*Интегратор*)
		Tm : REAL; (*Электромеханическая постоянная времени [с]*)
		ke : REAL; (*Постоянная ЭДС двигателя [В*мин/об]*)
		dt : REAL; (*Шаг расчета [с]*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Regulator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL; (*Рассогласование между задающим воздействием и реальной скоростью вращения вала ДПТ [об/мин]*)
	END_VAR
	VAR_OUTPUT
		u : REAL; (*Напряжение, подаваемое на вход ДПТ [B]*)
	END_VAR
	VAR
		k_p : REAL; (*Пропорциональный коэффициент регулятора*)
		k_i : REAL; (*Интегральный коэффициент регулятора*)
		integrator : FB_Integrator; (*Интегратор*)
		ivOld : REAL; (*Хранение предыдущего значения схемы противонакопления*)
		max_abs_value : REAL; (*Граница блока ограничения [В]*)
		dt : REAL; (*Шаг расчета [c]*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Integrator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL; (*Вход интегрирующего звена*)
	END_VAR
	VAR_OUTPUT
		out : REAL; (*Выход интегрирующего звена*)
	END_VAR
	VAR
		dt : REAL; (*Шаг расчета [c]*)
	END_VAR
END_FUNCTION_BLOCK
