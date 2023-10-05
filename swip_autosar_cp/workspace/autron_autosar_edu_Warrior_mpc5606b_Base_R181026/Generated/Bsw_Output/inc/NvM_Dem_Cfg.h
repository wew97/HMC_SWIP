/*******************************************************************************
**  FILE-NAME: NvM_Dem_Cfg.h                                                  **
**                                                                            **
**  MODULE-NAME: AUTOSAR NVRAM Manager Module                                 **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.3.5                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Mcal\Ecud_Fee.arxml
 *                Configuration\ECU\Ecud_Dem.arxml
 *                Configuration\ECU\Mcal\Ecud_Gpt.arxml
 *                Configuration\ECU\Mcal\Ecud_Fls.arxml
 *                Configuration\ECU\Ecud_NvM.arxml
 * GENERATED ON:  This timestamp is removed.
 */

#ifndef NVM_DEM_CFG_H
#define NVM_DEM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define NVM_DEM_CFG_AR_RELEASE_MAJOR_VERSION               (4)
#define NVM_DEM_CFG_AR_RELEASE_MINOR_VERSION               (0)
#define NVM_DEM_CFG_AR_RELEASE_REVISION_VERSION            (3)
#define NVM_DEM_CFG_SW_MAJOR_VERSION                       (1)
#define NVM_DEM_CFG_SW_MINOR_VERSION                       (3)
#define NVM_DEM_CFG_SW_PATCH_VERSION                       (1)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Reference to the Dem Event */
#define NVM_E_INTEGRITY_FAILED              DemConf_DemEventParameter_NVM_E_INTEGRITY_FAILED

/* Reference to the Dem Event */
#define NVM_E_LOSS_OF_REDUNDANCY            DemConf_DemEventParameter_NVM_E_LOSS_OF_REDUNDANCY

/* Reference to the Dem Event */
#define NVM_E_QUEUE_OVERFLOW                DemConf_DemEventParameter_NVM_E_QUEUE_OVERFLOW

/* Reference to the Dem Event */
#define NVM_E_REQ_FAILED                    DemConf_DemEventParameter_NVM_E_REQ_FAILED

/* Reference to the Dem Event */
#define NVM_E_VERIFY_FAILED                 DemConf_DemEventParameter_NVM_E_VERIFY_FAILED

/* Reference to the Dem Event */
#define NVM_E_WRITE_PROTECTED               DemConf_DemEventParameter_NVM_E_WRITE_PROTECTED

/* Reference to the Dem Event */
#define NVM_E_WRONG_BLOCK_ID                DemConf_DemEventParameter_NVM_E_WRONG_BLOCK_ID


#endif /* NVM_DEM_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
