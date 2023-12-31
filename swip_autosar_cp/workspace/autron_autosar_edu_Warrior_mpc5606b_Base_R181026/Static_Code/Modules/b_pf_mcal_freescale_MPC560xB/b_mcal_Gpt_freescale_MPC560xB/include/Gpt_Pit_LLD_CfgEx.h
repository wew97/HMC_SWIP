/**
*   @file    Gpt_Pit_LLD_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - PIT driver header file.
*   @details PIT driver defines.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS_Stm_Pit_Rtc
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef GPT_PIT_LLD_CFG_EX_H
#define GPT_PIT_LLD_CFG_EX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Gpt_Pit_LLD_CfgEx_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Gpt_Pit_LLD_CfgEx_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Gpt_Pit_LLD_CfgEx_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Pit_LLD_CfgEx.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DGPT09300
* @{
*/
#define GPT_PIT_LLD_CFG_EX_VENDOR_ID                       43
/* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION        4
/*
* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_2 The compiler/linker shall be checked to ensure 31 
* character  significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION     3
/* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_CFG_EX_SW_MAJOR_VERSION                1
/* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_CFG_EX_SW_MINOR_VERSION                0
/* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_CFG_EX_SW_PATCH_VERSION                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* API SERVICE IDs */
/**
@brief API service ID for PIT_Gpt_ProcessInterrupt  function
@details Parameters used when raising a CER error/exception
*/
#define GPT_PIT_INTERRUPT_ID          ((uint8)0x02U)

/**
@{
@brief PIT Channels defines
*/
#define PIT_CH_0  ((uint8)0)
#define PIT_CH_1  ((uint8)1)
#define PIT_CH_2  ((uint8)2)
#define PIT_CH_3  ((uint8)3)
#define PIT_CH_4  ((uint8)4)
#define PIT_CH_5  ((uint8)5)
#define PIT_CH_6  ((uint8)6)
#define PIT_CH_7  ((uint8)7)
/**@}*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/*
* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and MemMap.h file are of the same Autosar version */
    #if ((GPT_PIT_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION != MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_PIT_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION != MEMMAP_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Gpt_Pit_LLD_CfgEx.h and MemMap.h are different"
    #endif
#endif

#define GPT_STOP_SEC_CODE
/*
* @violates @ref Gpt_Pit_LLD_CfgEx_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_PIT_LLD_CFG_EX_H*/

/** @} */
