/*
 * File: finalBlock.c
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
#include "finalBlock_dt.h"
#define finalBlock_PinNumber           (6.0)
#define finalBlock_PinNumber_g         (5.0)

/* Block signals (default storage) */
B_finalBlock_T finalBlock_B;

/* Continuous states */
X_finalBlock_T finalBlock_X;

/* Block states (default storage) */
DW_finalBlock_T finalBlock_DW;

/* Real-time model */
RT_MODEL_finalBlock_T finalBlock_M_;
RT_MODEL_finalBlock_T *const finalBlock_M = &finalBlock_M_;

/* Forward declaration for local functions */
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_int_g_T *obj,
  boolean_T value);
static void finalBlock_SystemCore_release(const codertarget_arduinobase_int_g_T *
  obj);
static void finalBlock_SystemCore_delete(const codertarget_arduinobase_int_g_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_g_T *obj);
static void SystemProp_matlabCodegenSetAn_g(codertarget_arduinobase_block_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCod_g(codertarget_arduinobase_block_T *obj);
static codertarget_arduinobase_int_g_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_g_T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  finalBlock_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  finalBlock_step();
  finalBlock_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  finalBlock_step();
  finalBlock_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_int_g_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S2>/PWM' */
  obj->matlabCodegenIsDeleted = value;
}

static void finalBlock_SystemCore_release(const codertarget_arduinobase_int_g_T *
  obj)
{
  /* Start for MATLABSystem: '<S2>/PWM' */
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0);
  }

  /* End of Start for MATLABSystem: '<S2>/PWM' */
}

static void finalBlock_SystemCore_delete(const codertarget_arduinobase_int_g_T
  *obj)
{
  /* Start for MATLABSystem: '<S2>/PWM' */
  finalBlock_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_g_T *obj)
{
  /* Start for MATLABSystem: '<S2>/PWM' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
    finalBlock_SystemCore_delete(obj);
  }

  /* End of Start for MATLABSystem: '<S2>/PWM' */
}

