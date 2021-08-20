/*
 * File: finalBlock_data.c
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

#include "finalBlock.h"
#include "finalBlock_private.h"

/* Block parameters (default storage) */
P_finalBlock_T finalBlock_P = {
  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S1>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S1>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S1>/Filter Coefficient'
   */
  10.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S1>/Proportional Gain'
   */
  50.0,

  /* Expression: 2
   * Referenced by: '<Root>/Step'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<Root>/Step'
   */
  45.0,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: InitialConditionForFilter
   * Referenced by: '<S1>/Filter'
   */
  0.0,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S2>/Saturation'
   */
  255,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S2>/Saturation'
   */
  -255,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S2>/Constant4'
   */
  0,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S2>/Constant3'
   */
  1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
