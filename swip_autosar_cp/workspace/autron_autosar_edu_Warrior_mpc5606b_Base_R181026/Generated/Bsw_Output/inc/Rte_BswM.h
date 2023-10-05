
/*******************************************************************************
**  FILE-NAME: Rte_BswM.h                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR RTE GENERATION TOOL                                  **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 4.4.2                                                   **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\ECUCD_EcucValueCollection.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Com.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Det.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_EcuC.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Os.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Rte.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Adc.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_BswM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Can.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_CanIf.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_CanSM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_CanTp.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Com.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_ComM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Crc.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Dcm.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Dem.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Det.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Dio.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Fee.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_FiM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Fls.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Gpt.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Icu_43.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Mcu.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_MemIf.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_NvM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Os.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_PduR.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Port.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Pwm_43.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Spi.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Wdg_43.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Composition\EcuExtract.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\DBImport\Project.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\DataTypes\AUTOSAR_DataTypes.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\DataTypes\AUTOSAR_DataTypes_Etc.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_ComM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_Dcm.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_Dem.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_FiM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_Mode.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_WdgM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\MODE_PortInterfaces.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_Bsw_BswM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_ComM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_Det.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_FiM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_EcuM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_IoHwAb.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_WdgIf.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_WdgM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_Dcm.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_Dem.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_EcuM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_NvM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_IoHwAb.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_WdgM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Static_Code\Modules\b_autosar_swc_ErrorManagement\App_ErrM.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Static_Code\Modules\b_autosar_sys_EcuM_R40\generator\EcuM_PortInterface.arxml
 *      C:\mobilgene\workspace\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Static_Code\Modules\b_autosar_sys_WdgM_R40\generator\Swcd_WdgM_Fixed.arxml

 * GENERATED ON:  This timestamp is removed.
*/

/*******************************************************************************
* PRE-JUSTIFICATION BEGINE SECTION (MISRA-C RULE CHECKER)
* These rules will not be applied for verification based on the MISRA Rule
* in Rte generated source
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
  polyspace:begin<MISRA-C:19.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1154, #6713)
  polyspace:begin<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)
*/

/*******************************************************************************
**                         MULTIPLE INCLUSION PROTECTION                      **
*******************************************************************************/
 #ifndef RTE_BSWM_H
      #define RTE_BSWM_H
 /*
  * CAUTION:
  *
  * Do NOT
  *
  *   #define RTE_ALLOW_CROSS_HEADER_INCLUSION
  *
  * in ASW/BSW code. The symbol shall be used only for RTE internally.
  */
 #ifndef RTE_ALLOW_CROSS_HEADER_INCLUSION
      #ifdef RTE_APPLICATION_HEADER_FILE
      #error Multiple application header files included.
      #endif
      #define RTE_APPLICATION_HEADER_FILE
      #endif