static void SystemProp_matlabCodegenSetAn_g(codertarget_arduinobase_block_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
   *  MATLABSystem: '<S4>/Digital Output'
   */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCod_g(codertarget_arduinobase_block_T *obj)
{
  /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
   *  MATLABSystem: '<S4>/Digital Output'
   */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAn_g(obj, true);
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Output' */
}

static codertarget_arduinobase_int_g_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_g_T *obj)
{
  codertarget_arduinobase_int_g_T *b_obj;

  /* Start for MATLABSystem: '<S2>/PWM' */
  obj->isInitialized = 0L;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/* Model step function */
void finalBlock_step(void)
{
  real_T rtb_Sum;
  boolean_T rtb_Direction;
  int16_T rtb_Saturation;
  real_T u0;
  if (rtmIsMajorTimeStep(finalBlock_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&finalBlock_M->solverInfo,
                          ((finalBlock_M->Timing.clockTick0+1)*
      finalBlock_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(finalBlock_M)) {
    finalBlock_M->Timing.t[0] = rtsiGetT(&finalBlock_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(finalBlock_DW.IfActionSubsystem3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(finalBlock_DW.IfActionSubsystem4_SubsysRanBC);

  /* Step: '<Root>/Step' */
  if (finalBlock_M->Timing.t[0] < finalBlock_P.Step_Time) {
    finalBlock_B.Step = finalBlock_P.Step_Y0;
  } else {
    finalBlock_B.Step = finalBlock_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
  if (rtmIsMajorTimeStep(finalBlock_M)) {
    /* S-Function (arduinoFinalCode): '<S2>/S-Function Builder1' */
    arduinoFinalCode_Outputs_wrapper(&finalBlock_B.SFunctionBuilder1,
      &finalBlock_DW.SFunctionBuilder1_DSTATE);
  }

  /* Sum: '<Root>/Sum' */
  rtb_Sum = finalBlock_B.Step - finalBlock_B.SFunctionBuilder1;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  finalBlock_B.FilterCoefficient = (finalBlock_P.PIDController1_D * rtb_Sum -
    finalBlock_X.Filter_CSTATE) * finalBlock_P.PIDController1_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Proportional Gain'
   *  Integrator: '<S1>/Integrator'
   */
  finalBlock_B.Sum = (finalBlock_P.PIDController1_P * rtb_Sum +
                      finalBlock_X.Integrator_CSTATE) +
    finalBlock_B.FilterCoefficient;
  if (rtmIsMajorTimeStep(finalBlock_M)) {
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  u0 = floor(finalBlock_B.Sum);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 65536.0);
  }

  rtb_Saturation = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)(uint16_T)u0;

  /* End of DataTypeConversion: '<S2>/Data Type Conversion1' */

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Saturation > finalBlock_P.Saturation_UpperSat) {
    rtb_Saturation = finalBlock_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < finalBlock_P.Saturation_LowerSat) {
      rtb_Saturation = finalBlock_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* If: '<S2>/If1' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Inport: '<S5>/In1'
   *  Inport: '<S6>/In1'
   */
  if (rtmIsMajorTimeStep(finalBlock_M)) {
    finalBlock_DW.If1_ActiveSubsystem = (int8_T)!(rtb_Saturation > 0);
  }

  switch (finalBlock_DW.If1_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    if (rtmIsMajorTimeStep(finalBlock_M)) {
      rtb_Direction = finalBlock_P.Constant3_Value;
    }

    if (rtmIsMajorTimeStep(finalBlock_M)) {
      srUpdateBC(finalBlock_DW.IfActionSubsystem3_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    if (rtmIsMajorTimeStep(finalBlock_M)) {
      rtb_Direction = finalBlock_P.Constant4_Value;
    }

    if (rtmIsMajorTimeStep(finalBlock_M)) {
      srUpdateBC(finalBlock_DW.IfActionSubsystem4_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem4' */
    break;
  }

  /* End of If: '<S2>/If1' */

  /* Abs: '<S2>/Abs' */
  if (rtb_Saturation < 0) {
    rtb_Saturation = -rtb_Saturation;
  }

  /* End of Abs: '<S2>/Abs' */

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (rtb_Saturation < 255.0) {
    u0 = rtb_Saturation;
  } else {
    u0 = 255.0;
  }

  if (!(u0 > 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(finalBlock_DW.obj.MW_PWM_HANDLE, u0);

  /* End of Start for MATLABSystem: '<S2>/PWM' */

  /* Gain: '<S1>/Integral Gain' */
  finalBlock_B.IntegralGain = finalBlock_P.PIDController1_I * rtb_Sum;
  if (rtmIsMajorTimeStep(finalBlock_M)) {
    /* Start for MATLABSystem: '<S4>/Digital Output' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     *  S-Function (sfix_bitop): '<S2>/Bitwise Operator'
     */
    writeDigitalPin((uint8_T)finalBlock_PinNumber_g, (uint8_T)!rtb_Direction);

    /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion'
     */
    writeDigitalPin((uint8_T)finalBlock_PinNumber, (uint8_T)rtb_Direction);
  }

  if (rtmIsMajorTimeStep(finalBlock_M)) {
    if (rtmIsMajorTimeStep(finalBlock_M)) {
      /* Update for S-Function (arduinoFinalCode): '<S2>/S-Function Builder1' */

      /* S-Function "arduinoFinalCode_wrapper" Block: <S2>/S-Function Builder1 */
      arduinoFinalCode_Update_wrapper(&finalBlock_B.SFunctionBuilder1,
        &finalBlock_DW.SFunctionBuilder1_DSTATE);
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, finalBlock_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(finalBlock_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, ((finalBlock_M->Timing.clockTick1) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(finalBlock_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(finalBlock_M)!=-1) &&
          !((rtmGetTFinal(finalBlock_M)-((finalBlock_M->Timing.clockTick1) *
             0.002)) > ((finalBlock_M->Timing.clockTick1) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(finalBlock_M, "Simulation finished");
      }

      if (rtmGetStopRequested(finalBlock_M)) {
        rtmSetErrorStatus(finalBlock_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&finalBlock_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++finalBlock_M->Timing.clockTick0;
    finalBlock_M->Timing.t[0] = rtsiGetSolverStopTime(&finalBlock_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      finalBlock_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void finalBlock_derivatives(void)
{
  XDot_finalBlock_T *_rtXdot;
  _rtXdot = ((XDot_finalBlock_T *) finalBlock_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = finalBlock_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = finalBlock_B.FilterCoefficient;
}

/* Model initialize function */
void finalBlock_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)finalBlock_M, 0,
                sizeof(RT_MODEL_finalBlock_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&finalBlock_M->solverInfo,
                          &finalBlock_M->Timing.simTimeStep);
    rtsiSetTPtr(&finalBlock_M->solverInfo, &rtmGetTPtr(finalBlock_M));
    rtsiSetStepSizePtr(&finalBlock_M->solverInfo,
                       &finalBlock_M->Timing.stepSize0);
    rtsiSetdXPtr(&finalBlock_M->solverInfo, &finalBlock_M->derivs);
    rtsiSetContStatesPtr(&finalBlock_M->solverInfo, (real_T **)
                         &finalBlock_M->contStates);
    rtsiSetNumContStatesPtr(&finalBlock_M->solverInfo,
      &finalBlock_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&finalBlock_M->solverInfo,
      &finalBlock_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&finalBlock_M->solverInfo,
      &finalBlock_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&finalBlock_M->solverInfo,
      &finalBlock_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&finalBlock_M->solverInfo, (&rtmGetErrorStatus
      (finalBlock_M)));
    rtsiSetRTModelPtr(&finalBlock_M->solverInfo, finalBlock_M);
  }

  rtsiSetSimTimeStep(&finalBlock_M->solverInfo, MAJOR_TIME_STEP);
  finalBlock_M->intgData.y = finalBlock_M->odeY;
  finalBlock_M->intgData.f[0] = finalBlock_M->odeF[0];
  finalBlock_M->intgData.f[1] = finalBlock_M->odeF[1];
  finalBlock_M->intgData.f[2] = finalBlock_M->odeF[2];
  finalBlock_M->contStates = ((X_finalBlock_T *) &finalBlock_X);
  rtsiSetSolverData(&finalBlock_M->solverInfo, (void *)&finalBlock_M->intgData);
  rtsiSetSolverName(&finalBlock_M->solverInfo,"ode3");
  rtmSetTPtr(finalBlock_M, &finalBlock_M->Timing.tArray[0]);
  rtmSetTFinal(finalBlock_M, -1);
  finalBlock_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  finalBlock_M->Sizes.checksums[0] = (2934836113U);
  finalBlock_M->Sizes.checksums[1] = (3197413141U);
  finalBlock_M->Sizes.checksums[2] = (3703122355U);
  finalBlock_M->Sizes.checksums[3] = (212578765U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    finalBlock_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&finalBlock_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&finalBlock_DW.IfActionSubsystem4_SubsysRanBC;
    rteiSetModelMappingInfoPtr(finalBlock_M->extModeInfo,
      &finalBlock_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(finalBlock_M->extModeInfo, finalBlock_M->Sizes.checksums);
    rteiSetTPtr(finalBlock_M->extModeInfo, rtmGetTPtr(finalBlock_M));
  }

  /* block I/O */
  (void) memset(((void *) &finalBlock_B), 0,
                sizeof(B_finalBlock_T));

  /* states (continuous) */
  {
    (void) memset((void *)&finalBlock_X, 0,
                  sizeof(X_finalBlock_T));
  }

  /* states (dwork) */
  (void) memset((void *)&finalBlock_DW, 0,
                sizeof(DW_finalBlock_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    finalBlock_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_int_g_T *obj;

    /* Start for If: '<S2>/If1' */
    finalBlock_DW.If1_ActiveSubsystem = -1;

    /* Start for MATLABSystem: '<S2>/PWM' */
    finalBlock_DW.obj.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&finalBlock_DW.obj);
    obj = &finalBlock_DW.obj;
    finalBlock_DW.obj.isSetupComplete = false;
    finalBlock_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(7UL, 0.0, 0.0);
    MW_PWM_Start(finalBlock_DW.obj.MW_PWM_HANDLE);
    finalBlock_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    finalBlock_DW.obj_k.matlabCodegenIsDeleted = true;
    finalBlock_DW.obj_k.isInitialized = 0L;
    finalBlock_DW.obj_k.matlabCodegenIsDeleted = false;
    finalBlock_DW.obj_k.isSetupComplete = false;
    finalBlock_DW.obj_k.isInitialized = 1L;
    digitalIOSetup((uint8_T)finalBlock_PinNumber_g, true);
    finalBlock_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    finalBlock_DW.obj_j.matlabCodegenIsDeleted = true;
    finalBlock_DW.obj_j.isInitialized = 0L;
    finalBlock_DW.obj_j.matlabCodegenIsDeleted = false;
    finalBlock_DW.obj_j.isSetupComplete = false;
    finalBlock_DW.obj_j.isInitialized = 1L;
    digitalIOSetup((uint8_T)finalBlock_PinNumber, true);
    finalBlock_DW.obj_j.isSetupComplete = true;

    /* InitializeConditions for S-Function (arduinoFinalCode): '<S2>/S-Function Builder1' */

    /* S-Function Block: <S2>/S-Function Builder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          finalBlock_DW.SFunctionBuilder1_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    finalBlock_X.Integrator_CSTATE = finalBlock_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S1>/Filter' */
    finalBlock_X.Filter_CSTATE = finalBlock_P.Filter_IC;
  }
}

/* Model terminate function */
void finalBlock_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  matlabCodegenHandle_matlabCodeg(&finalBlock_DW.obj);

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  matlabCodegenHandle_matlabCod_g(&finalBlock_DW.obj_k);

  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  matlabCodegenHandle_matlabCod_g(&finalBlock_DW.obj_j);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
