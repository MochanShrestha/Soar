#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

/********************************************************************
* @file gski_instanceinfo.cpp 
*********************************************************************
* @remarks Copyright (C) 2002 Soar Technology, All rights reserved. 
* The U.S. government has non-exclusive license to this software 
* for government purposes. 
*********************************************************************
* created:	   6/28/2002   12:07
*
* purpose: 
*********************************************************************/
#include "gSKI_InstanceInfo.h"
#include "gSKI_Error.h"

//#include "MegaUnitTest.h"
//DEF_EXPOSE(gSKI_InstanceInfo);


namespace gSKI
{
   /*
   =========================
 ___           _                       ___        __
|_ _|_ __  ___| |_ __ _ _ __   ___ ___|_ _|_ __  / _| ___
 | || '_ \/ __| __/ _` | '_ \ / __/ _ \| || '_ \| |_ / _ \
 | || | | \__ \ || (_| | | | | (_|  __/| || | | |  _| (_) |
|___|_| |_|___/\__\__,_|_| |_|\___\___|___|_| |_|_|  \___/
   =========================
   */
   InstanceInfo::InstanceInfo(const char*         instanceName, 
                              const char*         serverName, 
                              egSKIProcessType    processType, 
                              egSKIThreadingModel threadingModel) : m_instanceName(instanceName),
                                                                    m_serverName(serverName),
                                                                    m_threadingModel(threadingModel),
                                                                    m_processType(processType)
   {

   
   }

   /*
   =========================
 /\/|___           _                       ___        __
|/\/|_ _|_ __  ___| |_ __ _ _ __   ___ ___|_ _|_ __  / _| ___
     | || '_ \/ __| __/ _` | '_ \ / __/ _ \| || '_ \| |_ / _ \
     | || | | \__ \ || (_| | | | | (_|  __/| || | | |  _| (_) |
    |___|_| |_|___/\__\__,_|_| |_|\___\___|___|_| |_|_|  \___/
   =========================
   */
   InstanceInfo::~InstanceInfo()
   {
   
   }

   /*
   =========================
  ____      _   ___           _                       _   _
 / ___| ___| |_|_ _|_ __  ___| |_ __ _ _ __   ___ ___| \ | | __ _ _ __ ___   ___
| |  _ / _ \ __|| || '_ \/ __| __/ _` | '_ \ / __/ _ \  \| |/ _` | '_ ` _ \ / _ \
| |_| |  __/ |_ | || | | \__ \ || (_| | | | | (_|  __/ |\  | (_| | | | | | |  __/
 \____|\___|\__|___|_| |_|___/\__\__,_|_| |_|\___\___|_| \_|\__,_|_| |_| |_|\___|
   =========================
   */
   const char* InstanceInfo::GetInstanceName(Error* err) const
   {
      ClearError(err);

      return m_instanceName.c_str();
   }

   /*
   =========================
  ____      _   ____                            _____
 / ___| ___| |_|  _ \ _ __ ___   ___ ___ ___ __|_   _|   _ _ __   ___
| |  _ / _ \ __| |_) | '__/ _ \ / __/ _ Y __/ __|| || | | | '_ \ / _ \
| |_| |  __/ |_|  __/| | | (_) | (_|  __|__ \__ \| || |_| | |_) |  __/
 \____|\___|\__|_|   |_|  \___/ \___\___|___/___/|_| \__, | .__/ \___|
                                                     |___/|_|
   =========================
   */
   egSKIProcessType InstanceInfo::GetProcessType(Error* err) const
   {
      ClearError(err);
   
      return m_processType;
   }

   /*
   =========================
  ____      _   ____                           _   _
 / ___| ___| |_/ ___|  ___ _ ____   _____ _ __| \ | | __ _ _ __ ___   ___
| |  _ / _ \ __\___ \ / _ \ '__\ \ / / _ \ '__|  \| |/ _` | '_ ` _ \ / _ \
| |_| |  __/ |_ ___) |  __/ |   \ V /  __/ |  | |\  | (_| | | | | | |  __/
 \____|\___|\__|____/ \___|_|    \_/ \___|_|  |_| \_|\__,_|_| |_| |_|\___|
   =========================
   */
   const char* InstanceInfo::GetServerName(Error* err) const
   {
      ClearError(err);
   
      return m_serverName.c_str();
   }

   /*
   =========================
  ____      _  _____ _                        _ _             __  __           _      _
 / ___| ___| ||_   _| |__  _ __ ___  __ _  __| (_)_ __   __ _|  \/  | ___   __| | ___| |
| |  _ / _ \ __|| | | '_ \| '__/ _ \/ _` |/ _` | | '_ \ / _` | |\/| |/ _ \ / _` |/ _ \ |
| |_| |  __/ |_ | | | | | | | |  __/ (_| | (_| | | | | | (_| | |  | | (_) | (_| |  __/ |
 \____|\___|\__||_| |_| |_|_|  \___|\__,_|\__,_|_|_| |_|\__, |_|  |_|\___/ \__,_|\___|_|
                                                        |___/
   =========================
   */
   egSKIThreadingModel InstanceInfo::GetThreadingModel(Error* err) const
   {
      ClearError(err);
      return(m_threadingModel);
   }





}
