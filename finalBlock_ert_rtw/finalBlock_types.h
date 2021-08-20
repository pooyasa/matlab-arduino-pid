/*
 * File: finalBlock_types.h
 *
 * Code generated for Simulink model 'finalBlock'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Jan 23 14:11:09 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_finalBlock_types_h_
#define RTW_HEADER_finalBlock_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Custom Type definition for MATLABSystem: '<S2>/PWM' */
#include "MW_SVD.h"
#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} codertarget_arduinobase_block_T;

#endif                                 /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_cell_finalBlock_T
#define typedef_cell_finalBlock_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} cell_finalBlock_T;

#endif                                 /*typedef_cell_finalBlock_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_finalBlock_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_g_T
#define typedef_codertarget_arduinobase_int_g_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
} codertarget_arduinobase_int_g_T;

#endif                                 /*typedef_codertarget_arduinobase_int_g_T*/

/* Parameters (default storage) */
typedef struct P_finalBlock_T_ P_finalBlock_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_finalBlock_T RT_MODEL_finalBlock_T;

#endif                                 /* RTW_HEADER_finalBlock_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
