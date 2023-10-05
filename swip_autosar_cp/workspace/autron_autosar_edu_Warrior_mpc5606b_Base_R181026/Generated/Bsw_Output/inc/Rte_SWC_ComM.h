
/*******************************************************************************
**  FILE-NAME: Rte_SWC_ComM.h                                                     **
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
 #ifndef RTE_SWC_COMM_H
      #define RTE_SWC_COMM_H
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
#include "Rte_SWC_ComM_Type.h"

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
struct Rte_CDS_SWC_ComM
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
extern const struct Rte_CDS_SWC_ComM Rte_Inst_SWC_ComM;
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

#ifndef RTE_E_ComM_ChannelLimitation_E_NOT_OK
#define RTE_E_ComM_ChannelLimitation_E_NOT_OK 1U
#endif

#ifndef RTE_E_ComM_ECUModeLimitation_E_NOT_OK
#define RTE_E_ComM_ECUModeLimitation_E_NOT_OK 1U
#endif

#ifndef RTE_E_ComM_UserRequest_E_NOT_OK
#define RTE_E_ComM_UserRequest_E_NOT_OK 1U
#endif

#ifndef RTE_E_ComM_UserRequest_E_MODE_LIMITATION
#define RTE_E_ComM_UserRequest_E_MODE_LIMITATION 2U
#endif

/*******************************************************************************
** Prototypes for Rte API                                                     **
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL000_R_GetInhibitionStatus(
	OUT P2VAR(ComM_InhibitionStatusType, AUTOMATIC, RTE_APPL_DATA) Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL000_R_GetState(
	OUT P2VAR(ComM_StateType, AUTOMATIC, RTE_APPL_DATA) State);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL000_R_LimitChannelToNoComMode(
	IN boolean Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL000_R_PreventWakeUp(
	IN boolean Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL001_R_GetInhibitionStatus(
	OUT P2VAR(ComM_InhibitionStatusType, AUTOMATIC, RTE_APPL_DATA) Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL001_R_GetState(
	OUT P2VAR(ComM_StateType, AUTOMATIC, RTE_APPL_DATA) State);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL001_R_LimitChannelToNoComMode(
	IN boolean Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_CL001_R_PreventWakeUp(
	IN boolean Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_ML_R_GetStatus(
	OUT P2VAR(ComM_InitStatusType, AUTOMATIC, RTE_APPL_DATA) Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_ML_R_LimitECUToNoComMode(
	IN boolean Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_ML_R_ReadInhibitCounter(
	OUT P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) CounterValue);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_ML_R_ResetInhibitCounter(void);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_ML_R_SetECUGroupClassification(
	IN ComM_InhibitionStatusType Status);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_UR000_R_GetCurrentComMode(
	OUT P2VAR(ComM_ModeType, AUTOMATIC, RTE_APPL_DATA) ComMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_UR000_R_GetRequestedComMode(
	OUT P2VAR(ComM_ModeType, AUTOMATIC, RTE_APPL_DATA) ComMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_UR000_R_RequestComMode(
	IN ComM_ModeType ComMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_UR001_R_GetCurrentComMode(
	OUT P2VAR(ComM_ModeType, AUTOMATIC, RTE_APPL_DATA) ComMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_UR001_R_GetRequestedComMode(
	OUT P2VAR(ComM_ModeType, AUTOMATIC, RTE_APPL_DATA) ComMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_ComM_UR001_R_RequestComMode(
	IN ComM_ModeType ComMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_ComM_CR000_R_fullComRequestors(OUT P2VAR(ComM_UserHandleArrayType, AUTOMATIC, RTE_APPL_DATA) Data);

extern FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_ComM_CR001_R_fullComRequestors(OUT P2VAR(ComM_UserHandleArrayType, AUTOMATIC, RTE_APPL_DATA) Data);

extern FUNC(Rte_ModeType_ComMMode, RTE_CODE) Rte_Mode_SWC_ComM_UM000_R_currentMode(void);

extern FUNC(Rte_ModeType_ComMMode, RTE_CODE) Rte_Mode_SWC_ComM_UM001_R_currentMode(void);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** API Mapping                                                                **
*******************************************************************************/
#ifndef Rte_Read_CR000_R_fullComRequestors
#define Rte_Read_CR000_R_fullComRequestors \
  Rte_Read_SWC_ComM_CR000_R_fullComRequestors
#endif

#ifndef Rte_Read_CR001_R_fullComRequestors
#define Rte_Read_CR001_R_fullComRequestors \
  Rte_Read_SWC_ComM_CR001_R_fullComRequestors
#endif

#ifndef Rte_Mode_UM000_R_currentMode
#define Rte_Mode_UM000_R_currentMode  Rte_Mode_SWC_ComM_UM000_R_currentMode
#endif

