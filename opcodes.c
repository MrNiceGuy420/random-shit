#include "stdafx.h"
//include CLEO header
#include "CLEO.h"

#define OPCODE_INTOP_AND			0x0B10
#define OPCODE_INTOP_OR			0x0B11
#define OPCODE_INTOP_XOR			0x0B12
#define OPCODE_INTOP_NOT			0x0B13
#define OPCODE_INTOP_MOD			0x0B14
#define OPCODE_INTOP_SHR			0x0B15
#define OPCODE_INTOP_SHL			0x0B16
#define SCR_INTOP_AND		 	0x0B17
#define SCR_INTOP_OR				0x0B18
#define SCR_INTOP_XOR			0x0B19
#define SCR_INTOP_NOT			0x0B1A
#define SCR_INTOP_MOD			0x0B1B
#define SCR_INTOP_SHR			0x0B1C
#define SCR_INTOP_SHL			0x0B1D

OpcodeResult WINAPI Script_IntOp_AND(CScriptThread* thread);
OpcodeResult WINAPI Script_IntOp_OR (CScriptThread* thread);
OpcodeResult WINAPI Script_IntOp_XOR(CScriptThread* thread);
OpcodeResult WINAPI Script_IntOp_NOT(CScriptThread* thread);
OpcodeResult WINAPI Script_IntOp_MOD(CScriptThread* thread);
OpcodeResult WINAPI Script_IntOp_SHR(CScriptThread* thread);
OpcodeResult WINAPI Script_IntOp_SHL(CScriptThread* thread);

OpcodeResult WINAPI Scr_IntOp_AND(CScriptThread* thread);
OpcodeResult WINAPI Scr_IntOp_OR (CScriptThread* thread);
OpcodeResult WINAPI Scr_IntOp_XOR(CScriptThread* thread);
OpcodeResult WINAPI Scr_IntOp_NOT(CScriptThread* thread);
OpcodeResult WINAPI Scr_IntOp_MOD(CScriptThread* thread);
OpcodeResult WINAPI Scr_IntOp_SHR(CScriptThread* thread);
OpcodeResult WINAPI Scr_IntOp_SHL(CScriptThread* thread);

BOOL InitOpcodes()
{
	BOOL result = FALSE;

	//check cleo version
	if (CLEO_GetVersion() < CLEO_VERSION)
	{	
		MessageBox(HWND_DESKTOP, "An incorrect version of CLEO was loaded.", "IntOpearations.cleo", MB_ICONERROR);
		return FALSE;
	}

	//register opcodes
	if (CLEO_RegisterOpcode(OPCODE_INTOP_AND, &Script_IntOp_AND)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(OPCODE_INTOP_OR,  &Script_IntOp_OR )) 
		result = TRUE;
	if (CLEO_RegisterOpcode(OPCODE_INTOP_XOR, &Script_IntOp_XOR)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(OPCODE_INTOP_NOT, &Script_IntOp_NOT)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(OPCODE_INTOP_MOD, &Script_IntOp_MOD)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(OPCODE_INTOP_SHR, &Script_IntOp_SHR)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(OPCODE_INTOP_SHL, &Script_IntOp_SHL)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(SCR_INTOP_AND, &Scr_IntOp_AND)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(SCR_INTOP_OR,  &Scr_IntOp_OR )) 
		result = TRUE;
	if (CLEO_RegisterOpcode(SCR_INTOP_XOR, &Scr_IntOp_XOR)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(SCR_INTOP_NOT, &Scr_IntOp_NOT)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(SCR_INTOP_MOD, &Scr_IntOp_MOD)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(SCR_INTOP_SHR, &Scr_IntOp_SHR)) 
		result = TRUE;
	if (CLEO_RegisterOpcode(SCR_INTOP_SHL, &Scr_IntOp_SHL)) 
		result = TRUE;

	return result;
}

