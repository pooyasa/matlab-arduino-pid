/*
 * File: finalBlock_private.h
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

#ifndef RTW_HEADER_finalBlock_private_h_
#define RTW_HEADER_finalBlock_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void arduinoFinalCode_Start_wrapper(real_T *xD);
  extern void arduinoFinalCode_Outputs_wrapper(real_T *xAngle,
    const real_T *xD);
  extern void arduinoFinalCode_Update_wrapper(real_T *xAngle,
    real_T *xD);
  extern void arduinoFinalCode_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

/* private model entry point functions */
extern void finalBlock_derivatives(void);

#endif                                 /* RTW_HEADER_finalBlock_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