/*******************************************************************************
**                  Include Section                                           **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */
#include "Rte_BswM_Type.h"

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
 extern "C"
 {
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#ifdef RTE_VENDOR_ID
  #if (RTE_VENDOR_ID != 76)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Vendor Id"
  #endif
#else
  #define RTE_VENDOR_ID 76
#endif

#ifdef RTE_MODULE_ID
  #if (RTE_MODULE_ID != 2)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Module Id"
  #endif
#else
  #define RTE_MODULE_ID 2
#endif

#ifdef RTE_SW_MAJOR_VERSION
  #if (RTE_SW_MAJOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Major Version"
  #endif
#else
  #define RTE_SW_MAJOR_VERSION 4
#endif

#ifdef RTE_SW_MINOR_VERSION
  #if (RTE_SW_MINOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Minor Version"
  #endif
#else
  #define RTE_SW_MINOR_VERSION 4
#endif

#ifdef RTE_SW_PATCH_VERSION
  #if (RTE_SW_PATCH_VERSION != 2)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Patch Version"
  #endif
#else
  #define RTE_SW_PATCH_VERSION 2
#endif

#ifdef RTE_AR_RELEASE_MAJOR_VERSION
  #if (RTE_AR_RELEASE_MAJOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Major Version"
  #endif
#else
  #define RTE_AR_RELEASE_MAJOR_VERSION 4
#endif

#ifdef RTE_AR_RELEASE_MINOR_VERSION
  #if (RTE_AR_RELEASE_MINOR_VERSION != 0)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Minor Version"
  #endif
#else
  #define RTE_AR_RELEASE_MINOR_VERSION 0
#endif

#ifdef RTE_AR_RELEASE_REVISION_VERSION
  #if (RTE_AR_RELEASE_REVISION_VERSION != 3)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Revision Version"
  #endif
#else
  #define RTE_AR_RELEASE_REVISION_VERSION 3
#endif

/*******************************************************************************
** Init Macro
*******************************************************************************/

/******************************************************************************
** Type Definitions for Rte API                                               **
*******************************************************************************/

/*******************************************************************************
** Global Variables                                                           **
*******************************************************************************/

/*******************************************************************************
** Global Variables for Per Instance Memory                                   **
*******************************************************************************/

/*******************************************************************************
** Invalid Value Const Variables                                              **
*******************************************************************************/

/*******************************************************************************
** Macros for Direct API functions defined in PDS                             **
*******************************************************************************/

/*******************************************************************************
** Macros for InDirect(port oriented) API functions defined in PDS            **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for port handles of PDS                                   **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for component instance handles                            **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #3724)
*/
struct Rte_CDS_BswM
{
  VAR(uint8, RTE_DATA) _dummy;
};

/*
  polyspace:end<MISRA-C:5.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #3724)
*/
/*******************************************************************************
** Component instance handles                                                 **
*******************************************************************************/
#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern const struct Rte_CDS_BswM Rte_Inst_BswM;
#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
** Global Variables for Component Instance Handle                             **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for component instance handles                            **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for PerInstanceMemory (Exists only for multiple instances)**
*******************************************************************************/

/*******************************************************************************
** Macros for Direct API functions                                            **
*******************************************************************************/

/*******************************************************************************
** Macros for Exclusive Areas                                                 **
*******************************************************************************/

/*******************************************************************************
** Macros for ApplicationError in Client Server                               **
*******************************************************************************/

/*******************************************************************************
** Prototypes for Rte API                                                     **
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_BswM_modeRequestPort_AppMode_AppMode(OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);

extern FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_BswM_modeRequestPort_ComMMode_Project_ComMMode_Project(OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_modeSwitchPort_ComMMode_Project_ComMMode_Project(IN Rte_ModeType_MDG_ComMMode NewMode);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_modeSwitchPort_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(IN Rte_ModeType_DcmDiagnosticSessionControl NewMode);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_modeSwitchPort_EcuMode_EcuMode(IN Rte_ModeType_EcuMode NewMode);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_modeSwitchPort_InitState_InitState(IN Rte_ModeType_MDG_InitState NewMode);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_modeSwitchPort_PduGroupRx_Project_PduGroupRx_Project(IN Rte_ModeType_MDG_PduGroup NewMode);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_modeSwitchPort_PduGroupTx_Project_PduGroupTx_Project(IN Rte_ModeType_MDG_PduGroup NewMode);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_modeSwitchPort_WakeupEvent_WakeupEvent(IN Rte_ModeType_MDG_WakeupEvent NewMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** API Mapping                                                                **
*******************************************************************************/
#ifndef Rte_Read_modeRequestPort_AppMode_AppMode
#define Rte_Read_modeRequestPort_AppMode_AppMode \
  Rte_Read_BswM_modeRequestPort_AppMode_AppMode
#endif

#ifndef Rte_Read_modeRequestPort_ComMMode_Project_ComMMode_Project
#define Rte_Read_modeRequestPort_ComMMode_Project_ComMMode_Project \
  Rte_Read_BswM_modeRequestPort_ComMMode_Project_ComMMode_Project
#endif

#ifndef Rte_Switch_modeSwitchPort_ComMMode_Project_ComMMode_Project
#define Rte_Switch_modeSwitchPort_ComMMode_Project_ComMMode_Project  Rte_Switch_BswM_modeSwitchPort_ComMMode_Project_ComMMode_Project
#endif

#ifndef Rte_Switch_modeSwitchPort_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#define Rte_Switch_modeSwitchPort_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl  Rte_Switch_BswM_modeSwitchPort_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#endif

#ifndef Rte_Switch_modeSwitchPort_EcuMode_EcuMode
#define Rte_Switch_modeSwitchPort_EcuMode_EcuMode  Rte_Switch_BswM_modeSwitchPort_EcuMode_EcuMode
#endif

#ifndef Rte_Switch_modeSwitchPort_InitState_InitState
#define Rte_Switch_modeSwitchPort_InitState_InitState  Rte_Switch_BswM_modeSwitchPort_InitState_InitState
#endif

#ifndef Rte_Switch_modeSwitchPort_PduGroupRx_Project_PduGroupRx_Project
#define Rte_Switch_modeSwitchPort_PduGroupRx_Project_PduGroupRx_Project  Rte_Switch_BswM_modeSwitchPort_PduGroupRx_Project_PduGroupRx_Project
#endif

#ifndef Rte_Switch_modeSwitchPort_PduGroupTx_Project_PduGroupTx_Project
#define Rte_Switch_modeSwitchPort_PduGroupTx_Project_PduGroupTx_Project  Rte_Switch_BswM_modeSwitchPort_PduGroupTx_Project_PduGroupTx_Project
#endif

#ifndef Rte_Switch_modeSwitchPort_WakeupEvent_WakeupEvent
#define Rte_Switch_modeSwitchPort_WakeupEvent_WakeupEvent  Rte_Switch_BswM_modeSwitchPort_WakeupEvent_WakeupEvent
#endif

/*******************************************************************************
** Client Server Macro                                                        **
*******************************************************************************/

/*******************************************************************************
** Prototypes for Runnable entities                                           **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

#define BswM_START_SEC_CODE
#include "BswM_MemMap.h"
FUNC(void, BswM_CODE) BswM_ActionList_RteSwitch_ComMMode_Project(void);

FUNC(void, BswM_CODE) BswM_ActionList_RteSwitch_DcmDiagnosticSessionControl(void);

FUNC(void, BswM_CODE) BswM_ActionList_RteSwitch_EcuMode(void);

FUNC(void, BswM_CODE) BswM_ActionList_RteSwitch_InitState(void);

FUNC(void, BswM_CODE) BswM_ActionList_RteSwitch_PduGroupRx_Project(void);

FUNC(void, BswM_CODE) BswM_ActionList_RteSwitch_PduGroupTx_Project(void);

FUNC(void, BswM_CODE) BswM_ActionList_RteSwitch_WakeupEvent(void);

FUNC(void, BswM_CODE) BswM_Immediate_SwcModeRequest_AppMode(void);

FUNC(void, BswM_CODE) BswM_Immediate_SwcModeRequest_ComMMode_Project(void);

#define BswM_STOP_SEC_CODE
#include "BswM_MemMap.h"

/*
  polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

/*******************************************************************************
** Runnables Mapping                                                          **
*******************************************************************************/
#ifndef RTE_RUNNABLE_BswM_ActionList_RteSwitch_ComMMode_Project
#define RTE_RUNNABLE_BswM_ActionList_RteSwitch_ComMMode_Project BswM_ActionList_RteSwitch_ComMMode_Project
#endif
#ifndef RTE_RUNNABLE_BswM_ActionList_RteSwitch_DcmDiagnosticSessionControl
#define RTE_RUNNABLE_BswM_ActionList_RteSwitch_DcmDiagnosticSessionControl BswM_ActionList_RteSwitch_DcmDiagnosticSessionControl
#endif
#ifndef RTE_RUNNABLE_BswM_ActionList_RteSwitch_EcuMode
#define RTE_RUNNABLE_BswM_ActionList_RteSwitch_EcuMode BswM_ActionList_RteSwitch_EcuMode
#endif
#ifndef RTE_RUNNABLE_BswM_ActionList_RteSwitch_InitState
#define RTE_RUNNABLE_BswM_ActionList_RteSwitch_InitState BswM_ActionList_RteSwitch_InitState
#endif
#ifndef RTE_RUNNABLE_BswM_ActionList_RteSwitch_PduGroupRx_Project
#define RTE_RUNNABLE_BswM_ActionList_RteSwitch_PduGroupRx_Project BswM_ActionList_RteSwitch_PduGroupRx_Project
#endif
#ifndef RTE_RUNNABLE_BswM_ActionList_RteSwitch_PduGroupTx_Project
#define RTE_RUNNABLE_BswM_ActionList_RteSwitch_PduGroupTx_Project BswM_ActionList_RteSwitch_PduGroupTx_Project
#endif
#ifndef RTE_RUNNABLE_BswM_ActionList_RteSwitch_WakeupEvent
#define RTE_RUNNABLE_BswM_ActionList_RteSwitch_WakeupEvent BswM_ActionList_RteSwitch_WakeupEvent
#endif
#ifndef RTE_RUNNABLE_BswM_Immediate_SwcModeRequest_AppMode
#define RTE_RUNNABLE_BswM_Immediate_SwcModeRequest_AppMode BswM_Immediate_SwcModeRequest_AppMode
#endif
#ifndef RTE_RUNNABLE_BswM_Immediate_SwcModeRequest_ComMMode_Project
#define RTE_RUNNABLE_BswM_Immediate_SwcModeRequest_ComMMode_Project BswM_Immediate_SwcModeRequest_ComMMode_Project
#endif

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
 }
#endif

#endif

/*******************************************************************************
* PRE-JUSTIFICATION END SECTION (MISRA-C RULE CHECKER)
*******************************************************************************/
/*
  polyspace:end<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
  polyspace:end<MISRA-C:19.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1154, #6713)
  polyspace:end<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)
*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