#ifndef Rte_Mode_UM001_R_currentMode
#define Rte_Mode_UM001_R_currentMode  Rte_Mode_SWC_ComM_UM001_R_currentMode
#endif

#ifndef Rte_Call_CL000_R_GetInhibitionStatus
#define Rte_Call_CL000_R_GetInhibitionStatus Rte_Call_SWC_ComM_CL000_R_GetInhibitionStatus
#endif

#ifndef Rte_Call_CL000_R_GetState
#define Rte_Call_CL000_R_GetState Rte_Call_SWC_ComM_CL000_R_GetState
#endif

#ifndef Rte_Call_CL000_R_LimitChannelToNoComMode
#define Rte_Call_CL000_R_LimitChannelToNoComMode Rte_Call_SWC_ComM_CL000_R_LimitChannelToNoComMode
#endif

#ifndef Rte_Call_CL000_R_PreventWakeUp
#define Rte_Call_CL000_R_PreventWakeUp Rte_Call_SWC_ComM_CL000_R_PreventWakeUp
#endif

#ifndef Rte_Call_CL001_R_GetInhibitionStatus
#define Rte_Call_CL001_R_GetInhibitionStatus Rte_Call_SWC_ComM_CL001_R_GetInhibitionStatus
#endif

#ifndef Rte_Call_CL001_R_GetState
#define Rte_Call_CL001_R_GetState Rte_Call_SWC_ComM_CL001_R_GetState
#endif

#ifndef Rte_Call_CL001_R_LimitChannelToNoComMode
#define Rte_Call_CL001_R_LimitChannelToNoComMode Rte_Call_SWC_ComM_CL001_R_LimitChannelToNoComMode
#endif

#ifndef Rte_Call_CL001_R_PreventWakeUp
#define Rte_Call_CL001_R_PreventWakeUp Rte_Call_SWC_ComM_CL001_R_PreventWakeUp
#endif

#ifndef Rte_Call_ML_R_GetStatus
#define Rte_Call_ML_R_GetStatus Rte_Call_SWC_ComM_ML_R_GetStatus
#endif

#ifndef Rte_Call_ML_R_LimitECUToNoComMode
#define Rte_Call_ML_R_LimitECUToNoComMode Rte_Call_SWC_ComM_ML_R_LimitECUToNoComMode
#endif

#ifndef Rte_Call_ML_R_ReadInhibitCounter
#define Rte_Call_ML_R_ReadInhibitCounter Rte_Call_SWC_ComM_ML_R_ReadInhibitCounter
#endif

#ifndef Rte_Call_ML_R_ResetInhibitCounter
#define Rte_Call_ML_R_ResetInhibitCounter Rte_Call_SWC_ComM_ML_R_ResetInhibitCounter
#endif

#ifndef Rte_Call_ML_R_SetECUGroupClassification
#define Rte_Call_ML_R_SetECUGroupClassification Rte_Call_SWC_ComM_ML_R_SetECUGroupClassification
#endif

#ifndef Rte_Call_UR000_R_GetCurrentComMode
#define Rte_Call_UR000_R_GetCurrentComMode Rte_Call_SWC_ComM_UR000_R_GetCurrentComMode
#endif

#ifndef Rte_Call_UR000_R_GetRequestedComMode
#define Rte_Call_UR000_R_GetRequestedComMode Rte_Call_SWC_ComM_UR000_R_GetRequestedComMode
#endif

#ifndef Rte_Call_UR000_R_RequestComMode
#define Rte_Call_UR000_R_RequestComMode Rte_Call_SWC_ComM_UR000_R_RequestComMode
#endif

#ifndef Rte_Call_UR001_R_GetCurrentComMode
#define Rte_Call_UR001_R_GetCurrentComMode Rte_Call_SWC_ComM_UR001_R_GetCurrentComMode
#endif

#ifndef Rte_Call_UR001_R_GetRequestedComMode
#define Rte_Call_UR001_R_GetRequestedComMode Rte_Call_SWC_ComM_UR001_R_GetRequestedComMode
#endif

#ifndef Rte_Call_UR001_R_RequestComMode
#define Rte_Call_UR001_R_RequestComMode Rte_Call_SWC_ComM_UR001_R_RequestComMode
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

#define SWC_ComM_START_SEC_CODE
#include "SWC_ComM_MemMap.h"
FUNC(void, SWC_ComM_CODE) SWC_ComM_Runnable(void);

#define SWC_ComM_STOP_SEC_CODE
#include "SWC_ComM_MemMap.h"

/*
  polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

/*******************************************************************************
** Runnables Mapping                                                          **
*******************************************************************************/
#ifndef RTE_RUNNABLE_SWC_ComM_Runnable
#define RTE_RUNNABLE_SWC_ComM_Runnable SWC_ComM_Runnable
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

