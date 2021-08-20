/*
 * finalBlock_dt.h
 *
 * Code generation for model "finalBlock".
 *
 * Model version              : 1.68
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Thu Jan 23 14:11:09 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_arduinobase_block_T),
  sizeof(codertarget_arduinobase_int_g_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_arduinobase_block_T",
  "codertarget_arduinobase_int_g_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&finalBlock_B.Step), 0, 0, 5 }
  ,

  { (char_T *)(&finalBlock_DW.obj), 15, 0, 1 },

  { (char_T *)(&finalBlock_DW.obj_k), 14, 0, 2 },

  { (char_T *)(&finalBlock_DW.SFunctionBuilder1_DSTATE), 0, 0, 1 },

  { (char_T *)(&finalBlock_DW.ToWorkspace3_PWORK.LoggedData), 11, 0, 5 },

  { (char_T *)(&finalBlock_DW.If1_ActiveSubsystem), 2, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&finalBlock_P.PIDController1_D), 0, 0, 9 },

  { (char_T *)(&finalBlock_P.Saturation_UpperSat), 4, 0, 2 },

  { (char_T *)(&finalBlock_P.Constant4_Value), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] finalBlock_dt.h */