OpcodeResult WINAPI Script_IntOp_AND(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B10=3,%3d% = %1d% AND %2d%
****************************************************************/
{
	int a = CLEO_GetIntOpcodeParam(thread);
	int b = CLEO_GetIntOpcodeParam(thread);

	CLEO_SetIntOpcodeParam(thread, a & b);

	return OR_CONTINUE;
}

OpcodeResult WINAPI Script_IntOp_OR(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B11=3,%3d% = %1d% OR %2d%
****************************************************************/
{
	int a = CLEO_GetIntOpcodeParam(thread);
	int b = CLEO_GetIntOpcodeParam(thread);

	CLEO_SetIntOpcodeParam(thread, a | b);

	return OR_CONTINUE;
}

OpcodeResult WINAPI Script_IntOp_XOR(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B12=3,%3d% = %1d% XOR %2d%
****************************************************************/
{
	int a = CLEO_GetIntOpcodeParam(thread);
	int b = CLEO_GetIntOpcodeParam(thread);

	CLEO_SetIntOpcodeParam(thread, a ^ b);

	return OR_CONTINUE;
}

OpcodeResult WINAPI Script_IntOp_NOT(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B13=2,%2d% = NOT %1d%
****************************************************************/
{
	int a = CLEO_GetIntOpcodeParam(thread);

	CLEO_SetIntOpcodeParam(thread, ~a);

	return OR_CONTINUE;
}

OpcodeResult WINAPI Script_IntOp_MOD(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B14=3,%3d% = %1d% MOD %2d%
****************************************************************/
{
	int a = CLEO_GetIntOpcodeParam(thread);
	int b = CLEO_GetIntOpcodeParam(thread);

	CLEO_SetIntOpcodeParam(thread, a % b);

	return OR_CONTINUE;
}

OpcodeResult WINAPI Script_IntOp_SHR(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B15=3,%3d% = %1d% SHR %2d%
****************************************************************/
{
	int a = CLEO_GetIntOpcodeParam(thread);
	int b = CLEO_GetIntOpcodeParam(thread);

	CLEO_SetIntOpcodeParam(thread, a >> b);

	return OR_CONTINUE;
}

OpcodeResult WINAPI Script_IntOp_SHL(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B16=3,%3d% = %1d% SHL %2d%
****************************************************************/
{
	int a = CLEO_GetIntOpcodeParam(thread);
	int b = CLEO_GetIntOpcodeParam(thread);

	CLEO_SetIntOpcodeParam(thread, a << b);

	return OR_CONTINUE;
}

/****************************************************************
Now do them as real operators...
*****************************************************************/

OpcodeResult WINAPI Scr_IntOp_AND(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B17=2,%1d% &= %2d%
****************************************************************/
{
	SCRIPT_VAR * op = CLEO_GetPointerToScriptVariable(thread);
	int val = CLEO_GetIntOpcodeParam(thread);
	op->dwParam &= val;
	return OR_CONTINUE;
}

OpcodeResult WINAPI Scr_IntOp_OR(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B18=2,%1d% |= %2d%
****************************************************************/
{
	SCRIPT_VAR * op = CLEO_GetPointerToScriptVariable(thread);
	int val = CLEO_GetIntOpcodeParam(thread);
	op->dwParam |= val;
	return OR_CONTINUE;
}

OpcodeResult WINAPI Scr_IntOp_XOR(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B19=2,%1d% ^= %2d%
****************************************************************/
{
	SCRIPT_VAR * op = CLEO_GetPointerToScriptVariable(thread);
	int val = CLEO_GetIntOpcodeParam(thread);
	op->dwParam ^= val;
	return OR_CONTINUE;
}

OpcodeResult WINAPI Scr_IntOp_NOT(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B1A=1,~%1d%
****************************************************************/
{
	SCRIPT_VAR * op = CLEO_GetPointerToScriptVariable(thread);
	op->dwParam = ~op->dwParam;
	return OR_CONTINUE;
}

OpcodeResult WINAPI Scr_IntOp_MOD(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B1B=2,%1d% %= %2d%
****************************************************************/
{
	SCRIPT_VAR * op = CLEO_GetPointerToScriptVariable(thread);
	int val = CLEO_GetIntOpcodeParam(thread);
	op->dwParam %= val;
	return OR_CONTINUE;
}

OpcodeResult WINAPI Scr_IntOp_SHR(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B1C=3,%1d% >>= %2d%
****************************************************************/
{
	SCRIPT_VAR * op = CLEO_GetPointerToScriptVariable(thread);
	int val = CLEO_GetIntOpcodeParam(thread);
	op->dwParam >>= val;
	return OR_CONTINUE;
}

OpcodeResult WINAPI Scr_IntOp_SHL(CScriptThread* thread)
/****************************************************************
						Opcode Format
0B1D=3,%1d% <<= %2d%
****************************************************************/
{
	SCRIPT_VAR * op = CLEO_GetPointerToScriptVariable(thread);
	int val = CLEO_GetIntOpcodeParam(thread);
	op->dwParam <<= val;
	return OR_CONTINUE;
}
