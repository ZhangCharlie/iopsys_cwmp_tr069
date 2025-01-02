/*
 *      This program is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      Copyright (C) 2019 iopsys Software Solutions AB
 *		Author: Amin Ben Ramdhane <amin.benramdhane@pivasoftware.com>
 */

#include "dmcwmp.h"
#include "dmcommon.h"
#include "rootinternetgatewaydevice.h"

/* *** InternetGatewayDevice. *** */
DMOBJ tRootInternetGatewayDeviceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Services", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"Capabilities", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tCapabilitiesObj, NULL, NULL},
    {"DeviceInfo", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDeviceInfoObj, tDeviceInfoParams, NULL},
    {"DeviceConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tDeviceConfigParams, NULL},
    {"ManagementServer", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tManagementServerObj, tManagementServerParams, NULL},
    {"Time", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tTimeParams, NULL},
    {"UserInterface", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tUserInterfaceObj, tUserInterfaceParams, NULL},
    {"CaptivePortal", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tCaptivePortalParams, NULL},
    {"Layer3Forwarding", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tLayer3ForwardingObj, tLayer3ForwardingParams, NULL},
    {"Layer2Bridging", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tLayer2BridgingObj, tLayer2BridgingParams, NULL},
    {"QueueManagement", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tQueueManagementObj, tQueueManagementParams, NULL},
    {"LANConfigSecurity", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tLANConfigSecurityParams, NULL},
    {"IPPingDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tIPPingDiagnosticsParams, NULL},
    {"TraceRouteDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tTraceRouteDiagnosticsObj, tTraceRouteDiagnosticsParams, NULL},
    {"DownloadDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tDownloadDiagnosticsParams, NULL},
    {"UploadDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tUploadDiagnosticsParams, NULL},
    {"UDPEchoConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tUDPEchoConfigParams, NULL},
    {"LANDevice", &DMWRITE, addObjLANDevice, delObjLANDevice, NULL, browseLANDeviceInst, NULL, NULL, tLANDeviceObj, tLANDeviceParams, NULL},
    {"LANInterfaces", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tLANInterfacesObj, tLANInterfacesParams, NULL},
    {"WANDevice", &DMREAD, NULL, NULL, NULL, browseWANDeviceInst, NULL, NULL, tWANDeviceObj, tWANDeviceParams, NULL},
    {"User", &DMWRITE, addObjUser, delObjUser, NULL, browseUserInst, NULL, NULL, NULL, tUserParams, NULL},
    {"UPnP", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tUPnPObj, NULL, NULL},
    {"DLNA", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDLNAObj, NULL, NULL},
    {"SmartCardReader", &DMREAD, NULL, NULL, NULL, browseSmartCardReaderInst, NULL, NULL, tSmartCardReaderObj, tSmartCardReaderParams, NULL},
    {"SelfTestDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tSelfTestDiagnosticsParams, NULL},
    {"NSLookupDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tNSLookupDiagnosticsObj, tNSLookupDiagnosticsParams, NULL},
    {"Firewall", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFirewallParams, NULL},
    {"USBHosts", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tUSBHostsObj, tUSBHostsParams, NULL},
    {"PeriodicStatistics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tPeriodicStatisticsObj, tPeriodicStatisticsParams, NULL},
    {"DownloadAvailability", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDownloadAvailabilityObj, NULL, NULL},
    {"SoftwareModules", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tSoftwareModulesObj, tSoftwareModulesParams, NULL},
    {"Security", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tSecurityObj, tSecurityParams, NULL},
    {"FaultMgmt", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFaultMgmtObj, tFaultMgmtParams, NULL},
    {"FAP", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFAPObj, NULL, NULL},
    {"BulkData", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tBulkDataObj, tBulkDataParams, NULL},
    {"DNS", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDNSObj, NULL, NULL},
    {"XMPP", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tXMPPObj, tXMPPParams, NULL},
    {0}};

DMLEAF tRootInternetGatewayDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DeviceSummary", &DMREAD, DMT_STRING, get_RootInternetGatewayDevice_DeviceSummary, NULL, NULL, NULL},
    {"LANDeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_RootInternetGatewayDevice_LANDeviceNumberOfEntries, NULL, NULL, NULL},
    {"WANDeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_RootInternetGatewayDevice_WANDeviceNumberOfEntries, NULL, NULL, NULL},
    {"UserNumberOfEntries", &DMREAD, DMT_UNINT, get_RootInternetGatewayDevice_UserNumberOfEntries, NULL, NULL, NULL},
    {"SmartCardReaderNumberOfEntries", &DMREAD, DMT_UNINT, get_RootInternetGatewayDevice_SmartCardReaderNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Capabilities. *** */
DMOBJ tCapabilitiesObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"PerformanceDiagnostic", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tCapabilitiesPerformanceDiagnosticParams, NULL},
    {0}};

/* *** InternetGatewayDevice.Capabilities.PerformanceDiagnostic. *** */
DMLEAF tCapabilitiesPerformanceDiagnosticParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DownloadTransports", &DMREAD, DMT_STRING, get_CapabilitiesPerformanceDiagnostic_DownloadTransports, NULL, NULL, NULL},
    {"UploadTransports", &DMREAD, DMT_STRING, get_CapabilitiesPerformanceDiagnostic_UploadTransports, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo. *** */
DMOBJ tDeviceInfoObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"VendorConfigFile", &DMREAD, NULL, NULL, NULL, browseDeviceInfoVendorConfigFileInst, NULL, NULL, NULL, tDeviceInfoVendorConfigFileParams, NULL},
    {"MemoryStatus", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tDeviceInfoMemoryStatusParams, NULL},
    {"ProcessStatus", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDeviceInfoProcessStatusObj, tDeviceInfoProcessStatusParams, NULL},
    {"TemperatureStatus", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDeviceInfoTemperatureStatusObj, tDeviceInfoTemperatureStatusParams, NULL},
    {"NetworkProperties", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tDeviceInfoNetworkPropertiesParams, NULL},
    {"SupportedDataModel", &DMREAD, NULL, NULL, NULL, browseDeviceInfoSupportedDataModelInst, NULL, NULL, NULL, tDeviceInfoSupportedDataModelParams, NULL},
    {"Processor", &DMREAD, NULL, NULL, NULL, browseDeviceInfoProcessorInst, NULL, NULL, NULL, tDeviceInfoProcessorParams, NULL},
    {"VendorLogFile", &DMREAD, NULL, NULL, NULL, browseDeviceInfoVendorLogFileInst, NULL, NULL, NULL, tDeviceInfoVendorLogFileParams, NULL},
    {"ProxierInfo", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tDeviceInfoProxierInfoParams, NULL},
    {"Location", &DMWRITE, addObjDeviceInfoLocation, delObjDeviceInfoLocation, NULL, browseDeviceInfoLocationInst, NULL, NULL, NULL, tDeviceInfoLocationParams, NULL},
    {0}};

DMLEAF tDeviceInfoParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DeviceCategory", &DMREAD, DMT_STRING, get_DeviceInfo_DeviceCategory, NULL, NULL, NULL},
    {"Manufacturer", &DMREAD, DMT_STRING, get_DeviceInfo_Manufacturer, NULL, NULL, NULL},
    {"ManufacturerOUI", &DMREAD, DMT_STRING, get_DeviceInfo_ManufacturerOUI, NULL, NULL, NULL},
    {"ModelName", &DMREAD, DMT_STRING, get_DeviceInfo_ModelName, NULL, NULL, NULL},
    {"ModelNumber", &DMREAD, DMT_STRING, get_DeviceInfo_ModelNumber, NULL, NULL, NULL},
    {"Description", &DMREAD, DMT_STRING, get_DeviceInfo_Description, NULL, NULL, NULL},
    {"ProductClass", &DMREAD, DMT_STRING, get_DeviceInfo_ProductClass, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_DeviceInfo_SerialNumber, NULL, NULL, NULL},
    {"HardwareVersion", &DMREAD, DMT_STRING, get_DeviceInfo_HardwareVersion, NULL, NULL, NULL},
    {"SoftwareVersion", &DMREAD, DMT_STRING, get_DeviceInfo_SoftwareVersion, NULL, NULL, NULL},
    {"ModemFirmwareVersion", &DMREAD, DMT_STRING, get_DeviceInfo_ModemFirmwareVersion, NULL, NULL, NULL},
    {"EnabledOptions", &DMREAD, DMT_STRING, get_DeviceInfo_EnabledOptions, NULL, NULL, NULL},
    {"AdditionalHardwareVersion", &DMREAD, DMT_STRING, get_DeviceInfo_AdditionalHardwareVersion, NULL, NULL, NULL},
    {"AdditionalSoftwareVersion", &DMREAD, DMT_STRING, get_DeviceInfo_AdditionalSoftwareVersion, NULL, NULL, NULL},
    {"SpecVersion", &DMREAD, DMT_STRING, get_DeviceInfo_SpecVersion, NULL, NULL, NULL},
    {"ProvisioningCode", &DMWRITE, DMT_STRING, get_DeviceInfo_ProvisioningCode, set_DeviceInfo_ProvisioningCode, NULL, NULL},
    {"UpTime", &DMREAD, DMT_UNINT, get_DeviceInfo_UpTime, NULL, NULL, NULL},
    {"FirstUseDate", &DMREAD, DMT_TIME, get_DeviceInfo_FirstUseDate, NULL, NULL, NULL},
    {"DeviceLog", &DMREAD, DMT_STRING, get_DeviceInfo_DeviceLog, NULL, NULL, NULL},
    {"VendorConfigFileNumberOfEntries", &DMREAD, DMT_UNINT, get_DeviceInfo_VendorConfigFileNumberOfEntries, NULL, NULL, NULL},
    {"SupportedDataModelNumberOfEntries", &DMREAD, DMT_UNINT, get_DeviceInfo_SupportedDataModelNumberOfEntries, NULL, NULL, NULL},
    {"ProcessorNumberOfEntries", &DMREAD, DMT_UNINT, get_DeviceInfo_ProcessorNumberOfEntries, NULL, NULL, NULL},
    {"VendorLogFileNumberOfEntries", &DMREAD, DMT_UNINT, get_DeviceInfo_VendorLogFileNumberOfEntries, NULL, NULL, NULL},
    {"LocationNumberOfEntries", &DMREAD, DMT_UNINT, get_DeviceInfo_LocationNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.VendorConfigFile.{i}. *** */
DMLEAF tDeviceInfoVendorConfigFileParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_DeviceInfoVendorConfigFile_Alias, set_DeviceInfoVendorConfigFile_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_DeviceInfoVendorConfigFile_Name, NULL, NULL, NULL},
    {"Version", &DMREAD, DMT_STRING, get_DeviceInfoVendorConfigFile_Version, NULL, NULL, NULL},
    {"Date", &DMREAD, DMT_TIME, get_DeviceInfoVendorConfigFile_Date, NULL, NULL, NULL},
    {"Description", &DMREAD, DMT_STRING, get_DeviceInfoVendorConfigFile_Description, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.MemoryStatus. *** */
DMLEAF tDeviceInfoMemoryStatusParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Total", &DMREAD, DMT_UNINT, get_DeviceInfoMemoryStatus_Total, NULL, NULL, NULL},
    {"Free", &DMREAD, DMT_UNINT, get_DeviceInfoMemoryStatus_Free, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.ProcessStatus. *** */
DMOBJ tDeviceInfoProcessStatusObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Process", &DMREAD, NULL, NULL, NULL, browseDeviceInfoProcessStatusProcessInst, NULL, NULL, NULL, tDeviceInfoProcessStatusProcessParams, NULL},
    {0}};

DMLEAF tDeviceInfoProcessStatusParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"CPUUsage", &DMREAD, DMT_UNINT, get_DeviceInfoProcessStatus_CPUUsage, NULL, NULL, NULL},
    {"ProcessNumberOfEntries", &DMREAD, DMT_UNINT, get_DeviceInfoProcessStatus_ProcessNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.ProcessStatus.Process.{i}. *** */
DMLEAF tDeviceInfoProcessStatusProcessParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"PID", &DMREAD, DMT_UNINT, get_DeviceInfoProcessStatusProcess_PID, NULL, NULL, NULL},
    {"Command", &DMREAD, DMT_STRING, get_DeviceInfoProcessStatusProcess_Command, NULL, NULL, NULL},
    {"Size", &DMREAD, DMT_UNINT, get_DeviceInfoProcessStatusProcess_Size, NULL, NULL, NULL},
    {"Priority", &DMREAD, DMT_UNINT, get_DeviceInfoProcessStatusProcess_Priority, NULL, NULL, NULL},
    {"CPUTime", &DMREAD, DMT_UNINT, get_DeviceInfoProcessStatusProcess_CPUTime, NULL, NULL, NULL},
    {"State", &DMREAD, DMT_STRING, get_DeviceInfoProcessStatusProcess_State, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.TemperatureStatus. *** */
DMOBJ tDeviceInfoTemperatureStatusObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"TemperatureSensor", &DMREAD, NULL, NULL, NULL, browseDeviceInfoTemperatureStatusTemperatureSensorInst, NULL, NULL, NULL, tDeviceInfoTemperatureStatusTemperatureSensorParams, NULL},
    {0}};

DMLEAF tDeviceInfoTemperatureStatusParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"TemperatureSensorNumberOfEntries", &DMREAD, DMT_UNINT, get_DeviceInfoTemperatureStatus_TemperatureSensorNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.TemperatureStatus.TemperatureSensor.{i}. *** */
DMLEAF tDeviceInfoTemperatureStatusTemperatureSensorParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_DeviceInfoTemperatureStatusTemperatureSensor_Alias, set_DeviceInfoTemperatureStatusTemperatureSensor_Alias, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_DeviceInfoTemperatureStatusTemperatureSensor_Enable, set_DeviceInfoTemperatureStatusTemperatureSensor_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_DeviceInfoTemperatureStatusTemperatureSensor_Status, NULL, NULL, NULL},
    {"Reset", &DMWRITE, DMT_BOOL, get_DeviceInfoTemperatureStatusTemperatureSensor_Reset, set_DeviceInfoTemperatureStatusTemperatureSensor_Reset, NULL, NULL},
    {"ResetTime", &DMREAD, DMT_TIME, get_DeviceInfoTemperatureStatusTemperatureSensor_ResetTime, NULL, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_DeviceInfoTemperatureStatusTemperatureSensor_Name, NULL, NULL, NULL},
    {"Value", &DMREAD, DMT_INT, get_DeviceInfoTemperatureStatusTemperatureSensor_Value, NULL, NULL, NULL},
    {"LastUpdate", &DMREAD, DMT_TIME, get_DeviceInfoTemperatureStatusTemperatureSensor_LastUpdate, NULL, NULL, NULL},
    {"MinValue", &DMREAD, DMT_INT, get_DeviceInfoTemperatureStatusTemperatureSensor_MinValue, NULL, NULL, NULL},
    {"MinTime", &DMREAD, DMT_TIME, get_DeviceInfoTemperatureStatusTemperatureSensor_MinTime, NULL, NULL, NULL},
    {"MaxValue", &DMREAD, DMT_INT, get_DeviceInfoTemperatureStatusTemperatureSensor_MaxValue, NULL, NULL, NULL},
    {"MaxTime", &DMREAD, DMT_TIME, get_DeviceInfoTemperatureStatusTemperatureSensor_MaxTime, NULL, NULL, NULL},
    {"LowAlarmValue", &DMWRITE, DMT_INT, get_DeviceInfoTemperatureStatusTemperatureSensor_LowAlarmValue, set_DeviceInfoTemperatureStatusTemperatureSensor_LowAlarmValue, NULL, NULL},
    {"LowAlarmTime", &DMREAD, DMT_TIME, get_DeviceInfoTemperatureStatusTemperatureSensor_LowAlarmTime, NULL, NULL, NULL},
    {"HighAlarmValue", &DMWRITE, DMT_INT, get_DeviceInfoTemperatureStatusTemperatureSensor_HighAlarmValue, set_DeviceInfoTemperatureStatusTemperatureSensor_HighAlarmValue, NULL, NULL},
    {"PollingInterval", &DMWRITE, DMT_UNINT, get_DeviceInfoTemperatureStatusTemperatureSensor_PollingInterval, set_DeviceInfoTemperatureStatusTemperatureSensor_PollingInterval, NULL, NULL},
    {"HighAlarmTime", &DMREAD, DMT_TIME, get_DeviceInfoTemperatureStatusTemperatureSensor_HighAlarmTime, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.NetworkProperties. *** */
DMLEAF tDeviceInfoNetworkPropertiesParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"MaxTCPWindowSize", &DMREAD, DMT_UNINT, get_DeviceInfoNetworkProperties_MaxTCPWindowSize, NULL, NULL, NULL},
    {"TCPImplementation", &DMREAD, DMT_STRING, get_DeviceInfoNetworkProperties_TCPImplementation, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.SupportedDataModel.{i}. *** */
DMLEAF tDeviceInfoSupportedDataModelParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_DeviceInfoSupportedDataModel_Alias, set_DeviceInfoSupportedDataModel_Alias, NULL, NULL},
    {"URL", &DMREAD, DMT_STRING, get_DeviceInfoSupportedDataModel_URL, NULL, NULL, NULL},
    {"UUID", &DMREAD, DMT_STRING, get_DeviceInfoSupportedDataModel_UUID, NULL, NULL, NULL},
    {"URN", &DMREAD, DMT_STRING, get_DeviceInfoSupportedDataModel_URN, NULL, NULL, NULL},
    {"Features", &DMREAD, DMT_STRING, get_DeviceInfoSupportedDataModel_Features, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.Processor.{i}. *** */
DMLEAF tDeviceInfoProcessorParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_DeviceInfoProcessor_Alias, set_DeviceInfoProcessor_Alias, NULL, NULL},
    {"Architecture", &DMREAD, DMT_STRING, get_DeviceInfoProcessor_Architecture, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.VendorLogFile.{i}. *** */
DMLEAF tDeviceInfoVendorLogFileParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_DeviceInfoVendorLogFile_Alias, set_DeviceInfoVendorLogFile_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_DeviceInfoVendorLogFile_Name, NULL, NULL, NULL},
    {"MaximumSize", &DMREAD, DMT_UNINT, get_DeviceInfoVendorLogFile_MaximumSize, NULL, NULL, NULL},
    {"Persistent", &DMREAD, DMT_BOOL, get_DeviceInfoVendorLogFile_Persistent, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.ProxierInfo. *** */
DMLEAF tDeviceInfoProxierInfoParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ManufacturerOUI", &DMREAD, DMT_STRING, get_DeviceInfoProxierInfo_ManufacturerOUI, NULL, NULL, NULL},
    {"ProductClass", &DMREAD, DMT_STRING, get_DeviceInfoProxierInfo_ProductClass, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_DeviceInfoProxierInfo_SerialNumber, NULL, NULL, NULL},
    {"ProxyProtocol", &DMREAD, DMT_STRING, get_DeviceInfoProxierInfo_ProxyProtocol, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceInfo.Location.{i}. *** */
DMLEAF tDeviceInfoLocationParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Source", &DMREAD, DMT_STRING, get_DeviceInfoLocation_Source, NULL, NULL, NULL},
    {"AcquiredTime", &DMREAD, DMT_TIME, get_DeviceInfoLocation_AcquiredTime, NULL, NULL, NULL},
    {"ExternalSource", &DMREAD, DMT_STRING, get_DeviceInfoLocation_ExternalSource, NULL, NULL, NULL},
    {"ExternalProtocol", &DMREAD, DMT_STRING, get_DeviceInfoLocation_ExternalProtocol, NULL, NULL, NULL},
    {"DataObject", &DMWRITE, DMT_STRING, get_DeviceInfoLocation_DataObject, set_DeviceInfoLocation_DataObject, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DeviceConfig. *** */
DMLEAF tDeviceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"PersistentData", &DMWRITE, DMT_STRING, get_DeviceConfig_PersistentData, set_DeviceConfig_PersistentData, NULL, NULL},
    {"ConfigFile", &DMWRITE, DMT_STRING, get_DeviceConfig_ConfigFile, set_DeviceConfig_ConfigFile, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer. *** */
DMOBJ tManagementServerObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"ManageableDevice", &DMREAD, NULL, NULL, NULL, browseManagementServerManageableDeviceInst, NULL, NULL, NULL, tManagementServerManageableDeviceParams, NULL},
    {"AutonomousTransferCompletePolicy", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tManagementServerAutonomousTransferCompletePolicyParams, NULL},
    {"DUStateChangeComplPolicy", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tManagementServerDUStateChangeComplPolicyParams, NULL},
    {"EmbeddedDevice", &DMREAD, NULL, NULL, NULL, browseManagementServerEmbeddedDeviceInst, NULL, NULL, NULL, tManagementServerEmbeddedDeviceParams, NULL},
    {"VirtualDevice", &DMREAD, NULL, NULL, NULL, browseManagementServerVirtualDeviceInst, NULL, NULL, NULL, tManagementServerVirtualDeviceParams, NULL},
    {"StandbyPolicy", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tManagementServerStandbyPolicyParams, NULL},
    {"InformParameter",
     &DMWRITE,
     addObjManagementServerInformParameter,
     delObjManagementServerInformParameter,
     NULL,
     browseManagementServerInformParameterInst,
     NULL,
     NULL,
     NULL,
     tManagementServerInformParameterParams,
     NULL},
    {0}};

DMLEAF tManagementServerParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EnableCWMP", &DMWRITE, DMT_BOOL, get_ManagementServer_EnableCWMP, set_ManagementServer_EnableCWMP, NULL, NULL},
    {"URL", &DMWRITE, DMT_STRING, get_ManagementServer_URL, set_ManagementServer_URL, NULL, NULL},
    {"Username", &DMWRITE, DMT_STRING, get_ManagementServer_Username, set_ManagementServer_Username, NULL, NULL},
    {"Password", &DMWRITE, DMT_STRING, get_ManagementServer_Password, set_ManagementServer_Password, NULL, NULL},
    {"PeriodicInformEnable", &DMWRITE, DMT_BOOL, get_ManagementServer_PeriodicInformEnable, set_ManagementServer_PeriodicInformEnable, NULL, NULL},
    {"PeriodicInformInterval", &DMWRITE, DMT_UNINT, get_ManagementServer_PeriodicInformInterval, set_ManagementServer_PeriodicInformInterval, NULL, NULL},
    {"PeriodicInformTime", &DMWRITE, DMT_TIME, get_ManagementServer_PeriodicInformTime, set_ManagementServer_PeriodicInformTime, NULL, NULL},
    {"ParameterKey", &DMREAD, DMT_STRING, get_ManagementServer_ParameterKey, NULL, NULL, NULL},
    {"ConnectionRequestURL", &DMREAD, DMT_STRING, get_ManagementServer_ConnectionRequestURL, NULL, NULL, NULL},
    {"ConnectionRequestUsername", &DMWRITE, DMT_STRING, get_ManagementServer_ConnectionRequestUsername, set_ManagementServer_ConnectionRequestUsername, NULL, NULL},
    {"ConnectionRequestPassword", &DMWRITE, DMT_STRING, get_ManagementServer_ConnectionRequestPassword, set_ManagementServer_ConnectionRequestPassword, NULL, NULL},
    {"UpgradesManaged", &DMWRITE, DMT_BOOL, get_ManagementServer_UpgradesManaged, set_ManagementServer_UpgradesManaged, NULL, NULL},
    {"KickURL", &DMREAD, DMT_STRING, get_ManagementServer_KickURL, NULL, NULL, NULL},
    {"DownloadProgressURL", &DMREAD, DMT_STRING, get_ManagementServer_DownloadProgressURL, NULL, NULL, NULL},
    {"DefaultActiveNotificationThrottle", &DMWRITE, DMT_UNINT, get_ManagementServer_DefaultActiveNotificationThrottle, set_ManagementServer_DefaultActiveNotificationThrottle, NULL, NULL},
    {"UDPConnectionRequestAddress", &DMREAD, DMT_STRING, get_ManagementServer_UDPConnectionRequestAddress, NULL, NULL, NULL},
    {"UDPConnectionRequestAddressNotificationLimit",
     &DMWRITE,
     DMT_UNINT,
     get_ManagementServer_UDPConnectionRequestAddressNotificationLimit,
     set_ManagementServer_UDPConnectionRequestAddressNotificationLimit,
     NULL,
     NULL},
    {"STUNEnable", &DMWRITE, DMT_BOOL, get_ManagementServer_STUNEnable, set_ManagementServer_STUNEnable, NULL, NULL},
    {"STUNServerAddress", &DMWRITE, DMT_STRING, get_ManagementServer_STUNServerAddress, set_ManagementServer_STUNServerAddress, NULL, NULL},
    {"STUNServerPort", &DMWRITE, DMT_UNINT, get_ManagementServer_STUNServerPort, set_ManagementServer_STUNServerPort, NULL, NULL},
    {"STUNUsername", &DMWRITE, DMT_STRING, get_ManagementServer_STUNUsername, set_ManagementServer_STUNUsername, NULL, NULL},
    {"STUNPassword", &DMWRITE, DMT_STRING, get_ManagementServer_STUNPassword, set_ManagementServer_STUNPassword, NULL, NULL},
    {"STUNMaximumKeepAlivePeriod", &DMWRITE, DMT_INT, get_ManagementServer_STUNMaximumKeepAlivePeriod, set_ManagementServer_STUNMaximumKeepAlivePeriod, NULL, NULL},
    {"STUNMinimumKeepAlivePeriod", &DMWRITE, DMT_UNINT, get_ManagementServer_STUNMinimumKeepAlivePeriod, set_ManagementServer_STUNMinimumKeepAlivePeriod, NULL, NULL},
    {"NATDetected", &DMREAD, DMT_BOOL, get_ManagementServer_NATDetected, NULL, NULL, NULL},
    {"AliasBasedAddressing", &DMREAD, DMT_BOOL, get_ManagementServer_AliasBasedAddressing, NULL, NULL, NULL},
    {"InstanceMode", &DMWRITE, DMT_STRING, get_ManagementServer_InstanceMode, set_ManagementServer_InstanceMode, NULL, NULL},
    {"AutoCreateInstances", &DMWRITE, DMT_BOOL, get_ManagementServer_AutoCreateInstances, set_ManagementServer_AutoCreateInstances, NULL, NULL},
    {"CWMPRetryMinimumWaitInterval", &DMWRITE, DMT_UNINT, get_ManagementServer_CWMPRetryMinimumWaitInterval, set_ManagementServer_CWMPRetryMinimumWaitInterval, NULL, NULL},
    {"CWMPRetryIntervalMultiplier", &DMWRITE, DMT_UNINT, get_ManagementServer_CWMPRetryIntervalMultiplier, set_ManagementServer_CWMPRetryIntervalMultiplier, NULL, NULL},
    {"ManageableDeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_ManagementServer_ManageableDeviceNumberOfEntries, NULL, NULL, NULL},
    {"ManageableDeviceNotificationLimit", &DMWRITE, DMT_UNINT, get_ManagementServer_ManageableDeviceNotificationLimit, set_ManagementServer_ManageableDeviceNotificationLimit, NULL, NULL},
    {"EmbeddedDeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_ManagementServer_EmbeddedDeviceNumberOfEntries, NULL, NULL, NULL},
    {"VirtualDeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_ManagementServer_VirtualDeviceNumberOfEntries, NULL, NULL, NULL},
    {"SupportedConnReqMethods", &DMREAD, DMT_STRING, get_ManagementServer_SupportedConnReqMethods, NULL, NULL, NULL},
    {"ConnReqXMPPConnection", &DMWRITE, DMT_STRING, get_ManagementServer_ConnReqXMPPConnection, set_ManagementServer_ConnReqXMPPConnection, NULL, NULL},
    {"ConnReqAllowedJabberIDs", &DMWRITE, DMT_STRING, get_ManagementServer_ConnReqAllowedJabberIDs, set_ManagementServer_ConnReqAllowedJabberIDs, NULL, NULL},
    {"ConnReqJabberID", &DMREAD, DMT_STRING, get_ManagementServer_ConnReqJabberID, NULL, NULL, NULL},
    {"HTTPCompressionSupported", &DMREAD, DMT_STRING, get_ManagementServer_HTTPCompressionSupported, NULL, NULL, NULL},
    {"HTTPCompression", &DMWRITE, DMT_STRING, get_ManagementServer_HTTPCompression, set_ManagementServer_HTTPCompression, NULL, NULL},
    {"LightweightNotificationProtocolsSupported", &DMREAD, DMT_STRING, get_ManagementServer_LightweightNotificationProtocolsSupported, NULL, NULL, NULL},
    {"LightweightNotificationProtocolsUsed", &DMWRITE, DMT_STRING, get_ManagementServer_LightweightNotificationProtocolsUsed, set_ManagementServer_LightweightNotificationProtocolsUsed, NULL, NULL},
    {"UDPLightweightNotificationHost", &DMWRITE, DMT_STRING, get_ManagementServer_UDPLightweightNotificationHost, set_ManagementServer_UDPLightweightNotificationHost, NULL, NULL},
    {"UDPLightweightNotificationPort", &DMWRITE, DMT_UNINT, get_ManagementServer_UDPLightweightNotificationPort, set_ManagementServer_UDPLightweightNotificationPort, NULL, NULL},
    {"InformParameterNumberOfEntries", &DMREAD, DMT_UNINT, get_ManagementServer_InformParameterNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer.ManageableDevice.{i}. *** */
DMLEAF tManagementServerManageableDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ManufacturerOUI", &DMREAD, DMT_STRING, get_ManagementServerManageableDevice_ManufacturerOUI, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_ManagementServerManageableDevice_SerialNumber, NULL, NULL, NULL},
    {"ProductClass", &DMREAD, DMT_STRING, get_ManagementServerManageableDevice_ProductClass, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_ManagementServerManageableDevice_Host, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer.AutonomousTransferCompletePolicy. *** */
DMLEAF tManagementServerAutonomousTransferCompletePolicyParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_ManagementServerAutonomousTransferCompletePolicy_Enable, set_ManagementServerAutonomousTransferCompletePolicy_Enable, NULL, NULL},
    {"TransferTypeFilter",
     &DMWRITE,
     DMT_STRING,
     get_ManagementServerAutonomousTransferCompletePolicy_TransferTypeFilter,
     set_ManagementServerAutonomousTransferCompletePolicy_TransferTypeFilter,
     NULL,
     NULL},
    {"ResultTypeFilter",
     &DMWRITE,
     DMT_STRING,
     get_ManagementServerAutonomousTransferCompletePolicy_ResultTypeFilter,
     set_ManagementServerAutonomousTransferCompletePolicy_ResultTypeFilter,
     NULL,
     NULL},
    {"FileTypeFilter", &DMWRITE, DMT_STRING, get_ManagementServerAutonomousTransferCompletePolicy_FileTypeFilter, set_ManagementServerAutonomousTransferCompletePolicy_FileTypeFilter, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer.DUStateChangeComplPolicy. *** */
DMLEAF tManagementServerDUStateChangeComplPolicyParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_ManagementServerDUStateChangeComplPolicy_Enable, set_ManagementServerDUStateChangeComplPolicy_Enable, NULL, NULL},
    {"OperationTypeFilter", &DMWRITE, DMT_STRING, get_ManagementServerDUStateChangeComplPolicy_OperationTypeFilter, set_ManagementServerDUStateChangeComplPolicy_OperationTypeFilter, NULL, NULL},
    {"ResultTypeFilter", &DMWRITE, DMT_STRING, get_ManagementServerDUStateChangeComplPolicy_ResultTypeFilter, set_ManagementServerDUStateChangeComplPolicy_ResultTypeFilter, NULL, NULL},
    {"FaultCodeFilter", &DMWRITE, DMT_STRING, get_ManagementServerDUStateChangeComplPolicy_FaultCodeFilter, set_ManagementServerDUStateChangeComplPolicy_FaultCodeFilter, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer.EmbeddedDevice.{i}. *** */
DMLEAF tManagementServerEmbeddedDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ControllerID", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_ControllerID, NULL, NULL, NULL},
    {"ProxiedDeviceID", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_ProxiedDeviceID, NULL, NULL, NULL},
    {"Reference", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_Reference, NULL, NULL, NULL},
    {"SupportedDataModel", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_SupportedDataModel, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_Host, NULL, NULL, NULL},
    {"ProxyProtocol", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_ProxyProtocol, NULL, NULL, NULL},
    {"ProxyProtocolReference", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_ProxyProtocolReference, NULL, NULL, NULL},
    {"DiscoveryProtocol", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_DiscoveryProtocol, NULL, NULL, NULL},
    {"DiscoveryProtocolReference", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_DiscoveryProtocolReference, NULL, NULL, NULL},
    {"CommandProcessed", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_CommandProcessed, NULL, NULL, NULL},
    {"CommandProcessingErrMsg", &DMREAD, DMT_STRING, get_ManagementServerEmbeddedDevice_CommandProcessingErrMsg, NULL, NULL, NULL},
    {"LastSyncTime", &DMREAD, DMT_TIME, get_ManagementServerEmbeddedDevice_LastSyncTime, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer.VirtualDevice.{i}. *** */
DMLEAF tManagementServerVirtualDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ManufacturerOUI", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_ManufacturerOUI, NULL, NULL, NULL},
    {"ProductClass", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_ProductClass, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_SerialNumber, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_Host, NULL, NULL, NULL},
    {"ProxyProtocol", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_ProxyProtocol, NULL, NULL, NULL},
    {"ProxyProtocolReference", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_ProxyProtocolReference, NULL, NULL, NULL},
    {"DiscoveryProtocol", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_DiscoveryProtocol, NULL, NULL, NULL},
    {"DiscoveryProtocolReference", &DMREAD, DMT_STRING, get_ManagementServerVirtualDevice_DiscoveryProtocolReference, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer.StandbyPolicy. *** */
DMLEAF tManagementServerStandbyPolicyParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"CRUnawarenessMaxDuration", &DMWRITE, DMT_INT, get_ManagementServerStandbyPolicy_CRUnawarenessMaxDuration, set_ManagementServerStandbyPolicy_CRUnawarenessMaxDuration, NULL, NULL},
    {"MaxMissedPeriodic", &DMWRITE, DMT_INT, get_ManagementServerStandbyPolicy_MaxMissedPeriodic, set_ManagementServerStandbyPolicy_MaxMissedPeriodic, NULL, NULL},
    {"NotifyMissedScheduled", &DMWRITE, DMT_BOOL, get_ManagementServerStandbyPolicy_NotifyMissedScheduled, set_ManagementServerStandbyPolicy_NotifyMissedScheduled, NULL, NULL},
    {"NetworkAwarenessCapable", &DMREAD, DMT_BOOL, get_ManagementServerStandbyPolicy_NetworkAwarenessCapable, NULL, NULL, NULL},
    {"SelfTimerCapable", &DMREAD, DMT_BOOL, get_ManagementServerStandbyPolicy_SelfTimerCapable, NULL, NULL, NULL},
    {"CRAwarenessRequested", &DMWRITE, DMT_BOOL, get_ManagementServerStandbyPolicy_CRAwarenessRequested, set_ManagementServerStandbyPolicy_CRAwarenessRequested, NULL, NULL},
    {"PeriodicAwarenessRequested", &DMWRITE, DMT_BOOL, get_ManagementServerStandbyPolicy_PeriodicAwarenessRequested, set_ManagementServerStandbyPolicy_PeriodicAwarenessRequested, NULL, NULL},
    {"ScheduledAwarenessRequested", &DMWRITE, DMT_BOOL, get_ManagementServerStandbyPolicy_ScheduledAwarenessRequested, set_ManagementServerStandbyPolicy_ScheduledAwarenessRequested, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.ManagementServer.InformParameter.{i}. *** */
DMLEAF tManagementServerInformParameterParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_ManagementServerInformParameter_Enable, set_ManagementServerInformParameter_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_ManagementServerInformParameter_Alias, set_ManagementServerInformParameter_Alias, NULL, NULL},
    {"ParameterName", &DMWRITE, DMT_STRING, get_ManagementServerInformParameter_ParameterName, set_ManagementServerInformParameter_ParameterName, NULL, NULL},
    {"EventList", &DMWRITE, DMT_STRING, get_ManagementServerInformParameter_EventList, set_ManagementServerInformParameter_EventList, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Time. *** */
DMLEAF tTimeParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_Time_Enable, set_Time_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_Time_Status, NULL, NULL, NULL},
    {"NTPServer1", &DMWRITE, DMT_STRING, get_Time_NTPServer1, set_Time_NTPServer1, NULL, NULL},
    {"NTPServer2", &DMWRITE, DMT_STRING, get_Time_NTPServer2, set_Time_NTPServer2, NULL, NULL},
    {"NTPServer3", &DMWRITE, DMT_STRING, get_Time_NTPServer3, set_Time_NTPServer3, NULL, NULL},
    {"NTPServer4", &DMWRITE, DMT_STRING, get_Time_NTPServer4, set_Time_NTPServer4, NULL, NULL},
    {"NTPServer5", &DMWRITE, DMT_STRING, get_Time_NTPServer5, set_Time_NTPServer5, NULL, NULL},
    {"CurrentLocalTime", &DMREAD, DMT_TIME, get_Time_CurrentLocalTime, NULL, NULL, NULL},
    {"LocalTimeZone", &DMWRITE, DMT_STRING, get_Time_LocalTimeZone, set_Time_LocalTimeZone, NULL, NULL},
    {"LocalTimeZoneName", &DMWRITE, DMT_STRING, get_Time_LocalTimeZoneName, set_Time_LocalTimeZoneName, NULL, NULL},
    {"DaylightSavingsUsed", &DMWRITE, DMT_BOOL, get_Time_DaylightSavingsUsed, set_Time_DaylightSavingsUsed, NULL, NULL},
    {"DaylightSavingsStart", &DMWRITE, DMT_TIME, get_Time_DaylightSavingsStart, set_Time_DaylightSavingsStart, NULL, NULL},
    {"DaylightSavingsEnd", &DMWRITE, DMT_TIME, get_Time_DaylightSavingsEnd, set_Time_DaylightSavingsEnd, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UserInterface. *** */
DMOBJ tUserInterfaceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"RemoteAccess", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tUserInterfaceRemoteAccessParams, NULL},
    {"LocalDisplay", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tUserInterfaceLocalDisplayParams, NULL},
    {0}};

DMLEAF tUserInterfaceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"UserDatabaseSupported", &DMREAD, DMT_BOOL, get_UserInterface_UserDatabaseSupported, NULL, NULL, NULL},
    {"SharedPassword", &DMWRITE, DMT_BOOL, get_UserInterface_SharedPassword, set_UserInterface_SharedPassword, NULL, NULL},
    {"PasswordRequired", &DMWRITE, DMT_BOOL, get_UserInterface_PasswordRequired, set_UserInterface_PasswordRequired, NULL, NULL},
    {"PasswordUserSelectable", &DMWRITE, DMT_BOOL, get_UserInterface_PasswordUserSelectable, set_UserInterface_PasswordUserSelectable, NULL, NULL},
    {"UpgradeAvailable", &DMWRITE, DMT_BOOL, get_UserInterface_UpgradeAvailable, set_UserInterface_UpgradeAvailable, NULL, NULL},
    {"WarrantyDate", &DMWRITE, DMT_TIME, get_UserInterface_WarrantyDate, set_UserInterface_WarrantyDate, NULL, NULL},
    {"ISPName", &DMWRITE, DMT_STRING, get_UserInterface_ISPName, set_UserInterface_ISPName, NULL, NULL},
    {"ISPHelpDesk", &DMWRITE, DMT_STRING, get_UserInterface_ISPHelpDesk, set_UserInterface_ISPHelpDesk, NULL, NULL},
    {"ISPHomePage", &DMWRITE, DMT_STRING, get_UserInterface_ISPHomePage, set_UserInterface_ISPHomePage, NULL, NULL},
    {"ISPHelpPage", &DMWRITE, DMT_STRING, get_UserInterface_ISPHelpPage, set_UserInterface_ISPHelpPage, NULL, NULL},
    {"ISPLogo", &DMWRITE, DMT_BASE64, get_UserInterface_ISPLogo, set_UserInterface_ISPLogo, NULL, NULL},
    {"ISPLogoSize", &DMWRITE, DMT_UNINT, get_UserInterface_ISPLogoSize, set_UserInterface_ISPLogoSize, NULL, NULL},
    {"ISPMailServer", &DMWRITE, DMT_STRING, get_UserInterface_ISPMailServer, set_UserInterface_ISPMailServer, NULL, NULL},
    {"ISPNewsServer", &DMWRITE, DMT_STRING, get_UserInterface_ISPNewsServer, set_UserInterface_ISPNewsServer, NULL, NULL},
    {"TextColor", &DMWRITE, DMT_STRING, get_UserInterface_TextColor, set_UserInterface_TextColor, NULL, NULL},
    {"BackgroundColor", &DMWRITE, DMT_STRING, get_UserInterface_BackgroundColor, set_UserInterface_BackgroundColor, NULL, NULL},
    {"ButtonColor", &DMWRITE, DMT_STRING, get_UserInterface_ButtonColor, set_UserInterface_ButtonColor, NULL, NULL},
    {"ButtonTextColor", &DMWRITE, DMT_STRING, get_UserInterface_ButtonTextColor, set_UserInterface_ButtonTextColor, NULL, NULL},
    {"AutoUpdateServer", &DMWRITE, DMT_STRING, get_UserInterface_AutoUpdateServer, set_UserInterface_AutoUpdateServer, NULL, NULL},
    {"UserUpdateServer", &DMWRITE, DMT_STRING, get_UserInterface_UserUpdateServer, set_UserInterface_UserUpdateServer, NULL, NULL},
    {"ExampleLogin", &DMWRITE, DMT_STRING, get_UserInterface_ExampleLogin, set_UserInterface_ExampleLogin, NULL, NULL},
    {"ExamplePassword", &DMWRITE, DMT_STRING, get_UserInterface_ExamplePassword, set_UserInterface_ExamplePassword, NULL, NULL},
    {"AvailableLanguages", &DMREAD, DMT_STRING, get_UserInterface_AvailableLanguages, NULL, NULL, NULL},
    {"CurrentLanguage", &DMWRITE, DMT_STRING, get_UserInterface_CurrentLanguage, set_UserInterface_CurrentLanguage, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UserInterface.RemoteAccess. *** */
DMLEAF tUserInterfaceRemoteAccessParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_UserInterfaceRemoteAccess_Enable, set_UserInterfaceRemoteAccess_Enable, NULL, NULL},
    {"Port", &DMWRITE, DMT_UNINT, get_UserInterfaceRemoteAccess_Port, set_UserInterfaceRemoteAccess_Port, NULL, NULL},
    {"SupportedProtocols", &DMREAD, DMT_STRING, get_UserInterfaceRemoteAccess_SupportedProtocols, NULL, NULL, NULL},
    {"Protocol", &DMWRITE, DMT_STRING, get_UserInterfaceRemoteAccess_Protocol, set_UserInterfaceRemoteAccess_Protocol, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UserInterface.LocalDisplay. *** */
DMLEAF tUserInterfaceLocalDisplayParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Movable", &DMWRITE, DMT_BOOL, get_UserInterfaceLocalDisplay_Movable, set_UserInterfaceLocalDisplay_Movable, NULL, NULL},
    {"Resizable", &DMWRITE, DMT_BOOL, get_UserInterfaceLocalDisplay_Resizable, set_UserInterfaceLocalDisplay_Resizable, NULL, NULL},
    {"PosX", &DMWRITE, DMT_INT, get_UserInterfaceLocalDisplay_PosX, set_UserInterfaceLocalDisplay_PosX, NULL, NULL},
    {"PosY", &DMWRITE, DMT_INT, get_UserInterfaceLocalDisplay_PosY, set_UserInterfaceLocalDisplay_PosY, NULL, NULL},
    {"Width", &DMWRITE, DMT_UNINT, get_UserInterfaceLocalDisplay_Width, set_UserInterfaceLocalDisplay_Width, NULL, NULL},
    {"Height", &DMWRITE, DMT_UNINT, get_UserInterfaceLocalDisplay_Height, set_UserInterfaceLocalDisplay_Height, NULL, NULL},
    {"DisplayWidth", &DMREAD, DMT_UNINT, get_UserInterfaceLocalDisplay_DisplayWidth, NULL, NULL, NULL},
    {"DisplayHeight", &DMREAD, DMT_UNINT, get_UserInterfaceLocalDisplay_DisplayHeight, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.CaptivePortal. *** */
DMLEAF tCaptivePortalParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_CaptivePortal_Enable, set_CaptivePortal_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_CaptivePortal_Status, NULL, NULL, NULL},
    {"AllowedList", &DMWRITE, DMT_STRING, get_CaptivePortal_AllowedList, set_CaptivePortal_AllowedList, NULL, NULL},
    {"CaptivePortalURL", &DMWRITE, DMT_STRING, get_CaptivePortal_CaptivePortalURL, set_CaptivePortal_CaptivePortalURL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer3Forwarding. *** */
DMOBJ tLayer3ForwardingObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Forwarding", &DMWRITE, addObjLayer3ForwardingForwarding, delObjLayer3ForwardingForwarding, NULL, browseLayer3ForwardingForwardingInst, NULL, NULL, NULL, tLayer3ForwardingForwardingParams, NULL},
    {0}};

DMLEAF tLayer3ForwardingParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DefaultConnectionService", &DMWRITE, DMT_STRING, get_Layer3Forwarding_DefaultConnectionService, set_Layer3Forwarding_DefaultConnectionService, NULL, NULL},
    {"ForwardNumberOfEntries", &DMREAD, DMT_UNINT, get_Layer3Forwarding_ForwardNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer3Forwarding.Forwarding.{i}. *** */
DMLEAF tLayer3ForwardingForwardingParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_Layer3ForwardingForwarding_Enable, set_Layer3ForwardingForwarding_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_Layer3ForwardingForwarding_Status, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_Alias, set_Layer3ForwardingForwarding_Alias, NULL, NULL},
    {"StaticRoute", &DMREAD, DMT_BOOL, get_Layer3ForwardingForwarding_StaticRoute, NULL, NULL, NULL},
    {"Type", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_Type, set_Layer3ForwardingForwarding_Type, NULL, NULL},
    {"DestIPAddress", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_DestIPAddress, set_Layer3ForwardingForwarding_DestIPAddress, NULL, NULL},
    {"DestSubnetMask", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_DestSubnetMask, set_Layer3ForwardingForwarding_DestSubnetMask, NULL, NULL},
    {"SourceIPAddress", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_SourceIPAddress, set_Layer3ForwardingForwarding_SourceIPAddress, NULL, NULL},
    {"SourceSubnetMask", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_SourceSubnetMask, set_Layer3ForwardingForwarding_SourceSubnetMask, NULL, NULL},
    {"ForwardingPolicy", &DMWRITE, DMT_INT, get_Layer3ForwardingForwarding_ForwardingPolicy, set_Layer3ForwardingForwarding_ForwardingPolicy, NULL, NULL},
    {"GatewayIPAddress", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_GatewayIPAddress, set_Layer3ForwardingForwarding_GatewayIPAddress, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_Layer3ForwardingForwarding_Interface, set_Layer3ForwardingForwarding_Interface, NULL, NULL},
    {"ForwardingMetric", &DMWRITE, DMT_INT, get_Layer3ForwardingForwarding_ForwardingMetric, set_Layer3ForwardingForwarding_ForwardingMetric, NULL, NULL},
    {"MTU", &DMWRITE, DMT_UNINT, get_Layer3ForwardingForwarding_MTU, set_Layer3ForwardingForwarding_MTU, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer2Bridging. *** */
DMOBJ tLayer2BridgingObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Bridge", &DMWRITE, addObjLayer2BridgingBridge, delObjLayer2BridgingBridge, NULL, browseLayer2BridgingBridgeInst, NULL, NULL, tLayer2BridgingBridgeObj, tLayer2BridgingBridgeParams, NULL},
    {"Filter", &DMWRITE, addObjLayer2BridgingFilter, delObjLayer2BridgingFilter, NULL, browseLayer2BridgingFilterInst, NULL, NULL, NULL, tLayer2BridgingFilterParams, NULL},
    {"Marking", &DMWRITE, addObjLayer2BridgingMarking, delObjLayer2BridgingMarking, NULL, browseLayer2BridgingMarkingInst, NULL, NULL, NULL, tLayer2BridgingMarkingParams, NULL},
    {"AvailableInterface", &DMREAD, NULL, NULL, NULL, browseLayer2BridgingAvailableInterfaceInst, NULL, NULL, NULL, tLayer2BridgingAvailableInterfaceParams, NULL},
    {0}};

DMLEAF tLayer2BridgingParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"MaxBridgeEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_MaxBridgeEntries, NULL, NULL, NULL},
    {"MaxDBridgeEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_MaxDBridgeEntries, NULL, NULL, NULL},
    {"MaxQBridgeEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_MaxQBridgeEntries, NULL, NULL, NULL},
    {"MaxVLANEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_MaxVLANEntries, NULL, NULL, NULL},
    {"MaxFilterEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_MaxFilterEntries, NULL, NULL, NULL},
    {"MaxMarkingEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_MaxMarkingEntries, NULL, NULL, NULL},
    {"BridgeNumberOfEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_BridgeNumberOfEntries, NULL, NULL, NULL},
    {"FilterNumberOfEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_FilterNumberOfEntries, NULL, NULL, NULL},
    {"MarkingNumberOfEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_MarkingNumberOfEntries, NULL, NULL, NULL},
    {"AvailableInterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_Layer2Bridging_AvailableInterfaceNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer2Bridging.Bridge.{i}. *** */
DMOBJ tLayer2BridgingBridgeObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Port", &DMWRITE, addObjLayer2BridgingBridgePort, delObjLayer2BridgingBridgePort, NULL, browseLayer2BridgingBridgePortInst, NULL, NULL, NULL, tLayer2BridgingBridgePortParams, NULL},
    {"VLAN", &DMWRITE, addObjLayer2BridgingBridgeVLAN, delObjLayer2BridgingBridgeVLAN, NULL, browseLayer2BridgingBridgeVLANInst, NULL, NULL, NULL, tLayer2BridgingBridgeVLANParams, NULL},
    {0}};

DMLEAF tLayer2BridgingBridgeParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_Layer2BridgingBridge_Alias, set_Layer2BridgingBridge_Alias, NULL, NULL},
    {"BridgeKey", &DMREAD, DMT_UNINT, get_Layer2BridgingBridge_BridgeKey, NULL, NULL, NULL},
    {"BridgeStandard", &DMWRITE, DMT_STRING, get_Layer2BridgingBridge_BridgeStandard, set_Layer2BridgingBridge_BridgeStandard, NULL, NULL},
    {"BridgeEnable", &DMWRITE, DMT_BOOL, get_Layer2BridgingBridge_BridgeEnable, set_Layer2BridgingBridge_BridgeEnable, NULL, NULL},
    {"BridgeStatus", &DMREAD, DMT_STRING, get_Layer2BridgingBridge_BridgeStatus, NULL, NULL, NULL},
    {"BridgeName", &DMWRITE, DMT_STRING, get_Layer2BridgingBridge_BridgeName, set_Layer2BridgingBridge_BridgeName, NULL, NULL},
    {"VLANID", &DMWRITE, DMT_UNINT, get_Layer2BridgingBridge_VLANID, set_Layer2BridgingBridge_VLANID, NULL, NULL},
    {"PortNumberOfEntries", &DMREAD, DMT_UNINT, get_Layer2BridgingBridge_PortNumberOfEntries, NULL, NULL, NULL},
    {"VLANNumberOfEntries", &DMREAD, DMT_UNINT, get_Layer2BridgingBridge_VLANNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer2Bridging.Bridge.{i}.Port.{i}. *** */
DMLEAF tLayer2BridgingBridgePortParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"PortEnable", &DMWRITE, DMT_BOOL, get_Layer2BridgingBridgePort_PortEnable, set_Layer2BridgingBridgePort_PortEnable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_Layer2BridgingBridgePort_Alias, set_Layer2BridgingBridgePort_Alias, NULL, NULL},
    {"PortInterface", &DMWRITE, DMT_STRING, get_Layer2BridgingBridgePort_PortInterface, set_Layer2BridgingBridgePort_PortInterface, NULL, NULL},
    {"PortState", &DMREAD, DMT_STRING, get_Layer2BridgingBridgePort_PortState, NULL, NULL, NULL},
    {"PVID", &DMWRITE, DMT_INT, get_Layer2BridgingBridgePort_PVID, set_Layer2BridgingBridgePort_PVID, NULL, NULL},
    {"AcceptableFrameTypes", &DMWRITE, DMT_STRING, get_Layer2BridgingBridgePort_AcceptableFrameTypes, set_Layer2BridgingBridgePort_AcceptableFrameTypes, NULL, NULL},
    {"IngressFiltering", &DMWRITE, DMT_BOOL, get_Layer2BridgingBridgePort_IngressFiltering, set_Layer2BridgingBridgePort_IngressFiltering, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer2Bridging.Bridge.{i}.VLAN.{i}. *** */
DMLEAF tLayer2BridgingBridgeVLANParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"VLANEnable", &DMWRITE, DMT_BOOL, get_Layer2BridgingBridgeVLAN_VLANEnable, set_Layer2BridgingBridgeVLAN_VLANEnable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_Layer2BridgingBridgeVLAN_Alias, set_Layer2BridgingBridgeVLAN_Alias, NULL, NULL},
    {"VLANName", &DMWRITE, DMT_STRING, get_Layer2BridgingBridgeVLAN_VLANName, set_Layer2BridgingBridgeVLAN_VLANName, NULL, NULL},
    {"VLANID", &DMWRITE, DMT_INT, get_Layer2BridgingBridgeVLAN_VLANID, set_Layer2BridgingBridgeVLAN_VLANID, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer2Bridging.Filter.{i}. *** */
DMLEAF tLayer2BridgingFilterParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_Alias, set_Layer2BridgingFilter_Alias, NULL, NULL},
    {"FilterKey", &DMREAD, DMT_UNINT, get_Layer2BridgingFilter_FilterKey, NULL, NULL, NULL},
    {"FilterEnable", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_FilterEnable, set_Layer2BridgingFilter_FilterEnable, NULL, NULL},
    {"FilterStatus", &DMREAD, DMT_STRING, get_Layer2BridgingFilter_FilterStatus, NULL, NULL, NULL},
    {"FilterBridgeReference", &DMWRITE, DMT_INT, get_Layer2BridgingFilter_FilterBridgeReference, set_Layer2BridgingFilter_FilterBridgeReference, NULL, NULL},
    {"ExclusivityOrder", &DMWRITE, DMT_UNINT, get_Layer2BridgingFilter_ExclusivityOrder, set_Layer2BridgingFilter_ExclusivityOrder, NULL, NULL},
    {"FilterInterface", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_FilterInterface, set_Layer2BridgingFilter_FilterInterface, NULL, NULL},
    {"VLANIDFilter", &DMWRITE, DMT_INT, get_Layer2BridgingFilter_VLANIDFilter, set_Layer2BridgingFilter_VLANIDFilter, NULL, NULL},
    {"AdmitOnlyVLANTagged", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_AdmitOnlyVLANTagged, set_Layer2BridgingFilter_AdmitOnlyVLANTagged, NULL, NULL},
    {"EthertypeFilterList", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_EthertypeFilterList, set_Layer2BridgingFilter_EthertypeFilterList, NULL, NULL},
    {"EthertypeFilterExclude", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_EthertypeFilterExclude, set_Layer2BridgingFilter_EthertypeFilterExclude, NULL, NULL},
    {"SourceMACAddressFilterList", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_SourceMACAddressFilterList, set_Layer2BridgingFilter_SourceMACAddressFilterList, NULL, NULL},
    {"SourceMACAddressFilterExclude", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_SourceMACAddressFilterExclude, set_Layer2BridgingFilter_SourceMACAddressFilterExclude, NULL, NULL},
    {"DestMACAddressFilterList", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_DestMACAddressFilterList, set_Layer2BridgingFilter_DestMACAddressFilterList, NULL, NULL},
    {"DestMACAddressFilterExclude", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_DestMACAddressFilterExclude, set_Layer2BridgingFilter_DestMACAddressFilterExclude, NULL, NULL},
    {"SourceMACFromVendorClassIDFilter", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_SourceMACFromVendorClassIDFilter, set_Layer2BridgingFilter_SourceMACFromVendorClassIDFilter, NULL, NULL},
    {"SourceMACFromVendorClassIDFilterExclude",
     &DMWRITE,
     DMT_BOOL,
     get_Layer2BridgingFilter_SourceMACFromVendorClassIDFilterExclude,
     set_Layer2BridgingFilter_SourceMACFromVendorClassIDFilterExclude,
     NULL,
     NULL},
    {"SourceMACFromVendorClassIDMode", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_SourceMACFromVendorClassIDMode, set_Layer2BridgingFilter_SourceMACFromVendorClassIDMode, NULL, NULL},
    {"DestMACFromVendorClassIDFilter", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_DestMACFromVendorClassIDFilter, set_Layer2BridgingFilter_DestMACFromVendorClassIDFilter, NULL, NULL},
    {"DestMACFromVendorClassIDFilterExclude",
     &DMWRITE,
     DMT_BOOL,
     get_Layer2BridgingFilter_DestMACFromVendorClassIDFilterExclude,
     set_Layer2BridgingFilter_DestMACFromVendorClassIDFilterExclude,
     NULL,
     NULL},
    {"DestMACFromVendorClassIDMode", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_DestMACFromVendorClassIDMode, set_Layer2BridgingFilter_DestMACFromVendorClassIDMode, NULL, NULL},
    {"SourceMACFromClientIDFilter", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_SourceMACFromClientIDFilter, set_Layer2BridgingFilter_SourceMACFromClientIDFilter, NULL, NULL},
    {"SourceMACFromClientIDFilterExclude", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_SourceMACFromClientIDFilterExclude, set_Layer2BridgingFilter_SourceMACFromClientIDFilterExclude, NULL, NULL},
    {"DestMACFromClientIDFilter", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_DestMACFromClientIDFilter, set_Layer2BridgingFilter_DestMACFromClientIDFilter, NULL, NULL},
    {"DestMACFromClientIDFilterExclude", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_DestMACFromClientIDFilterExclude, set_Layer2BridgingFilter_DestMACFromClientIDFilterExclude, NULL, NULL},
    {"SourceMACFromUserClassIDFilter", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_SourceMACFromUserClassIDFilter, set_Layer2BridgingFilter_SourceMACFromUserClassIDFilter, NULL, NULL},
    {"SourceMACFromUserClassIDFilterExclude",
     &DMWRITE,
     DMT_BOOL,
     get_Layer2BridgingFilter_SourceMACFromUserClassIDFilterExclude,
     set_Layer2BridgingFilter_SourceMACFromUserClassIDFilterExclude,
     NULL,
     NULL},
    {"DestMACFromUserClassIDFilter", &DMWRITE, DMT_STRING, get_Layer2BridgingFilter_DestMACFromUserClassIDFilter, set_Layer2BridgingFilter_DestMACFromUserClassIDFilter, NULL, NULL},
    {"DestMACFromUserClassIDFilterExclude", &DMWRITE, DMT_BOOL, get_Layer2BridgingFilter_DestMACFromUserClassIDFilterExclude, set_Layer2BridgingFilter_DestMACFromUserClassIDFilterExclude, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer2Bridging.Marking.{i}. *** */
DMLEAF tLayer2BridgingMarkingParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_Layer2BridgingMarking_Alias, set_Layer2BridgingMarking_Alias, NULL, NULL},
    {"MarkingKey", &DMREAD, DMT_UNINT, get_Layer2BridgingMarking_MarkingKey, NULL, NULL, NULL},
    {"MarkingEnable", &DMWRITE, DMT_BOOL, get_Layer2BridgingMarking_MarkingEnable, set_Layer2BridgingMarking_MarkingEnable, NULL, NULL},
    {"MarkingStatus", &DMREAD, DMT_STRING, get_Layer2BridgingMarking_MarkingStatus, NULL, NULL, NULL},
    {"MarkingBridgeReference", &DMWRITE, DMT_INT, get_Layer2BridgingMarking_MarkingBridgeReference, set_Layer2BridgingMarking_MarkingBridgeReference, NULL, NULL},
    {"MarkingInterface", &DMWRITE, DMT_STRING, get_Layer2BridgingMarking_MarkingInterface, set_Layer2BridgingMarking_MarkingInterface, NULL, NULL},
    {"VLANIDUntag", &DMWRITE, DMT_BOOL, get_Layer2BridgingMarking_VLANIDUntag, set_Layer2BridgingMarking_VLANIDUntag, NULL, NULL},
    {"VLANIDMark", &DMWRITE, DMT_INT, get_Layer2BridgingMarking_VLANIDMark, set_Layer2BridgingMarking_VLANIDMark, NULL, NULL},
    {"VLANIDMarkOverride", &DMWRITE, DMT_BOOL, get_Layer2BridgingMarking_VLANIDMarkOverride, set_Layer2BridgingMarking_VLANIDMarkOverride, NULL, NULL},
    {"EthernetPriorityMark", &DMWRITE, DMT_INT, get_Layer2BridgingMarking_EthernetPriorityMark, set_Layer2BridgingMarking_EthernetPriorityMark, NULL, NULL},
    {"EthernetPriorityOverride", &DMWRITE, DMT_BOOL, get_Layer2BridgingMarking_EthernetPriorityOverride, set_Layer2BridgingMarking_EthernetPriorityOverride, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Layer2Bridging.AvailableInterface.{i}. *** */
DMLEAF tLayer2BridgingAvailableInterfaceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_Layer2BridgingAvailableInterface_Alias, set_Layer2BridgingAvailableInterface_Alias, NULL, NULL},
    {"AvailableInterfaceKey", &DMREAD, DMT_UNINT, get_Layer2BridgingAvailableInterface_AvailableInterfaceKey, NULL, NULL, NULL},
    {"InterfaceType", &DMREAD, DMT_STRING, get_Layer2BridgingAvailableInterface_InterfaceType, NULL, NULL, NULL},
    {"InterfaceReference", &DMREAD, DMT_STRING, get_Layer2BridgingAvailableInterface_InterfaceReference, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.QueueManagement. *** */
DMOBJ tQueueManagementObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Classification",
     &DMWRITE,
     addObjQueueManagementClassification,
     delObjQueueManagementClassification,
     NULL,
     browseQueueManagementClassificationInst,
     NULL,
     NULL,
     NULL,
     tQueueManagementClassificationParams,
     NULL},
    {"App", &DMWRITE, addObjQueueManagementApp, delObjQueueManagementApp, NULL, browseQueueManagementAppInst, NULL, NULL, NULL, tQueueManagementAppParams, NULL},
    {"Flow", &DMWRITE, addObjQueueManagementFlow, delObjQueueManagementFlow, NULL, browseQueueManagementFlowInst, NULL, NULL, NULL, tQueueManagementFlowParams, NULL},
    {"Policer", &DMWRITE, addObjQueueManagementPolicer, delObjQueueManagementPolicer, NULL, browseQueueManagementPolicerInst, NULL, NULL, NULL, tQueueManagementPolicerParams, NULL},
    {"Queue", &DMWRITE, addObjQueueManagementQueue, delObjQueueManagementQueue, NULL, browseQueueManagementQueueInst, NULL, NULL, NULL, tQueueManagementQueueParams, NULL},
    {"QueueStats", &DMWRITE, addObjQueueManagementQueueStats, delObjQueueManagementQueueStats, NULL, browseQueueManagementQueueStatsInst, NULL, NULL, NULL, tQueueManagementQueueStatsParams, NULL},
    {0}};

DMLEAF tQueueManagementParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_QueueManagement_Enable, set_QueueManagement_Enable, NULL, NULL},
    {"MaxQueues", &DMREAD, DMT_UNINT, get_QueueManagement_MaxQueues, NULL, NULL, NULL},
    {"MaxClassificationEntries", &DMREAD, DMT_UNINT, get_QueueManagement_MaxClassificationEntries, NULL, NULL, NULL},
    {"ClassificationNumberOfEntries", &DMREAD, DMT_UNINT, get_QueueManagement_ClassificationNumberOfEntries, NULL, NULL, NULL},
    {"MaxAppEntries", &DMREAD, DMT_UNINT, get_QueueManagement_MaxAppEntries, NULL, NULL, NULL},
    {"AppNumberOfEntries", &DMREAD, DMT_UNINT, get_QueueManagement_AppNumberOfEntries, NULL, NULL, NULL},
    {"MaxFlowEntries", &DMREAD, DMT_UNINT, get_QueueManagement_MaxFlowEntries, NULL, NULL, NULL},
    {"FlowNumberOfEntries", &DMREAD, DMT_UNINT, get_QueueManagement_FlowNumberOfEntries, NULL, NULL, NULL},
    {"MaxPolicerEntries", &DMREAD, DMT_UNINT, get_QueueManagement_MaxPolicerEntries, NULL, NULL, NULL},
    {"PolicerNumberOfEntries", &DMREAD, DMT_UNINT, get_QueueManagement_PolicerNumberOfEntries, NULL, NULL, NULL},
    {"MaxQueueEntries", &DMREAD, DMT_UNINT, get_QueueManagement_MaxQueueEntries, NULL, NULL, NULL},
    {"QueueNumberOfEntries", &DMREAD, DMT_UNINT, get_QueueManagement_QueueNumberOfEntries, NULL, NULL, NULL},
    {"QueueStatsNumberOfEntries", &DMREAD, DMT_UNINT, get_QueueManagement_QueueStatsNumberOfEntries, NULL, NULL, NULL},
    {"DefaultForwardingPolicy", &DMWRITE, DMT_UNINT, get_QueueManagement_DefaultForwardingPolicy, set_QueueManagement_DefaultForwardingPolicy, NULL, NULL},
    {"DefaultTrafficClass", &DMWRITE, DMT_INT, get_QueueManagement_DefaultTrafficClass, set_QueueManagement_DefaultTrafficClass, NULL, NULL},
    {"DefaultPolicer", &DMWRITE, DMT_INT, get_QueueManagement_DefaultPolicer, set_QueueManagement_DefaultPolicer, NULL, NULL},
    {"DefaultQueue", &DMWRITE, DMT_UNINT, get_QueueManagement_DefaultQueue, set_QueueManagement_DefaultQueue, NULL, NULL},
    {"DefaultDSCPMark", &DMWRITE, DMT_INT, get_QueueManagement_DefaultDSCPMark, set_QueueManagement_DefaultDSCPMark, NULL, NULL},
    {"DefaultEthernetPriorityMark", &DMWRITE, DMT_INT, get_QueueManagement_DefaultEthernetPriorityMark, set_QueueManagement_DefaultEthernetPriorityMark, NULL, NULL},
    {"AvailableAppList", &DMREAD, DMT_STRING, get_QueueManagement_AvailableAppList, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.QueueManagement.Classification.{i}. *** */
DMLEAF tQueueManagementClassificationParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ClassificationKey", &DMREAD, DMT_UNINT, get_QueueManagementClassification_ClassificationKey, NULL, NULL, NULL},
    {"ClassificationEnable", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_ClassificationEnable, set_QueueManagementClassification_ClassificationEnable, NULL, NULL},
    {"ClassificationStatus", &DMREAD, DMT_STRING, get_QueueManagementClassification_ClassificationStatus, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_QueueManagementClassification_Alias, set_QueueManagementClassification_Alias, NULL, NULL},
    {"ClassificationOrder", &DMWRITE, DMT_UNINT, get_QueueManagementClassification_ClassificationOrder, set_QueueManagementClassification_ClassificationOrder, NULL, NULL},
    {"ClassInterface", &DMWRITE, DMT_STRING, get_QueueManagementClassification_ClassInterface, set_QueueManagementClassification_ClassInterface, NULL, NULL},
    {"DestIP", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestIP, set_QueueManagementClassification_DestIP, NULL, NULL},
    {"DestMask", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestMask, set_QueueManagementClassification_DestMask, NULL, NULL},
    {"DestIPExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DestIPExclude, set_QueueManagementClassification_DestIPExclude, NULL, NULL},
    {"SourceIP", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceIP, set_QueueManagementClassification_SourceIP, NULL, NULL},
    {"SourceMask", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceMask, set_QueueManagementClassification_SourceMask, NULL, NULL},
    {"SourceIPExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SourceIPExclude, set_QueueManagementClassification_SourceIPExclude, NULL, NULL},
    {"Protocol", &DMWRITE, DMT_INT, get_QueueManagementClassification_Protocol, set_QueueManagementClassification_Protocol, NULL, NULL},
    {"ProtocolExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_ProtocolExclude, set_QueueManagementClassification_ProtocolExclude, NULL, NULL},
    {"DestPort", &DMWRITE, DMT_INT, get_QueueManagementClassification_DestPort, set_QueueManagementClassification_DestPort, NULL, NULL},
    {"DestPortRangeMax", &DMWRITE, DMT_INT, get_QueueManagementClassification_DestPortRangeMax, set_QueueManagementClassification_DestPortRangeMax, NULL, NULL},
    {"DestPortExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DestPortExclude, set_QueueManagementClassification_DestPortExclude, NULL, NULL},
    {"SourcePort", &DMWRITE, DMT_INT, get_QueueManagementClassification_SourcePort, set_QueueManagementClassification_SourcePort, NULL, NULL},
    {"SourcePortRangeMax", &DMWRITE, DMT_INT, get_QueueManagementClassification_SourcePortRangeMax, set_QueueManagementClassification_SourcePortRangeMax, NULL, NULL},
    {"SourcePortExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SourcePortExclude, set_QueueManagementClassification_SourcePortExclude, NULL, NULL},
    {"SourceMACAddress", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceMACAddress, set_QueueManagementClassification_SourceMACAddress, NULL, NULL},
    {"SourceMACMask", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceMACMask, set_QueueManagementClassification_SourceMACMask, NULL, NULL},
    {"SourceMACExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SourceMACExclude, set_QueueManagementClassification_SourceMACExclude, NULL, NULL},
    {"DestMACAddress", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestMACAddress, set_QueueManagementClassification_DestMACAddress, NULL, NULL},
    {"DestMACMask", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestMACMask, set_QueueManagementClassification_DestMACMask, NULL, NULL},
    {"DestMACExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DestMACExclude, set_QueueManagementClassification_DestMACExclude, NULL, NULL},
    {"Ethertype", &DMWRITE, DMT_INT, get_QueueManagementClassification_Ethertype, set_QueueManagementClassification_Ethertype, NULL, NULL},
    {"EthertypeExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_EthertypeExclude, set_QueueManagementClassification_EthertypeExclude, NULL, NULL},
    {"SSAP", &DMWRITE, DMT_INT, get_QueueManagementClassification_SSAP, set_QueueManagementClassification_SSAP, NULL, NULL},
    {"SSAPExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SSAPExclude, set_QueueManagementClassification_SSAPExclude, NULL, NULL},
    {"DSAP", &DMWRITE, DMT_INT, get_QueueManagementClassification_DSAP, set_QueueManagementClassification_DSAP, NULL, NULL},
    {"DSAPExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DSAPExclude, set_QueueManagementClassification_DSAPExclude, NULL, NULL},
    {"LLCControl", &DMWRITE, DMT_INT, get_QueueManagementClassification_LLCControl, set_QueueManagementClassification_LLCControl, NULL, NULL},
    {"LLCControlExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_LLCControlExclude, set_QueueManagementClassification_LLCControlExclude, NULL, NULL},
    {"SNAPOUI", &DMWRITE, DMT_INT, get_QueueManagementClassification_SNAPOUI, set_QueueManagementClassification_SNAPOUI, NULL, NULL},
    {"SNAPOUIExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SNAPOUIExclude, set_QueueManagementClassification_SNAPOUIExclude, NULL, NULL},
    {"SourceVendorClassID", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceVendorClassID, set_QueueManagementClassification_SourceVendorClassID, NULL, NULL},
    {"SourceVendorClassIDExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SourceVendorClassIDExclude, set_QueueManagementClassification_SourceVendorClassIDExclude, NULL, NULL},
    {"SourceVendorClassIDMode", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceVendorClassIDMode, set_QueueManagementClassification_SourceVendorClassIDMode, NULL, NULL},
    {"DestVendorClassID", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestVendorClassID, set_QueueManagementClassification_DestVendorClassID, NULL, NULL},
    {"DestVendorClassIDExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DestVendorClassIDExclude, set_QueueManagementClassification_DestVendorClassIDExclude, NULL, NULL},
    {"DestVendorClassIDMode", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestVendorClassIDMode, set_QueueManagementClassification_DestVendorClassIDMode, NULL, NULL},
    {"SourceClientID", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceClientID, set_QueueManagementClassification_SourceClientID, NULL, NULL},
    {"SourceClientIDExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SourceClientIDExclude, set_QueueManagementClassification_SourceClientIDExclude, NULL, NULL},
    {"DestClientID", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestClientID, set_QueueManagementClassification_DestClientID, NULL, NULL},
    {"DestClientIDExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DestClientIDExclude, set_QueueManagementClassification_DestClientIDExclude, NULL, NULL},
    {"SourceUserClassID", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceUserClassID, set_QueueManagementClassification_SourceUserClassID, NULL, NULL},
    {"SourceUserClassIDExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_SourceUserClassIDExclude, set_QueueManagementClassification_SourceUserClassIDExclude, NULL, NULL},
    {"DestUserClassID", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestUserClassID, set_QueueManagementClassification_DestUserClassID, NULL, NULL},
    {"DestUserClassIDExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DestUserClassIDExclude, set_QueueManagementClassification_DestUserClassIDExclude, NULL, NULL},
    {"SourceVendorSpecificInfo", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceVendorSpecificInfo, set_QueueManagementClassification_SourceVendorSpecificInfo, NULL, NULL},
    {"SourceVendorSpecificInfoExclude",
     &DMWRITE,
     DMT_BOOL,
     get_QueueManagementClassification_SourceVendorSpecificInfoExclude,
     set_QueueManagementClassification_SourceVendorSpecificInfoExclude,
     NULL,
     NULL},
    {"SourceVendorSpecificInfoEnterprise",
     &DMWRITE,
     DMT_UNINT,
     get_QueueManagementClassification_SourceVendorSpecificInfoEnterprise,
     set_QueueManagementClassification_SourceVendorSpecificInfoEnterprise,
     NULL,
     NULL},
    {"SourceVendorSpecificInfoSubOption",
     &DMWRITE,
     DMT_INT,
     get_QueueManagementClassification_SourceVendorSpecificInfoSubOption,
     set_QueueManagementClassification_SourceVendorSpecificInfoSubOption,
     NULL,
     NULL},
    {"SourceVendorSpecificInfoMode", &DMWRITE, DMT_STRING, get_QueueManagementClassification_SourceVendorSpecificInfoMode, set_QueueManagementClassification_SourceVendorSpecificInfoMode, NULL, NULL},
    {"DestVendorSpecificInfo", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestVendorSpecificInfo, set_QueueManagementClassification_DestVendorSpecificInfo, NULL, NULL},
    {"DestVendorSpecificInfoExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DestVendorSpecificInfoExclude, set_QueueManagementClassification_DestVendorSpecificInfoExclude, NULL, NULL},
    {"DestVendorSpecificInfoEnterprise",
     &DMWRITE,
     DMT_UNINT,
     get_QueueManagementClassification_DestVendorSpecificInfoEnterprise,
     set_QueueManagementClassification_DestVendorSpecificInfoEnterprise,
     NULL,
     NULL},
    {"DestVendorSpecificInfoSubOption",
     &DMWRITE,
     DMT_INT,
     get_QueueManagementClassification_DestVendorSpecificInfoSubOption,
     set_QueueManagementClassification_DestVendorSpecificInfoSubOption,
     NULL,
     NULL},
    {"DestVendorSpecificInfoMode", &DMWRITE, DMT_STRING, get_QueueManagementClassification_DestVendorSpecificInfoMode, set_QueueManagementClassification_DestVendorSpecificInfoMode, NULL, NULL},
    {"TCPACK", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_TCPACK, set_QueueManagementClassification_TCPACK, NULL, NULL},
    {"TCPACKExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_TCPACKExclude, set_QueueManagementClassification_TCPACKExclude, NULL, NULL},
    {"IPLengthMin", &DMWRITE, DMT_UNINT, get_QueueManagementClassification_IPLengthMin, set_QueueManagementClassification_IPLengthMin, NULL, NULL},
    {"IPLengthMax", &DMWRITE, DMT_UNINT, get_QueueManagementClassification_IPLengthMax, set_QueueManagementClassification_IPLengthMax, NULL, NULL},
    {"IPLengthExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_IPLengthExclude, set_QueueManagementClassification_IPLengthExclude, NULL, NULL},
    {"DSCPCheck", &DMWRITE, DMT_INT, get_QueueManagementClassification_DSCPCheck, set_QueueManagementClassification_DSCPCheck, NULL, NULL},
    {"DSCPExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_DSCPExclude, set_QueueManagementClassification_DSCPExclude, NULL, NULL},
    {"DSCPMark", &DMWRITE, DMT_INT, get_QueueManagementClassification_DSCPMark, set_QueueManagementClassification_DSCPMark, NULL, NULL},
    {"EthernetPriorityCheck", &DMWRITE, DMT_INT, get_QueueManagementClassification_EthernetPriorityCheck, set_QueueManagementClassification_EthernetPriorityCheck, NULL, NULL},
    {"EthernetPriorityExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_EthernetPriorityExclude, set_QueueManagementClassification_EthernetPriorityExclude, NULL, NULL},
    {"EthernetPriorityMark", &DMWRITE, DMT_INT, get_QueueManagementClassification_EthernetPriorityMark, set_QueueManagementClassification_EthernetPriorityMark, NULL, NULL},
    {"VLANIDCheck", &DMWRITE, DMT_INT, get_QueueManagementClassification_VLANIDCheck, set_QueueManagementClassification_VLANIDCheck, NULL, NULL},
    {"VLANIDExclude", &DMWRITE, DMT_BOOL, get_QueueManagementClassification_VLANIDExclude, set_QueueManagementClassification_VLANIDExclude, NULL, NULL},
    {"OutOfBandInfo", &DMWRITE, DMT_INT, get_QueueManagementClassification_OutOfBandInfo, set_QueueManagementClassification_OutOfBandInfo, NULL, NULL},
    {"ForwardingPolicy", &DMWRITE, DMT_UNINT, get_QueueManagementClassification_ForwardingPolicy, set_QueueManagementClassification_ForwardingPolicy, NULL, NULL},
    {"TrafficClass", &DMWRITE, DMT_INT, get_QueueManagementClassification_TrafficClass, set_QueueManagementClassification_TrafficClass, NULL, NULL},
    {"ClassPolicer", &DMWRITE, DMT_INT, get_QueueManagementClassification_ClassPolicer, set_QueueManagementClassification_ClassPolicer, NULL, NULL},
    {"ClassQueue", &DMWRITE, DMT_INT, get_QueueManagementClassification_ClassQueue, set_QueueManagementClassification_ClassQueue, NULL, NULL},
    {"ClassApp", &DMWRITE, DMT_INT, get_QueueManagementClassification_ClassApp, set_QueueManagementClassification_ClassApp, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.QueueManagement.App.{i}. *** */
DMLEAF tQueueManagementAppParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"AppKey", &DMREAD, DMT_UNINT, get_QueueManagementApp_AppKey, NULL, NULL, NULL},
    {"AppEnable", &DMWRITE, DMT_BOOL, get_QueueManagementApp_AppEnable, set_QueueManagementApp_AppEnable, NULL, NULL},
    {"AppStatus", &DMREAD, DMT_STRING, get_QueueManagementApp_AppStatus, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_QueueManagementApp_Alias, set_QueueManagementApp_Alias, NULL, NULL},
    {"ProtocolIdentifier", &DMWRITE, DMT_STRING, get_QueueManagementApp_ProtocolIdentifier, set_QueueManagementApp_ProtocolIdentifier, NULL, NULL},
    {"AppName", &DMWRITE, DMT_STRING, get_QueueManagementApp_AppName, set_QueueManagementApp_AppName, NULL, NULL},
    {"AppDefaultForwardingPolicy", &DMWRITE, DMT_UNINT, get_QueueManagementApp_AppDefaultForwardingPolicy, set_QueueManagementApp_AppDefaultForwardingPolicy, NULL, NULL},
    {"AppDefaultTrafficClass", &DMWRITE, DMT_INT, get_QueueManagementApp_AppDefaultTrafficClass, set_QueueManagementApp_AppDefaultTrafficClass, NULL, NULL},
    {"AppDefaultPolicer", &DMWRITE, DMT_INT, get_QueueManagementApp_AppDefaultPolicer, set_QueueManagementApp_AppDefaultPolicer, NULL, NULL},
    {"AppDefaultQueue", &DMWRITE, DMT_INT, get_QueueManagementApp_AppDefaultQueue, set_QueueManagementApp_AppDefaultQueue, NULL, NULL},
    {"AppDefaultDSCPMark", &DMWRITE, DMT_INT, get_QueueManagementApp_AppDefaultDSCPMark, set_QueueManagementApp_AppDefaultDSCPMark, NULL, NULL},
    {"AppDefaultEthernetPriorityMark", &DMWRITE, DMT_INT, get_QueueManagementApp_AppDefaultEthernetPriorityMark, set_QueueManagementApp_AppDefaultEthernetPriorityMark, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.QueueManagement.Flow.{i}. *** */
DMLEAF tQueueManagementFlowParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"FlowKey", &DMREAD, DMT_UNINT, get_QueueManagementFlow_FlowKey, NULL, NULL, NULL},
    {"FlowEnable", &DMWRITE, DMT_BOOL, get_QueueManagementFlow_FlowEnable, set_QueueManagementFlow_FlowEnable, NULL, NULL},
    {"FlowStatus", &DMREAD, DMT_STRING, get_QueueManagementFlow_FlowStatus, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_QueueManagementFlow_Alias, set_QueueManagementFlow_Alias, NULL, NULL},
    {"FlowType", &DMWRITE, DMT_STRING, get_QueueManagementFlow_FlowType, set_QueueManagementFlow_FlowType, NULL, NULL},
    {"FlowTypeParameters", &DMWRITE, DMT_STRING, get_QueueManagementFlow_FlowTypeParameters, set_QueueManagementFlow_FlowTypeParameters, NULL, NULL},
    {"FlowName", &DMWRITE, DMT_STRING, get_QueueManagementFlow_FlowName, set_QueueManagementFlow_FlowName, NULL, NULL},
    {"AppIdentifier", &DMWRITE, DMT_INT, get_QueueManagementFlow_AppIdentifier, set_QueueManagementFlow_AppIdentifier, NULL, NULL},
    {"FlowForwardingPolicy", &DMWRITE, DMT_UNINT, get_QueueManagementFlow_FlowForwardingPolicy, set_QueueManagementFlow_FlowForwardingPolicy, NULL, NULL},
    {"FlowTrafficClass", &DMWRITE, DMT_INT, get_QueueManagementFlow_FlowTrafficClass, set_QueueManagementFlow_FlowTrafficClass, NULL, NULL},
    {"FlowPolicer", &DMWRITE, DMT_INT, get_QueueManagementFlow_FlowPolicer, set_QueueManagementFlow_FlowPolicer, NULL, NULL},
    {"FlowQueue", &DMWRITE, DMT_INT, get_QueueManagementFlow_FlowQueue, set_QueueManagementFlow_FlowQueue, NULL, NULL},
    {"FlowDSCPMark", &DMWRITE, DMT_INT, get_QueueManagementFlow_FlowDSCPMark, set_QueueManagementFlow_FlowDSCPMark, NULL, NULL},
    {"FlowEthernetPriorityMark", &DMWRITE, DMT_INT, get_QueueManagementFlow_FlowEthernetPriorityMark, set_QueueManagementFlow_FlowEthernetPriorityMark, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.QueueManagement.Policer.{i}. *** */
DMLEAF tQueueManagementPolicerParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"PolicerKey", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_PolicerKey, NULL, NULL, NULL},
    {"PolicerEnable", &DMWRITE, DMT_BOOL, get_QueueManagementPolicer_PolicerEnable, set_QueueManagementPolicer_PolicerEnable, NULL, NULL},
    {"PolicerStatus", &DMREAD, DMT_STRING, get_QueueManagementPolicer_PolicerStatus, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_QueueManagementPolicer_Alias, set_QueueManagementPolicer_Alias, NULL, NULL},
    {"CommittedRate", &DMWRITE, DMT_UNINT, get_QueueManagementPolicer_CommittedRate, set_QueueManagementPolicer_CommittedRate, NULL, NULL},
    {"CommittedBurstSize", &DMWRITE, DMT_UNINT, get_QueueManagementPolicer_CommittedBurstSize, set_QueueManagementPolicer_CommittedBurstSize, NULL, NULL},
    {"ExcessBurstSize", &DMWRITE, DMT_UNINT, get_QueueManagementPolicer_ExcessBurstSize, set_QueueManagementPolicer_ExcessBurstSize, NULL, NULL},
    {"PeakRate", &DMWRITE, DMT_UNINT, get_QueueManagementPolicer_PeakRate, set_QueueManagementPolicer_PeakRate, NULL, NULL},
    {"PeakBurstSize", &DMWRITE, DMT_UNINT, get_QueueManagementPolicer_PeakBurstSize, set_QueueManagementPolicer_PeakBurstSize, NULL, NULL},
    {"MeterType", &DMWRITE, DMT_STRING, get_QueueManagementPolicer_MeterType, set_QueueManagementPolicer_MeterType, NULL, NULL},
    {"PossibleMeterTypes", &DMREAD, DMT_STRING, get_QueueManagementPolicer_PossibleMeterTypes, NULL, NULL, NULL},
    {"ConformingAction", &DMWRITE, DMT_STRING, get_QueueManagementPolicer_ConformingAction, set_QueueManagementPolicer_ConformingAction, NULL, NULL},
    {"PartialConformingAction", &DMWRITE, DMT_STRING, get_QueueManagementPolicer_PartialConformingAction, set_QueueManagementPolicer_PartialConformingAction, NULL, NULL},
    {"NonConformingAction", &DMWRITE, DMT_STRING, get_QueueManagementPolicer_NonConformingAction, set_QueueManagementPolicer_NonConformingAction, NULL, NULL},
    {"CountedPackets", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_CountedPackets, NULL, NULL, NULL},
    {"CountedBytes", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_CountedBytes, NULL, NULL, NULL},
    {"TotalCountedPackets", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_TotalCountedPackets, NULL, NULL, NULL},
    {"TotalCountedBytes", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_TotalCountedBytes, NULL, NULL, NULL},
    {"ConformingCountedPackets", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_ConformingCountedPackets, NULL, NULL, NULL},
    {"ConformingCountedBytes", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_ConformingCountedBytes, NULL, NULL, NULL},
    {"PartiallyConformingCountedPackets", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_PartiallyConformingCountedPackets, NULL, NULL, NULL},
    {"PartiallyConformingCountedBytes", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_PartiallyConformingCountedBytes, NULL, NULL, NULL},
    {"NonConformingCountedPackets", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_NonConformingCountedPackets, NULL, NULL, NULL},
    {"NonConformingCountedBytes", &DMREAD, DMT_UNINT, get_QueueManagementPolicer_NonConformingCountedBytes, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.QueueManagement.Queue.{i}. *** */
DMLEAF tQueueManagementQueueParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"QueueKey", &DMREAD, DMT_UNINT, get_QueueManagementQueue_QueueKey, NULL, NULL, NULL},
    {"QueueEnable", &DMWRITE, DMT_BOOL, get_QueueManagementQueue_QueueEnable, set_QueueManagementQueue_QueueEnable, NULL, NULL},
    {"QueueStatus", &DMREAD, DMT_STRING, get_QueueManagementQueue_QueueStatus, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_QueueManagementQueue_Alias, set_QueueManagementQueue_Alias, NULL, NULL},
    {"TrafficClasses", &DMWRITE, DMT_STRING, get_QueueManagementQueue_TrafficClasses, set_QueueManagementQueue_TrafficClasses, NULL, NULL},
    {"QueueInterface", &DMWRITE, DMT_STRING, get_QueueManagementQueue_QueueInterface, set_QueueManagementQueue_QueueInterface, NULL, NULL},
    {"QueueBufferLength", &DMREAD, DMT_UNINT, get_QueueManagementQueue_QueueBufferLength, NULL, NULL, NULL},
    {"QueueWeight", &DMWRITE, DMT_UNINT, get_QueueManagementQueue_QueueWeight, set_QueueManagementQueue_QueueWeight, NULL, NULL},
    {"QueuePrecedence", &DMWRITE, DMT_UNINT, get_QueueManagementQueue_QueuePrecedence, set_QueueManagementQueue_QueuePrecedence, NULL, NULL},
    {"REDThreshold", &DMWRITE, DMT_UNINT, get_QueueManagementQueue_REDThreshold, set_QueueManagementQueue_REDThreshold, NULL, NULL},
    {"REDPercentage", &DMWRITE, DMT_UNINT, get_QueueManagementQueue_REDPercentage, set_QueueManagementQueue_REDPercentage, NULL, NULL},
    {"DropAlgorithm", &DMWRITE, DMT_STRING, get_QueueManagementQueue_DropAlgorithm, set_QueueManagementQueue_DropAlgorithm, NULL, NULL},
    {"SchedulerAlgorithm", &DMWRITE, DMT_STRING, get_QueueManagementQueue_SchedulerAlgorithm, set_QueueManagementQueue_SchedulerAlgorithm, NULL, NULL},
    {"ShapingRate", &DMWRITE, DMT_INT, get_QueueManagementQueue_ShapingRate, set_QueueManagementQueue_ShapingRate, NULL, NULL},
    {"ShapingBurstSize", &DMWRITE, DMT_UNINT, get_QueueManagementQueue_ShapingBurstSize, set_QueueManagementQueue_ShapingBurstSize, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.QueueManagement.QueueStats.{i}. *** */
DMLEAF tQueueManagementQueueStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_QueueManagementQueueStats_Enable, set_QueueManagementQueueStats_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_QueueManagementQueueStats_Status, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_QueueManagementQueueStats_Alias, set_QueueManagementQueueStats_Alias, NULL, NULL},
    {"Queue", &DMWRITE, DMT_UNINT, get_QueueManagementQueueStats_Queue, set_QueueManagementQueueStats_Queue, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_QueueManagementQueueStats_Interface, set_QueueManagementQueueStats_Interface, NULL, NULL},
    {"OutputPackets", &DMREAD, DMT_UNINT, get_QueueManagementQueueStats_OutputPackets, NULL, NULL, NULL},
    {"OutputBytes", &DMREAD, DMT_UNINT, get_QueueManagementQueueStats_OutputBytes, NULL, NULL, NULL},
    {"DroppedPackets", &DMREAD, DMT_UNINT, get_QueueManagementQueueStats_DroppedPackets, NULL, NULL, NULL},
    {"DroppedBytes", &DMREAD, DMT_UNINT, get_QueueManagementQueueStats_DroppedBytes, NULL, NULL, NULL},
    {"QueueOccupancyPackets", &DMREAD, DMT_UNINT, get_QueueManagementQueueStats_QueueOccupancyPackets, NULL, NULL, NULL},
    {"QueueOccupancyPercentage", &DMREAD, DMT_UNINT, get_QueueManagementQueueStats_QueueOccupancyPercentage, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANConfigSecurity. *** */
DMLEAF tLANConfigSecurityParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ConfigPassword", &DMWRITE, DMT_STRING, get_LANConfigSecurity_ConfigPassword, set_LANConfigSecurity_ConfigPassword, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.IPPingDiagnostics. *** */
DMLEAF tIPPingDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DiagnosticsState", &DMWRITE, DMT_STRING, get_IPPingDiagnostics_DiagnosticsState, set_IPPingDiagnostics_DiagnosticsState, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_IPPingDiagnostics_Interface, set_IPPingDiagnostics_Interface, NULL, NULL},
    {"Host", &DMWRITE, DMT_STRING, get_IPPingDiagnostics_Host, set_IPPingDiagnostics_Host, NULL, NULL},
    {"NumberOfRepetitions", &DMWRITE, DMT_UNINT, get_IPPingDiagnostics_NumberOfRepetitions, set_IPPingDiagnostics_NumberOfRepetitions, NULL, NULL},
    {"Timeout", &DMWRITE, DMT_UNINT, get_IPPingDiagnostics_Timeout, set_IPPingDiagnostics_Timeout, NULL, NULL},
    {"DataBlockSize", &DMWRITE, DMT_UNINT, get_IPPingDiagnostics_DataBlockSize, set_IPPingDiagnostics_DataBlockSize, NULL, NULL},
    {"DSCP", &DMWRITE, DMT_UNINT, get_IPPingDiagnostics_DSCP, set_IPPingDiagnostics_DSCP, NULL, NULL},
    {"SuccessCount", &DMREAD, DMT_UNINT, get_IPPingDiagnostics_SuccessCount, NULL, NULL, NULL},
    {"FailureCount", &DMREAD, DMT_UNINT, get_IPPingDiagnostics_FailureCount, NULL, NULL, NULL},
    {"AverageResponseTime", &DMREAD, DMT_UNINT, get_IPPingDiagnostics_AverageResponseTime, NULL, NULL, NULL},
    {"MinimumResponseTime", &DMREAD, DMT_UNINT, get_IPPingDiagnostics_MinimumResponseTime, NULL, NULL, NULL},
    {"MaximumResponseTime", &DMREAD, DMT_UNINT, get_IPPingDiagnostics_MaximumResponseTime, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.TraceRouteDiagnostics. *** */
DMOBJ tTraceRouteDiagnosticsObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"RouteHops", &DMREAD, NULL, NULL, NULL, browseTraceRouteDiagnosticsRouteHopsInst, NULL, NULL, NULL, tTraceRouteDiagnosticsRouteHopsParams, NULL},
    {0}};

DMLEAF tTraceRouteDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DiagnosticsState", &DMWRITE, DMT_STRING, get_TraceRouteDiagnostics_DiagnosticsState, set_TraceRouteDiagnostics_DiagnosticsState, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_TraceRouteDiagnostics_Interface, set_TraceRouteDiagnostics_Interface, NULL, NULL},
    {"Host", &DMWRITE, DMT_STRING, get_TraceRouteDiagnostics_Host, set_TraceRouteDiagnostics_Host, NULL, NULL},
    {"NumberOfTries", &DMWRITE, DMT_UNINT, get_TraceRouteDiagnostics_NumberOfTries, set_TraceRouteDiagnostics_NumberOfTries, NULL, NULL},
    {"Timeout", &DMWRITE, DMT_UNINT, get_TraceRouteDiagnostics_Timeout, set_TraceRouteDiagnostics_Timeout, NULL, NULL},
    {"DataBlockSize", &DMWRITE, DMT_UNINT, get_TraceRouteDiagnostics_DataBlockSize, set_TraceRouteDiagnostics_DataBlockSize, NULL, NULL},
    {"DSCP", &DMWRITE, DMT_UNINT, get_TraceRouteDiagnostics_DSCP, set_TraceRouteDiagnostics_DSCP, NULL, NULL},
    {"MaxHopCount", &DMWRITE, DMT_UNINT, get_TraceRouteDiagnostics_MaxHopCount, set_TraceRouteDiagnostics_MaxHopCount, NULL, NULL},
    {"ResponseTime", &DMREAD, DMT_UNINT, get_TraceRouteDiagnostics_ResponseTime, NULL, NULL, NULL},
    {"RouteHopsNumberOfEntries", &DMREAD, DMT_UNINT, get_TraceRouteDiagnostics_RouteHopsNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.TraceRouteDiagnostics.RouteHops.{i}. *** */
DMLEAF tTraceRouteDiagnosticsRouteHopsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"HopHost", &DMREAD, DMT_STRING, get_TraceRouteDiagnosticsRouteHops_HopHost, NULL, NULL, NULL},
    {"HopHostAddress", &DMREAD, DMT_STRING, get_TraceRouteDiagnosticsRouteHops_HopHostAddress, NULL, NULL, NULL},
    {"HopErrorCode", &DMREAD, DMT_UNINT, get_TraceRouteDiagnosticsRouteHops_HopErrorCode, NULL, NULL, NULL},
    {"HopRTTimes", &DMREAD, DMT_STRING, get_TraceRouteDiagnosticsRouteHops_HopRTTimes, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DownloadDiagnostics. *** */
DMLEAF tDownloadDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DiagnosticsState", &DMWRITE, DMT_STRING, get_DownloadDiagnostics_DiagnosticsState, set_DownloadDiagnostics_DiagnosticsState, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_DownloadDiagnostics_Interface, set_DownloadDiagnostics_Interface, NULL, NULL},
    {"DownloadURL", &DMWRITE, DMT_STRING, get_DownloadDiagnostics_DownloadURL, set_DownloadDiagnostics_DownloadURL, NULL, NULL},
    {"DSCP", &DMWRITE, DMT_UNINT, get_DownloadDiagnostics_DSCP, set_DownloadDiagnostics_DSCP, NULL, NULL},
    {"EthernetPriority", &DMWRITE, DMT_UNINT, get_DownloadDiagnostics_EthernetPriority, set_DownloadDiagnostics_EthernetPriority, NULL, NULL},
    {"ROMTime", &DMREAD, DMT_TIME, get_DownloadDiagnostics_ROMTime, NULL, NULL, NULL},
    {"BOMTime", &DMREAD, DMT_TIME, get_DownloadDiagnostics_BOMTime, NULL, NULL, NULL},
    {"EOMTime", &DMREAD, DMT_TIME, get_DownloadDiagnostics_EOMTime, NULL, NULL, NULL},
    {"TestBytesReceived", &DMREAD, DMT_UNINT, get_DownloadDiagnostics_TestBytesReceived, NULL, NULL, NULL},
    {"TotalBytesReceived", &DMREAD, DMT_UNINT, get_DownloadDiagnostics_TotalBytesReceived, NULL, NULL, NULL},
    {"TCPOpenRequestTime", &DMREAD, DMT_TIME, get_DownloadDiagnostics_TCPOpenRequestTime, NULL, NULL, NULL},
    {"TCPOpenResponseTime", &DMREAD, DMT_TIME, get_DownloadDiagnostics_TCPOpenResponseTime, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UploadDiagnostics. *** */
DMLEAF tUploadDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DiagnosticsState", &DMWRITE, DMT_STRING, get_UploadDiagnostics_DiagnosticsState, set_UploadDiagnostics_DiagnosticsState, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_UploadDiagnostics_Interface, set_UploadDiagnostics_Interface, NULL, NULL},
    {"UploadURL", &DMWRITE, DMT_STRING, get_UploadDiagnostics_UploadURL, set_UploadDiagnostics_UploadURL, NULL, NULL},
    {"DSCP", &DMWRITE, DMT_UNINT, get_UploadDiagnostics_DSCP, set_UploadDiagnostics_DSCP, NULL, NULL},
    {"EthernetPriority", &DMWRITE, DMT_UNINT, get_UploadDiagnostics_EthernetPriority, set_UploadDiagnostics_EthernetPriority, NULL, NULL},
    {"TestFileLength", &DMWRITE, DMT_UNINT, get_UploadDiagnostics_TestFileLength, set_UploadDiagnostics_TestFileLength, NULL, NULL},
    {"ROMTime", &DMREAD, DMT_TIME, get_UploadDiagnostics_ROMTime, NULL, NULL, NULL},
    {"BOMTime", &DMREAD, DMT_TIME, get_UploadDiagnostics_BOMTime, NULL, NULL, NULL},
    {"EOMTime", &DMREAD, DMT_TIME, get_UploadDiagnostics_EOMTime, NULL, NULL, NULL},
    {"TotalBytesSent", &DMREAD, DMT_UNINT, get_UploadDiagnostics_TotalBytesSent, NULL, NULL, NULL},
    {"TCPOpenRequestTime", &DMREAD, DMT_TIME, get_UploadDiagnostics_TCPOpenRequestTime, NULL, NULL, NULL},
    {"TCPOpenResponseTime", &DMREAD, DMT_TIME, get_UploadDiagnostics_TCPOpenResponseTime, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UDPEchoConfig. *** */
DMLEAF tUDPEchoConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_UDPEchoConfig_Enable, set_UDPEchoConfig_Enable, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_UDPEchoConfig_Interface, set_UDPEchoConfig_Interface, NULL, NULL},
    {"SourceIPAddress", &DMWRITE, DMT_STRING, get_UDPEchoConfig_SourceIPAddress, set_UDPEchoConfig_SourceIPAddress, NULL, NULL},
    {"UDPPort", &DMWRITE, DMT_UNINT, get_UDPEchoConfig_UDPPort, set_UDPEchoConfig_UDPPort, NULL, NULL},
    {"EchoPlusEnabled", &DMWRITE, DMT_BOOL, get_UDPEchoConfig_EchoPlusEnabled, set_UDPEchoConfig_EchoPlusEnabled, NULL, NULL},
    {"EchoPlusSupported", &DMREAD, DMT_BOOL, get_UDPEchoConfig_EchoPlusSupported, NULL, NULL, NULL},
    {"PacketsReceived", &DMREAD, DMT_UNINT, get_UDPEchoConfig_PacketsReceived, NULL, NULL, NULL},
    {"PacketsResponded", &DMREAD, DMT_UNINT, get_UDPEchoConfig_PacketsResponded, NULL, NULL, NULL},
    {"BytesReceived", &DMREAD, DMT_UNINT, get_UDPEchoConfig_BytesReceived, NULL, NULL, NULL},
    {"BytesResponded", &DMREAD, DMT_UNINT, get_UDPEchoConfig_BytesResponded, NULL, NULL, NULL},
    {"TimeFirstPacketReceived", &DMREAD, DMT_TIME, get_UDPEchoConfig_TimeFirstPacketReceived, NULL, NULL, NULL},
    {"TimeLastPacketReceived", &DMREAD, DMT_TIME, get_UDPEchoConfig_TimeLastPacketReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}. *** */
DMOBJ tLANDeviceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"LANHostConfigManagement", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tLANDeviceLANHostConfigManagementObj, tLANDeviceLANHostConfigManagementParams, NULL},
    {"LANEthernetInterfaceConfig",
     &DMREAD,
     NULL,
     NULL,
     NULL,
     browseLANDeviceLANEthernetInterfaceConfigInst,
     NULL,
     NULL,
     tLANDeviceLANEthernetInterfaceConfigObj,
     tLANDeviceLANEthernetInterfaceConfigParams,
     NULL},
    {"LANUSBInterfaceConfig", &DMREAD, NULL, NULL, NULL, browseLANDeviceLANUSBInterfaceConfigInst, NULL, NULL, tLANDeviceLANUSBInterfaceConfigObj, tLANDeviceLANUSBInterfaceConfigParams, NULL},
    {"WLANConfiguration", &DMREAD, NULL, NULL, NULL, browseLANDeviceWLANConfigurationInst, NULL, NULL, tLANDeviceWLANConfigurationObj, tLANDeviceWLANConfigurationParams, NULL},
    {"Hosts", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tLANDeviceHostsObj, tLANDeviceHostsParams, NULL},
    {0}};

DMLEAF tLANDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANDevice_Alias, set_LANDevice_Alias, NULL, NULL},
    {"LANEthernetInterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDevice_LANEthernetInterfaceNumberOfEntries, NULL, NULL, NULL},
    {"LANUSBInterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDevice_LANUSBInterfaceNumberOfEntries, NULL, NULL, NULL},
    {"LANWLANConfigurationNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDevice_LANWLANConfigurationNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANHostConfigManagement. *** */
DMOBJ tLANDeviceLANHostConfigManagementObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"IPInterface",
     &DMWRITE,
     addObjLANDeviceLANHostConfigManagementIPInterface,
     delObjLANDeviceLANHostConfigManagementIPInterface,
     NULL,
     browseLANDeviceLANHostConfigManagementIPInterfaceInst,
     NULL,
     NULL,
     NULL,
     tLANDeviceLANHostConfigManagementIPInterfaceParams,
     NULL},
    {"DHCPStaticAddress",
     &DMWRITE,
     addObjLANDeviceLANHostConfigManagementDHCPStaticAddress,
     delObjLANDeviceLANHostConfigManagementDHCPStaticAddress,
     NULL,
     browseLANDeviceLANHostConfigManagementDHCPStaticAddressInst,
     NULL,
     NULL,
     NULL,
     tLANDeviceLANHostConfigManagementDHCPStaticAddressParams,
     NULL},
    {"DHCPOption",
     &DMWRITE,
     addObjLANDeviceLANHostConfigManagementDHCPOption,
     delObjLANDeviceLANHostConfigManagementDHCPOption,
     NULL,
     browseLANDeviceLANHostConfigManagementDHCPOptionInst,
     NULL,
     NULL,
     NULL,
     tLANDeviceLANHostConfigManagementDHCPOptionParams,
     NULL},
    {"DHCPConditionalServingPool",
     &DMWRITE,
     addObjLANDeviceLANHostConfigManagementDHCPConditionalServingPool,
     delObjLANDeviceLANHostConfigManagementDHCPConditionalServingPool,
     NULL,
     browseLANDeviceLANHostConfigManagementDHCPConditionalServingPoolInst,
     NULL,
     NULL,
     tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolObj,
     tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolParams,
     NULL},
    {0}};

DMLEAF tLANDeviceLANHostConfigManagementParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"MACAddress", &DMREAD, DMT_STRING, get_LANDeviceLANHostConfigManagement_MACAddress, NULL, NULL, NULL},
    {"DHCPServerConfigurable", &DMWRITE, DMT_BOOL, get_LANDeviceLANHostConfigManagement_DHCPServerConfigurable, set_LANDeviceLANHostConfigManagement_DHCPServerConfigurable, NULL, NULL},
    {"DHCPServerEnable", &DMWRITE, DMT_BOOL, get_LANDeviceLANHostConfigManagement_DHCPServerEnable, set_LANDeviceLANHostConfigManagement_DHCPServerEnable, NULL, NULL},
    {"DHCPRelay", &DMREAD, DMT_BOOL, get_LANDeviceLANHostConfigManagement_DHCPRelay, NULL, NULL, NULL},
    {"MinAddress", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_MinAddress, set_LANDeviceLANHostConfigManagement_MinAddress, NULL, NULL},
    {"MaxAddress", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_MaxAddress, set_LANDeviceLANHostConfigManagement_MaxAddress, NULL, NULL},
    {"ReservedAddresses", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_ReservedAddresses, set_LANDeviceLANHostConfigManagement_ReservedAddresses, NULL, NULL},
    {"SubnetMask", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_SubnetMask, set_LANDeviceLANHostConfigManagement_SubnetMask, NULL, NULL},
    {"DNSServers", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_DNSServers, set_LANDeviceLANHostConfigManagement_DNSServers, NULL, NULL},
    {"DomainName", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_DomainName, set_LANDeviceLANHostConfigManagement_DomainName, NULL, NULL},
    {"IPRouters", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_IPRouters, set_LANDeviceLANHostConfigManagement_IPRouters, NULL, NULL},
    {"DHCPLeaseTime", &DMWRITE, DMT_INT, get_LANDeviceLANHostConfigManagement_DHCPLeaseTime, set_LANDeviceLANHostConfigManagement_DHCPLeaseTime, NULL, NULL},
    {"UseAllocatedWAN", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_UseAllocatedWAN, set_LANDeviceLANHostConfigManagement_UseAllocatedWAN, NULL, NULL},
    {"AssociatedConnection", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_AssociatedConnection, set_LANDeviceLANHostConfigManagement_AssociatedConnection, NULL, NULL},
    {"PassthroughLease", &DMWRITE, DMT_UNINT, get_LANDeviceLANHostConfigManagement_PassthroughLease, set_LANDeviceLANHostConfigManagement_PassthroughLease, NULL, NULL},
    {"PassthroughMACAddress", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_PassthroughMACAddress, set_LANDeviceLANHostConfigManagement_PassthroughMACAddress, NULL, NULL},
    {"AllowedMACAddresses", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagement_AllowedMACAddresses, set_LANDeviceLANHostConfigManagement_AllowedMACAddresses, NULL, NULL},
    {"IPInterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceLANHostConfigManagement_IPInterfaceNumberOfEntries, NULL, NULL, NULL},
    {"DHCPStaticAddressNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceLANHostConfigManagement_DHCPStaticAddressNumberOfEntries, NULL, NULL, NULL},
    {"DHCPOptionNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceLANHostConfigManagement_DHCPOptionNumberOfEntries, NULL, NULL, NULL},
    {"DHCPConditionalPoolNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceLANHostConfigManagement_DHCPConditionalPoolNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANHostConfigManagement.IPInterface.{i}. *** */
DMLEAF tLANDeviceLANHostConfigManagementIPInterfaceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceLANHostConfigManagementIPInterface_Enable, set_LANDeviceLANHostConfigManagementIPInterface_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementIPInterface_Alias, set_LANDeviceLANHostConfigManagementIPInterface_Alias, NULL, NULL},
    {"IPInterfaceIPAddress",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceIPAddress,
     set_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceIPAddress,
     NULL,
     NULL},
    {"IPInterfaceSubnetMask",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceSubnetMask,
     set_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceSubnetMask,
     NULL,
     NULL},
    {"IPInterfaceAddressingType",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceAddressingType,
     set_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceAddressingType,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANHostConfigManagement.DHCPStaticAddress.{i}. *** */
DMLEAF tLANDeviceLANHostConfigManagementDHCPStaticAddressParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Enable, set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Alias, set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Alias, NULL, NULL},
    {"Chaddr", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Chaddr, set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Chaddr, NULL, NULL},
    {"Yiaddr", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Yiaddr, set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Yiaddr, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANHostConfigManagement.DHCPOption.{i}. *** */
DMLEAF tLANDeviceLANHostConfigManagementDHCPOptionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceLANHostConfigManagementDHCPOption_Enable, set_LANDeviceLANHostConfigManagementDHCPOption_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPOption_Alias, set_LANDeviceLANHostConfigManagementDHCPOption_Alias, NULL, NULL},
    {"Tag", &DMWRITE, DMT_UNINT, get_LANDeviceLANHostConfigManagementDHCPOption_Tag, set_LANDeviceLANHostConfigManagementDHCPOption_Tag, NULL, NULL},
    {"Value", &DMWRITE, DMT_BASE64, get_LANDeviceLANHostConfigManagementDHCPOption_Value, set_LANDeviceLANHostConfigManagementDHCPOption_Value, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANHostConfigManagement.DHCPConditionalServingPool.{i}. *** */
DMOBJ tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"DHCPStaticAddress",
     &DMWRITE,
     addObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress,
     delObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress,
     NULL,
     browseLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddressInst,
     NULL,
     NULL,
     NULL,
     tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddressParams,
     NULL},
    {"DHCPOption",
     &DMWRITE,
     addObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption,
     delObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption,
     NULL,
     browseLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOptionInst,
     NULL,
     NULL,
     NULL,
     tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOptionParams,
     NULL},
    {0}};

DMLEAF tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Enable, set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Alias, set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Alias, NULL, NULL},
    {"PoolOrder", &DMWRITE, DMT_UNINT, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_PoolOrder, set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_PoolOrder, NULL, NULL},
    {"SourceInterface",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SourceInterface,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SourceInterface,
     NULL,
     NULL},
    {"VendorClassID",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassID,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassID,
     NULL,
     NULL},
    {"VendorClassIDExclude",
     &DMWRITE,
     DMT_BOOL,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDExclude,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDExclude,
     NULL,
     NULL},
    {"VendorClassIDMode",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDMode,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDMode,
     NULL,
     NULL},
    {"ClientID", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientID, set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientID, NULL, NULL},
    {"ClientIDExclude",
     &DMWRITE,
     DMT_BOOL,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientIDExclude,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientIDExclude,
     NULL,
     NULL},
    {"UserClassID",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassID,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassID,
     NULL,
     NULL},
    {"UserClassIDExclude",
     &DMWRITE,
     DMT_BOOL,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassIDExclude,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassIDExclude,
     NULL,
     NULL},
    {"Chaddr", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Chaddr, set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Chaddr, NULL, NULL},
    {"ChaddrMask",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrMask,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrMask,
     NULL,
     NULL},
    {"ChaddrExclude",
     &DMWRITE,
     DMT_BOOL,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrExclude,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrExclude,
     NULL,
     NULL},
    {"LocallyServed",
     &DMWRITE,
     DMT_BOOL,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_LocallyServed,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_LocallyServed,
     NULL,
     NULL},
    {"MinAddress",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MinAddress,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MinAddress,
     NULL,
     NULL},
    {"MaxAddress",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MaxAddress,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MaxAddress,
     NULL,
     NULL},
    {"ReservedAddresses",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ReservedAddresses,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ReservedAddresses,
     NULL,
     NULL},
    {"SubnetMask",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SubnetMask,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SubnetMask,
     NULL,
     NULL},
    {"DNSServers",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DNSServers,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DNSServers,
     NULL,
     NULL},
    {"DomainName",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DomainName,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DomainName,
     NULL,
     NULL},
    {"IPRouters", &DMWRITE, DMT_STRING, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_IPRouters, set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_IPRouters, NULL, NULL},
    {"DHCPLeaseTime",
     &DMWRITE,
     DMT_INT,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPLeaseTime,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPLeaseTime,
     NULL,
     NULL},
    {"UseAllocatedWAN",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UseAllocatedWAN,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UseAllocatedWAN,
     NULL,
     NULL},
    {"AssociatedConnection",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_AssociatedConnection,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_AssociatedConnection,
     NULL,
     NULL},
    {"DHCPServerIPAddress",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPServerIPAddress,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPServerIPAddress,
     NULL,
     NULL},
    {"DHCPStaticAddressNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPStaticAddressNumberOfEntries, NULL, NULL, NULL},
    {"DHCPOptionNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPOptionNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANHostConfigManagement.DHCPConditionalServingPool.{i}.DHCPStaticAddress.{i}. *** */
DMLEAF tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddressParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable",
     &DMWRITE,
     DMT_BOOL,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Enable,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Enable,
     NULL,
     NULL},
    {"Alias",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Alias,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Alias,
     NULL,
     NULL},
    {"Chaddr",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Chaddr,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Chaddr,
     NULL,
     NULL},
    {"Yiaddr",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Yiaddr,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Yiaddr,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANHostConfigManagement.DHCPConditionalServingPool.{i}.DHCPOption.{i}. *** */
DMLEAF tLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOptionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable",
     &DMWRITE,
     DMT_BOOL,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Enable,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Enable,
     NULL,
     NULL},
    {"Alias",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Alias,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Alias,
     NULL,
     NULL},
    {"Tag",
     &DMWRITE,
     DMT_UNINT,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Tag,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Tag,
     NULL,
     NULL},
    {"Value",
     &DMWRITE,
     DMT_BASE64,
     get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Value,
     set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Value,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANEthernetInterfaceConfig.{i}. *** */
DMOBJ tLANDeviceLANEthernetInterfaceConfigObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tLANDeviceLANEthernetInterfaceConfigStatsParams, NULL},
    {0}};

DMLEAF tLANDeviceLANEthernetInterfaceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceLANEthernetInterfaceConfig_Enable, set_LANDeviceLANEthernetInterfaceConfig_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_LANDeviceLANEthernetInterfaceConfig_Status, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceLANEthernetInterfaceConfig_Alias, set_LANDeviceLANEthernetInterfaceConfig_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_LANDeviceLANEthernetInterfaceConfig_Name, NULL, NULL, NULL},
    {"MACAddress", &DMREAD, DMT_STRING, get_LANDeviceLANEthernetInterfaceConfig_MACAddress, NULL, NULL, NULL},
    {"MACAddressControlEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceLANEthernetInterfaceConfig_MACAddressControlEnabled, set_LANDeviceLANEthernetInterfaceConfig_MACAddressControlEnabled, NULL, NULL},
    {"MaxBitRate", &DMWRITE, DMT_STRING, get_LANDeviceLANEthernetInterfaceConfig_MaxBitRate, set_LANDeviceLANEthernetInterfaceConfig_MaxBitRate, NULL, NULL},
    {"DuplexMode", &DMWRITE, DMT_STRING, get_LANDeviceLANEthernetInterfaceConfig_DuplexMode, set_LANDeviceLANEthernetInterfaceConfig_DuplexMode, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANEthernetInterfaceConfig.{i}.Stats. *** */
DMLEAF tLANDeviceLANEthernetInterfaceConfigStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"BytesSent", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_BytesSent, NULL, NULL, NULL},
    {"BytesReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_BytesReceived, NULL, NULL, NULL},
    {"PacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_PacketsSent, NULL, NULL, NULL},
    {"PacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_PacketsReceived, NULL, NULL, NULL},
    {"ErrorsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_ErrorsSent, NULL, NULL, NULL},
    {"ErrorsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_ErrorsReceived, NULL, NULL, NULL},
    {"UnicastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_UnicastPacketsSent, NULL, NULL, NULL},
    {"UnicastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_UnicastPacketsReceived, NULL, NULL, NULL},
    {"DiscardPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_DiscardPacketsSent, NULL, NULL, NULL},
    {"DiscardPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_DiscardPacketsReceived, NULL, NULL, NULL},
    {"MulticastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_MulticastPacketsSent, NULL, NULL, NULL},
    {"MulticastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_MulticastPacketsReceived, NULL, NULL, NULL},
    {"BroadcastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_BroadcastPacketsSent, NULL, NULL, NULL},
    {"BroadcastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_BroadcastPacketsReceived, NULL, NULL, NULL},
    {"UnknownProtoPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANEthernetInterfaceConfigStats_UnknownProtoPacketsReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANUSBInterfaceConfig.{i}. *** */
DMOBJ tLANDeviceLANUSBInterfaceConfigObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tLANDeviceLANUSBInterfaceConfigStatsParams, NULL},
    {0}};

DMLEAF tLANDeviceLANUSBInterfaceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceLANUSBInterfaceConfig_Enable, set_LANDeviceLANUSBInterfaceConfig_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_Status, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_Alias, set_LANDeviceLANUSBInterfaceConfig_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_Name, NULL, NULL, NULL},
    {"MACAddress", &DMREAD, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_MACAddress, NULL, NULL, NULL},
    {"MACAddressControlEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceLANUSBInterfaceConfig_MACAddressControlEnabled, set_LANDeviceLANUSBInterfaceConfig_MACAddressControlEnabled, NULL, NULL},
    {"Standard", &DMREAD, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_Standard, NULL, NULL, NULL},
    {"Type", &DMREAD, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_Type, NULL, NULL, NULL},
    {"Rate", &DMREAD, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_Rate, NULL, NULL, NULL},
    {"Power", &DMREAD, DMT_STRING, get_LANDeviceLANUSBInterfaceConfig_Power, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.LANUSBInterfaceConfig.{i}.Stats. *** */
DMLEAF tLANDeviceLANUSBInterfaceConfigStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"BytesSent", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_BytesSent, NULL, NULL, NULL},
    {"BytesReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_BytesReceived, NULL, NULL, NULL},
    {"CellsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_CellsSent, NULL, NULL, NULL},
    {"CellsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_CellsReceived, NULL, NULL, NULL},
    {"ErrorsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_ErrorsSent, NULL, NULL, NULL},
    {"ErrorsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_ErrorsReceived, NULL, NULL, NULL},
    {"UnicastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_UnicastPacketsSent, NULL, NULL, NULL},
    {"UnicastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_UnicastPacketsReceived, NULL, NULL, NULL},
    {"DiscardPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_DiscardPacketsSent, NULL, NULL, NULL},
    {"DiscardPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_DiscardPacketsReceived, NULL, NULL, NULL},
    {"MulticastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_MulticastPacketsSent, NULL, NULL, NULL},
    {"MulticastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_MulticastPacketsReceived, NULL, NULL, NULL},
    {"BroadcastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_BroadcastPacketsSent, NULL, NULL, NULL},
    {"BroadcastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_BroadcastPacketsReceived, NULL, NULL, NULL},
    {"UnknownProtoPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceLANUSBInterfaceConfigStats_UnknownProtoPacketsReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}. *** */
DMOBJ tLANDeviceWLANConfigurationObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"AssociatedDevice", &DMREAD, NULL, NULL, NULL, browseLANDeviceWLANConfigurationAssociatedDeviceInst, NULL, NULL, NULL, tLANDeviceWLANConfigurationAssociatedDeviceParams, NULL},
    {"WEPKey", &DMREAD, NULL, NULL, NULL, browseLANDeviceWLANConfigurationWEPKeyInst, NULL, NULL, NULL, tLANDeviceWLANConfigurationWEPKeyParams, NULL},
    {"PreSharedKey", &DMREAD, NULL, NULL, NULL, browseLANDeviceWLANConfigurationPreSharedKeyInst, NULL, NULL, NULL, tLANDeviceWLANConfigurationPreSharedKeyParams, NULL},
    {"APWMMParameter", &DMREAD, NULL, NULL, NULL, browseLANDeviceWLANConfigurationAPWMMParameterInst, NULL, NULL, NULL, tLANDeviceWLANConfigurationAPWMMParameterParams, NULL},
    {"STAWMMParameter", &DMREAD, NULL, NULL, NULL, browseLANDeviceWLANConfigurationSTAWMMParameterInst, NULL, NULL, NULL, tLANDeviceWLANConfigurationSTAWMMParameterParams, NULL},
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tLANDeviceWLANConfigurationStatsParams, NULL},
    {"WPS", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tLANDeviceWLANConfigurationWPSObj, tLANDeviceWLANConfigurationWPSParams, NULL},
    {0}};

DMLEAF tLANDeviceWLANConfigurationParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_Enable, set_LANDeviceWLANConfiguration_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_Status, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_Alias, set_LANDeviceWLANConfiguration_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_Name, NULL, NULL, NULL},
    {"BSSID", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_BSSID, NULL, NULL, NULL},
    {"MaxBitRate", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_MaxBitRate, set_LANDeviceWLANConfiguration_MaxBitRate, NULL, NULL},
    {"Channel", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfiguration_Channel, set_LANDeviceWLANConfiguration_Channel, NULL, NULL},
    {"AutoChannelEnable", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_AutoChannelEnable, set_LANDeviceWLANConfiguration_AutoChannelEnable, NULL, NULL},
    {"SSID", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_SSID, set_LANDeviceWLANConfiguration_SSID, NULL, NULL},
    {"BeaconType", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_BeaconType, set_LANDeviceWLANConfiguration_BeaconType, NULL, NULL},
    {"MACAddressControlEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_MACAddressControlEnabled, set_LANDeviceWLANConfiguration_MACAddressControlEnabled, NULL, NULL},
    {"Standard", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_Standard, NULL, NULL, NULL},
    {"WEPKeyIndex", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfiguration_WEPKeyIndex, set_LANDeviceWLANConfiguration_WEPKeyIndex, NULL, NULL},
    {"KeyPassphrase", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_KeyPassphrase, set_LANDeviceWLANConfiguration_KeyPassphrase, NULL, NULL},
    {"WEPEncryptionLevel", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_WEPEncryptionLevel, NULL, NULL, NULL},
    {"BasicEncryptionModes", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_BasicEncryptionModes, set_LANDeviceWLANConfiguration_BasicEncryptionModes, NULL, NULL},
    {"BasicAuthenticationMode", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_BasicAuthenticationMode, set_LANDeviceWLANConfiguration_BasicAuthenticationMode, NULL, NULL},
    {"WPAEncryptionModes", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_WPAEncryptionModes, set_LANDeviceWLANConfiguration_WPAEncryptionModes, NULL, NULL},
    {"WPAAuthenticationMode", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_WPAAuthenticationMode, set_LANDeviceWLANConfiguration_WPAAuthenticationMode, NULL, NULL},
    {"IEEE11iEncryptionModes", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_IEEE11iEncryptionModes, set_LANDeviceWLANConfiguration_IEEE11iEncryptionModes, NULL, NULL},
    {"IEEE11iAuthenticationMode", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_IEEE11iAuthenticationMode, set_LANDeviceWLANConfiguration_IEEE11iAuthenticationMode, NULL, NULL},
    {"PossibleChannels", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_PossibleChannels, NULL, NULL, NULL},
    {"BasicDataTransmitRates", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_BasicDataTransmitRates, set_LANDeviceWLANConfiguration_BasicDataTransmitRates, NULL, NULL},
    {"OperationalDataTransmitRates", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_OperationalDataTransmitRates, set_LANDeviceWLANConfiguration_OperationalDataTransmitRates, NULL, NULL},
    {"PossibleDataTransmitRates", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_PossibleDataTransmitRates, NULL, NULL, NULL},
    {"InsecureOOBAccessEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_InsecureOOBAccessEnabled, set_LANDeviceWLANConfiguration_InsecureOOBAccessEnabled, NULL, NULL},
    {"BeaconAdvertisementEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_BeaconAdvertisementEnabled, set_LANDeviceWLANConfiguration_BeaconAdvertisementEnabled, NULL, NULL},
    {"SSIDAdvertisementEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_SSIDAdvertisementEnabled, set_LANDeviceWLANConfiguration_SSIDAdvertisementEnabled, NULL, NULL},
    {"RadioEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_RadioEnabled, set_LANDeviceWLANConfiguration_RadioEnabled, NULL, NULL},
    {"TransmitPowerSupported", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_TransmitPowerSupported, NULL, NULL, NULL},
    {"TransmitPower", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfiguration_TransmitPower, set_LANDeviceWLANConfiguration_TransmitPower, NULL, NULL},
    {"AutoRateFallBackEnabled", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_AutoRateFallBackEnabled, set_LANDeviceWLANConfiguration_AutoRateFallBackEnabled, NULL, NULL},
    {"LocationDescription", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_LocationDescription, set_LANDeviceWLANConfiguration_LocationDescription, NULL, NULL},
    {"RegulatoryDomain", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_RegulatoryDomain, set_LANDeviceWLANConfiguration_RegulatoryDomain, NULL, NULL},
    {"TotalPSKFailures", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfiguration_TotalPSKFailures, NULL, NULL, NULL},
    {"TotalIntegrityFailures", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfiguration_TotalIntegrityFailures, NULL, NULL, NULL},
    {"ChannelsInUse", &DMREAD, DMT_STRING, get_LANDeviceWLANConfiguration_ChannelsInUse, NULL, NULL, NULL},
    {"DeviceOperationMode", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_DeviceOperationMode, set_LANDeviceWLANConfiguration_DeviceOperationMode, NULL, NULL},
    {"DistanceFromRoot", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfiguration_DistanceFromRoot, set_LANDeviceWLANConfiguration_DistanceFromRoot, NULL, NULL},
    {"PeerBSSID", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_PeerBSSID, set_LANDeviceWLANConfiguration_PeerBSSID, NULL, NULL},
    {"AuthenticationServiceMode", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfiguration_AuthenticationServiceMode, set_LANDeviceWLANConfiguration_AuthenticationServiceMode, NULL, NULL},
    {"WMMSupported", &DMREAD, DMT_BOOL, get_LANDeviceWLANConfiguration_WMMSupported, NULL, NULL, NULL},
    {"UAPSDSupported", &DMREAD, DMT_BOOL, get_LANDeviceWLANConfiguration_UAPSDSupported, NULL, NULL, NULL},
    {"WMMEnable", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_WMMEnable, set_LANDeviceWLANConfiguration_WMMEnable, NULL, NULL},
    {"UAPSDEnable", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfiguration_UAPSDEnable, set_LANDeviceWLANConfiguration_UAPSDEnable, NULL, NULL},
    {"TotalBytesSent", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfiguration_TotalBytesSent, NULL, NULL, NULL},
    {"TotalBytesReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfiguration_TotalBytesReceived, NULL, NULL, NULL},
    {"TotalPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfiguration_TotalPacketsSent, NULL, NULL, NULL},
    {"TotalPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfiguration_TotalPacketsReceived, NULL, NULL, NULL},
    {"TotalAssociations", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfiguration_TotalAssociations, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.AssociatedDevice.{i}. *** */
DMLEAF tLANDeviceWLANConfigurationAssociatedDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"AssociatedDeviceMACAddress", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationAssociatedDevice_AssociatedDeviceMACAddress, NULL, NULL, NULL},
    {"AssociatedDeviceIPAddress", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationAssociatedDevice_AssociatedDeviceIPAddress, NULL, NULL, NULL},
    {"AssociatedDeviceAuthenticationState", &DMREAD, DMT_BOOL, get_LANDeviceWLANConfigurationAssociatedDevice_AssociatedDeviceAuthenticationState, NULL, NULL, NULL},
    {"LastRequestedUnicastCipher", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationAssociatedDevice_LastRequestedUnicastCipher, NULL, NULL, NULL},
    {"LastRequestedMulticastCipher", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationAssociatedDevice_LastRequestedMulticastCipher, NULL, NULL, NULL},
    {"LastPMKId", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationAssociatedDevice_LastPMKId, NULL, NULL, NULL},
    {"LastDataTransmitRate", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationAssociatedDevice_LastDataTransmitRate, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.WEPKey.{i}. *** */
DMLEAF tLANDeviceWLANConfigurationWEPKeyParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationWEPKey_Alias, set_LANDeviceWLANConfigurationWEPKey_Alias, NULL, NULL},
    {"WEPKey", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationWEPKey_WEPKey, set_LANDeviceWLANConfigurationWEPKey_WEPKey, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.PreSharedKey.{i}. *** */
DMLEAF tLANDeviceWLANConfigurationPreSharedKeyParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationPreSharedKey_Alias, set_LANDeviceWLANConfigurationPreSharedKey_Alias, NULL, NULL},
    {"PreSharedKey", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationPreSharedKey_PreSharedKey, set_LANDeviceWLANConfigurationPreSharedKey_PreSharedKey, NULL, NULL},
    {"KeyPassphrase", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationPreSharedKey_KeyPassphrase, set_LANDeviceWLANConfigurationPreSharedKey_KeyPassphrase, NULL, NULL},
    {"AssociatedDeviceMACAddress",
     &DMWRITE,
     DMT_STRING,
     get_LANDeviceWLANConfigurationPreSharedKey_AssociatedDeviceMACAddress,
     set_LANDeviceWLANConfigurationPreSharedKey_AssociatedDeviceMACAddress,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.APWMMParameter.{i}. *** */
DMLEAF tLANDeviceWLANConfigurationAPWMMParameterParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationAPWMMParameter_Alias, set_LANDeviceWLANConfigurationAPWMMParameter_Alias, NULL, NULL},
    {"AIFSN", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationAPWMMParameter_AIFSN, set_LANDeviceWLANConfigurationAPWMMParameter_AIFSN, NULL, NULL},
    {"ECWMin", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationAPWMMParameter_ECWMin, set_LANDeviceWLANConfigurationAPWMMParameter_ECWMin, NULL, NULL},
    {"ECWMax", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationAPWMMParameter_ECWMax, set_LANDeviceWLANConfigurationAPWMMParameter_ECWMax, NULL, NULL},
    {"TXOP", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationAPWMMParameter_TXOP, set_LANDeviceWLANConfigurationAPWMMParameter_TXOP, NULL, NULL},
    {"AckPolicy", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfigurationAPWMMParameter_AckPolicy, set_LANDeviceWLANConfigurationAPWMMParameter_AckPolicy, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.STAWMMParameter.{i}. *** */
DMLEAF tLANDeviceWLANConfigurationSTAWMMParameterParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationSTAWMMParameter_Alias, set_LANDeviceWLANConfigurationSTAWMMParameter_Alias, NULL, NULL},
    {"AIFSN", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationSTAWMMParameter_AIFSN, set_LANDeviceWLANConfigurationSTAWMMParameter_AIFSN, NULL, NULL},
    {"ECWMin", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationSTAWMMParameter_ECWMin, set_LANDeviceWLANConfigurationSTAWMMParameter_ECWMin, NULL, NULL},
    {"ECWMax", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationSTAWMMParameter_ECWMax, set_LANDeviceWLANConfigurationSTAWMMParameter_ECWMax, NULL, NULL},
    {"TXOP", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationSTAWMMParameter_TXOP, set_LANDeviceWLANConfigurationSTAWMMParameter_TXOP, NULL, NULL},
    {"AckPolicy", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfigurationSTAWMMParameter_AckPolicy, set_LANDeviceWLANConfigurationSTAWMMParameter_AckPolicy, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.Stats. *** */
DMLEAF tLANDeviceWLANConfigurationStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ErrorsSent", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_ErrorsSent, NULL, NULL, NULL},
    {"ErrorsReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_ErrorsReceived, NULL, NULL, NULL},
    {"UnicastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_UnicastPacketsSent, NULL, NULL, NULL},
    {"UnicastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_UnicastPacketsReceived, NULL, NULL, NULL},
    {"DiscardPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_DiscardPacketsSent, NULL, NULL, NULL},
    {"DiscardPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_DiscardPacketsReceived, NULL, NULL, NULL},
    {"MulticastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_MulticastPacketsSent, NULL, NULL, NULL},
    {"MulticastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_MulticastPacketsReceived, NULL, NULL, NULL},
    {"BroadcastPacketsSent", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_BroadcastPacketsSent, NULL, NULL, NULL},
    {"BroadcastPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_BroadcastPacketsReceived, NULL, NULL, NULL},
    {"UnknownProtoPacketsReceived", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationStats_UnknownProtoPacketsReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.WPS. *** */
DMOBJ tLANDeviceWLANConfigurationWPSObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Registrar", &DMREAD, NULL, NULL, NULL, browseLANDeviceWLANConfigurationWPSRegistrarInst, NULL, NULL, NULL, tLANDeviceWLANConfigurationWPSRegistrarParams, NULL},
    {0}};

DMLEAF tLANDeviceWLANConfigurationWPSParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfigurationWPS_Enable, set_LANDeviceWLANConfigurationWPS_Enable, NULL, NULL},
    {"DeviceName", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPS_DeviceName, NULL, NULL, NULL},
    {"DevicePassword", &DMWRITE, DMT_UNINT, get_LANDeviceWLANConfigurationWPS_DevicePassword, set_LANDeviceWLANConfigurationWPS_DevicePassword, NULL, NULL},
    {"UUID", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPS_UUID, NULL, NULL, NULL},
    {"Version", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationWPS_Version, NULL, NULL, NULL},
    {"ConfigMethodsSupported", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPS_ConfigMethodsSupported, NULL, NULL, NULL},
    {"ConfigMethodsEnabled", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationWPS_ConfigMethodsEnabled, set_LANDeviceWLANConfigurationWPS_ConfigMethodsEnabled, NULL, NULL},
    {"SetupLockedState", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPS_SetupLockedState, NULL, NULL, NULL},
    {"SetupLock", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfigurationWPS_SetupLock, set_LANDeviceWLANConfigurationWPS_SetupLock, NULL, NULL},
    {"ConfigurationState", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPS_ConfigurationState, NULL, NULL, NULL},
    {"LastConfigurationError", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPS_LastConfigurationError, NULL, NULL, NULL},
    {"RegistrarNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceWLANConfigurationWPS_RegistrarNumberOfEntries, NULL, NULL, NULL},
    {"RegistrarEstablished", &DMREAD, DMT_BOOL, get_LANDeviceWLANConfigurationWPS_RegistrarEstablished, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.WLANConfiguration.{i}.WPS.Registrar.{i}. *** */
DMLEAF tLANDeviceWLANConfigurationWPSRegistrarParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_LANDeviceWLANConfigurationWPSRegistrar_Enable, set_LANDeviceWLANConfigurationWPSRegistrar_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_LANDeviceWLANConfigurationWPSRegistrar_Alias, set_LANDeviceWLANConfigurationWPSRegistrar_Alias, NULL, NULL},
    {"UUID", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPSRegistrar_UUID, NULL, NULL, NULL},
    {"DeviceName", &DMREAD, DMT_STRING, get_LANDeviceWLANConfigurationWPSRegistrar_DeviceName, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.Hosts. *** */
DMOBJ tLANDeviceHostsObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Host", &DMREAD, NULL, NULL, NULL, browseLANDeviceHostsHostInst, NULL, NULL, NULL, tLANDeviceHostsHostParams, NULL},
    {0}};

DMLEAF tLANDeviceHostsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"HostNumberOfEntries", &DMREAD, DMT_UNINT, get_LANDeviceHosts_HostNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANDevice.{i}.Hosts.Host.{i}. *** */
DMLEAF tLANDeviceHostsHostParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"IPAddress", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_IPAddress, NULL, NULL, NULL},
    {"AddressSource", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_AddressSource, NULL, NULL, NULL},
    {"LeaseTimeRemaining", &DMREAD, DMT_INT, get_LANDeviceHostsHost_LeaseTimeRemaining, NULL, NULL, NULL},
    {"MACAddress", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_MACAddress, NULL, NULL, NULL},
    {"Layer2Interface", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_Layer2Interface, NULL, NULL, NULL},
    {"VendorClassID", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_VendorClassID, NULL, NULL, NULL},
    {"ClientID", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_ClientID, NULL, NULL, NULL},
    {"UserClassID", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_UserClassID, NULL, NULL, NULL},
    {"HostName", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_HostName, NULL, NULL, NULL},
    {"InterfaceType", &DMREAD, DMT_STRING, get_LANDeviceHostsHost_InterfaceType, NULL, NULL, NULL},
    {"Active", &DMREAD, DMT_BOOL, get_LANDeviceHostsHost_Active, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANInterfaces. *** */
DMOBJ tLANInterfacesObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"LANEthernetInterfaceConfig", &DMREAD, NULL, NULL, NULL, browseLANInterfacesLANEthernetInterfaceConfigInst, NULL, NULL, NULL, tLANInterfacesLANEthernetInterfaceConfigParams, NULL},
    {"LANUSBInterfaceConfig", &DMREAD, NULL, NULL, NULL, browseLANInterfacesLANUSBInterfaceConfigInst, NULL, NULL, NULL, tLANInterfacesLANUSBInterfaceConfigParams, NULL},
    {"WLANConfiguration", &DMREAD, NULL, NULL, NULL, browseLANInterfacesWLANConfigurationInst, NULL, NULL, NULL, tLANInterfacesWLANConfigurationParams, NULL},
    {0}};

DMLEAF tLANInterfacesParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"LANEthernetInterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_LANInterfaces_LANEthernetInterfaceNumberOfEntries, NULL, NULL, NULL},
    {"LANUSBInterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_LANInterfaces_LANUSBInterfaceNumberOfEntries, NULL, NULL, NULL},
    {"LANWLANConfigurationNumberOfEntries", &DMREAD, DMT_UNINT, get_LANInterfaces_LANWLANConfigurationNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANInterfaces.LANEthernetInterfaceConfig.{i}. *** */
DMLEAF tLANInterfacesLANEthernetInterfaceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANInterfacesLANEthernetInterfaceConfig_Alias, set_LANInterfacesLANEthernetInterfaceConfig_Alias, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANInterfaces.LANUSBInterfaceConfig.{i}. *** */
DMLEAF tLANInterfacesLANUSBInterfaceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANInterfacesLANUSBInterfaceConfig_Alias, set_LANInterfacesLANUSBInterfaceConfig_Alias, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.LANInterfaces.WLANConfiguration.{i}. *** */
DMLEAF tLANInterfacesWLANConfigurationParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_LANInterfacesWLANConfiguration_Alias, set_LANInterfacesWLANConfiguration_Alias, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}. *** */
DMOBJ tWANDeviceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"WANCommonInterfaceConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANCommonInterfaceConfigObj, tWANDeviceWANCommonInterfaceConfigParams, NULL},
    {"WANDSLInterfaceConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigObj, tWANDeviceWANDSLInterfaceConfigParams, NULL},
    {"WANEthernetInterfaceConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANEthernetInterfaceConfigObj, tWANDeviceWANEthernetInterfaceConfigParams, NULL},
    {"WANDSLConnectionManagement", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLConnectionManagementObj, tWANDeviceWANDSLConnectionManagementParams, NULL},
    {"WANDSLDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLDiagnosticsParams, NULL},
    {"WANConnectionDevice",
     &DMWRITE,
     addObjWANDeviceWANConnectionDevice,
     delObjWANDeviceWANConnectionDevice,
     NULL,
     browseWANDeviceWANConnectionDeviceInst,
     NULL,
     NULL,
     tWANDeviceWANConnectionDeviceObj,
     tWANDeviceWANConnectionDeviceParams,
     NULL},
    {0}};

DMLEAF tWANDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_WANDevice_Alias, set_WANDevice_Alias, NULL, NULL},
    {"WANConnectionNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDevice_WANConnectionNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANCommonInterfaceConfig. *** */
DMOBJ tWANDeviceWANCommonInterfaceConfigObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Connection", &DMREAD, NULL, NULL, NULL, browseWANDeviceWANCommonInterfaceConfigConnectionInst, NULL, NULL, NULL, tWANDeviceWANCommonInterfaceConfigConnectionParams, NULL},
    {0}};

DMLEAF tWANDeviceWANCommonInterfaceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EnabledForInternet", &DMWRITE, DMT_BOOL, get_WANDeviceWANCommonInterfaceConfig_EnabledForInternet, set_WANDeviceWANCommonInterfaceConfig_EnabledForInternet, NULL, NULL},
    {"WANAccessType", &DMREAD, DMT_STRING, get_WANDeviceWANCommonInterfaceConfig_WANAccessType, NULL, NULL, NULL},
    {"Layer1UpstreamMaxBitRate", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_Layer1UpstreamMaxBitRate, NULL, NULL, NULL},
    {"Layer1DownstreamMaxBitRate", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_Layer1DownstreamMaxBitRate, NULL, NULL, NULL},
    {"PhysicalLinkStatus", &DMREAD, DMT_STRING, get_WANDeviceWANCommonInterfaceConfig_PhysicalLinkStatus, NULL, NULL, NULL},
    {"WANAccessProvider", &DMREAD, DMT_STRING, get_WANDeviceWANCommonInterfaceConfig_WANAccessProvider, NULL, NULL, NULL},
    {"TotalBytesSent", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_TotalBytesSent, NULL, NULL, NULL},
    {"TotalBytesReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_TotalBytesReceived, NULL, NULL, NULL},
    {"TotalPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_TotalPacketsSent, NULL, NULL, NULL},
    {"TotalPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_TotalPacketsReceived, NULL, NULL, NULL},
    {"MaximumActiveConnections", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_MaximumActiveConnections, NULL, NULL, NULL},
    {"NumberOfActiveConnections", &DMREAD, DMT_UNINT, get_WANDeviceWANCommonInterfaceConfig_NumberOfActiveConnections, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANCommonInterfaceConfig.Connection.{i}. *** */
DMLEAF tWANDeviceWANCommonInterfaceConfigConnectionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_WANDeviceWANCommonInterfaceConfigConnection_Alias, set_WANDeviceWANCommonInterfaceConfigConnection_Alias, NULL, NULL},
    {"ActiveConnectionDeviceContainer", &DMREAD, DMT_STRING, get_WANDeviceWANCommonInterfaceConfigConnection_ActiveConnectionDeviceContainer, NULL, NULL, NULL},
    {"ActiveConnectionServiceID", &DMREAD, DMT_STRING, get_WANDeviceWANCommonInterfaceConfigConnection_ActiveConnectionServiceID, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig. *** */
DMOBJ tWANDeviceWANDSLInterfaceConfigObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigStatsObj, NULL, NULL},
    {"TestParams", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigTestParamsParams, NULL},
    {0}};

DMLEAF tWANDeviceWANDSLInterfaceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfig_Enable, set_WANDeviceWANDSLInterfaceConfig_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_Status, NULL, NULL, NULL},
    {"LinkEncapsulationSupported", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationSupported, NULL, NULL, NULL},
    {"LinkEncapsulationRequested", &DMWRITE, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationRequested, set_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationRequested, NULL, NULL},
    {"LinkEncapsulationUsed", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationUsed, NULL, NULL, NULL},
    {"ModulationType", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_ModulationType, NULL, NULL, NULL},
    {"StandardsSupported", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_StandardsSupported, NULL, NULL, NULL},
    {"StandardUsed", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_StandardUsed, NULL, NULL, NULL},
    {"LineEncoding", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_LineEncoding, NULL, NULL, NULL},
    {"AllowedProfiles", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_AllowedProfiles, NULL, NULL, NULL},
    {"CurrentProfile", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_CurrentProfile, NULL, NULL, NULL},
    {"PowerManagementState", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_PowerManagementState, NULL, NULL, NULL},
    {"SuccessFailureCause", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_SuccessFailureCause, NULL, NULL, NULL},
    {"LastStateTransmittedDownstream", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_LastStateTransmittedDownstream, NULL, NULL, NULL},
    {"LastStateTransmittedUpstream", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_LastStateTransmittedUpstream, NULL, NULL, NULL},
    {"UPBOKLE", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_UPBOKLE, NULL, NULL, NULL},
    {"MREFPSDds", &DMREAD, DMT_BASE64, get_WANDeviceWANDSLInterfaceConfig_MREFPSDds, NULL, NULL, NULL},
    {"MREFPSDus", &DMREAD, DMT_BASE64, get_WANDeviceWANDSLInterfaceConfig_MREFPSDus, NULL, NULL, NULL},
    {"LIMITMASK", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_LIMITMASK, NULL, NULL, NULL},
    {"US0MASK", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_US0MASK, NULL, NULL, NULL},
    {"DataPath", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_DataPath, NULL, NULL, NULL},
    {"InterleaveDepth", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_InterleaveDepth, NULL, NULL, NULL},
    {"LPATH", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_LPATH, NULL, NULL, NULL},
    {"INTLVDEPTH", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_INTLVDEPTH, NULL, NULL, NULL},
    {"INTLVBLOCK", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_INTLVBLOCK, NULL, NULL, NULL},
    {"ActualInterleavingDelay", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ActualInterleavingDelay, NULL, NULL, NULL},
    {"ACTINP", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_ACTINP, NULL, NULL, NULL},
    {"INPREPORT", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfig_INPREPORT, NULL, NULL, NULL},
    {"NFEC", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_NFEC, NULL, NULL, NULL},
    {"RFEC", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_RFEC, NULL, NULL, NULL},
    {"LSYMB", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_LSYMB, NULL, NULL, NULL},
    {"TRELLISds", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_TRELLISds, NULL, NULL, NULL},
    {"TRELLISus", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_TRELLISus, NULL, NULL, NULL},
    {"ACTSNRMODEds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ACTSNRMODEds, NULL, NULL, NULL},
    {"ACTSNRMODEus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ACTSNRMODEus, NULL, NULL, NULL},
    {"VirtualNoisePSDds", &DMREAD, DMT_BASE64, get_WANDeviceWANDSLInterfaceConfig_VirtualNoisePSDds, NULL, NULL, NULL},
    {"VirtualNoisePSDus", &DMREAD, DMT_BASE64, get_WANDeviceWANDSLInterfaceConfig_VirtualNoisePSDus, NULL, NULL, NULL},
    {"ACTUALCE", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ACTUALCE, NULL, NULL, NULL},
    {"LineNumber", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_LineNumber, NULL, NULL, NULL},
    {"UpstreamCurrRate", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_UpstreamCurrRate, NULL, NULL, NULL},
    {"DownstreamCurrRate", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_DownstreamCurrRate, NULL, NULL, NULL},
    {"UpstreamMaxRate", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_UpstreamMaxRate, NULL, NULL, NULL},
    {"DownstreamMaxRate", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_DownstreamMaxRate, NULL, NULL, NULL},
    {"UpstreamNoiseMargin", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_UpstreamNoiseMargin, NULL, NULL, NULL},
    {"DownstreamNoiseMargin", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_DownstreamNoiseMargin, NULL, NULL, NULL},
    {"SNRMpbus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_SNRMpbus, NULL, NULL, NULL},
    {"SNRMpbds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_SNRMpbds, NULL, NULL, NULL},
    {"INMIATOds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_INMIATOds, NULL, NULL, NULL},
    {"INMIATSds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_INMIATSds, NULL, NULL, NULL},
    {"INMCCds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_INMCCds, NULL, NULL, NULL},
    {"INMINPEQMODEds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_INMINPEQMODEds, NULL, NULL, NULL},
    {"UpstreamAttenuation", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_UpstreamAttenuation, NULL, NULL, NULL},
    {"DownstreamAttenuation", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_DownstreamAttenuation, NULL, NULL, NULL},
    {"UpstreamPower", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_UpstreamPower, NULL, NULL, NULL},
    {"DownstreamPower", &DMREAD, DMT_INT, get_WANDeviceWANDSLInterfaceConfig_DownstreamPower, NULL, NULL, NULL},
    {"ATURVendor", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_ATURVendor, NULL, NULL, NULL},
    {"ATURCountry", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_ATURCountry, NULL, NULL, NULL},
    {"ATURANSIStd", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ATURANSIStd, NULL, NULL, NULL},
    {"ATURANSIRev", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ATURANSIRev, NULL, NULL, NULL},
    {"ATUCVendor", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_ATUCVendor, NULL, NULL, NULL},
    {"ATUCCountry", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfig_ATUCCountry, NULL, NULL, NULL},
    {"ATUCANSIStd", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ATUCANSIStd, NULL, NULL, NULL},
    {"ATUCANSIRev", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ATUCANSIRev, NULL, NULL, NULL},
    {"TotalStart", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_TotalStart, NULL, NULL, NULL},
    {"ShowtimeStart", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_ShowtimeStart, NULL, NULL, NULL},
    {"LastShowtimeStart", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_LastShowtimeStart, NULL, NULL, NULL},
    {"CurrentDayStart", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_CurrentDayStart, NULL, NULL, NULL},
    {"QuarterHourStart", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfig_QuarterHourStart, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig.Stats. *** */
DMOBJ tWANDeviceWANDSLInterfaceConfigStatsObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Total", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigStatsTotalParams, NULL},
    {"Showtime", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigStatsShowtimeParams, NULL},
    {"LastShowtime", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigStatsLastShowtimeParams, NULL},
    {"CurrentDay", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigStatsCurrentDayParams, NULL},
    {"QuarterHour", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANDSLInterfaceConfigStatsQuarterHourParams, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig.Stats.Total. *** */
DMLEAF tWANDeviceWANDSLInterfaceConfigStatsTotalParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ReceiveBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_ReceiveBlocks, NULL, NULL, NULL},
    {"TransmitBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_TransmitBlocks, NULL, NULL, NULL},
    {"CellDelin", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_CellDelin, NULL, NULL, NULL},
    {"LinkRetrain", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_LinkRetrain, NULL, NULL, NULL},
    {"InitErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_InitErrors, NULL, NULL, NULL},
    {"LInit", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsTotal_LInit, NULL, NULL, NULL},
    {"InitTimeouts", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_InitTimeouts, NULL, NULL, NULL},
    {"LossOfFraming", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_LossOfFraming, NULL, NULL, NULL},
    {"LOF", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsTotal_LOF, NULL, NULL, NULL},
    {"ErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_ErroredSecs, NULL, NULL, NULL},
    {"ATUCErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCErroredSecs, NULL, NULL, NULL},
    {"SeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_SeverelyErroredSecs, NULL, NULL, NULL},
    {"ATUCSeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCSeverelyErroredSecs, NULL, NULL, NULL},
    {"FECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_FECErrors, NULL, NULL, NULL},
    {"ATUCFECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCFECErrors, NULL, NULL, NULL},
    {"HECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_HECErrors, NULL, NULL, NULL},
    {"ATUCHECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCHECErrors, NULL, NULL, NULL},
    {"CRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_CRCErrors, NULL, NULL, NULL},
    {"ATUCCRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCCRCErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig.Stats.Showtime. *** */
DMLEAF tWANDeviceWANDSLInterfaceConfigStatsShowtimeParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ReceiveBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ReceiveBlocks, NULL, NULL, NULL},
    {"TransmitBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_TransmitBlocks, NULL, NULL, NULL},
    {"CellDelin", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_CellDelin, NULL, NULL, NULL},
    {"LinkRetrain", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LinkRetrain, NULL, NULL, NULL},
    {"InitErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_InitErrors, NULL, NULL, NULL},
    {"LInit", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LInit, NULL, NULL, NULL},
    {"InitTimeouts", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_InitTimeouts, NULL, NULL, NULL},
    {"LossOfFraming", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LossOfFraming, NULL, NULL, NULL},
    {"LOF", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LOF, NULL, NULL, NULL},
    {"ErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ErroredSecs, NULL, NULL, NULL},
    {"ATUCErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCErroredSecs, NULL, NULL, NULL},
    {"SeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_SeverelyErroredSecs, NULL, NULL, NULL},
    {"ATUCSeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCSeverelyErroredSecs, NULL, NULL, NULL},
    {"FECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_FECErrors, NULL, NULL, NULL},
    {"ATUCFECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCFECErrors, NULL, NULL, NULL},
    {"HECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_HECErrors, NULL, NULL, NULL},
    {"ATUCHECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCHECErrors, NULL, NULL, NULL},
    {"CRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_CRCErrors, NULL, NULL, NULL},
    {"ATUCCRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCCRCErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig.Stats.LastShowtime. *** */
DMLEAF tWANDeviceWANDSLInterfaceConfigStatsLastShowtimeParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ReceiveBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ReceiveBlocks, NULL, NULL, NULL},
    {"TransmitBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_TransmitBlocks, NULL, NULL, NULL},
    {"CellDelin", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_CellDelin, NULL, NULL, NULL},
    {"LinkRetrain", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LinkRetrain, NULL, NULL, NULL},
    {"InitErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_InitErrors, NULL, NULL, NULL},
    {"LInit", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LInit, NULL, NULL, NULL},
    {"InitTimeouts", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_InitTimeouts, NULL, NULL, NULL},
    {"LossOfFraming", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LossOfFraming, NULL, NULL, NULL},
    {"LOF", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LOF, NULL, NULL, NULL},
    {"ErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ErroredSecs, NULL, NULL, NULL},
    {"ATUCErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCErroredSecs, NULL, NULL, NULL},
    {"SeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_SeverelyErroredSecs, NULL, NULL, NULL},
    {"ATUCSeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCSeverelyErroredSecs, NULL, NULL, NULL},
    {"FECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_FECErrors, NULL, NULL, NULL},
    {"ATUCFECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCFECErrors, NULL, NULL, NULL},
    {"HECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_HECErrors, NULL, NULL, NULL},
    {"ATUCHECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCHECErrors, NULL, NULL, NULL},
    {"CRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_CRCErrors, NULL, NULL, NULL},
    {"ATUCCRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCCRCErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig.Stats.CurrentDay. *** */
DMLEAF tWANDeviceWANDSLInterfaceConfigStatsCurrentDayParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ReceiveBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ReceiveBlocks, NULL, NULL, NULL},
    {"TransmitBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_TransmitBlocks, NULL, NULL, NULL},
    {"CellDelin", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_CellDelin, NULL, NULL, NULL},
    {"LinkRetrain", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LinkRetrain, NULL, NULL, NULL},
    {"InitErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_InitErrors, NULL, NULL, NULL},
    {"LInit", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LInit, NULL, NULL, NULL},
    {"InitTimeouts", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_InitTimeouts, NULL, NULL, NULL},
    {"LossOfFraming", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LossOfFraming, NULL, NULL, NULL},
    {"LOF", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LOF, NULL, NULL, NULL},
    {"ErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ErroredSecs, NULL, NULL, NULL},
    {"ATUCErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCErroredSecs, NULL, NULL, NULL},
    {"SeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_SeverelyErroredSecs, NULL, NULL, NULL},
    {"ATUCSeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCSeverelyErroredSecs, NULL, NULL, NULL},
    {"FECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_FECErrors, NULL, NULL, NULL},
    {"ATUCFECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCFECErrors, NULL, NULL, NULL},
    {"HECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_HECErrors, NULL, NULL, NULL},
    {"ATUCHECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCHECErrors, NULL, NULL, NULL},
    {"CRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_CRCErrors, NULL, NULL, NULL},
    {"ATUCCRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCCRCErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig.Stats.QuarterHour. *** */
DMLEAF tWANDeviceWANDSLInterfaceConfigStatsQuarterHourParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ReceiveBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ReceiveBlocks, NULL, NULL, NULL},
    {"TransmitBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_TransmitBlocks, NULL, NULL, NULL},
    {"CellDelin", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_CellDelin, NULL, NULL, NULL},
    {"LinkRetrain", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LinkRetrain, NULL, NULL, NULL},
    {"InitErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_InitErrors, NULL, NULL, NULL},
    {"LInit", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LInit, NULL, NULL, NULL},
    {"InitTimeouts", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_InitTimeouts, NULL, NULL, NULL},
    {"LossOfFraming", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LossOfFraming, NULL, NULL, NULL},
    {"LOF", &DMREAD, DMT_BOOL, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LOF, NULL, NULL, NULL},
    {"ErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ErroredSecs, NULL, NULL, NULL},
    {"ATUCErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCErroredSecs, NULL, NULL, NULL},
    {"SeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_SeverelyErroredSecs, NULL, NULL, NULL},
    {"ATUCSeverelyErroredSecs", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCSeverelyErroredSecs, NULL, NULL, NULL},
    {"FECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_FECErrors, NULL, NULL, NULL},
    {"ATUCFECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCFECErrors, NULL, NULL, NULL},
    {"HECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_HECErrors, NULL, NULL, NULL},
    {"ATUCHECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCHECErrors, NULL, NULL, NULL},
    {"CRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_CRCErrors, NULL, NULL, NULL},
    {"ATUCCRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCCRCErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLInterfaceConfig.TestParams. *** */
DMLEAF tWANDeviceWANDSLInterfaceConfigTestParamsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"HLOGGds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGGds, NULL, NULL, NULL},
    {"HLOGGus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGGus, NULL, NULL, NULL},
    {"HLOGpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGpsds, NULL, NULL, NULL},
    {"HLOGpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGpsus, NULL, NULL, NULL},
    {"HLOGMTds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGMTds, NULL, NULL, NULL},
    {"HLOGMTus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGMTus, NULL, NULL, NULL},
    {"QLNGds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_QLNGds, NULL, NULL, NULL},
    {"QLNGus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_QLNGus, NULL, NULL, NULL},
    {"QLNpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_QLNpsds, NULL, NULL, NULL},
    {"QLNpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_QLNpsus, NULL, NULL, NULL},
    {"QLNMTds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_QLNMTds, NULL, NULL, NULL},
    {"QLNMTus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_QLNMTus, NULL, NULL, NULL},
    {"SNRGds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_SNRGds, NULL, NULL, NULL},
    {"SNRGus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_SNRGus, NULL, NULL, NULL},
    {"SNRpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_SNRpsds, NULL, NULL, NULL},
    {"SNRpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_SNRpsus, NULL, NULL, NULL},
    {"SNRMTds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_SNRMTds, NULL, NULL, NULL},
    {"SNRMTus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLInterfaceConfigTestParams_SNRMTus, NULL, NULL, NULL},
    {"LATNds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_LATNds, NULL, NULL, NULL},
    {"LATNus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_LATNus, NULL, NULL, NULL},
    {"SATNds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_SATNds, NULL, NULL, NULL},
    {"SATNus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLInterfaceConfigTestParams_SATNus, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANEthernetInterfaceConfig. *** */
DMOBJ tWANDeviceWANEthernetInterfaceConfigObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANEthernetInterfaceConfigStatsParams, NULL},
    {0}};

DMLEAF tWANDeviceWANEthernetInterfaceConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_WANDeviceWANEthernetInterfaceConfig_Enable, set_WANDeviceWANEthernetInterfaceConfig_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_WANDeviceWANEthernetInterfaceConfig_Status, NULL, NULL, NULL},
    {"MACAddress", &DMREAD, DMT_STRING, get_WANDeviceWANEthernetInterfaceConfig_MACAddress, NULL, NULL, NULL},
    {"MaxBitRate", &DMWRITE, DMT_STRING, get_WANDeviceWANEthernetInterfaceConfig_MaxBitRate, set_WANDeviceWANEthernetInterfaceConfig_MaxBitRate, NULL, NULL},
    {"DuplexMode", &DMWRITE, DMT_STRING, get_WANDeviceWANEthernetInterfaceConfig_DuplexMode, set_WANDeviceWANEthernetInterfaceConfig_DuplexMode, NULL, NULL},
    {"ShapingRate", &DMWRITE, DMT_INT, get_WANDeviceWANEthernetInterfaceConfig_ShapingRate, set_WANDeviceWANEthernetInterfaceConfig_ShapingRate, NULL, NULL},
    {"ShapingBurstSize", &DMWRITE, DMT_UNINT, get_WANDeviceWANEthernetInterfaceConfig_ShapingBurstSize, set_WANDeviceWANEthernetInterfaceConfig_ShapingBurstSize, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANEthernetInterfaceConfig.Stats. *** */
DMLEAF tWANDeviceWANEthernetInterfaceConfigStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"BytesSent", &DMREAD, DMT_UNINT, get_WANDeviceWANEthernetInterfaceConfigStats_BytesSent, NULL, NULL, NULL},
    {"BytesReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANEthernetInterfaceConfigStats_BytesReceived, NULL, NULL, NULL},
    {"PacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANEthernetInterfaceConfigStats_PacketsSent, NULL, NULL, NULL},
    {"PacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANEthernetInterfaceConfigStats_PacketsReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLConnectionManagement. *** */
DMOBJ tWANDeviceWANDSLConnectionManagementObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"ConnectionService",
     &DMREAD,
     NULL,
     NULL,
     NULL,
     browseWANDeviceWANDSLConnectionManagementConnectionServiceInst,
     NULL,
     NULL,
     NULL,
     tWANDeviceWANDSLConnectionManagementConnectionServiceParams,
     NULL},
    {0}};

DMLEAF tWANDeviceWANDSLConnectionManagementParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ConnectionServiceNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLConnectionManagement_ConnectionServiceNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLConnectionManagement.ConnectionService.{i}. *** */
DMLEAF tWANDeviceWANDSLConnectionManagementConnectionServiceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"WANConnectionDevice", &DMREAD, DMT_STRING, get_WANDeviceWANDSLConnectionManagementConnectionService_WANConnectionDevice, NULL, NULL, NULL},
    {"WANConnectionService", &DMREAD, DMT_STRING, get_WANDeviceWANDSLConnectionManagementConnectionService_WANConnectionService, NULL, NULL, NULL},
    {"DestinationAddress", &DMREAD, DMT_STRING, get_WANDeviceWANDSLConnectionManagementConnectionService_DestinationAddress, NULL, NULL, NULL},
    {"LinkType", &DMREAD, DMT_STRING, get_WANDeviceWANDSLConnectionManagementConnectionService_LinkType, NULL, NULL, NULL},
    {"ConnectionType", &DMREAD, DMT_STRING, get_WANDeviceWANDSLConnectionManagementConnectionService_ConnectionType, NULL, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_WANDeviceWANDSLConnectionManagementConnectionService_Name, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANDSLDiagnostics. *** */
DMLEAF tWANDeviceWANDSLDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"LoopDiagnosticsState", &DMWRITE, DMT_STRING, get_WANDeviceWANDSLDiagnostics_LoopDiagnosticsState, set_WANDeviceWANDSLDiagnostics_LoopDiagnosticsState, NULL, NULL},
    {"ACTPSDds", &DMREAD, DMT_INT, get_WANDeviceWANDSLDiagnostics_ACTPSDds, NULL, NULL, NULL},
    {"ACTPSDus", &DMREAD, DMT_INT, get_WANDeviceWANDSLDiagnostics_ACTPSDus, NULL, NULL, NULL},
    {"ACTATPds", &DMREAD, DMT_INT, get_WANDeviceWANDSLDiagnostics_ACTATPds, NULL, NULL, NULL},
    {"ACTATPus", &DMREAD, DMT_INT, get_WANDeviceWANDSLDiagnostics_ACTATPus, NULL, NULL, NULL},
    {"HLINSCds", &DMREAD, DMT_INT, get_WANDeviceWANDSLDiagnostics_HLINSCds, NULL, NULL, NULL},
    {"HLINSCus", &DMREAD, DMT_INT, get_WANDeviceWANDSLDiagnostics_HLINSCus, NULL, NULL, NULL},
    {"HLINGds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_HLINGds, NULL, NULL, NULL},
    {"HLINGus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_HLINGus, NULL, NULL, NULL},
    {"HLOGGds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_HLOGGds, NULL, NULL, NULL},
    {"HLOGGus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_HLOGGus, NULL, NULL, NULL},
    {"HLOGpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_HLOGpsds, NULL, NULL, NULL},
    {"HLOGpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_HLOGpsus, NULL, NULL, NULL},
    {"HLOGMTds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_HLOGMTds, NULL, NULL, NULL},
    {"HLOGMTus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_HLOGMTus, NULL, NULL, NULL},
    {"LATNpbds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_LATNpbds, NULL, NULL, NULL},
    {"LATNpbus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_LATNpbus, NULL, NULL, NULL},
    {"SATNds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_SATNds, NULL, NULL, NULL},
    {"SATNus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_SATNus, NULL, NULL, NULL},
    {"HLINpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_HLINpsds, NULL, NULL, NULL},
    {"HLINpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_HLINpsus, NULL, NULL, NULL},
    {"QLNGds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_QLNGds, NULL, NULL, NULL},
    {"QLNGus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_QLNGus, NULL, NULL, NULL},
    {"QLNpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_QLNpsds, NULL, NULL, NULL},
    {"QLNpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_QLNpsus, NULL, NULL, NULL},
    {"QLNMTds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_QLNMTds, NULL, NULL, NULL},
    {"QLNMTus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_QLNMTus, NULL, NULL, NULL},
    {"SNRGds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_SNRGds, NULL, NULL, NULL},
    {"SNRGus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_SNRGus, NULL, NULL, NULL},
    {"SNRpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_SNRpsds, NULL, NULL, NULL},
    {"SNRpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_SNRpsus, NULL, NULL, NULL},
    {"SNRMTds", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_SNRMTds, NULL, NULL, NULL},
    {"SNRMTus", &DMREAD, DMT_UNINT, get_WANDeviceWANDSLDiagnostics_SNRMTus, NULL, NULL, NULL},
    {"BITSpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_BITSpsds, NULL, NULL, NULL},
    {"BITSpsus", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_BITSpsus, NULL, NULL, NULL},
    {"GAINSpsds", &DMREAD, DMT_STRING, get_WANDeviceWANDSLDiagnostics_GAINSpsds, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}. *** */
DMOBJ tWANDeviceWANConnectionDeviceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"WANDSLLinkConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANDSLLinkConfigParams, NULL},
    {"WANATMF5LoopbackDiagnostics", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnosticsParams, NULL},
    {"WANPTMLinkConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANPTMLinkConfigObj, tWANDeviceWANConnectionDeviceWANPTMLinkConfigParams, NULL},
    {"WANEthernetLinkConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANEthernetLinkConfigParams, NULL},
    {"WANPOTSLinkConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANPOTSLinkConfigParams, NULL},
    {"WANIPConnection",
     &DMWRITE,
     addObjWANDeviceWANConnectionDeviceWANIPConnection,
     delObjWANDeviceWANConnectionDeviceWANIPConnection,
     NULL,
     browseWANDeviceWANConnectionDeviceWANIPConnectionInst,
     NULL,
     NULL,
     tWANDeviceWANConnectionDeviceWANIPConnectionObj,
     tWANDeviceWANConnectionDeviceWANIPConnectionParams,
     NULL},
    {"WANPPPConnection",
     &DMWRITE,
     addObjWANDeviceWANConnectionDeviceWANPPPConnection,
     delObjWANDeviceWANConnectionDeviceWANPPPConnection,
     NULL,
     browseWANDeviceWANConnectionDeviceWANPPPConnectionInst,
     NULL,
     NULL,
     tWANDeviceWANConnectionDeviceWANPPPConnectionObj,
     tWANDeviceWANConnectionDeviceWANPPPConnectionParams,
     NULL},
    {0}};

DMLEAF tWANDeviceWANConnectionDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDevice_Alias, set_WANDeviceWANConnectionDevice_Alias, NULL, NULL},
    {"WANIPConnectionNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDevice_WANIPConnectionNumberOfEntries, NULL, NULL, NULL},
    {"WANPPPConnectionNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDevice_WANPPPConnectionNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANDSLLinkConfig. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANDSLLinkConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_Enable, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_Enable, NULL, NULL},
    {"LinkStatus", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_LinkStatus, NULL, NULL, NULL},
    {"LinkType", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_LinkType, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_LinkType, NULL, NULL},
    {"AutoConfig", &DMREAD, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_AutoConfig, NULL, NULL, NULL},
    {"ModulationType", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ModulationType, NULL, NULL, NULL},
    {"DestinationAddress", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_DestinationAddress, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_DestinationAddress, NULL, NULL},
    {"ATMEncapsulation", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMEncapsulation, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMEncapsulation, NULL, NULL},
    {"FCSPreserved", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_FCSPreserved, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_FCSPreserved, NULL, NULL},
    {"VCSearchList", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_VCSearchList, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_VCSearchList, NULL, NULL},
    {"ATMAAL", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMAAL, NULL, NULL, NULL},
    {"ATMTransmittedBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMTransmittedBlocks, NULL, NULL, NULL},
    {"ATMReceivedBlocks", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMReceivedBlocks, NULL, NULL, NULL},
    {"ATMQoS", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMQoS, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMQoS, NULL, NULL},
    {"ATMPeakCellRate", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMPeakCellRate, set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMPeakCellRate, NULL, NULL},
    {"ATMMaximumBurstSize",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMMaximumBurstSize,
     set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMMaximumBurstSize,
     NULL,
     NULL},
    {"ATMSustainableCellRate",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMSustainableCellRate,
     set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMSustainableCellRate,
     NULL,
     NULL},
    {"AAL5CRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_AAL5CRCErrors, NULL, NULL, NULL},
    {"ATMCRCErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMCRCErrors, NULL, NULL, NULL},
    {"ATMHECErrors", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMHECErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANATMF5LoopbackDiagnostics. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DiagnosticsState",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_DiagnosticsState,
     set_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_DiagnosticsState,
     NULL,
     NULL},
    {"NumberOfRepetitions",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_NumberOfRepetitions,
     set_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_NumberOfRepetitions,
     NULL,
     NULL},
    {"Timeout", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_Timeout, set_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_Timeout, NULL, NULL},
    {"SuccessCount", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_SuccessCount, NULL, NULL, NULL},
    {"FailureCount", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_FailureCount, NULL, NULL, NULL},
    {"AverageResponseTime", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_AverageResponseTime, NULL, NULL, NULL},
    {"MinimumResponseTime", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_MinimumResponseTime, NULL, NULL, NULL},
    {"MaximumResponseTime", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_MaximumResponseTime, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANPTMLinkConfig. *** */
DMOBJ tWANDeviceWANConnectionDeviceWANPTMLinkConfigObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANPTMLinkConfigStatsParams, NULL},
    {0}};

DMLEAF tWANDeviceWANConnectionDeviceWANPTMLinkConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPTMLinkConfig_Enable, set_WANDeviceWANConnectionDeviceWANPTMLinkConfig_Enable, NULL, NULL},
    {"LinkStatus", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPTMLinkConfig_LinkStatus, NULL, NULL, NULL},
    {"MACAddress", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPTMLinkConfig_MACAddress, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANPTMLinkConfig.Stats. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANPTMLinkConfigStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"BytesSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BytesSent, NULL, NULL, NULL},
    {"BytesReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BytesReceived, NULL, NULL, NULL},
    {"FramesSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_FramesSent, NULL, NULL, NULL},
    {"FramesReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_FramesReceived, NULL, NULL, NULL},
    {"OOSNearEnd", &DMREAD, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_OOSNearEnd, NULL, NULL, NULL},
    {"OOSFarEnd", &DMREAD, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_OOSFarEnd, NULL, NULL, NULL},
    {"ErrorsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_ErrorsSent, NULL, NULL, NULL},
    {"ErrorsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_ErrorsReceived, NULL, NULL, NULL},
    {"UnicastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_UnicastPacketsSent, NULL, NULL, NULL},
    {"UnicastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_UnicastPacketsReceived, NULL, NULL, NULL},
    {"DiscardPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_DiscardPacketsSent, NULL, NULL, NULL},
    {"DiscardPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_DiscardPacketsReceived, NULL, NULL, NULL},
    {"MulticastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_MulticastPacketsSent, NULL, NULL, NULL},
    {"MulticastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_MulticastPacketsReceived, NULL, NULL, NULL},
    {"BroadcastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BroadcastPacketsSent, NULL, NULL, NULL},
    {"BroadcastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BroadcastPacketsReceived, NULL, NULL, NULL},
    {"UnknownProtoPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_UnknownProtoPacketsReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANEthernetLinkConfig. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANEthernetLinkConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EthernetLinkStatus", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANEthernetLinkConfig_EthernetLinkStatus, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANPOTSLinkConfig. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANPOTSLinkConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_Enable, set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_Enable, NULL, NULL},
    {"LinkStatus", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_LinkStatus, NULL, NULL, NULL},
    {"ISPPhoneNumber", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPPhoneNumber, set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPPhoneNumber, NULL, NULL},
    {"ISPInfo", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPInfo, set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPInfo, NULL, NULL},
    {"LinkType", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_LinkType, set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_LinkType, NULL, NULL},
    {"NumberOfRetries", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_NumberOfRetries, set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_NumberOfRetries, NULL, NULL},
    {"DelayBetweenRetries",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DelayBetweenRetries,
     set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DelayBetweenRetries,
     NULL,
     NULL},
    {"Fclass", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_Fclass, NULL, NULL, NULL},
    {"DataModulationSupported", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DataModulationSupported, NULL, NULL, NULL},
    {"DataProtocol", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DataProtocol, NULL, NULL, NULL},
    {"DataCompression", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DataCompression, NULL, NULL, NULL},
    {"PlusVTRCommandSupported", &DMREAD, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_PlusVTRCommandSupported, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANIPConnection.{i}. *** */
DMOBJ tWANDeviceWANConnectionDeviceWANIPConnectionObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"DHCPClient", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientObj, tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientParams, NULL},
    {"PortMapping",
     &DMWRITE,
     addObjWANDeviceWANConnectionDeviceWANIPConnectionPortMapping,
     delObjWANDeviceWANConnectionDeviceWANIPConnectionPortMapping,
     NULL,
     browseWANDeviceWANConnectionDeviceWANIPConnectionPortMappingInst,
     NULL,
     NULL,
     NULL,
     tWANDeviceWANConnectionDeviceWANIPConnectionPortMappingParams,
     NULL},
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANIPConnectionStatsParams, NULL},
    {0}};

DMLEAF tWANDeviceWANConnectionDeviceWANIPConnectionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANIPConnection_Enable, set_WANDeviceWANConnectionDeviceWANIPConnection_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_Alias, set_WANDeviceWANConnectionDeviceWANIPConnection_Alias, NULL, NULL},
    {"Reset", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANIPConnection_Reset, set_WANDeviceWANConnectionDeviceWANIPConnection_Reset, NULL, NULL},
    {"ConnectionStatus", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionStatus, NULL, NULL, NULL},
    {"PossibleConnectionTypes", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_PossibleConnectionTypes, NULL, NULL, NULL},
    {"ConnectionType", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionType, set_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionType, NULL, NULL},
    {"Name", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_Name, set_WANDeviceWANConnectionDeviceWANIPConnection_Name, NULL, NULL},
    {"Uptime", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnection_Uptime, NULL, NULL, NULL},
    {"LastConnectionError", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_LastConnectionError, NULL, NULL, NULL},
    {"AutoDisconnectTime", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnection_AutoDisconnectTime, set_WANDeviceWANConnectionDeviceWANIPConnection_AutoDisconnectTime, NULL, NULL},
    {"IdleDisconnectTime", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnection_IdleDisconnectTime, set_WANDeviceWANConnectionDeviceWANIPConnection_IdleDisconnectTime, NULL, NULL},
    {"WarnDisconnectDelay", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnection_WarnDisconnectDelay, set_WANDeviceWANConnectionDeviceWANIPConnection_WarnDisconnectDelay, NULL, NULL},
    {"RSIPAvailable", &DMREAD, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANIPConnection_RSIPAvailable, NULL, NULL, NULL},
    {"NATEnabled", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANIPConnection_NATEnabled, set_WANDeviceWANConnectionDeviceWANIPConnection_NATEnabled, NULL, NULL},
    {"AddressingType", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_AddressingType, set_WANDeviceWANConnectionDeviceWANIPConnection_AddressingType, NULL, NULL},
    {"ExternalIPAddress", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_ExternalIPAddress, set_WANDeviceWANConnectionDeviceWANIPConnection_ExternalIPAddress, NULL, NULL},
    {"SubnetMask", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_SubnetMask, set_WANDeviceWANConnectionDeviceWANIPConnection_SubnetMask, NULL, NULL},
    {"DefaultGateway", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_DefaultGateway, set_WANDeviceWANConnectionDeviceWANIPConnection_DefaultGateway, NULL, NULL},
    {"DNSEnabled", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANIPConnection_DNSEnabled, set_WANDeviceWANConnectionDeviceWANIPConnection_DNSEnabled, NULL, NULL},
    {"DNSOverrideAllowed", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANIPConnection_DNSOverrideAllowed, set_WANDeviceWANConnectionDeviceWANIPConnection_DNSOverrideAllowed, NULL, NULL},
    {"DNSServers", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_DNSServers, set_WANDeviceWANConnectionDeviceWANIPConnection_DNSServers, NULL, NULL},
    {"MaxMTUSize", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnection_MaxMTUSize, set_WANDeviceWANConnectionDeviceWANIPConnection_MaxMTUSize, NULL, NULL},
    {"MACAddress", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_MACAddress, set_WANDeviceWANConnectionDeviceWANIPConnection_MACAddress, NULL, NULL},
    {"MACAddressOverride", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANIPConnection_MACAddressOverride, set_WANDeviceWANConnectionDeviceWANIPConnection_MACAddressOverride, NULL, NULL},
    {"ConnectionTrigger", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionTrigger, set_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionTrigger, NULL, NULL},
    {"RouteProtocolRx", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnection_RouteProtocolRx, set_WANDeviceWANConnectionDeviceWANIPConnection_RouteProtocolRx, NULL, NULL},
    {"ShapingRate", &DMWRITE, DMT_INT, get_WANDeviceWANConnectionDeviceWANIPConnection_ShapingRate, set_WANDeviceWANConnectionDeviceWANIPConnection_ShapingRate, NULL, NULL},
    {"ShapingBurstSize", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnection_ShapingBurstSize, set_WANDeviceWANConnectionDeviceWANIPConnection_ShapingBurstSize, NULL, NULL},
    {"PortMappingNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnection_PortMappingNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANIPConnection.{i}.DHCPClient. *** */
DMOBJ tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"SentDHCPOption",
     &DMWRITE,
     addObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption,
     delObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption,
     NULL,
     browseWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOptionInst,
     NULL,
     NULL,
     NULL,
     tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOptionParams,
     NULL},
    {"ReqDHCPOption",
     &DMWRITE,
     addObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption,
     delObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption,
     NULL,
     browseWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOptionInst,
     NULL,
     NULL,
     NULL,
     tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOptionParams,
     NULL},
    {0}};

DMLEAF tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"SentDHCPOptionNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClient_SentDHCPOptionNumberOfEntries, NULL, NULL, NULL},
    {"ReqDHCPOptionNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClient_ReqDHCPOptionNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANIPConnection.{i}.DHCPClient.SentDHCPOption.{i}. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOptionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable",
     &DMWRITE,
     DMT_BOOL,
     get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Enable,
     set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Enable,
     NULL,
     NULL},
    {"Alias",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Alias,
     set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Alias,
     NULL,
     NULL},
    {"Tag", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Tag, set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Tag, NULL, NULL},
    {"Value",
     &DMWRITE,
     DMT_BASE64,
     get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Value,
     set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Value,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANIPConnection.{i}.DHCPClient.ReqDHCPOption.{i}. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOptionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable",
     &DMWRITE,
     DMT_BOOL,
     get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Enable,
     set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Enable,
     NULL,
     NULL},
    {"Alias",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Alias,
     set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Alias,
     NULL,
     NULL},
    {"Order",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Order,
     set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Order,
     NULL,
     NULL},
    {"Tag", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Tag, set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Tag, NULL, NULL},
    {"Value", &DMREAD, DMT_BASE64, get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Value, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANIPConnection.{i}.PortMapping.{i}. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANIPConnectionPortMappingParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"PortMappingEnabled",
     &DMWRITE,
     DMT_BOOL,
     get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingEnabled,
     set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingEnabled,
     NULL,
     NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_Alias, set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_Alias, NULL, NULL},
    {"PortMappingLeaseDuration",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingLeaseDuration,
     set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingLeaseDuration,
     NULL,
     NULL},
    {"RemoteHost", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_RemoteHost, set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_RemoteHost, NULL, NULL},
    {"ExternalPort", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPort, set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPort, NULL, NULL},
    {"ExternalPortEndRange",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPortEndRange,
     set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPortEndRange,
     NULL,
     NULL},
    {"InternalPort", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalPort, set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalPort, NULL, NULL},
    {"PortMappingProtocol",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingProtocol,
     set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingProtocol,
     NULL,
     NULL},
    {"InternalClient",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalClient,
     set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalClient,
     NULL,
     NULL},
    {"PortMappingDescription",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingDescription,
     set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingDescription,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANIPConnection.{i}.Stats. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANIPConnectionStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EthernetBytesSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBytesSent, NULL, NULL, NULL},
    {"EthernetBytesReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBytesReceived, NULL, NULL, NULL},
    {"EthernetPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetPacketsSent, NULL, NULL, NULL},
    {"EthernetPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetPacketsReceived, NULL, NULL, NULL},
    {"EthernetErrorsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetErrorsSent, NULL, NULL, NULL},
    {"EthernetErrorsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetErrorsReceived, NULL, NULL, NULL},
    {"EthernetUnicastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetUnicastPacketsSent, NULL, NULL, NULL},
    {"EthernetUnicastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetUnicastPacketsReceived, NULL, NULL, NULL},
    {"EthernetDiscardPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetDiscardPacketsSent, NULL, NULL, NULL},
    {"EthernetDiscardPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetDiscardPacketsReceived, NULL, NULL, NULL},
    {"EthernetMulticastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetMulticastPacketsSent, NULL, NULL, NULL},
    {"EthernetMulticastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetMulticastPacketsReceived, NULL, NULL, NULL},
    {"EthernetBroadcastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBroadcastPacketsSent, NULL, NULL, NULL},
    {"EthernetBroadcastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBroadcastPacketsReceived, NULL, NULL, NULL},
    {"EthernetUnknownProtoPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetUnknownProtoPacketsReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANPPPConnection.{i}. *** */
DMOBJ tWANDeviceWANConnectionDeviceWANPPPConnectionObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"PortMapping",
     &DMWRITE,
     addObjWANDeviceWANConnectionDeviceWANPPPConnectionPortMapping,
     delObjWANDeviceWANConnectionDeviceWANPPPConnectionPortMapping,
     NULL,
     browseWANDeviceWANConnectionDeviceWANPPPConnectionPortMappingInst,
     NULL,
     NULL,
     NULL,
     tWANDeviceWANConnectionDeviceWANPPPConnectionPortMappingParams,
     NULL},
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tWANDeviceWANConnectionDeviceWANPPPConnectionStatsParams, NULL},
    {0}};

DMLEAF tWANDeviceWANConnectionDeviceWANPPPConnectionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPPPConnection_Enable, set_WANDeviceWANConnectionDeviceWANPPPConnection_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_Alias, set_WANDeviceWANConnectionDeviceWANPPPConnection_Alias, NULL, NULL},
    {"Reset", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPPPConnection_Reset, set_WANDeviceWANConnectionDeviceWANPPPConnection_Reset, NULL, NULL},
    {"ConnectionStatus", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionStatus, NULL, NULL, NULL},
    {"PossibleConnectionTypes", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_PossibleConnectionTypes, NULL, NULL, NULL},
    {"ConnectionType", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionType, set_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionType, NULL, NULL},
    {"PPPoESessionID", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoESessionID, NULL, NULL, NULL},
    {"DefaultGateway", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_DefaultGateway, NULL, NULL, NULL},
    {"Name", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_Name, set_WANDeviceWANConnectionDeviceWANPPPConnection_Name, NULL, NULL},
    {"Uptime", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_Uptime, NULL, NULL, NULL},
    {"LastConnectionError", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_LastConnectionError, NULL, NULL, NULL},
    {"AutoDisconnectTime", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_AutoDisconnectTime, set_WANDeviceWANConnectionDeviceWANPPPConnection_AutoDisconnectTime, NULL, NULL},
    {"IdleDisconnectTime", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_IdleDisconnectTime, set_WANDeviceWANConnectionDeviceWANPPPConnection_IdleDisconnectTime, NULL, NULL},
    {"WarnDisconnectDelay",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANPPPConnection_WarnDisconnectDelay,
     set_WANDeviceWANConnectionDeviceWANPPPConnection_WarnDisconnectDelay,
     NULL,
     NULL},
    {"RSIPAvailable", &DMREAD, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPPPConnection_RSIPAvailable, NULL, NULL, NULL},
    {"NATEnabled", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPPPConnection_NATEnabled, set_WANDeviceWANConnectionDeviceWANPPPConnection_NATEnabled, NULL, NULL},
    {"Username", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_Username, set_WANDeviceWANConnectionDeviceWANPPPConnection_Username, NULL, NULL},
    {"Password", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_Password, set_WANDeviceWANConnectionDeviceWANPPPConnection_Password, NULL, NULL},
    {"PPPEncryptionProtocol", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPEncryptionProtocol, NULL, NULL, NULL},
    {"PPPCompressionProtocol", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPCompressionProtocol, NULL, NULL, NULL},
    {"PPPAuthenticationProtocol", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPAuthenticationProtocol, NULL, NULL, NULL},
    {"ExternalIPAddress", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_ExternalIPAddress, set_WANDeviceWANConnectionDeviceWANPPPConnection_ExternalIPAddress, NULL, NULL},
    {"RemoteIPAddress", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_RemoteIPAddress, NULL, NULL, NULL},
    {"MaxMRUSize", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_MaxMRUSize, set_WANDeviceWANConnectionDeviceWANPPPConnection_MaxMRUSize, NULL, NULL},
    {"CurrentMRUSize", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_CurrentMRUSize, NULL, NULL, NULL},
    {"DNSEnabled", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPPPConnection_DNSEnabled, set_WANDeviceWANConnectionDeviceWANPPPConnection_DNSEnabled, NULL, NULL},
    {"DNSOverrideAllowed", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPPPConnection_DNSOverrideAllowed, set_WANDeviceWANConnectionDeviceWANPPPConnection_DNSOverrideAllowed, NULL, NULL},
    {"DNSServers", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_DNSServers, set_WANDeviceWANConnectionDeviceWANPPPConnection_DNSServers, NULL, NULL},
    {"MACAddress", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddress, set_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddress, NULL, NULL},
    {"MACAddressOverride", &DMWRITE, DMT_BOOL, get_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddressOverride, set_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddressOverride, NULL, NULL},
    {"TransportType", &DMREAD, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_TransportType, NULL, NULL, NULL},
    {"PPPoEACName", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEACName, set_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEACName, NULL, NULL},
    {"PPPoEServiceName", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEServiceName, set_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEServiceName, NULL, NULL},
    {"ConnectionTrigger", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionTrigger, set_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionTrigger, NULL, NULL},
    {"RouteProtocolRx", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnection_RouteProtocolRx, set_WANDeviceWANConnectionDeviceWANPPPConnection_RouteProtocolRx, NULL, NULL},
    {"PPPLCPEcho", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPLCPEcho, NULL, NULL, NULL},
    {"PPPLCPEchoRetry", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPLCPEchoRetry, NULL, NULL, NULL},
    {"ShapingRate", &DMWRITE, DMT_INT, get_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingRate, set_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingRate, NULL, NULL},
    {"ShapingBurstSize", &DMWRITE, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingBurstSize, set_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingBurstSize, NULL, NULL},
    {"PortMappingNumberOfEntries", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnection_PortMappingNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANPPPConnection.{i}.PortMapping.{i}. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANPPPConnectionPortMappingParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"PortMappingEnabled",
     &DMWRITE,
     DMT_BOOL,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingEnabled,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingEnabled,
     NULL,
     NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_Alias, set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_Alias, NULL, NULL},
    {"PortMappingLeaseDuration",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingLeaseDuration,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingLeaseDuration,
     NULL,
     NULL},
    {"RemoteHost", &DMWRITE, DMT_STRING, get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_RemoteHost, set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_RemoteHost, NULL, NULL},
    {"ExternalPort",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPort,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPort,
     NULL,
     NULL},
    {"ExternalPortEndRange",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPortEndRange,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPortEndRange,
     NULL,
     NULL},
    {"InternalPort",
     &DMWRITE,
     DMT_UNINT,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalPort,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalPort,
     NULL,
     NULL},
    {"PortMappingProtocol",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingProtocol,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingProtocol,
     NULL,
     NULL},
    {"InternalClient",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalClient,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalClient,
     NULL,
     NULL},
    {"PortMappingDescription",
     &DMWRITE,
     DMT_STRING,
     get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingDescription,
     set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingDescription,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.WANDevice.{i}.WANConnectionDevice.{i}.WANPPPConnection.{i}.Stats. *** */
DMLEAF tWANDeviceWANConnectionDeviceWANPPPConnectionStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EthernetBytesSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBytesSent, NULL, NULL, NULL},
    {"EthernetBytesReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBytesReceived, NULL, NULL, NULL},
    {"EthernetPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetPacketsSent, NULL, NULL, NULL},
    {"EthernetPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetPacketsReceived, NULL, NULL, NULL},
    {"EthernetErrorsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetErrorsSent, NULL, NULL, NULL},
    {"EthernetErrorsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetErrorsReceived, NULL, NULL, NULL},
    {"EthernetUnicastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetUnicastPacketsSent, NULL, NULL, NULL},
    {"EthernetUnicastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetUnicastPacketsReceived, NULL, NULL, NULL},
    {"EthernetDiscardPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetDiscardPacketsSent, NULL, NULL, NULL},
    {"EthernetDiscardPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetDiscardPacketsReceived, NULL, NULL, NULL},
    {"EthernetMulticastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetMulticastPacketsSent, NULL, NULL, NULL},
    {"EthernetMulticastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetMulticastPacketsReceived, NULL, NULL, NULL},
    {"EthernetBroadcastPacketsSent", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBroadcastPacketsSent, NULL, NULL, NULL},
    {"EthernetBroadcastPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBroadcastPacketsReceived, NULL, NULL, NULL},
    {"EthernetUnknownProtoPacketsReceived", &DMREAD, DMT_UNINT, get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetUnknownProtoPacketsReceived, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.User.{i}. *** */
DMLEAF tUserParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_User_Alias, set_User_Alias, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_User_Enable, set_User_Enable, NULL, NULL},
    {"RemoteAccessCapable", &DMWRITE, DMT_BOOL, get_User_RemoteAccessCapable, set_User_RemoteAccessCapable, NULL, NULL},
    {"Username", &DMWRITE, DMT_STRING, get_User_Username, set_User_Username, NULL, NULL},
    {"Password", &DMWRITE, DMT_STRING, get_User_Password, set_User_Password, NULL, NULL},
    {"Language", &DMWRITE, DMT_STRING, get_User_Language, set_User_Language, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP. *** */
DMOBJ tUPnPObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Device", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tUPnPDeviceObj, tUPnPDeviceParams, NULL},
    {"Discovery", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tUPnPDiscoveryObj, tUPnPDiscoveryParams, NULL},
    {"Description", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tUPnPDescriptionObj, tUPnPDescriptionParams, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Device. *** */
DMOBJ tUPnPDeviceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Capabilities", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tUPnPDeviceCapabilitiesParams, NULL},
    {0}};

DMLEAF tUPnPDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_UPnPDevice_Enable, set_UPnPDevice_Enable, NULL, NULL},
    {"UPnPMediaServer", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPMediaServer, set_UPnPDevice_UPnPMediaServer, NULL, NULL},
    {"UPnPMediaRenderer", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPMediaRenderer, set_UPnPDevice_UPnPMediaRenderer, NULL, NULL},
    {"UPnPWLANAccessPoint", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPWLANAccessPoint, set_UPnPDevice_UPnPWLANAccessPoint, NULL, NULL},
    {"UPnPQoSDevice ", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPQoSDevice, set_UPnPDevice_UPnPQoSDevice, NULL, NULL},
    {"UPnPQoSPolicyHolder", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPQoSPolicyHolder, set_UPnPDevice_UPnPQoSPolicyHolder, NULL, NULL},
    {"UPnPIGD", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPIGD, set_UPnPDevice_UPnPIGD, NULL, NULL},
    {"UPnPDMBasicMgmt", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPDMBasicMgmt, set_UPnPDevice_UPnPDMBasicMgmt, NULL, NULL},
    {"UPnPDMConfigurationMgmt", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPDMConfigurationMgmt, set_UPnPDevice_UPnPDMConfigurationMgmt, NULL, NULL},
    {"UPnPDMSoftwareMgmt", &DMWRITE, DMT_BOOL, get_UPnPDevice_UPnPDMSoftwareMgmt, set_UPnPDevice_UPnPDMSoftwareMgmt, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Device.Capabilities. *** */
DMLEAF tUPnPDeviceCapabilitiesParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"UPnPArchitecture", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPArchitecture, NULL, NULL, NULL},
    {"UPnPArchitectureMinorVer", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPArchitectureMinorVer, NULL, NULL, NULL},
    {"UPnPMediaServer", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPMediaServer, NULL, NULL, NULL},
    {"UPnPMediaRenderer", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPMediaRenderer, NULL, NULL, NULL},
    {"UPnPWLANAccessPoint", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPWLANAccessPoint, NULL, NULL, NULL},
    {"UPnPBasicDevice", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPBasicDevice, NULL, NULL, NULL},
    {"UPnPQoSDevice", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPQoSDevice, NULL, NULL, NULL},
    {"UPnPQoSPolicyHolder", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPQoSPolicyHolder, NULL, NULL, NULL},
    {"UPnPIGD", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPIGD, NULL, NULL, NULL},
    {"UPnPDMBasicMgmt", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPDMBasicMgmt, NULL, NULL, NULL},
    {"UPnPDMConfigurationMgmt", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPDMConfigurationMgmt, NULL, NULL, NULL},
    {"UPnPDMSoftwareMgmt", &DMREAD, DMT_UNINT, get_UPnPDeviceCapabilities_UPnPDMSoftwareMgmt, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Discovery. *** */
DMOBJ tUPnPDiscoveryObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"RootDevice", &DMREAD, NULL, NULL, NULL, browseUPnPDiscoveryRootDeviceInst, NULL, NULL, NULL, tUPnPDiscoveryRootDeviceParams, NULL},
    {"Device", &DMREAD, NULL, NULL, NULL, browseUPnPDiscoveryDeviceInst, NULL, NULL, NULL, tUPnPDiscoveryDeviceParams, NULL},
    {"Service", &DMREAD, NULL, NULL, NULL, browseUPnPDiscoveryServiceInst, NULL, NULL, NULL, tUPnPDiscoveryServiceParams, NULL},
    {0}};

DMLEAF tUPnPDiscoveryParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"RootDeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_UPnPDiscovery_RootDeviceNumberOfEntries, NULL, NULL, NULL},
    {"DeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_UPnPDiscovery_DeviceNumberOfEntries, NULL, NULL, NULL},
    {"ServiceNumberOfEntries", &DMREAD, DMT_UNINT, get_UPnPDiscovery_ServiceNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Discovery.RootDevice.{i}. *** */
DMLEAF tUPnPDiscoveryRootDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Status", &DMREAD, DMT_STRING, get_UPnPDiscoveryRootDevice_Status, NULL, NULL, NULL},
    {"UUID", &DMREAD, DMT_STRING, get_UPnPDiscoveryRootDevice_UUID, NULL, NULL, NULL},
    {"USN", &DMREAD, DMT_STRING, get_UPnPDiscoveryRootDevice_USN, NULL, NULL, NULL},
    {"LeaseTime", &DMREAD, DMT_UNINT, get_UPnPDiscoveryRootDevice_LeaseTime, NULL, NULL, NULL},
    {"Location", &DMREAD, DMT_STRING, get_UPnPDiscoveryRootDevice_Location, NULL, NULL, NULL},
    {"Server", &DMREAD, DMT_STRING, get_UPnPDiscoveryRootDevice_Server, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_UPnPDiscoveryRootDevice_Host, NULL, NULL, NULL},
    {"LastUpdate", &DMREAD, DMT_TIME, get_UPnPDiscoveryRootDevice_LastUpdate, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Discovery.Device.{i}. *** */
DMLEAF tUPnPDiscoveryDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Status", &DMREAD, DMT_STRING, get_UPnPDiscoveryDevice_Status, NULL, NULL, NULL},
    {"UUID", &DMREAD, DMT_STRING, get_UPnPDiscoveryDevice_UUID, NULL, NULL, NULL},
    {"USN", &DMREAD, DMT_STRING, get_UPnPDiscoveryDevice_USN, NULL, NULL, NULL},
    {"LeaseTime", &DMREAD, DMT_UNINT, get_UPnPDiscoveryDevice_LeaseTime, NULL, NULL, NULL},
    {"Location", &DMREAD, DMT_STRING, get_UPnPDiscoveryDevice_Location, NULL, NULL, NULL},
    {"Server", &DMREAD, DMT_STRING, get_UPnPDiscoveryDevice_Server, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_UPnPDiscoveryDevice_Host, NULL, NULL, NULL},
    {"LastUpdate", &DMREAD, DMT_TIME, get_UPnPDiscoveryDevice_LastUpdate, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Discovery.Service.{i}. *** */
DMLEAF tUPnPDiscoveryServiceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Status", &DMREAD, DMT_STRING, get_UPnPDiscoveryService_Status, NULL, NULL, NULL},
    {"USN", &DMREAD, DMT_STRING, get_UPnPDiscoveryService_USN, NULL, NULL, NULL},
    {"LeaseTime", &DMREAD, DMT_UNINT, get_UPnPDiscoveryService_LeaseTime, NULL, NULL, NULL},
    {"Location", &DMREAD, DMT_STRING, get_UPnPDiscoveryService_Location, NULL, NULL, NULL},
    {"Server", &DMREAD, DMT_STRING, get_UPnPDiscoveryService_Server, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_UPnPDiscoveryService_Host, NULL, NULL, NULL},
    {"LastUpdate", &DMREAD, DMT_TIME, get_UPnPDiscoveryService_LastUpdate, NULL, NULL, NULL},
    {"ParentDevice", &DMREAD, DMT_STRING, get_UPnPDiscoveryService_ParentDevice, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Description. *** */
DMOBJ tUPnPDescriptionObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"DeviceDescription", &DMREAD, NULL, NULL, NULL, browseUPnPDescriptionDeviceDescriptionInst, NULL, NULL, NULL, tUPnPDescriptionDeviceDescriptionParams, NULL},
    {"DeviceInstance", &DMREAD, NULL, NULL, NULL, browseUPnPDescriptionDeviceInstanceInst, NULL, NULL, NULL, tUPnPDescriptionDeviceInstanceParams, NULL},
    {"ServiceInstance", &DMREAD, NULL, NULL, NULL, browseUPnPDescriptionServiceInstanceInst, NULL, NULL, NULL, tUPnPDescriptionServiceInstanceParams, NULL},
    {0}};

DMLEAF tUPnPDescriptionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DeviceDescriptionNumberOfEntries", &DMREAD, DMT_UNINT, get_UPnPDescription_DeviceDescriptionNumberOfEntries, NULL, NULL, NULL},
    {"DeviceInstanceNumberOfEntries", &DMREAD, DMT_UNINT, get_UPnPDescription_DeviceInstanceNumberOfEntries, NULL, NULL, NULL},
    {"ServiceInstanceNumberOfEntries", &DMREAD, DMT_UNINT, get_UPnPDescription_ServiceInstanceNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Description.DeviceDescription.{i}. *** */
DMLEAF tUPnPDescriptionDeviceDescriptionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"URLBase", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceDescription_URLBase, NULL, NULL, NULL},
    {"SpecVersion", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceDescription_SpecVersion, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceDescription_Host, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Description.DeviceInstance.{i}. *** */
DMLEAF tUPnPDescriptionDeviceInstanceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"UDN", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_UDN, NULL, NULL, NULL},
    {"ParentDevice", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_ParentDevice, NULL, NULL, NULL},
    {"DiscoveryDevice", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_DiscoveryDevice, NULL, NULL, NULL},
    {"DeviceType", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_DeviceType, NULL, NULL, NULL},
    {"FriendlyName", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_FriendlyName, NULL, NULL, NULL},
    {"DeviceCategory", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_DeviceCategory, NULL, NULL, NULL},
    {"Manufacturer", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_Manufacturer, NULL, NULL, NULL},
    {"ManufacturerOUI", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_ManufacturerOUI, NULL, NULL, NULL},
    {"ManufacturerURL", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_ManufacturerURL, NULL, NULL, NULL},
    {"ModelDescription", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_ModelDescription, NULL, NULL, NULL},
    {"ModelName", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_ModelName, NULL, NULL, NULL},
    {"ModelNumber", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_ModelNumber, NULL, NULL, NULL},
    {"ModelURL", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_ModelURL, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_SerialNumber, NULL, NULL, NULL},
    {"UPC", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_UPC, NULL, NULL, NULL},
    {"PresentationURL", &DMREAD, DMT_STRING, get_UPnPDescriptionDeviceInstance_PresentationURL, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.UPnP.Description.ServiceInstance.{i}. *** */
DMLEAF tUPnPDescriptionServiceInstanceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ParentDevice", &DMREAD, DMT_STRING, get_UPnPDescriptionServiceInstance_ParentDevice, NULL, NULL, NULL},
    {"ServiceId", &DMREAD, DMT_STRING, get_UPnPDescriptionServiceInstance_ServiceId, NULL, NULL, NULL},
    {"ServiceDiscovery", &DMREAD, DMT_STRING, get_UPnPDescriptionServiceInstance_ServiceDiscovery, NULL, NULL, NULL},
    {"ServiceType", &DMREAD, DMT_STRING, get_UPnPDescriptionServiceInstance_ServiceType, NULL, NULL, NULL},
    {"SCPDURL", &DMREAD, DMT_STRING, get_UPnPDescriptionServiceInstance_SCPDURL, NULL, NULL, NULL},
    {"ControlURL", &DMREAD, DMT_STRING, get_UPnPDescriptionServiceInstance_ControlURL, NULL, NULL, NULL},
    {"EventSubURL", &DMREAD, DMT_STRING, get_UPnPDescriptionServiceInstance_EventSubURL, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DLNA. *** */
DMOBJ tDLNAObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Capabilities", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tDLNACapabilitiesParams, NULL},
    {0}};

/* *** InternetGatewayDevice.DLNA.Capabilities. *** */
DMLEAF tDLNACapabilitiesParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"HNDDeviceClass", &DMREAD, DMT_STRING, get_DLNACapabilities_HNDDeviceClass, NULL, NULL, NULL},
    {"DeviceCapability", &DMREAD, DMT_STRING, get_DLNACapabilities_DeviceCapability, NULL, NULL, NULL},
    {"HIDDeviceClass", &DMREAD, DMT_STRING, get_DLNACapabilities_HIDDeviceClass, NULL, NULL, NULL},
    {"ImageClassProfileID", &DMREAD, DMT_STRING, get_DLNACapabilities_ImageClassProfileID, NULL, NULL, NULL},
    {"AudioClassProfileID", &DMREAD, DMT_STRING, get_DLNACapabilities_AudioClassProfileID, NULL, NULL, NULL},
    {"AVClassProfileID", &DMREAD, DMT_STRING, get_DLNACapabilities_AVClassProfileID, NULL, NULL, NULL},
    {"MediaCollectionProfileID", &DMREAD, DMT_STRING, get_DLNACapabilities_MediaCollectionProfileID, NULL, NULL, NULL},
    {"PrinterClassProfileID", &DMREAD, DMT_STRING, get_DLNACapabilities_PrinterClassProfileID, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.SmartCardReader.{i}. *** */
DMOBJ tSmartCardReaderObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"SmartCard", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tSmartCardReaderSmartCardParams, NULL},
    {0}};

DMLEAF tSmartCardReaderParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_SmartCardReader_Alias, set_SmartCardReader_Alias, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_SmartCardReader_Enable, set_SmartCardReader_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_SmartCardReader_Status, NULL, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_SmartCardReader_Name, NULL, NULL, NULL},
    {"Reset", &DMWRITE, DMT_BOOL, get_SmartCardReader_Reset, set_SmartCardReader_Reset, NULL, NULL},
    {"ResetTime", &DMREAD, DMT_TIME, get_SmartCardReader_ResetTime, NULL, NULL, NULL},
    {"DecryptionFailedCounter", &DMREAD, DMT_UNINT, get_SmartCardReader_DecryptionFailedCounter, NULL, NULL, NULL},
    {"DecryptionFailedNoKeyCounter", &DMREAD, DMT_UNINT, get_SmartCardReader_DecryptionFailedNoKeyCounter, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.SmartCardReader.{i}.SmartCard. *** */
DMLEAF tSmartCardReaderSmartCardParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Status", &DMREAD, DMT_STRING, get_SmartCardReaderSmartCard_Status, NULL, NULL, NULL},
    {"Type", &DMREAD, DMT_STRING, get_SmartCardReaderSmartCard_Type, NULL, NULL, NULL},
    {"Application", &DMREAD, DMT_STRING, get_SmartCardReaderSmartCard_Application, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_SmartCardReaderSmartCard_SerialNumber, NULL, NULL, NULL},
    {"ATR", &DMREAD, DMT_STRING, get_SmartCardReaderSmartCard_ATR, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.SelfTestDiagnostics. *** */
DMLEAF tSelfTestDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DiagnosticsState", &DMWRITE, DMT_STRING, get_SelfTestDiagnostics_DiagnosticsState, set_SelfTestDiagnostics_DiagnosticsState, NULL, NULL},
    {"Results", &DMREAD, DMT_STRING, get_SelfTestDiagnostics_Results, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.NSLookupDiagnostics. *** */
DMOBJ tNSLookupDiagnosticsObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Result", &DMREAD, NULL, NULL, NULL, browseNSLookupDiagnosticsResultInst, NULL, NULL, NULL, tNSLookupDiagnosticsResultParams, NULL},
    {0}};

DMLEAF tNSLookupDiagnosticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DiagnosticsState", &DMWRITE, DMT_STRING, get_NSLookupDiagnostics_DiagnosticsState, set_NSLookupDiagnostics_DiagnosticsState, NULL, NULL},
    {"Interface", &DMWRITE, DMT_STRING, get_NSLookupDiagnostics_Interface, set_NSLookupDiagnostics_Interface, NULL, NULL},
    {"HostName", &DMWRITE, DMT_STRING, get_NSLookupDiagnostics_HostName, set_NSLookupDiagnostics_HostName, NULL, NULL},
    {"DNSServer", &DMWRITE, DMT_STRING, get_NSLookupDiagnostics_DNSServer, set_NSLookupDiagnostics_DNSServer, NULL, NULL},
    {"Timeout", &DMWRITE, DMT_UNINT, get_NSLookupDiagnostics_Timeout, set_NSLookupDiagnostics_Timeout, NULL, NULL},
    {"NumberOfRepetitions", &DMWRITE, DMT_UNINT, get_NSLookupDiagnostics_NumberOfRepetitions, set_NSLookupDiagnostics_NumberOfRepetitions, NULL, NULL},
    {"SuccessCount", &DMREAD, DMT_UNINT, get_NSLookupDiagnostics_SuccessCount, NULL, NULL, NULL},
    {"ResultNumberOfEntries", &DMREAD, DMT_UNINT, get_NSLookupDiagnostics_ResultNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.NSLookupDiagnostics.Result.{i}. *** */
DMLEAF tNSLookupDiagnosticsResultParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Status", &DMREAD, DMT_STRING, get_NSLookupDiagnosticsResult_Status, NULL, NULL, NULL},
    {"AnswerType", &DMREAD, DMT_STRING, get_NSLookupDiagnosticsResult_AnswerType, NULL, NULL, NULL},
    {"HostNameReturned", &DMREAD, DMT_STRING, get_NSLookupDiagnosticsResult_HostNameReturned, NULL, NULL, NULL},
    {"IPAddresses", &DMREAD, DMT_STRING, get_NSLookupDiagnosticsResult_IPAddresses, NULL, NULL, NULL},
    {"DNSServerIP", &DMREAD, DMT_STRING, get_NSLookupDiagnosticsResult_DNSServerIP, NULL, NULL, NULL},
    {"ResponseTime", &DMREAD, DMT_UNINT, get_NSLookupDiagnosticsResult_ResponseTime, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Firewall. *** */
DMLEAF tFirewallParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Config", &DMWRITE, DMT_STRING, get_Firewall_Config, set_Firewall_Config, NULL, NULL},
    {"Version", &DMREAD, DMT_STRING, get_Firewall_Version, NULL, NULL, NULL},
    {"LastChange", &DMREAD, DMT_TIME, get_Firewall_LastChange, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.USBHosts. *** */
DMOBJ tUSBHostsObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Host", &DMREAD, NULL, NULL, NULL, browseUSBHostsHostInst, NULL, NULL, tUSBHostsHostObj, tUSBHostsHostParams, NULL},
    {0}};

DMLEAF tUSBHostsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"HostNumberOfEntries", &DMREAD, DMT_UNINT, get_USBHosts_HostNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.USBHosts.Host.{i}. *** */
DMOBJ tUSBHostsHostObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Device", &DMREAD, NULL, NULL, NULL, browseUSBHostsHostDeviceInst, NULL, NULL, tUSBHostsHostDeviceObj, tUSBHostsHostDeviceParams, NULL},
    {0}};

DMLEAF tUSBHostsHostParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_USBHostsHost_Alias, set_USBHostsHost_Alias, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_USBHostsHost_Enable, set_USBHostsHost_Enable, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_USBHostsHost_Name, NULL, NULL, NULL},
    {"Type", &DMREAD, DMT_STRING, get_USBHostsHost_Type, NULL, NULL, NULL},
    {"Reset", &DMWRITE, DMT_BOOL, get_USBHostsHost_Reset, set_USBHostsHost_Reset, NULL, NULL},
    {"PowerManagementEnable", &DMWRITE, DMT_BOOL, get_USBHostsHost_PowerManagementEnable, set_USBHostsHost_PowerManagementEnable, NULL, NULL},
    {"USBVersion", &DMREAD, DMT_STRING, get_USBHostsHost_USBVersion, NULL, NULL, NULL},
    {"DeviceNumberOfEntries", &DMREAD, DMT_UNINT, get_USBHostsHost_DeviceNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.USBHosts.Host.{i}.Device.{i}. *** */
DMOBJ tUSBHostsHostDeviceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Configuration", &DMREAD, NULL, NULL, NULL, browseUSBHostsHostDeviceConfigurationInst, NULL, NULL, tUSBHostsHostDeviceConfigurationObj, tUSBHostsHostDeviceConfigurationParams, NULL},
    {0}};

DMLEAF tUSBHostsHostDeviceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"DeviceNumber", &DMREAD, DMT_UNINT, get_USBHostsHostDevice_DeviceNumber, NULL, NULL, NULL},
    {"USBVersion", &DMREAD, DMT_STRING, get_USBHostsHostDevice_USBVersion, NULL, NULL, NULL},
    {"DeviceClass", &DMREAD, DMT_HEXBIN, get_USBHostsHostDevice_DeviceClass, NULL, NULL, NULL},
    {"DeviceSubClass", &DMREAD, DMT_HEXBIN, get_USBHostsHostDevice_DeviceSubClass, NULL, NULL, NULL},
    {"DeviceVersion", &DMREAD, DMT_UNINT, get_USBHostsHostDevice_DeviceVersion, NULL, NULL, NULL},
    {"DeviceProtocol", &DMREAD, DMT_HEXBIN, get_USBHostsHostDevice_DeviceProtocol, NULL, NULL, NULL},
    {"ProductID", &DMREAD, DMT_UNINT, get_USBHostsHostDevice_ProductID, NULL, NULL, NULL},
    {"VendorID", &DMREAD, DMT_UNINT, get_USBHostsHostDevice_VendorID, NULL, NULL, NULL},
    {"Manufacturer", &DMREAD, DMT_STRING, get_USBHostsHostDevice_Manufacturer, NULL, NULL, NULL},
    {"ProductClass", &DMREAD, DMT_STRING, get_USBHostsHostDevice_ProductClass, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_USBHostsHostDevice_SerialNumber, NULL, NULL, NULL},
    {"Port", &DMREAD, DMT_UNINT, get_USBHostsHostDevice_Port, NULL, NULL, NULL},
    {"Rate", &DMREAD, DMT_STRING, get_USBHostsHostDevice_Rate, NULL, NULL, NULL},
    {"Parent", &DMREAD, DMT_STRING, get_USBHostsHostDevice_Parent, NULL, NULL, NULL},
    {"MaxChildren", &DMREAD, DMT_UNINT, get_USBHostsHostDevice_MaxChildren, NULL, NULL, NULL},
    {"IsSuspended", &DMREAD, DMT_BOOL, get_USBHostsHostDevice_IsSuspended, NULL, NULL, NULL},
    {"IsSelfPowered", &DMREAD, DMT_BOOL, get_USBHostsHostDevice_IsSelfPowered, NULL, NULL, NULL},
    {"ConfigurationNumberOfEntries", &DMREAD, DMT_UNINT, get_USBHostsHostDevice_ConfigurationNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.USBHosts.Host.{i}.Device.{i}.Configuration.{i}. *** */
DMOBJ tUSBHostsHostDeviceConfigurationObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Interface", &DMREAD, NULL, NULL, NULL, browseUSBHostsHostDeviceConfigurationInterfaceInst, NULL, NULL, NULL, tUSBHostsHostDeviceConfigurationInterfaceParams, NULL},
    {0}};

DMLEAF tUSBHostsHostDeviceConfigurationParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ConfigurationNumber", &DMREAD, DMT_UNINT, get_USBHostsHostDeviceConfiguration_ConfigurationNumber, NULL, NULL, NULL},
    {"InterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_USBHostsHostDeviceConfiguration_InterfaceNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.USBHosts.Host.{i}.Device.{i}.Configuration.{i}.Interface.{i}. *** */
DMLEAF tUSBHostsHostDeviceConfigurationInterfaceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"InterfaceNumber", &DMREAD, DMT_UNINT, get_USBHostsHostDeviceConfigurationInterface_InterfaceNumber, NULL, NULL, NULL},
    {"InterfaceClass", &DMREAD, DMT_HEXBIN, get_USBHostsHostDeviceConfigurationInterface_InterfaceClass, NULL, NULL, NULL},
    {"InterfaceSubClass", &DMREAD, DMT_HEXBIN, get_USBHostsHostDeviceConfigurationInterface_InterfaceSubClass, NULL, NULL, NULL},
    {"InterfaceProtocol", &DMREAD, DMT_HEXBIN, get_USBHostsHostDeviceConfigurationInterface_InterfaceProtocol, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.PeriodicStatistics. *** */
DMOBJ tPeriodicStatisticsObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"SampleSet",
     &DMWRITE,
     addObjPeriodicStatisticsSampleSet,
     delObjPeriodicStatisticsSampleSet,
     NULL,
     browsePeriodicStatisticsSampleSetInst,
     NULL,
     NULL,
     tPeriodicStatisticsSampleSetObj,
     tPeriodicStatisticsSampleSetParams,
     NULL},
    {0}};

DMLEAF tPeriodicStatisticsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"MinSampleInterval", &DMREAD, DMT_UNINT, get_PeriodicStatistics_MinSampleInterval, NULL, NULL, NULL},
    {"MaxReportSamples", &DMREAD, DMT_UNINT, get_PeriodicStatistics_MaxReportSamples, NULL, NULL, NULL},
    {"SampleSetNumberOfEntries", &DMREAD, DMT_UNINT, get_PeriodicStatistics_SampleSetNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.PeriodicStatistics.SampleSet.{i}. *** */
DMOBJ tPeriodicStatisticsSampleSetObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Parameter",
     &DMWRITE,
     addObjPeriodicStatisticsSampleSetParameter,
     delObjPeriodicStatisticsSampleSetParameter,
     NULL,
     browsePeriodicStatisticsSampleSetParameterInst,
     NULL,
     NULL,
     NULL,
     tPeriodicStatisticsSampleSetParameterParams,
     NULL},
    {0}};

DMLEAF tPeriodicStatisticsSampleSetParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_PeriodicStatisticsSampleSet_Alias, set_PeriodicStatisticsSampleSet_Alias, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_PeriodicStatisticsSampleSet_Enable, set_PeriodicStatisticsSampleSet_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_PeriodicStatisticsSampleSet_Status, NULL, NULL, NULL},
    {"Name", &DMWRITE, DMT_STRING, get_PeriodicStatisticsSampleSet_Name, set_PeriodicStatisticsSampleSet_Name, NULL, NULL},
    {"SampleInterval", &DMWRITE, DMT_UNINT, get_PeriodicStatisticsSampleSet_SampleInterval, set_PeriodicStatisticsSampleSet_SampleInterval, NULL, NULL},
    {"ReportSamples", &DMWRITE, DMT_UNINT, get_PeriodicStatisticsSampleSet_ReportSamples, set_PeriodicStatisticsSampleSet_ReportSamples, NULL, NULL},
    {"TimeReference", &DMWRITE, DMT_TIME, get_PeriodicStatisticsSampleSet_TimeReference, set_PeriodicStatisticsSampleSet_TimeReference, NULL, NULL},
    {"FetchSamples", &DMWRITE, DMT_UNINT, get_PeriodicStatisticsSampleSet_FetchSamples, set_PeriodicStatisticsSampleSet_FetchSamples, NULL, NULL},
    {"ForceSample", &DMWRITE, DMT_BOOL, get_PeriodicStatisticsSampleSet_ForceSample, set_PeriodicStatisticsSampleSet_ForceSample, NULL, NULL},
    {"ReportStartTime", &DMREAD, DMT_TIME, get_PeriodicStatisticsSampleSet_ReportStartTime, NULL, NULL, NULL},
    {"ReportEndTime", &DMREAD, DMT_TIME, get_PeriodicStatisticsSampleSet_ReportEndTime, NULL, NULL, NULL},
    {"SampleSeconds", &DMREAD, DMT_STRING, get_PeriodicStatisticsSampleSet_SampleSeconds, NULL, NULL, NULL},
    {"ParameterNumberOfEntries", &DMREAD, DMT_UNINT, get_PeriodicStatisticsSampleSet_ParameterNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.PeriodicStatistics.SampleSet.{i}.Parameter.{i}. *** */
DMLEAF tPeriodicStatisticsSampleSetParameterParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_PeriodicStatisticsSampleSetParameter_Alias, set_PeriodicStatisticsSampleSetParameter_Alias, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_PeriodicStatisticsSampleSetParameter_Enable, set_PeriodicStatisticsSampleSetParameter_Enable, NULL, NULL},
    {"Reference", &DMWRITE, DMT_STRING, get_PeriodicStatisticsSampleSetParameter_Reference, set_PeriodicStatisticsSampleSetParameter_Reference, NULL, NULL},
    {"SampleMode", &DMWRITE, DMT_STRING, get_PeriodicStatisticsSampleSetParameter_SampleMode, set_PeriodicStatisticsSampleSetParameter_SampleMode, NULL, NULL},
    {"CalculationMode", &DMWRITE, DMT_STRING, get_PeriodicStatisticsSampleSetParameter_CalculationMode, set_PeriodicStatisticsSampleSetParameter_CalculationMode, NULL, NULL},
    {"LowThreshold", &DMWRITE, DMT_INT, get_PeriodicStatisticsSampleSetParameter_LowThreshold, set_PeriodicStatisticsSampleSetParameter_LowThreshold, NULL, NULL},
    {"HighThreshold", &DMWRITE, DMT_INT, get_PeriodicStatisticsSampleSetParameter_HighThreshold, set_PeriodicStatisticsSampleSetParameter_HighThreshold, NULL, NULL},
    {"SampleSeconds", &DMREAD, DMT_STRING, get_PeriodicStatisticsSampleSetParameter_SampleSeconds, NULL, NULL, NULL},
    {"SuspectData", &DMREAD, DMT_STRING, get_PeriodicStatisticsSampleSetParameter_SuspectData, NULL, NULL, NULL},
    {"Values", &DMREAD, DMT_STRING, get_PeriodicStatisticsSampleSetParameter_Values, NULL, NULL, NULL},
    {"Failures", &DMREAD, DMT_UNINT, get_PeriodicStatisticsSampleSetParameter_Failures, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DownloadAvailability. *** */
DMOBJ tDownloadAvailabilityObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Announcement", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDownloadAvailabilityAnnouncementObj, tDownloadAvailabilityAnnouncementParams, NULL},
    {"Query", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tDownloadAvailabilityQueryParams, NULL},
    {0}};

/* *** InternetGatewayDevice.DownloadAvailability.Announcement. *** */
DMOBJ tDownloadAvailabilityAnnouncementObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Group",
     &DMWRITE,
     addObjDownloadAvailabilityAnnouncementGroup,
     delObjDownloadAvailabilityAnnouncementGroup,
     NULL,
     browseDownloadAvailabilityAnnouncementGroupInst,
     NULL,
     NULL,
     NULL,
     tDownloadAvailabilityAnnouncementGroupParams,
     NULL},
    {0}};

DMLEAF tDownloadAvailabilityAnnouncementParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_DownloadAvailabilityAnnouncement_Enable, set_DownloadAvailabilityAnnouncement_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_DownloadAvailabilityAnnouncement_Status, NULL, NULL, NULL},
    {"GroupNumberOfEntries", &DMREAD, DMT_UNINT, get_DownloadAvailabilityAnnouncement_GroupNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DownloadAvailability.Announcement.Group.{i}. *** */
DMLEAF tDownloadAvailabilityAnnouncementGroupParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Alias", &DMWRITE, DMT_STRING, get_DownloadAvailabilityAnnouncementGroup_Alias, set_DownloadAvailabilityAnnouncementGroup_Alias, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_DownloadAvailabilityAnnouncementGroup_Enable, set_DownloadAvailabilityAnnouncementGroup_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_DownloadAvailabilityAnnouncementGroup_Status, NULL, NULL, NULL},
    {"URL", &DMWRITE, DMT_STRING, get_DownloadAvailabilityAnnouncementGroup_URL, set_DownloadAvailabilityAnnouncementGroup_URL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DownloadAvailability.Query. *** */
DMLEAF tDownloadAvailabilityQueryParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_DownloadAvailabilityQuery_Enable, set_DownloadAvailabilityQuery_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_DownloadAvailabilityQuery_Status, NULL, NULL, NULL},
    {"URL", &DMWRITE, DMT_STRING, get_DownloadAvailabilityQuery_URL, set_DownloadAvailabilityQuery_URL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.SoftwareModules. *** */
DMOBJ tSoftwareModulesObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"ExecEnv", &DMREAD, NULL, NULL, NULL, browseSoftwareModulesExecEnvInst, NULL, NULL, NULL, tSoftwareModulesExecEnvParams, NULL},
    {"DeploymentUnit", &DMREAD, NULL, NULL, NULL, browseSoftwareModulesDeploymentUnitInst, NULL, NULL, NULL, tSoftwareModulesDeploymentUnitParams, NULL},
    {"ExecutionUnit", &DMREAD, NULL, NULL, NULL, browseSoftwareModulesExecutionUnitInst, NULL, NULL, tSoftwareModulesExecutionUnitObj, tSoftwareModulesExecutionUnitParams, NULL},
    {0}};

DMLEAF tSoftwareModulesParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ExecEnvNumberOfEntries", &DMREAD, DMT_UNINT, get_SoftwareModules_ExecEnvNumberOfEntries, NULL, NULL, NULL},
    {"DeploymentUnitNumberOfEntries", &DMREAD, DMT_UNINT, get_SoftwareModules_DeploymentUnitNumberOfEntries, NULL, NULL, NULL},
    {"ExecutionUnitNumberOfEntries", &DMREAD, DMT_UNINT, get_SoftwareModules_ExecutionUnitNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.SoftwareModules.ExecEnv.{i}. *** */
DMLEAF tSoftwareModulesExecEnvParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_SoftwareModulesExecEnv_Enable, set_SoftwareModulesExecEnv_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_Status, NULL, NULL, NULL},
    {"Reset", &DMWRITE, DMT_BOOL, get_SoftwareModulesExecEnv_Reset, set_SoftwareModulesExecEnv_Reset, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_SoftwareModulesExecEnv_Alias, set_SoftwareModulesExecEnv_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_Name, NULL, NULL, NULL},
    {"Type", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_Type, NULL, NULL, NULL},
    {"InitialRunLevel", &DMWRITE, DMT_UNINT, get_SoftwareModulesExecEnv_InitialRunLevel, set_SoftwareModulesExecEnv_InitialRunLevel, NULL, NULL},
    {"RequestedRunLevel", &DMWRITE, DMT_INT, get_SoftwareModulesExecEnv_RequestedRunLevel, set_SoftwareModulesExecEnv_RequestedRunLevel, NULL, NULL},
    {"CurrentRunLevel", &DMREAD, DMT_INT, get_SoftwareModulesExecEnv_CurrentRunLevel, NULL, NULL, NULL},
    {"InitialExecutionUnitRunLevel", &DMWRITE, DMT_INT, get_SoftwareModulesExecEnv_InitialExecutionUnitRunLevel, set_SoftwareModulesExecEnv_InitialExecutionUnitRunLevel, NULL, NULL},
    {"Vendor", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_Vendor, NULL, NULL, NULL},
    {"Version", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_Version, NULL, NULL, NULL},
    {"ParentExecEnv", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_ParentExecEnv, NULL, NULL, NULL},
    {"AllocatedDiskSpace", &DMREAD, DMT_INT, get_SoftwareModulesExecEnv_AllocatedDiskSpace, NULL, NULL, NULL},
    {"AvailableDiskSpace", &DMREAD, DMT_INT, get_SoftwareModulesExecEnv_AvailableDiskSpace, NULL, NULL, NULL},
    {"AllocatedMemory", &DMREAD, DMT_INT, get_SoftwareModulesExecEnv_AllocatedMemory, NULL, NULL, NULL},
    {"AvailableMemory", &DMREAD, DMT_INT, get_SoftwareModulesExecEnv_AvailableMemory, NULL, NULL, NULL},
    {"ActiveExecutionUnits", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_ActiveExecutionUnits, NULL, NULL, NULL},
    {"ProcessorRefList", &DMREAD, DMT_STRING, get_SoftwareModulesExecEnv_ProcessorRefList, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.SoftwareModules.DeploymentUnit.{i}. *** */
DMLEAF tSoftwareModulesDeploymentUnitParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"UUID", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_UUID, NULL, NULL, NULL},
    {"DUID", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_DUID, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_SoftwareModulesDeploymentUnit_Alias, set_SoftwareModulesDeploymentUnit_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_Name, NULL, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_Status, NULL, NULL, NULL},
    {"Resolved", &DMREAD, DMT_BOOL, get_SoftwareModulesDeploymentUnit_Resolved, NULL, NULL, NULL},
    {"URL", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_URL, NULL, NULL, NULL},
    {"Description", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_Description, NULL, NULL, NULL},
    {"Vendor", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_Vendor, NULL, NULL, NULL},
    {"Version", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_Version, NULL, NULL, NULL},
    {"VendorLogList", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_VendorLogList, NULL, NULL, NULL},
    {"VendorConfigList", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_VendorConfigList, NULL, NULL, NULL},
    {"ExecutionUnitList", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_ExecutionUnitList, NULL, NULL, NULL},
    {"ExecutionEnvRef", &DMREAD, DMT_STRING, get_SoftwareModulesDeploymentUnit_ExecutionEnvRef, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.SoftwareModules.ExecutionUnit.{i}. *** */
DMOBJ tSoftwareModulesExecutionUnitObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Extensions", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {0}};

DMLEAF tSoftwareModulesExecutionUnitParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EUID", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_EUID, NULL, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_SoftwareModulesExecutionUnit_Alias, set_SoftwareModulesExecutionUnit_Alias, NULL, NULL},
    {"Name", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_Name, NULL, NULL, NULL},
    {"ExecEnvLabel", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_ExecEnvLabel, NULL, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_Status, NULL, NULL, NULL},
    {"RequestedState", &DMWRITE, DMT_STRING, get_SoftwareModulesExecutionUnit_RequestedState, set_SoftwareModulesExecutionUnit_RequestedState, NULL, NULL},
    {"ExecutionFaultCode", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_ExecutionFaultCode, NULL, NULL, NULL},
    {"ExecutionFaultMessage", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_ExecutionFaultMessage, NULL, NULL, NULL},
    {"AutoStart", &DMWRITE, DMT_BOOL, get_SoftwareModulesExecutionUnit_AutoStart, set_SoftwareModulesExecutionUnit_AutoStart, NULL, NULL},
    {"RunLevel", &DMWRITE, DMT_UNINT, get_SoftwareModulesExecutionUnit_RunLevel, set_SoftwareModulesExecutionUnit_RunLevel, NULL, NULL},
    {"Vendor", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_Vendor, NULL, NULL, NULL},
    {"Version", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_Version, NULL, NULL, NULL},
    {"Description", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_Description, NULL, NULL, NULL},
    {"DiskSpaceInUse", &DMREAD, DMT_INT, get_SoftwareModulesExecutionUnit_DiskSpaceInUse, NULL, NULL, NULL},
    {"MemoryInUse", &DMREAD, DMT_INT, get_SoftwareModulesExecutionUnit_MemoryInUse, NULL, NULL, NULL},
    {"References", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_References, NULL, NULL, NULL},
    {"AssociatedProcessList", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_AssociatedProcessList, NULL, NULL, NULL},
    {"VendorLogList", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_VendorLogList, NULL, NULL, NULL},
    {"VendorConfigList", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_VendorConfigList, NULL, NULL, NULL},
    {"SupportedDataModelList", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_SupportedDataModelList, NULL, NULL, NULL},
    {"ExecutionEnvRef", &DMREAD, DMT_STRING, get_SoftwareModulesExecutionUnit_ExecutionEnvRef, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Security. *** */
DMOBJ tSecurityObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Certificate", &DMREAD, NULL, NULL, NULL, browseSecurityCertificateInst, NULL, NULL, NULL, tSecurityCertificateParams, NULL},
    {0}};

DMLEAF tSecurityParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"CertificateNumberOfEntries", &DMREAD, DMT_UNINT, get_Security_CertificateNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.Security.Certificate.{i}. *** */
DMLEAF tSecurityCertificateParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_SecurityCertificate_Enable, set_SecurityCertificate_Enable, NULL, NULL},
    {"LastModif", &DMREAD, DMT_TIME, get_SecurityCertificate_LastModif, NULL, NULL, NULL},
    {"SerialNumber", &DMREAD, DMT_STRING, get_SecurityCertificate_SerialNumber, NULL, NULL, NULL},
    {"Issuer", &DMREAD, DMT_STRING, get_SecurityCertificate_Issuer, NULL, NULL, NULL},
    {"NotBefore", &DMREAD, DMT_TIME, get_SecurityCertificate_NotBefore, NULL, NULL, NULL},
    {"NotAfter", &DMREAD, DMT_TIME, get_SecurityCertificate_NotAfter, NULL, NULL, NULL},
    {"Subject", &DMREAD, DMT_STRING, get_SecurityCertificate_Subject, NULL, NULL, NULL},
    {"SubjectAlt", &DMREAD, DMT_STRING, get_SecurityCertificate_SubjectAlt, NULL, NULL, NULL},
    {"SignatureAlgorithm", &DMREAD, DMT_STRING, get_SecurityCertificate_SignatureAlgorithm, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FaultMgmt. *** */
DMOBJ tFaultMgmtObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"SupportedAlarm", &DMREAD, NULL, NULL, NULL, browseFaultMgmtSupportedAlarmInst, NULL, NULL, NULL, tFaultMgmtSupportedAlarmParams, NULL},
    {"CurrentAlarm", &DMREAD, NULL, NULL, NULL, browseFaultMgmtCurrentAlarmInst, NULL, NULL, NULL, tFaultMgmtCurrentAlarmParams, NULL},
    {"HistoryEvent", &DMREAD, NULL, NULL, NULL, browseFaultMgmtHistoryEventInst, NULL, NULL, NULL, tFaultMgmtHistoryEventParams, NULL},
    {"ExpeditedEvent", &DMREAD, NULL, NULL, NULL, browseFaultMgmtExpeditedEventInst, NULL, NULL, NULL, tFaultMgmtExpeditedEventParams, NULL},
    {"QueuedEvent", &DMREAD, NULL, NULL, NULL, browseFaultMgmtQueuedEventInst, NULL, NULL, NULL, tFaultMgmtQueuedEventParams, NULL},
    {0}};

DMLEAF tFaultMgmtParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"SupportedAlarmNumberOfEntries", &DMREAD, DMT_UNINT, get_FaultMgmt_SupportedAlarmNumberOfEntries, NULL, NULL, NULL},
    {"MaxCurrentAlarmEntries", &DMREAD, DMT_UNINT, get_FaultMgmt_MaxCurrentAlarmEntries, NULL, NULL, NULL},
    {"CurrentAlarmNumberOfEntries", &DMREAD, DMT_UNINT, get_FaultMgmt_CurrentAlarmNumberOfEntries, NULL, NULL, NULL},
    {"HistoryEventNumberOfEntries", &DMREAD, DMT_UNINT, get_FaultMgmt_HistoryEventNumberOfEntries, NULL, NULL, NULL},
    {"ExpeditedEventNumberOfEntries", &DMREAD, DMT_UNINT, get_FaultMgmt_ExpeditedEventNumberOfEntries, NULL, NULL, NULL},
    {"QueuedEventNumberOfEntries", &DMREAD, DMT_UNINT, get_FaultMgmt_QueuedEventNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FaultMgmt.SupportedAlarm.{i}. *** */
DMLEAF tFaultMgmtSupportedAlarmParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EventType", &DMREAD, DMT_STRING, get_FaultMgmtSupportedAlarm_EventType, NULL, NULL, NULL},
    {"ProbableCause", &DMREAD, DMT_STRING, get_FaultMgmtSupportedAlarm_ProbableCause, NULL, NULL, NULL},
    {"SpecificProblem", &DMREAD, DMT_STRING, get_FaultMgmtSupportedAlarm_SpecificProblem, NULL, NULL, NULL},
    {"PerceivedSeverity", &DMREAD, DMT_STRING, get_FaultMgmtSupportedAlarm_PerceivedSeverity, NULL, NULL, NULL},
    {"ReportingMechanism", &DMWRITE, DMT_STRING, get_FaultMgmtSupportedAlarm_ReportingMechanism, set_FaultMgmtSupportedAlarm_ReportingMechanism, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FaultMgmt.CurrentAlarm.{i}. *** */
DMLEAF tFaultMgmtCurrentAlarmParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"AlarmIdentifier", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_AlarmIdentifier, NULL, NULL, NULL},
    {"AlarmRaisedTime", &DMREAD, DMT_TIME, get_FaultMgmtCurrentAlarm_AlarmRaisedTime, NULL, NULL, NULL},
    {"AlarmChangedTime", &DMREAD, DMT_TIME, get_FaultMgmtCurrentAlarm_AlarmChangedTime, NULL, NULL, NULL},
    {"ManagedObjectInstance", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_ManagedObjectInstance, NULL, NULL, NULL},
    {"EventType", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_EventType, NULL, NULL, NULL},
    {"ProbableCause", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_ProbableCause, NULL, NULL, NULL},
    {"SpecificProblem", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_SpecificProblem, NULL, NULL, NULL},
    {"PerceivedSeverity", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_PerceivedSeverity, NULL, NULL, NULL},
    {"AdditionalText", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_AdditionalText, NULL, NULL, NULL},
    {"AdditionalInformation", &DMREAD, DMT_STRING, get_FaultMgmtCurrentAlarm_AdditionalInformation, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FaultMgmt.HistoryEvent.{i}. *** */
DMLEAF tFaultMgmtHistoryEventParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EventTime", &DMREAD, DMT_TIME, get_FaultMgmtHistoryEvent_EventTime, NULL, NULL, NULL},
    {"AlarmIdentifier", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_AlarmIdentifier, NULL, NULL, NULL},
    {"NotificationType", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_NotificationType, NULL, NULL, NULL},
    {"ManagedObjectInstance", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_ManagedObjectInstance, NULL, NULL, NULL},
    {"EventType", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_EventType, NULL, NULL, NULL},
    {"ProbableCause", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_ProbableCause, NULL, NULL, NULL},
    {"SpecificProblem", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_SpecificProblem, NULL, NULL, NULL},
    {"PerceivedSeverity", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_PerceivedSeverity, NULL, NULL, NULL},
    {"AdditionalText", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_AdditionalText, NULL, NULL, NULL},
    {"AdditionalInformation", &DMREAD, DMT_STRING, get_FaultMgmtHistoryEvent_AdditionalInformation, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FaultMgmt.ExpeditedEvent.{i}. *** */
DMLEAF tFaultMgmtExpeditedEventParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EventTime", &DMREAD, DMT_TIME, get_FaultMgmtExpeditedEvent_EventTime, NULL, NULL, NULL},
    {"AlarmIdentifier", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_AlarmIdentifier, NULL, NULL, NULL},
    {"NotificationType", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_NotificationType, NULL, NULL, NULL},
    {"ManagedObjectInstance", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_ManagedObjectInstance, NULL, NULL, NULL},
    {"EventType", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_EventType, NULL, NULL, NULL},
    {"ProbableCause", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_ProbableCause, NULL, NULL, NULL},
    {"SpecificProblem", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_SpecificProblem, NULL, NULL, NULL},
    {"PerceivedSeverity", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_PerceivedSeverity, NULL, NULL, NULL},
    {"AdditionalText", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_AdditionalText, NULL, NULL, NULL},
    {"AdditionalInformation", &DMREAD, DMT_STRING, get_FaultMgmtExpeditedEvent_AdditionalInformation, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FaultMgmt.QueuedEvent.{i}. *** */
DMLEAF tFaultMgmtQueuedEventParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"EventTime", &DMREAD, DMT_TIME, get_FaultMgmtQueuedEvent_EventTime, NULL, NULL, NULL},
    {"AlarmIdentifier", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_AlarmIdentifier, NULL, NULL, NULL},
    {"NotificationType", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_NotificationType, NULL, NULL, NULL},
    {"ManagedObjectInstance", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_ManagedObjectInstance, NULL, NULL, NULL},
    {"EventType", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_EventType, NULL, NULL, NULL},
    {"ProbableCause", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_ProbableCause, NULL, NULL, NULL},
    {"SpecificProblem", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_SpecificProblem, NULL, NULL, NULL},
    {"PerceivedSeverity", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_PerceivedSeverity, NULL, NULL, NULL},
    {"AdditionalText", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_AdditionalText, NULL, NULL, NULL},
    {"AdditionalInformation", &DMREAD, DMT_STRING, get_FaultMgmtQueuedEvent_AdditionalInformation, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP. *** */
DMOBJ tFAPObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"GPS", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFAPGPSObj, tFAPGPSParams, NULL},
    {"Tunnel", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFAPTunnelObj, tFAPTunnelParams, NULL},
    {"PerfMgmt", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFAPPerfMgmtObj, tFAPPerfMgmtParams, NULL},
    {"ApplicationPlatform", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformObj, tFAPApplicationPlatformParams, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.GPS. *** */
DMOBJ tFAPGPSObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"ContinuousGPSStatus", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPGPSContinuousGPSStatusParams, NULL},
    {"AGPSServerConfig", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPGPSAGPSServerConfigParams, NULL},
    {0}};

DMLEAF tFAPGPSParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ScanOnBoot", &DMWRITE, DMT_BOOL, get_FAPGPS_ScanOnBoot, set_FAPGPS_ScanOnBoot, NULL, NULL},
    {"ScanPeriodically", &DMWRITE, DMT_BOOL, get_FAPGPS_ScanPeriodically, set_FAPGPS_ScanPeriodically, NULL, NULL},
    {"PeriodicInterval", &DMWRITE, DMT_UNINT, get_FAPGPS_PeriodicInterval, set_FAPGPS_PeriodicInterval, NULL, NULL},
    {"PeriodicTime", &DMWRITE, DMT_TIME, get_FAPGPS_PeriodicTime, set_FAPGPS_PeriodicTime, NULL, NULL},
    {"ContinuousGPS", &DMWRITE, DMT_BOOL, get_FAPGPS_ContinuousGPS, set_FAPGPS_ContinuousGPS, NULL, NULL},
    {"ScanTimeout", &DMWRITE, DMT_UNINT, get_FAPGPS_ScanTimeout, set_FAPGPS_ScanTimeout, NULL, NULL},
    {"ScanStatus", &DMREAD, DMT_STRING, get_FAPGPS_ScanStatus, NULL, NULL, NULL},
    {"ErrorDetails", &DMREAD, DMT_STRING, get_FAPGPS_ErrorDetails, NULL, NULL, NULL},
    {"LastScanTime", &DMREAD, DMT_TIME, get_FAPGPS_LastScanTime, NULL, NULL, NULL},
    {"LastSuccessfulScanTime", &DMREAD, DMT_TIME, get_FAPGPS_LastSuccessfulScanTime, NULL, NULL, NULL},
    {"LockedLatitude", &DMREAD, DMT_INT, get_FAPGPS_LockedLatitude, NULL, NULL, NULL},
    {"LockedLongitude", &DMREAD, DMT_INT, get_FAPGPS_LockedLongitude, NULL, NULL, NULL},
    {"NumberOfSatellites", &DMREAD, DMT_UNINT, get_FAPGPS_NumberOfSatellites, NULL, NULL, NULL},
    {"GPSReset", &DMWRITE, DMT_BOOL, get_FAPGPS_GPSReset, set_FAPGPS_GPSReset, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.GPS.ContinuousGPSStatus. *** */
DMLEAF tFAPGPSContinuousGPSStatusParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"CurrentFix", &DMREAD, DMT_BOOL, get_FAPGPSContinuousGPSStatus_CurrentFix, NULL, NULL, NULL},
    {"GotFix", &DMREAD, DMT_BOOL, get_FAPGPSContinuousGPSStatus_GotFix, NULL, NULL, NULL},
    {"TimingGood", &DMREAD, DMT_BOOL, get_FAPGPSContinuousGPSStatus_TimingGood, NULL, NULL, NULL},
    {"Latitude", &DMREAD, DMT_INT, get_FAPGPSContinuousGPSStatus_Latitude, NULL, NULL, NULL},
    {"Longitude", &DMREAD, DMT_INT, get_FAPGPSContinuousGPSStatus_Longitude, NULL, NULL, NULL},
    {"Elevation", &DMREAD, DMT_INT, get_FAPGPSContinuousGPSStatus_Elevation, NULL, NULL, NULL},
    {"LastFixTime", &DMREAD, DMT_TIME, get_FAPGPSContinuousGPSStatus_LastFixTime, NULL, NULL, NULL},
    {"LastFixDuration", &DMREAD, DMT_UNINT, get_FAPGPSContinuousGPSStatus_LastFixDuration, NULL, NULL, NULL},
    {"FirstFixTimeout", &DMWRITE, DMT_INT, get_FAPGPSContinuousGPSStatus_FirstFixTimeout, set_FAPGPSContinuousGPSStatus_FirstFixTimeout, NULL, NULL},
    {"SatellitesTracked", &DMREAD, DMT_UNINT, get_FAPGPSContinuousGPSStatus_SatellitesTracked, NULL, NULL, NULL},
    {"SatelliteTrackingInterval", &DMWRITE, DMT_UNINT, get_FAPGPSContinuousGPSStatus_SatelliteTrackingInterval, set_FAPGPSContinuousGPSStatus_SatelliteTrackingInterval, NULL, NULL},
    {"ReceiverStatus", &DMREAD, DMT_STRING, get_FAPGPSContinuousGPSStatus_ReceiverStatus, NULL, NULL, NULL},
    {"LocationType", &DMREAD, DMT_STRING, get_FAPGPSContinuousGPSStatus_LocationType, NULL, NULL, NULL},
    {"LockTimeOutDuration", &DMWRITE, DMT_UNINT, get_FAPGPSContinuousGPSStatus_LockTimeOutDuration, set_FAPGPSContinuousGPSStatus_LockTimeOutDuration, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.GPS.AGPSServerConfig. *** */
DMLEAF tFAPGPSAGPSServerConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_FAPGPSAGPSServerConfig_Enable, set_FAPGPSAGPSServerConfig_Enable, NULL, NULL},
    {"ServerURL", &DMWRITE, DMT_STRING, get_FAPGPSAGPSServerConfig_ServerURL, set_FAPGPSAGPSServerConfig_ServerURL, NULL, NULL},
    {"ServerPort", &DMWRITE, DMT_UNINT, get_FAPGPSAGPSServerConfig_ServerPort, set_FAPGPSAGPSServerConfig_ServerPort, NULL, NULL},
    {"Username", &DMWRITE, DMT_STRING, get_FAPGPSAGPSServerConfig_Username, set_FAPGPSAGPSServerConfig_Username, NULL, NULL},
    {"Password", &DMWRITE, DMT_STRING, get_FAPGPSAGPSServerConfig_Password, set_FAPGPSAGPSServerConfig_Password, NULL, NULL},
    {"ReferenceLatitude", &DMWRITE, DMT_INT, get_FAPGPSAGPSServerConfig_ReferenceLatitude, set_FAPGPSAGPSServerConfig_ReferenceLatitude, NULL, NULL},
    {"ReferenceLongitude", &DMWRITE, DMT_INT, get_FAPGPSAGPSServerConfig_ReferenceLongitude, set_FAPGPSAGPSServerConfig_ReferenceLongitude, NULL, NULL},
    {"ServerInUse", &DMREAD, DMT_BOOL, get_FAPGPSAGPSServerConfig_ServerInUse, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.Tunnel. *** */
DMOBJ tFAPTunnelObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"CryptoProfile", &DMWRITE, addObjFAPTunnelCryptoProfile, delObjFAPTunnelCryptoProfile, NULL, browseFAPTunnelCryptoProfileInst, NULL, NULL, NULL, tFAPTunnelCryptoProfileParams, NULL},
    {"IKESA", &DMREAD, NULL, NULL, NULL, browseFAPTunnelIKESAInst, NULL, NULL, NULL, tFAPTunnelIKESAParams, NULL},
    {"ChildSA", &DMREAD, NULL, NULL, NULL, browseFAPTunnelChildSAInst, NULL, NULL, NULL, tFAPTunnelChildSAParams, NULL},
    {"VirtualInterface",
     &DMWRITE,
     addObjFAPTunnelVirtualInterface,
     delObjFAPTunnelVirtualInterface,
     NULL,
     browseFAPTunnelVirtualInterfaceInst,
     NULL,
     NULL,
     NULL,
     tFAPTunnelVirtualInterfaceParams,
     NULL},
    {0}};

DMLEAF tFAPTunnelParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"CryptoProfileNumberOfEntries", &DMREAD, DMT_UNINT, get_FAPTunnel_CryptoProfileNumberOfEntries, NULL, NULL, NULL},
    {"IKESANumberOfEntries", &DMREAD, DMT_UNINT, get_FAPTunnel_IKESANumberOfEntries, NULL, NULL, NULL},
    {"ChildSANumberOfEntries", &DMREAD, DMT_UNINT, get_FAPTunnel_ChildSANumberOfEntries, NULL, NULL, NULL},
    {"MaxVirtualInterfaces", &DMREAD, DMT_UNINT, get_FAPTunnel_MaxVirtualInterfaces, NULL, NULL, NULL},
    {"VirtualInterfaceNumberOfEntries", &DMREAD, DMT_UNINT, get_FAPTunnel_VirtualInterfaceNumberOfEntries, NULL, NULL, NULL},
    {"UseForCWMP", &DMWRITE, DMT_BOOL, get_FAPTunnel_UseForCWMP, set_FAPTunnel_UseForCWMP, NULL, NULL},
    {"MaxChildSAPerIKE", &DMREAD, DMT_UNINT, get_FAPTunnel_MaxChildSAPerIKE, NULL, NULL, NULL},
    {"MaxIKESessions", &DMREAD, DMT_UNINT, get_FAPTunnel_MaxIKESessions, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.Tunnel.CryptoProfile.{i}. *** */
DMLEAF tFAPTunnelCryptoProfileParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_FAPTunnelCryptoProfile_Enable, set_FAPTunnelCryptoProfile_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_Alias, set_FAPTunnelCryptoProfile_Alias, NULL, NULL},
    {"AuthMethod", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_AuthMethod, set_FAPTunnelCryptoProfile_AuthMethod, NULL, NULL},
    {"MaxChildSA", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_MaxChildSA, set_FAPTunnelCryptoProfile_MaxChildSA, NULL, NULL},
    {"IKEEncrypt", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_IKEEncrypt, set_FAPTunnelCryptoProfile_IKEEncrypt, NULL, NULL},
    {"IKEPRF", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_IKEPRF, set_FAPTunnelCryptoProfile_IKEPRF, NULL, NULL},
    {"IKEIntegrity", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_IKEIntegrity, set_FAPTunnelCryptoProfile_IKEIntegrity, NULL, NULL},
    {"IKEDH", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_IKEDH, set_FAPTunnelCryptoProfile_IKEDH, NULL, NULL},
    {"ESPEncrypt", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_ESPEncrypt, set_FAPTunnelCryptoProfile_ESPEncrypt, NULL, NULL},
    {"ESPIntegrity", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_ESPIntegrity, set_FAPTunnelCryptoProfile_ESPIntegrity, NULL, NULL},
    {"IPsecWindowSize", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_IPsecWindowSize, set_FAPTunnelCryptoProfile_IPsecWindowSize, NULL, NULL},
    {"IKERekeyLifetime", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_IKERekeyLifetime, set_FAPTunnelCryptoProfile_IKERekeyLifetime, NULL, NULL},
    {"IPsecRekeyLifetimeByte", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_IPsecRekeyLifetimeByte, set_FAPTunnelCryptoProfile_IPsecRekeyLifetimeByte, NULL, NULL},
    {"IPsecRekeyLifetimeTime", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_IPsecRekeyLifetimeTime, set_FAPTunnelCryptoProfile_IPsecRekeyLifetimeTime, NULL, NULL},
    {"DPDTimer", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_DPDTimer, set_FAPTunnelCryptoProfile_DPDTimer, NULL, NULL},
    {"NATTKeepaliveTimer", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_NATTKeepaliveTimer, set_FAPTunnelCryptoProfile_NATTKeepaliveTimer, NULL, NULL},
    {"SecMaxFragSize", &DMWRITE, DMT_UNINT, get_FAPTunnelCryptoProfile_SecMaxFragSize, set_FAPTunnelCryptoProfile_SecMaxFragSize, NULL, NULL},
    {"SecDFBit", &DMWRITE, DMT_STRING, get_FAPTunnelCryptoProfile_SecDFBit, set_FAPTunnelCryptoProfile_SecDFBit, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.Tunnel.IKESA.{i}. *** */
DMLEAF tFAPTunnelIKESAParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Status", &DMREAD, DMT_STRING, get_FAPTunnelIKESA_Status, NULL, NULL, NULL},
    {"PeerAddress", &DMREAD, DMT_STRING, get_FAPTunnelIKESA_PeerAddress, NULL, NULL, NULL},
    {"CreationTime", &DMREAD, DMT_TIME, get_FAPTunnelIKESA_CreationTime, NULL, NULL, NULL},
    {"IPAddress", &DMREAD, DMT_STRING, get_FAPTunnelIKESA_IPAddress, NULL, NULL, NULL},
    {"SubnetMask", &DMREAD, DMT_STRING, get_FAPTunnelIKESA_SubnetMask, NULL, NULL, NULL},
    {"DNSServers", &DMREAD, DMT_STRING, get_FAPTunnelIKESA_DNSServers, NULL, NULL, NULL},
    {"DHCPServers", &DMREAD, DMT_STRING, get_FAPTunnelIKESA_DHCPServers, NULL, NULL, NULL},
    {"IntegrityErrors", &DMREAD, DMT_UNINT, get_FAPTunnelIKESA_IntegrityErrors, NULL, NULL, NULL},
    {"OtherErrors", &DMREAD, DMT_UNINT, get_FAPTunnelIKESA_OtherErrors, NULL, NULL, NULL},
    {"AuthErrors", &DMREAD, DMT_UNINT, get_FAPTunnelIKESA_AuthErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.Tunnel.ChildSA.{i}. *** */
DMLEAF tFAPTunnelChildSAParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ParentID", &DMREAD, DMT_STRING, get_FAPTunnelChildSA_ParentID, NULL, NULL, NULL},
    {"SPI", &DMREAD, DMT_UNINT, get_FAPTunnelChildSA_SPI, NULL, NULL, NULL},
    {"DirectionOutbound", &DMREAD, DMT_BOOL, get_FAPTunnelChildSA_DirectionOutbound, NULL, NULL, NULL},
    {"CreationTime", &DMREAD, DMT_TIME, get_FAPTunnelChildSA_CreationTime, NULL, NULL, NULL},
    {"Traffic", &DMREAD, DMT_UNINT, get_FAPTunnelChildSA_Traffic, NULL, NULL, NULL},
    {"IntegrityErrors", &DMREAD, DMT_UNINT, get_FAPTunnelChildSA_IntegrityErrors, NULL, NULL, NULL},
    {"ReplayErrors", &DMREAD, DMT_UNINT, get_FAPTunnelChildSA_ReplayErrors, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.Tunnel.VirtualInterface.{i}. *** */
DMLEAF tFAPTunnelVirtualInterfaceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_FAPTunnelVirtualInterface_Enable, set_FAPTunnelVirtualInterface_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_FAPTunnelVirtualInterface_Alias, set_FAPTunnelVirtualInterface_Alias, NULL, NULL},
    {"CryptoProfile", &DMWRITE, DMT_STRING, get_FAPTunnelVirtualInterface_CryptoProfile, set_FAPTunnelVirtualInterface_CryptoProfile, NULL, NULL},
    {"DSCPMarkPolicy", &DMWRITE, DMT_INT, get_FAPTunnelVirtualInterface_DSCPMarkPolicy, set_FAPTunnelVirtualInterface_DSCPMarkPolicy, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.PerfMgmt. *** */
DMOBJ tFAPPerfMgmtObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Config", &DMWRITE, addObjFAPPerfMgmtConfig, delObjFAPPerfMgmtConfig, NULL, browseFAPPerfMgmtConfigInst, NULL, NULL, NULL, tFAPPerfMgmtConfigParams, NULL},
    {0}};

DMLEAF tFAPPerfMgmtParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ConfigNumberOfEntries", &DMREAD, DMT_UNINT, get_FAPPerfMgmt_ConfigNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.PerfMgmt.Config.{i}. *** */
DMLEAF tFAPPerfMgmtConfigParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_FAPPerfMgmtConfig_Enable, set_FAPPerfMgmtConfig_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_FAPPerfMgmtConfig_Alias, set_FAPPerfMgmtConfig_Alias, NULL, NULL},
    {"URL", &DMWRITE, DMT_STRING, get_FAPPerfMgmtConfig_URL, set_FAPPerfMgmtConfig_URL, NULL, NULL},
    {"Username", &DMWRITE, DMT_STRING, get_FAPPerfMgmtConfig_Username, set_FAPPerfMgmtConfig_Username, NULL, NULL},
    {"Password", &DMWRITE, DMT_STRING, get_FAPPerfMgmtConfig_Password, set_FAPPerfMgmtConfig_Password, NULL, NULL},
    {"PeriodicUploadInterval", &DMWRITE, DMT_UNINT, get_FAPPerfMgmtConfig_PeriodicUploadInterval, set_FAPPerfMgmtConfig_PeriodicUploadInterval, NULL, NULL},
    {"PeriodicUploadTime", &DMWRITE, DMT_TIME, get_FAPPerfMgmtConfig_PeriodicUploadTime, set_FAPPerfMgmtConfig_PeriodicUploadTime, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform. *** */
DMOBJ tFAPApplicationPlatformObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Capabilities", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformCapabilitiesParams, NULL},
    {"Control", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformControlObj, tFAPApplicationPlatformControlParams, NULL},
    {"Monitoring", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformMonitoringObj, tFAPApplicationPlatformMonitoringParams, NULL},
    {0}};

DMLEAF tFAPApplicationPlatformParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Version", &DMREAD, DMT_STRING, get_FAPApplicationPlatform_Version, NULL, NULL, NULL},
    {"Enable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatform_Enable, set_FAPApplicationPlatform_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_FAPApplicationPlatform_Status, NULL, NULL, NULL},
    {"MaxNumberOfApplications", &DMREAD, DMT_UNINT, get_FAPApplicationPlatform_MaxNumberOfApplications, NULL, NULL, NULL},
    {"CurrentNumberofApplications", &DMREAD, DMT_UNINT, get_FAPApplicationPlatform_CurrentNumberofApplications, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Capabilities. *** */
DMLEAF tFAPApplicationPlatformCapabilitiesParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"PresenceApplicationSupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_PresenceApplicationSupport, NULL, NULL, NULL},
    {"FemtoAwarenessAPISupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_FemtoAwarenessAPISupport, NULL, NULL, NULL},
    {"SMSAPISupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_SMSAPISupport, NULL, NULL, NULL},
    {"SubscribeToNotificationsOfSMSSentToApplicationSupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_SubscribeToNotificationsOfSMSSentToApplicationSupport, NULL, NULL, NULL},
    {"QuerySMSDeliveryStatusSupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_QuerySMSDeliveryStatusSupport, NULL, NULL, NULL},
    {"MMSAPISupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_MMSAPISupport, NULL, NULL, NULL},
    {"QueryMMSDeliveryStatusSupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_QueryMMSDeliveryStatusSupport, NULL, NULL, NULL},
    {"SubscribeToNotificationsOfMMSSentToApplicationSupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_SubscribeToNotificationsOfMMSSentToApplicationSupport, NULL, NULL, NULL},
    {"TerminalLocationAPISupport", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformCapabilities_TerminalLocationAPISupport, NULL, NULL, NULL},
    {"AuthenticationMethodsSupported", &DMREAD, DMT_STRING, get_FAPApplicationPlatformCapabilities_AuthenticationMethodsSupported, NULL, NULL, NULL},
    {"AccessLevelsSupported", &DMREAD, DMT_STRING, get_FAPApplicationPlatformCapabilities_AccessLevelsSupported, NULL, NULL, NULL},
    {"SendSMSTargetAddressType", &DMREAD, DMT_STRING, get_FAPApplicationPlatformCapabilities_SendSMSTargetAddressType, NULL, NULL, NULL},
    {"SendMMSTargetAddressType", &DMREAD, DMT_STRING, get_FAPApplicationPlatformCapabilities_SendMMSTargetAddressType, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Control. *** */
DMOBJ tFAPApplicationPlatformControlObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"FemtoAwareness", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformControlFemtoAwarenessParams, NULL},
    {"SMS", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformControlSMSParams, NULL},
    {"MMS", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformControlMMSParams, NULL},
    {"TerminalLocation", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformControlTerminalLocationParams, NULL},
    {0}};

DMLEAF tFAPApplicationPlatformControlParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"AuthenticationMethod", &DMWRITE, DMT_STRING, get_FAPApplicationPlatformControl_AuthenticationMethod, set_FAPApplicationPlatformControl_AuthenticationMethod, NULL, NULL},
    {"TunnelInst", &DMWRITE, DMT_STRING, get_FAPApplicationPlatformControl_TunnelInst, set_FAPApplicationPlatformControl_TunnelInst, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Control.FemtoAwareness. *** */
DMLEAF tFAPApplicationPlatformControlFemtoAwarenessParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlFemtoAwareness_APIEnable, set_FAPApplicationPlatformControlFemtoAwareness_APIEnable, NULL, NULL},
    {"QueueEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlFemtoAwareness_QueueEnable, set_FAPApplicationPlatformControlFemtoAwareness_QueueEnable, NULL, NULL},
    {"Queueing ", &DMWRITE, DMT_STRING, get_FAPApplicationPlatformControlFemtoAwareness_Queueing, set_FAPApplicationPlatformControlFemtoAwareness_Queueing, NULL, NULL},
    {"MaxAPIUsersNumber", &DMWRITE, DMT_UNINT, get_FAPApplicationPlatformControlFemtoAwareness_MaxAPIUsersNumber, set_FAPApplicationPlatformControlFemtoAwareness_MaxAPIUsersNumber, NULL, NULL},
    {"FemtozoneID", &DMWRITE, DMT_STRING, get_FAPApplicationPlatformControlFemtoAwareness_FemtozoneID, set_FAPApplicationPlatformControlFemtoAwareness_FemtozoneID, NULL, NULL},
    {"NotificationsUserIdentifierMSISDN",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlFemtoAwareness_NotificationsUserIdentifierMSISDN,
     set_FAPApplicationPlatformControlFemtoAwareness_NotificationsUserIdentifierMSISDN,
     NULL,
     NULL},
    {"SubscribeToNotificationsResponseCallbackData",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlFemtoAwareness_SubscribeToNotificationsResponseCallbackData,
     set_FAPApplicationPlatformControlFemtoAwareness_SubscribeToNotificationsResponseCallbackData,
     NULL,
     NULL},
    {"QueryFemtocellResponseTimezone",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlFemtoAwareness_QueryFemtocellResponseTimezone,
     set_FAPApplicationPlatformControlFemtoAwareness_QueryFemtocellResponseTimezone,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Control.SMS. *** */
DMLEAF tFAPApplicationPlatformControlSMSParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlSMS_APIEnable, set_FAPApplicationPlatformControlSMS_APIEnable, NULL, NULL},
    {"QueueEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlSMS_QueueEnable, set_FAPApplicationPlatformControlSMS_QueueEnable, NULL, NULL},
    {"Queueing ", &DMWRITE, DMT_STRING, get_FAPApplicationPlatformControlSMS_Queueing, set_FAPApplicationPlatformControlSMS_Queueing, NULL, NULL},
    {"MaxAPIUsersNumber", &DMWRITE, DMT_UNINT, get_FAPApplicationPlatformControlSMS_MaxAPIUsersNumber, set_FAPApplicationPlatformControlSMS_MaxAPIUsersNumber, NULL, NULL},
    {"MinSendSMSTimeInterval", &DMWRITE, DMT_UNINT, get_FAPApplicationPlatformControlSMS_MinSendSMSTimeInterval, set_FAPApplicationPlatformControlSMS_MinSendSMSTimeInterval, NULL, NULL},
    {"EnableQuerySMSDeliveryStatus",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlSMS_EnableQuerySMSDeliveryStatus,
     set_FAPApplicationPlatformControlSMS_EnableQuerySMSDeliveryStatus,
     NULL,
     NULL},
    {"EnableSubscribeToNotificationsOfMessageSentToApplication",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlSMS_EnableSubscribeToNotificationsOfMessageSentToApplication,
     set_FAPApplicationPlatformControlSMS_EnableSubscribeToNotificationsOfMessageSentToApplication,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Control.MMS. *** */
DMLEAF tFAPApplicationPlatformControlMMSParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlMMS_APIEnable, set_FAPApplicationPlatformControlMMS_APIEnable, NULL, NULL},
    {"QueueEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlMMS_QueueEnable, set_FAPApplicationPlatformControlMMS_QueueEnable, NULL, NULL},
    {"Queueing ", &DMWRITE, DMT_STRING, get_FAPApplicationPlatformControlMMS_Queueing, set_FAPApplicationPlatformControlMMS_Queueing, NULL, NULL},
    {"MaxAPIUsersNumber", &DMWRITE, DMT_UNINT, get_FAPApplicationPlatformControlMMS_MaxAPIUsersNumber, set_FAPApplicationPlatformControlMMS_MaxAPIUsersNumber, NULL, NULL},
    {"MinSendMMSTimeInterval", &DMWRITE, DMT_UNINT, get_FAPApplicationPlatformControlMMS_MinSendMMSTimeInterval, set_FAPApplicationPlatformControlMMS_MinSendMMSTimeInterval, NULL, NULL},
    {"EnableQueryMMSDeliveryStatus",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlMMS_EnableQueryMMSDeliveryStatus,
     set_FAPApplicationPlatformControlMMS_EnableQueryMMSDeliveryStatus,
     NULL,
     NULL},
    {"EnableSubscribeToNotificationsOfMessageSentToApplication",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlMMS_EnableSubscribeToNotificationsOfMessageSentToApplication,
     set_FAPApplicationPlatformControlMMS_EnableSubscribeToNotificationsOfMessageSentToApplication,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Control.TerminalLocation. *** */
DMLEAF tFAPApplicationPlatformControlTerminalLocationParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlTerminalLocation_APIEnable, set_FAPApplicationPlatformControlTerminalLocation_APIEnable, NULL, NULL},
    {"QueueEnable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformControlTerminalLocation_QueueEnable, set_FAPApplicationPlatformControlTerminalLocation_QueueEnable, NULL, NULL},
    {"Queueing ", &DMWRITE, DMT_STRING, get_FAPApplicationPlatformControlTerminalLocation_Queueing, set_FAPApplicationPlatformControlTerminalLocation_Queueing, NULL, NULL},
    {"MaxAPIUsersNumber", &DMWRITE, DMT_UNINT, get_FAPApplicationPlatformControlTerminalLocation_MaxAPIUsersNumber, set_FAPApplicationPlatformControlTerminalLocation_MaxAPIUsersNumber, NULL, NULL},
    {"QueryMobileLocationResponseAddress",
     &DMWRITE,
     DMT_STRING,
     get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAddress,
     set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAddress,
     NULL,
     NULL},
    {"QueryMobileLocationResponseLongitudeLatitude",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseLongitudeLatitude,
     set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseLongitudeLatitude,
     NULL,
     NULL},
    {"QueryMobileLocationResponseAltitude",
     &DMWRITE,
     DMT_BOOL,
     get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAltitude,
     set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAltitude,
     NULL,
     NULL},
    {"QueryMobileLocationResponseTimestamp",
     &DMWRITE,
     DMT_UNINT,
     get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseTimestamp,
     set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseTimestamp,
     NULL,
     NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Monitoring. *** */
DMOBJ tFAPApplicationPlatformMonitoringObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"FemtoAwareness", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformMonitoringFemtoAwarenessParams, NULL},
    {"SMS", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformMonitoringSMSParams, NULL},
    {"MMS", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformMonitoringMMSParams, NULL},
    {"TerminalLocation", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tFAPApplicationPlatformMonitoringTerminalLocationParams, NULL},
    {0}};

DMLEAF tFAPApplicationPlatformMonitoringParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_FAPApplicationPlatformMonitoring_Enable, set_FAPApplicationPlatformMonitoring_Enable, NULL, NULL},
    {"MonitoringInterval", &DMWRITE, DMT_UNINT, get_FAPApplicationPlatformMonitoring_MonitoringInterval, set_FAPApplicationPlatformMonitoring_MonitoringInterval, NULL, NULL},
    {"AuthenticationRequestsReceived", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoring_AuthenticationRequestsReceived, NULL, NULL, NULL},
    {"AuthenticationRequestsRejected", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoring_AuthenticationRequestsRejected, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Monitoring.FemtoAwareness. *** */
DMLEAF tFAPApplicationPlatformMonitoringFemtoAwarenessParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIAvailable", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformMonitoringFemtoAwareness_APIAvailable, NULL, NULL, NULL},
    {"APIUsers", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringFemtoAwareness_APIUsers, NULL, NULL, NULL},
    {"QueueState", &DMREAD, DMT_STRING, get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueState, NULL, NULL, NULL},
    {"QueueNum", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueNum, NULL, NULL, NULL},
    {"QueueReceived", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueReceived, NULL, NULL, NULL},
    {"QueueDiscarded", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueDiscarded, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Monitoring.SMS. *** */
DMLEAF tFAPApplicationPlatformMonitoringSMSParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIAvailable", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformMonitoringSMS_APIAvailable, NULL, NULL, NULL},
    {"APIUsers", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringSMS_APIUsers, NULL, NULL, NULL},
    {"QueueState", &DMREAD, DMT_STRING, get_FAPApplicationPlatformMonitoringSMS_QueueState, NULL, NULL, NULL},
    {"QueueNum", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringSMS_QueueNum, NULL, NULL, NULL},
    {"QueueReceived", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringSMS_QueueReceived, NULL, NULL, NULL},
    {"QueueDiscarded", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringSMS_QueueDiscarded, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Monitoring.MMS. *** */
DMLEAF tFAPApplicationPlatformMonitoringMMSParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIAvailable", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformMonitoringMMS_APIAvailable, NULL, NULL, NULL},
    {"APIUsers", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringMMS_APIUsers, NULL, NULL, NULL},
    {"QueueState", &DMREAD, DMT_STRING, get_FAPApplicationPlatformMonitoringMMS_QueueState, NULL, NULL, NULL},
    {"QueueNum", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringMMS_QueueNum, NULL, NULL, NULL},
    {"QueueReceived", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringMMS_QueueReceived, NULL, NULL, NULL},
    {"QueueDiscarded", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringMMS_QueueDiscarded, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.FAP.ApplicationPlatform.Monitoring.TerminalLocation. *** */
DMLEAF tFAPApplicationPlatformMonitoringTerminalLocationParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"APIAvailable", &DMREAD, DMT_BOOL, get_FAPApplicationPlatformMonitoringTerminalLocation_APIAvailable, NULL, NULL, NULL},
    {"APIUsers", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringTerminalLocation_APIUsers, NULL, NULL, NULL},
    {"QueueState", &DMREAD, DMT_STRING, get_FAPApplicationPlatformMonitoringTerminalLocation_QueueState, NULL, NULL, NULL},
    {"QueueNum", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringTerminalLocation_QueueNum, NULL, NULL, NULL},
    {"QueueReceived", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringTerminalLocation_QueueReceived, NULL, NULL, NULL},
    {"QueueDiscarded", &DMREAD, DMT_UNINT, get_FAPApplicationPlatformMonitoringTerminalLocation_QueueDiscarded, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.BulkData. *** */
DMOBJ tBulkDataObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Profile", &DMWRITE, addObjBulkDataProfile, delObjBulkDataProfile, NULL, browseBulkDataProfileInst, NULL, NULL, tBulkDataProfileObj, tBulkDataProfileParams, NULL},
    {0}};

DMLEAF tBulkDataParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_BulkData_Enable, set_BulkData_Enable, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_BulkData_Status, NULL, NULL, NULL},
    {"MinReportingInterval", &DMREAD, DMT_UNINT, get_BulkData_MinReportingInterval, NULL, NULL, NULL},
    {"Protocols", &DMREAD, DMT_STRING, get_BulkData_Protocols, NULL, NULL, NULL},
    {"EncodingTypes", &DMREAD, DMT_STRING, get_BulkData_EncodingTypes, NULL, NULL, NULL},
    {"MaxNumberOfProfiles", &DMREAD, DMT_INT, get_BulkData_MaxNumberOfProfiles, NULL, NULL, NULL},
    {"MaxNumberOfParameterReferences", &DMREAD, DMT_INT, get_BulkData_MaxNumberOfParameterReferences, NULL, NULL, NULL},
    {"ProfileNumberOfEntries", &DMREAD, DMT_UNINT, get_BulkData_ProfileNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.BulkData.Profile.{i}. *** */
DMOBJ tBulkDataProfileObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Parameter", &DMWRITE, addObjBulkDataProfileParameter, delObjBulkDataProfileParameter, NULL, browseBulkDataProfileParameterInst, NULL, NULL, NULL, tBulkDataProfileParameterParams, NULL},
    {0}};

DMLEAF tBulkDataProfileParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_BulkDataProfile_Enable, set_BulkDataProfile_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_BulkDataProfile_Alias, set_BulkDataProfile_Alias, NULL, NULL},
    {"Protocol", &DMWRITE, DMT_STRING, get_BulkDataProfile_Protocol, set_BulkDataProfile_Protocol, NULL, NULL},
    {"EncodingType", &DMWRITE, DMT_STRING, get_BulkDataProfile_EncodingType, set_BulkDataProfile_EncodingType, NULL, NULL},
    {"ReportingInterval", &DMWRITE, DMT_UNINT, get_BulkDataProfile_ReportingInterval, set_BulkDataProfile_ReportingInterval, NULL, NULL},
    {"TimeReference", &DMWRITE, DMT_TIME, get_BulkDataProfile_TimeReference, set_BulkDataProfile_TimeReference, NULL, NULL},
    {"StreamingHost", &DMWRITE, DMT_STRING, get_BulkDataProfile_StreamingHost, set_BulkDataProfile_StreamingHost, NULL, NULL},
    {"StreamingPort", &DMWRITE, DMT_UNINT, get_BulkDataProfile_StreamingPort, set_BulkDataProfile_StreamingPort, NULL, NULL},
    {"StreamingSessionID", &DMWRITE, DMT_UNINT, get_BulkDataProfile_StreamingSessionID, set_BulkDataProfile_StreamingSessionID, NULL, NULL},
    {"FileTransferURL", &DMWRITE, DMT_STRING, get_BulkDataProfile_FileTransferURL, set_BulkDataProfile_FileTransferURL, NULL, NULL},
    {"FileTransferUsername", &DMWRITE, DMT_STRING, get_BulkDataProfile_FileTransferUsername, set_BulkDataProfile_FileTransferUsername, NULL, NULL},
    {"FileTransferPassword", &DMWRITE, DMT_STRING, get_BulkDataProfile_FileTransferPassword, set_BulkDataProfile_FileTransferPassword, NULL, NULL},
    {"ControlFileFormat", &DMWRITE, DMT_STRING, get_BulkDataProfile_ControlFileFormat, set_BulkDataProfile_ControlFileFormat, NULL, NULL},
    {"ParameterNumberOfEntries", &DMREAD, DMT_UNINT, get_BulkDataProfile_ParameterNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.BulkData.Profile.{i}.Parameter.{i}. *** */
DMLEAF tBulkDataProfileParameterParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Reference", &DMWRITE, DMT_STRING, get_BulkDataProfileParameter_Reference, set_BulkDataProfileParameter_Reference, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DNS. *** */
DMOBJ tDNSObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"SD", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, tDNSSDObj, tDNSSDParams, NULL},
    {0}};

/* *** InternetGatewayDevice.DNS.SD. *** */
DMOBJ tDNSSDObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Service", &DMREAD, NULL, NULL, NULL, browseDNSSDServiceInst, NULL, NULL, tDNSSDServiceObj, tDNSSDServiceParams, NULL},
    {0}};

DMLEAF tDNSSDParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_DNSSD_Enable, set_DNSSD_Enable, NULL, NULL},
    {"ServiceNumberOfEntries", &DMREAD, DMT_UNINT, get_DNSSD_ServiceNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DNS.SD.Service.{i}. *** */
DMOBJ tDNSSDServiceObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"TextRecord", &DMREAD, NULL, NULL, NULL, browseDNSSDServiceTextRecordInst, NULL, NULL, NULL, tDNSSDServiceTextRecordParams, NULL},
    {0}};

DMLEAF tDNSSDServiceParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"InstanceName", &DMREAD, DMT_STRING, get_DNSSDService_InstanceName, NULL, NULL, NULL},
    {"ApplicationProtocol", &DMREAD, DMT_STRING, get_DNSSDService_ApplicationProtocol, NULL, NULL, NULL},
    {"TransportProtocol", &DMREAD, DMT_STRING, get_DNSSDService_TransportProtocol, NULL, NULL, NULL},
    {"Domain", &DMREAD, DMT_STRING, get_DNSSDService_Domain, NULL, NULL, NULL},
    {"Port", &DMREAD, DMT_UNINT, get_DNSSDService_Port, NULL, NULL, NULL},
    {"Target", &DMREAD, DMT_STRING, get_DNSSDService_Target, NULL, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_DNSSDService_Status, NULL, NULL, NULL},
    {"LastUpdate", &DMREAD, DMT_TIME, get_DNSSDService_LastUpdate, NULL, NULL, NULL},
    {"Host", &DMREAD, DMT_STRING, get_DNSSDService_Host, NULL, NULL, NULL},
    {"TimeToLive", &DMREAD, DMT_UNINT, get_DNSSDService_TimeToLive, NULL, NULL, NULL},
    {"Priority", &DMREAD, DMT_UNINT, get_DNSSDService_Priority, NULL, NULL, NULL},
    {"Weight", &DMREAD, DMT_UNINT, get_DNSSDService_Weight, NULL, NULL, NULL},
    {"TextRecordNumberOfEntries", &DMREAD, DMT_UNINT, get_DNSSDService_TextRecordNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.DNS.SD.Service.{i}.TextRecord.{i}. *** */
DMLEAF tDNSSDServiceTextRecordParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Key", &DMREAD, DMT_STRING, get_DNSSDServiceTextRecord_Key, NULL, NULL, NULL},
    {"Value", &DMREAD, DMT_STRING, get_DNSSDServiceTextRecord_Value, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.XMPP. *** */
DMOBJ tXMPPObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Connection", &DMWRITE, addObjXMPPConnection, delObjXMPPConnection, NULL, browseXMPPConnectionInst, NULL, NULL, tXMPPConnectionObj, tXMPPConnectionParams, NULL},
    {0}};

DMLEAF tXMPPParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ConnectionNumberOfEntries", &DMREAD, DMT_UNINT, get_XMPP_ConnectionNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.XMPP.Connection.{i}. *** */
DMOBJ tXMPPConnectionObj[] = {
    /* OBJ, permission, addobj, delobj, checkobj, browseinstobj, forced_inform, notification, nextobj, leaf, linker*/
    {"Server", &DMWRITE, addObjXMPPConnectionServer, delObjXMPPConnectionServer, NULL, browseXMPPConnectionServerInst, NULL, NULL, NULL, tXMPPConnectionServerParams, NULL},
    {"Stats", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tXMPPConnectionStatsParams, NULL},
    {0}};

DMLEAF tXMPPConnectionParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_XMPPConnection_Enable, set_XMPPConnection_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_XMPPConnection_Alias, set_XMPPConnection_Alias, NULL, NULL},
    {"Username", &DMWRITE, DMT_STRING, get_XMPPConnection_Username, set_XMPPConnection_Username, NULL, NULL},
    {"Password", &DMWRITE, DMT_STRING, get_XMPPConnection_Password, set_XMPPConnection_Password, NULL, NULL},
    {"Domain", &DMWRITE, DMT_STRING, get_XMPPConnection_Domain, set_XMPPConnection_Domain, NULL, NULL},
    {"Resource", &DMWRITE, DMT_STRING, get_XMPPConnection_Resource, set_XMPPConnection_Resource, NULL, NULL},
    {"JabberID", &DMREAD, DMT_STRING, get_XMPPConnection_JabberID, NULL, NULL, NULL},
    {"Status", &DMREAD, DMT_STRING, get_XMPPConnection_Status, NULL, NULL, NULL},
    {"LastChangeDate", &DMREAD, DMT_TIME, get_XMPPConnection_LastChangeDate, NULL, NULL, NULL},
    {"ServerConnectAlgorithm", &DMWRITE, DMT_STRING, get_XMPPConnection_ServerConnectAlgorithm, set_XMPPConnection_ServerConnectAlgorithm, NULL, NULL},
    {"KeepAliveInterval", &DMWRITE, DMT_LONG, get_XMPPConnection_KeepAliveInterval, set_XMPPConnection_KeepAliveInterval, NULL, NULL},
    {"ServerConnectAttempts", &DMWRITE, DMT_UNINT, get_XMPPConnection_ServerConnectAttempts, set_XMPPConnection_ServerConnectAttempts, NULL, NULL},
    {"ServerRetryInitialInterval", &DMWRITE, DMT_UNINT, get_XMPPConnection_ServerRetryInitialInterval, set_XMPPConnection_ServerRetryInitialInterval, NULL, NULL},
    {"ServerRetryIntervalMultiplier", &DMWRITE, DMT_UNINT, get_XMPPConnection_ServerRetryIntervalMultiplier, set_XMPPConnection_ServerRetryIntervalMultiplier, NULL, NULL},
    {"ServerRetryMaxInterval", &DMWRITE, DMT_UNINT, get_XMPPConnection_ServerRetryMaxInterval, set_XMPPConnection_ServerRetryMaxInterval, NULL, NULL},
    {"UseTLS", &DMWRITE, DMT_BOOL, get_XMPPConnection_UseTLS, set_XMPPConnection_UseTLS, NULL, NULL},
    {"TLSEstablished", &DMREAD, DMT_BOOL, get_XMPPConnection_TLSEstablished, NULL, NULL, NULL},
    {"ServerNumberOfEntries", &DMREAD, DMT_UNINT, get_XMPPConnection_ServerNumberOfEntries, NULL, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.XMPP.Connection.{i}.Server.{i}. *** */
DMLEAF tXMPPConnectionServerParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"Enable", &DMWRITE, DMT_BOOL, get_XMPPConnectionServer_Enable, set_XMPPConnectionServer_Enable, NULL, NULL},
    {"Alias", &DMWRITE, DMT_STRING, get_XMPPConnectionServer_Alias, set_XMPPConnectionServer_Alias, NULL, NULL},
    {"Priority", &DMWRITE, DMT_UNINT, get_XMPPConnectionServer_Priority, set_XMPPConnectionServer_Priority, NULL, NULL},
    {"Weight", &DMWRITE, DMT_LONG, get_XMPPConnectionServer_Weight, set_XMPPConnectionServer_Weight, NULL, NULL},
    {"ServerAddress", &DMWRITE, DMT_STRING, get_XMPPConnectionServer_ServerAddress, set_XMPPConnectionServer_ServerAddress, NULL, NULL},
    {"Port", &DMWRITE, DMT_UNINT, get_XMPPConnectionServer_Port, set_XMPPConnectionServer_Port, NULL, NULL},
    {0}};

/* *** InternetGatewayDevice.XMPP.Connection.{i}.Stats. *** */
DMLEAF tXMPPConnectionStatsParams[] = {
    /* PARAM, permission, type, getvalue, setvalue, forced_inform, notification*/
    {"ReceivedMessages", &DMREAD, DMT_UNINT, get_XMPPConnectionStats_ReceivedMessages, NULL, NULL, NULL},
    {"TransmittedMessages", &DMREAD, DMT_UNINT, get_XMPPConnectionStats_TransmittedMessages, NULL, NULL, NULL},
    {"ReceivedErrorMessages", &DMREAD, DMT_UNINT, get_XMPPConnectionStats_ReceivedErrorMessages, NULL, NULL, NULL},
    {"TransmittedErrorMessages", &DMREAD, DMT_UNINT, get_XMPPConnectionStats_TransmittedErrorMessages, NULL, NULL, NULL},
    {0}};

/*************************************************************
 * ENTRY METHOD
/*************************************************************/
int browseLANDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUserInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseSmartCardReaderInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDeviceInfoVendorConfigFileInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDeviceInfoSupportedDataModelInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDeviceInfoProcessorInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDeviceInfoVendorLogFileInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDeviceInfoLocationInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDeviceInfoProcessStatusProcessInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDeviceInfoTemperatureStatusTemperatureSensorInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseManagementServerManageableDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseManagementServerEmbeddedDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseManagementServerVirtualDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseManagementServerInformParameterInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLayer3ForwardingForwardingInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLayer2BridgingBridgeInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLayer2BridgingFilterInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLayer2BridgingMarkingInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLayer2BridgingAvailableInterfaceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLayer2BridgingBridgePortInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLayer2BridgingBridgeVLANInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseQueueManagementClassificationInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseQueueManagementAppInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseQueueManagementFlowInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseQueueManagementPolicerInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseQueueManagementQueueInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseQueueManagementQueueStatsInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseTraceRouteDiagnosticsRouteHopsInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANEthernetInterfaceConfigInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANUSBInterfaceConfigInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceWLANConfigurationInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANHostConfigManagementIPInterfaceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANHostConfigManagementDHCPStaticAddressInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANHostConfigManagementDHCPOptionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANHostConfigManagementDHCPConditionalServingPoolInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddressInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOptionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceWLANConfigurationAssociatedDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceWLANConfigurationWEPKeyInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceWLANConfigurationPreSharedKeyInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceWLANConfigurationAPWMMParameterInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceWLANConfigurationSTAWMMParameterInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceWLANConfigurationWPSRegistrarInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANDeviceHostsHostInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANInterfacesLANEthernetInterfaceConfigInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANInterfacesLANUSBInterfaceConfigInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseLANInterfacesWLANConfigurationInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANConnectionDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANCommonInterfaceConfigConnectionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANDSLConnectionManagementConnectionServiceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANConnectionDeviceWANIPConnectionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANConnectionDeviceWANPPPConnectionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANConnectionDeviceWANIPConnectionPortMappingInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOptionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOptionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseWANDeviceWANConnectionDeviceWANPPPConnectionPortMappingInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUPnPDiscoveryRootDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUPnPDiscoveryDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUPnPDiscoveryServiceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUPnPDescriptionDeviceDescriptionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUPnPDescriptionDeviceInstanceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUPnPDescriptionServiceInstanceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseNSLookupDiagnosticsResultInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUSBHostsHostInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUSBHostsHostDeviceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUSBHostsHostDeviceConfigurationInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseUSBHostsHostDeviceConfigurationInterfaceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browsePeriodicStatisticsSampleSetInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browsePeriodicStatisticsSampleSetParameterInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDownloadAvailabilityAnnouncementGroupInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseSoftwareModulesExecEnvInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseSoftwareModulesDeploymentUnitInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseSoftwareModulesExecutionUnitInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseSecurityCertificateInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFaultMgmtSupportedAlarmInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFaultMgmtCurrentAlarmInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFaultMgmtHistoryEventInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFaultMgmtExpeditedEventInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFaultMgmtQueuedEventInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFAPTunnelCryptoProfileInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFAPTunnelIKESAInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFAPTunnelChildSAInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFAPTunnelVirtualInterfaceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseFAPPerfMgmtConfigInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseBulkDataProfileInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseBulkDataProfileParameterInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDNSSDServiceInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseDNSSDServiceTextRecordInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseXMPPConnectionInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

int browseXMPPConnectionServerInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    // TODO
    return 0;
}

/*************************************************************
 * ADD & DEL OBJ
/*************************************************************/
int addObjLANDevice(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLANDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjUser(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjUser(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjDeviceInfoLocation(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjDeviceInfoLocation(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjManagementServerInformParameter(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjManagementServerInformParameter(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLayer3ForwardingForwarding(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLayer3ForwardingForwarding(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLayer2BridgingBridge(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLayer2BridgingBridge(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLayer2BridgingFilter(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLayer2BridgingFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLayer2BridgingMarking(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLayer2BridgingMarking(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLayer2BridgingBridgePort(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLayer2BridgingBridgePort(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLayer2BridgingBridgeVLAN(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLayer2BridgingBridgeVLAN(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjQueueManagementClassification(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjQueueManagementClassification(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjQueueManagementApp(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjQueueManagementApp(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjQueueManagementFlow(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjQueueManagementFlow(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjQueueManagementPolicer(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjQueueManagementPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjQueueManagementQueue(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjQueueManagementQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjQueueManagementQueueStats(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjQueueManagementQueueStats(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLANDeviceLANHostConfigManagementIPInterface(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLANDeviceLANHostConfigManagementIPInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLANDeviceLANHostConfigManagementDHCPStaticAddress(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLANDeviceLANHostConfigManagementDHCPStaticAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLANDeviceLANHostConfigManagementDHCPOption(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLANDeviceLANHostConfigManagementDHCPOption(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLANDeviceLANHostConfigManagementDHCPConditionalServingPool(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLANDeviceLANHostConfigManagementDHCPConditionalServingPool(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjLANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjWANDeviceWANConnectionDevice(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjWANDeviceWANConnectionDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjWANDeviceWANConnectionDeviceWANIPConnection(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjWANDeviceWANConnectionDeviceWANIPConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjWANDeviceWANConnectionDeviceWANPPPConnection(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjWANDeviceWANConnectionDeviceWANPPPConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjWANDeviceWANConnectionDeviceWANIPConnectionPortMapping(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjWANDeviceWANConnectionDeviceWANIPConnectionPortMapping(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjWANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjWANDeviceWANConnectionDeviceWANPPPConnectionPortMapping(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjWANDeviceWANConnectionDeviceWANPPPConnectionPortMapping(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjPeriodicStatisticsSampleSet(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjPeriodicStatisticsSampleSet(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjPeriodicStatisticsSampleSetParameter(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjPeriodicStatisticsSampleSetParameter(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjDownloadAvailabilityAnnouncementGroup(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjDownloadAvailabilityAnnouncementGroup(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjFAPTunnelCryptoProfile(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjFAPTunnelCryptoProfile(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjFAPTunnelVirtualInterface(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjFAPTunnelVirtualInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjFAPPerfMgmtConfig(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjFAPPerfMgmtConfig(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjBulkDataProfile(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjBulkDataProfile(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjBulkDataProfileParameter(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjBulkDataProfileParameter(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjXMPPConnection(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjXMPPConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

int addObjXMPPConnectionServer(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    // TODO
    return 0;
}

int delObjXMPPConnectionServer(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    switch (del_action)
    {
        case DEL_INST:
            // TODO
            break;
        case DEL_ALL:
            // TODO
            break;
    }
    return 0;
}

/*************************************************************
 * GET & SET PARAM
/*************************************************************/
int get_RootInternetGatewayDevice_DeviceSummary(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_RootInternetGatewayDevice_LANDeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_RootInternetGatewayDevice_WANDeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_RootInternetGatewayDevice_UserNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_RootInternetGatewayDevice_SmartCardReaderNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_CapabilitiesPerformanceDiagnostic_DownloadTransports(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_CapabilitiesPerformanceDiagnostic_UploadTransports(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_DeviceCategory(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_Manufacturer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_ManufacturerOUI(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_ModelName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_ModelNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_Description(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_ProductClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_HardwareVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_SoftwareVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_ModemFirmwareVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_EnabledOptions(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_AdditionalHardwareVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_AdditionalSoftwareVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_SpecVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_ProvisioningCode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfo_ProvisioningCode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfo_UpTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_FirstUseDate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_DeviceLog(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_VendorConfigFileNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_SupportedDataModelNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_ProcessorNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_VendorLogFileNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfo_LocationNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoVendorConfigFile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoVendorConfigFile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoVendorConfigFile_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoVendorConfigFile_Version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoVendorConfigFile_Date(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoVendorConfigFile_Description(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoMemoryStatus_Total(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoMemoryStatus_Free(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatus_CPUUsage(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatus_ProcessNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatusProcess_PID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatusProcess_Command(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatusProcess_Size(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatusProcess_Priority(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatusProcess_CPUTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessStatusProcess_State(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatus_TemperatureSensorNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoTemperatureStatusTemperatureSensor_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoTemperatureStatusTemperatureSensor_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoTemperatureStatusTemperatureSensor_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_ResetTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_LastUpdate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_MinValue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_MinTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_MaxValue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_MaxTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_LowAlarmValue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoTemperatureStatusTemperatureSensor_LowAlarmValue(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_LowAlarmTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_HighAlarmValue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoTemperatureStatusTemperatureSensor_HighAlarmValue(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_PollingInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoTemperatureStatusTemperatureSensor_PollingInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoTemperatureStatusTemperatureSensor_HighAlarmTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoNetworkProperties_MaxTCPWindowSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoNetworkProperties_TCPImplementation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoSupportedDataModel_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoSupportedDataModel_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoSupportedDataModel_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoSupportedDataModel_UUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoSupportedDataModel_URN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoSupportedDataModel_Features(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProcessor_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoProcessor_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoProcessor_Architecture(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoVendorLogFile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoVendorLogFile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceInfoVendorLogFile_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoVendorLogFile_MaximumSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoVendorLogFile_Persistent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProxierInfo_ManufacturerOUI(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProxierInfo_ProductClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProxierInfo_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoProxierInfo_ProxyProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoLocation_Source(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoLocation_AcquiredTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoLocation_ExternalSource(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoLocation_ExternalProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DeviceInfoLocation_DataObject(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceInfoLocation_DataObject(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceConfig_PersistentData(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceConfig_PersistentData(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DeviceConfig_ConfigFile(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DeviceConfig_ConfigFile(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_EnableCWMP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_EnableCWMP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_PeriodicInformEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_PeriodicInformEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_PeriodicInformInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_PeriodicInformInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_PeriodicInformTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_PeriodicInformTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_ParameterKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_ConnectionRequestURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_ConnectionRequestUsername(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_ConnectionRequestUsername(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_ConnectionRequestPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_ConnectionRequestPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_UpgradesManaged(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_UpgradesManaged(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_KickURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_DownloadProgressURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_DefaultActiveNotificationThrottle(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_DefaultActiveNotificationThrottle(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_UDPConnectionRequestAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_UDPConnectionRequestAddressNotificationLimit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_UDPConnectionRequestAddressNotificationLimit(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_STUNEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_STUNEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_STUNServerAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_STUNServerAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_STUNServerPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_STUNServerPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_STUNUsername(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_STUNUsername(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_STUNPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_STUNPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_STUNMaximumKeepAlivePeriod(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_STUNMaximumKeepAlivePeriod(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_STUNMinimumKeepAlivePeriod(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_STUNMinimumKeepAlivePeriod(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_NATDetected(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_AliasBasedAddressing(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_InstanceMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_InstanceMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_AutoCreateInstances(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_AutoCreateInstances(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_CWMPRetryMinimumWaitInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_CWMPRetryMinimumWaitInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_CWMPRetryIntervalMultiplier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_CWMPRetryIntervalMultiplier(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_ManageableDeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_ManageableDeviceNotificationLimit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_ManageableDeviceNotificationLimit(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_EmbeddedDeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_VirtualDeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_SupportedConnReqMethods(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_ConnReqXMPPConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_ConnReqXMPPConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_ConnReqAllowedJabberIDs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_ConnReqAllowedJabberIDs(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_ConnReqJabberID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_HTTPCompressionSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_HTTPCompression(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_HTTPCompression(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_LightweightNotificationProtocolsSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServer_LightweightNotificationProtocolsUsed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_LightweightNotificationProtocolsUsed(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_UDPLightweightNotificationHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_UDPLightweightNotificationHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_UDPLightweightNotificationPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServer_UDPLightweightNotificationPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServer_InformParameterNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerManageableDevice_ManufacturerOUI(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerManageableDevice_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerManageableDevice_ProductClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerManageableDevice_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerAutonomousTransferCompletePolicy_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerAutonomousTransferCompletePolicy_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerAutonomousTransferCompletePolicy_TransferTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerAutonomousTransferCompletePolicy_TransferTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerAutonomousTransferCompletePolicy_ResultTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerAutonomousTransferCompletePolicy_ResultTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerAutonomousTransferCompletePolicy_FileTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerAutonomousTransferCompletePolicy_FileTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerDUStateChangeComplPolicy_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerDUStateChangeComplPolicy_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerDUStateChangeComplPolicy_OperationTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerDUStateChangeComplPolicy_OperationTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerDUStateChangeComplPolicy_ResultTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerDUStateChangeComplPolicy_ResultTypeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerDUStateChangeComplPolicy_FaultCodeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerDUStateChangeComplPolicy_FaultCodeFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerEmbeddedDevice_ControllerID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_ProxiedDeviceID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_Reference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_SupportedDataModel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_ProxyProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_ProxyProtocolReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_DiscoveryProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_DiscoveryProtocolReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_CommandProcessed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_CommandProcessingErrMsg(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerEmbeddedDevice_LastSyncTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_ManufacturerOUI(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_ProductClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_ProxyProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_ProxyProtocolReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_DiscoveryProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerVirtualDevice_DiscoveryProtocolReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerStandbyPolicy_CRUnawarenessMaxDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerStandbyPolicy_CRUnawarenessMaxDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerStandbyPolicy_MaxMissedPeriodic(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerStandbyPolicy_MaxMissedPeriodic(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerStandbyPolicy_NotifyMissedScheduled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerStandbyPolicy_NotifyMissedScheduled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerStandbyPolicy_NetworkAwarenessCapable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerStandbyPolicy_SelfTimerCapable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_ManagementServerStandbyPolicy_CRAwarenessRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerStandbyPolicy_CRAwarenessRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerStandbyPolicy_PeriodicAwarenessRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerStandbyPolicy_PeriodicAwarenessRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerStandbyPolicy_ScheduledAwarenessRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerStandbyPolicy_ScheduledAwarenessRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerInformParameter_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerInformParameter_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerInformParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerInformParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerInformParameter_ParameterName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerInformParameter_ParameterName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_ManagementServerInformParameter_EventList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_ManagementServerInformParameter_EventList(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Time_NTPServer1(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_NTPServer1(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_NTPServer2(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_NTPServer2(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_NTPServer3(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_NTPServer3(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_NTPServer4(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_NTPServer4(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_NTPServer5(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_NTPServer5(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_CurrentLocalTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Time_LocalTimeZone(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_LocalTimeZone(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_LocalTimeZoneName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_LocalTimeZoneName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_DaylightSavingsUsed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_DaylightSavingsUsed(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_DaylightSavingsStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_DaylightSavingsStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Time_DaylightSavingsEnd(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Time_DaylightSavingsEnd(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_UserDatabaseSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UserInterface_SharedPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_SharedPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_PasswordRequired(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_PasswordRequired(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_PasswordUserSelectable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_PasswordUserSelectable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_UpgradeAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_UpgradeAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_WarrantyDate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_WarrantyDate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPHelpDesk(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPHelpDesk(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPHomePage(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPHomePage(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPHelpPage(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPHelpPage(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPLogo(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPLogo(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPLogoSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPLogoSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPMailServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPMailServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ISPNewsServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ISPNewsServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_TextColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_TextColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_BackgroundColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_BackgroundColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ButtonColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ButtonColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ButtonTextColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ButtonTextColor(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_AutoUpdateServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_AutoUpdateServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_UserUpdateServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_UserUpdateServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ExampleLogin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ExampleLogin(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_ExamplePassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_ExamplePassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterface_AvailableLanguages(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UserInterface_CurrentLanguage(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterface_CurrentLanguage(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceRemoteAccess_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceRemoteAccess_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceRemoteAccess_Port(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceRemoteAccess_Port(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceRemoteAccess_SupportedProtocols(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UserInterfaceRemoteAccess_Protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceRemoteAccess_Protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceLocalDisplay_Movable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceLocalDisplay_Movable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceLocalDisplay_Resizable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceLocalDisplay_Resizable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceLocalDisplay_PosX(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceLocalDisplay_PosX(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceLocalDisplay_PosY(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceLocalDisplay_PosY(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceLocalDisplay_Width(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceLocalDisplay_Width(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceLocalDisplay_Height(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UserInterfaceLocalDisplay_Height(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UserInterfaceLocalDisplay_DisplayWidth(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UserInterfaceLocalDisplay_DisplayHeight(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_CaptivePortal_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_CaptivePortal_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_CaptivePortal_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_CaptivePortal_AllowedList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_CaptivePortal_AllowedList(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_CaptivePortal_CaptivePortalURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_CaptivePortal_CaptivePortalURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3Forwarding_DefaultConnectionService(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3Forwarding_DefaultConnectionService(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3Forwarding_ForwardNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer3ForwardingForwarding_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer3ForwardingForwarding_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_StaticRoute(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer3ForwardingForwarding_Type(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_Type(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_DestIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_DestIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_DestSubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_DestSubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_SourceIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_SourceIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_SourceSubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_SourceSubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_ForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_ForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_GatewayIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_GatewayIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_ForwardingMetric(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_ForwardingMetric(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer3ForwardingForwarding_MTU(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer3ForwardingForwarding_MTU(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2Bridging_MaxBridgeEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_MaxDBridgeEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_MaxQBridgeEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_MaxVLANEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_MaxFilterEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_MaxMarkingEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_BridgeNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_FilterNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_MarkingNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2Bridging_AvailableInterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingBridge_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridge_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridge_BridgeKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingBridge_BridgeStandard(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridge_BridgeStandard(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridge_BridgeEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridge_BridgeEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridge_BridgeStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingBridge_BridgeName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridge_BridgeName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridge_VLANID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridge_VLANID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridge_PortNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingBridge_VLANNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingBridgePort_PortEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgePort_PortEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgePort_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgePort_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgePort_PortInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgePort_PortInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgePort_PortState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingBridgePort_PVID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgePort_PVID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgePort_AcceptableFrameTypes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgePort_AcceptableFrameTypes(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgePort_IngressFiltering(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgePort_IngressFiltering(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgeVLAN_VLANEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgeVLAN_VLANEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgeVLAN_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgeVLAN_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgeVLAN_VLANName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgeVLAN_VLANName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingBridgeVLAN_VLANID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingBridgeVLAN_VLANID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_FilterKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingFilter_FilterEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_FilterEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_FilterStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingFilter_FilterBridgeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_FilterBridgeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_ExclusivityOrder(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_ExclusivityOrder(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_FilterInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_FilterInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_VLANIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_VLANIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_AdmitOnlyVLANTagged(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_AdmitOnlyVLANTagged(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_EthertypeFilterList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_EthertypeFilterList(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_EthertypeFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_EthertypeFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACAddressFilterList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACAddressFilterList(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACAddressFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACAddressFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACAddressFilterList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACAddressFilterList(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACAddressFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACAddressFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACFromVendorClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACFromVendorClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACFromVendorClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACFromVendorClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACFromVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACFromVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACFromVendorClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACFromVendorClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACFromVendorClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACFromVendorClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACFromVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACFromVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACFromClientIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACFromClientIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACFromClientIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACFromClientIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACFromClientIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACFromClientIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACFromClientIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACFromClientIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACFromUserClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACFromUserClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_SourceMACFromUserClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_SourceMACFromUserClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACFromUserClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACFromUserClassIDFilter(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingFilter_DestMACFromUserClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingFilter_DestMACFromUserClassIDFilterExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_MarkingKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingMarking_MarkingEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_MarkingEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_MarkingStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingMarking_MarkingBridgeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_MarkingBridgeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_MarkingInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_MarkingInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_VLANIDUntag(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_VLANIDUntag(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_VLANIDMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_VLANIDMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_VLANIDMarkOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_VLANIDMarkOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_EthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_EthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingMarking_EthernetPriorityOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingMarking_EthernetPriorityOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingAvailableInterface_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Layer2BridgingAvailableInterface_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Layer2BridgingAvailableInterface_AvailableInterfaceKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingAvailableInterface_InterfaceType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Layer2BridgingAvailableInterface_InterfaceReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagement_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagement_MaxQueues(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_MaxClassificationEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_ClassificationNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_MaxAppEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_AppNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_MaxFlowEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_FlowNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_MaxPolicerEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_PolicerNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_MaxQueueEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_QueueNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_QueueStatsNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagement_DefaultForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagement_DefaultForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagement_DefaultTrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagement_DefaultTrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagement_DefaultPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagement_DefaultPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagement_DefaultQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagement_DefaultQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagement_DefaultDSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagement_DefaultDSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagement_DefaultEthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagement_DefaultEthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagement_AvailableAppList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementClassification_ClassificationKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementClassification_ClassificationEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ClassificationEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ClassificationStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementClassification_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ClassificationOrder(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ClassificationOrder(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ClassInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ClassInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestIP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestIP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestIPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestIPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceIP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceIP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceIPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceIPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_Protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_Protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ProtocolExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ProtocolExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestPortRangeMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestPortRangeMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestPortExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestPortExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourcePort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourcePort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourcePortRangeMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourcePortRangeMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourcePortExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourcePortExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceMACMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceMACMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceMACExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceMACExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestMACMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestMACMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestMACExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestMACExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_Ethertype(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_Ethertype(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_EthertypeExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_EthertypeExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SSAP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SSAP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SSAPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SSAPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DSAP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DSAP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DSAPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DSAPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_LLCControl(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_LLCControl(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_LLCControlExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_LLCControlExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SNAPOUI(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SNAPOUI(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SNAPOUIExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SNAPOUIExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceClientID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceClientID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceClientIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceClientIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestClientID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestClientID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestClientIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestClientIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceUserClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceUserClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceUserClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceUserClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestUserClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestUserClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestUserClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestUserClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorSpecificInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorSpecificInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorSpecificInfoExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorSpecificInfoExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorSpecificInfoEnterprise(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorSpecificInfoEnterprise(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorSpecificInfoSubOption(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorSpecificInfoSubOption(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_SourceVendorSpecificInfoMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_SourceVendorSpecificInfoMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorSpecificInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorSpecificInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorSpecificInfoExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorSpecificInfoExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorSpecificInfoEnterprise(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorSpecificInfoEnterprise(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorSpecificInfoSubOption(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorSpecificInfoSubOption(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DestVendorSpecificInfoMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DestVendorSpecificInfoMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_TCPACK(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_TCPACK(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_TCPACKExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_TCPACKExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_IPLengthMin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_IPLengthMin(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_IPLengthMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_IPLengthMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_IPLengthExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_IPLengthExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DSCPCheck(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DSCPCheck(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DSCPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DSCPExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_DSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_DSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_EthernetPriorityCheck(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_EthernetPriorityCheck(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_EthernetPriorityExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_EthernetPriorityExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_EthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_EthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_VLANIDCheck(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_VLANIDCheck(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_VLANIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_VLANIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_OutOfBandInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_OutOfBandInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_TrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_TrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ClassPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ClassPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ClassQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ClassQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementClassification_ClassApp(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementClassification_ClassApp(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementApp_AppEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementApp_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_ProtocolIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_ProtocolIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppDefaultForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppDefaultForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppDefaultTrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppDefaultTrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppDefaultPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppDefaultPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppDefaultQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppDefaultQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppDefaultDSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppDefaultDSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementApp_AppDefaultEthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementApp_AppDefaultEthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementFlow_FlowEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementFlow_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowTypeParameters(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowTypeParameters(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_AppIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_AppIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowForwardingPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowTrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowTrafficClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowPolicer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowQueue(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowDSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowDSCPMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementFlow_FlowEthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementFlow_FlowEthernetPriorityMark(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_PolicerKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_PolicerEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_PolicerEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_PolicerStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_CommittedRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_CommittedRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_CommittedBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_CommittedBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_ExcessBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_ExcessBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_PeakRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_PeakRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_PeakBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_PeakBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_MeterType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_MeterType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_PossibleMeterTypes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_ConformingAction(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_ConformingAction(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_PartialConformingAction(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_PartialConformingAction(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_NonConformingAction(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementPolicer_NonConformingAction(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementPolicer_CountedPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_CountedBytes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_TotalCountedPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_TotalCountedBytes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_ConformingCountedPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_ConformingCountedBytes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_PartiallyConformingCountedPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_PartiallyConformingCountedBytes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_NonConformingCountedPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementPolicer_NonConformingCountedBytes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueue_QueueKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueue_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_QueueStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueue_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_TrafficClasses(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_TrafficClasses(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_QueueInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_QueueInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_QueueBufferLength(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueue_QueueWeight(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_QueueWeight(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_QueuePrecedence(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_QueuePrecedence(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_REDThreshold(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_REDThreshold(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_REDPercentage(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_REDPercentage(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_DropAlgorithm(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_DropAlgorithm(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_SchedulerAlgorithm(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_SchedulerAlgorithm(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueue_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueue_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueueStats_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueueStats_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueueStats_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueueStats_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueueStats_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueueStats_Queue(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueueStats_Queue(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueueStats_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_QueueManagementQueueStats_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_QueueManagementQueueStats_OutputPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueueStats_OutputBytes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueueStats_DroppedPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueueStats_DroppedBytes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueueStats_QueueOccupancyPackets(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_QueueManagementQueueStats_QueueOccupancyPercentage(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANConfigSecurity_ConfigPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANConfigSecurity_ConfigPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_IPPingDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_IPPingDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_IPPingDiagnostics_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_NumberOfRepetitions(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_IPPingDiagnostics_NumberOfRepetitions(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_IPPingDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_DataBlockSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_IPPingDiagnostics_DataBlockSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_IPPingDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_IPPingDiagnostics_SuccessCount(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_IPPingDiagnostics_FailureCount(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_IPPingDiagnostics_AverageResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_IPPingDiagnostics_MinimumResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_IPPingDiagnostics_MaximumResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_TraceRouteDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_NumberOfTries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_NumberOfTries(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_DataBlockSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_DataBlockSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_MaxHopCount(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_TraceRouteDiagnostics_MaxHopCount(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_TraceRouteDiagnostics_ResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_TraceRouteDiagnostics_RouteHopsNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_TraceRouteDiagnosticsRouteHops_HopHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_TraceRouteDiagnosticsRouteHops_HopHostAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_TraceRouteDiagnosticsRouteHops_HopErrorCode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_TraceRouteDiagnosticsRouteHops_HopRTTimes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadDiagnostics_DownloadURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadDiagnostics_DownloadURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadDiagnostics_EthernetPriority(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadDiagnostics_EthernetPriority(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadDiagnostics_ROMTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadDiagnostics_BOMTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadDiagnostics_EOMTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadDiagnostics_TestBytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadDiagnostics_TotalBytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadDiagnostics_TCPOpenRequestTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadDiagnostics_TCPOpenResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UploadDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UploadDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UploadDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UploadDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UploadDiagnostics_UploadURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UploadDiagnostics_UploadURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UploadDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UploadDiagnostics_DSCP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UploadDiagnostics_EthernetPriority(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UploadDiagnostics_EthernetPriority(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UploadDiagnostics_TestFileLength(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UploadDiagnostics_TestFileLength(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UploadDiagnostics_ROMTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UploadDiagnostics_BOMTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UploadDiagnostics_EOMTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UploadDiagnostics_TotalBytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UploadDiagnostics_TCPOpenRequestTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UploadDiagnostics_TCPOpenResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UDPEchoConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UDPEchoConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UDPEchoConfig_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UDPEchoConfig_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UDPEchoConfig_SourceIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UDPEchoConfig_SourceIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UDPEchoConfig_UDPPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UDPEchoConfig_UDPPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UDPEchoConfig_EchoPlusEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UDPEchoConfig_EchoPlusEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UDPEchoConfig_EchoPlusSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UDPEchoConfig_PacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UDPEchoConfig_PacketsResponded(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UDPEchoConfig_BytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UDPEchoConfig_BytesResponded(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UDPEchoConfig_TimeFirstPacketReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UDPEchoConfig_TimeLastPacketReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDevice_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDevice_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDevice_LANEthernetInterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDevice_LANUSBInterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDevice_LANWLANConfigurationNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagement_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DHCPServerConfigurable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_DHCPServerConfigurable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DHCPServerEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_DHCPServerEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DHCPRelay(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagement_MinAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_MinAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_MaxAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_MaxAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_ReservedAddresses(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_ReservedAddresses(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_SubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_SubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DomainName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_DomainName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_IPRouters(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_IPRouters(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DHCPLeaseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_DHCPLeaseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_UseAllocatedWAN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_UseAllocatedWAN(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_AssociatedConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_AssociatedConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_PassthroughLease(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_PassthroughLease(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_PassthroughMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_PassthroughMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_AllowedMACAddresses(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagement_AllowedMACAddresses(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagement_IPInterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DHCPStaticAddressNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DHCPOptionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagement_DHCPConditionalPoolNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagementIPInterface_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementIPInterface_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementIPInterface_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementIPInterface_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceSubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceSubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceAddressingType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementIPInterface_IPInterfaceAddressingType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Chaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Chaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPStaticAddress_Yiaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPStaticAddress_Yiaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPOption_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPOption_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_PoolOrder(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_PoolOrder(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SourceInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SourceInterface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_VendorClassIDMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ClientIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UserClassIDExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Chaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_Chaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ChaddrExclude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_LocallyServed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_LocallyServed(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MinAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MinAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MaxAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_MaxAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ReservedAddresses(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_ReservedAddresses(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_SubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DomainName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DomainName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_IPRouters(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_IPRouters(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPLeaseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPLeaseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UseAllocatedWAN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_UseAllocatedWAN(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_AssociatedConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_AssociatedConnection(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPServerIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPServerIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPStaticAddressNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPool_DHCPOptionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Chaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Chaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Yiaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPStaticAddress_Yiaddr(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANHostConfigManagementDHCPConditionalServingPoolDHCPOption_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANEthernetInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANEthernetInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_MACAddressControlEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANEthernetInterfaceConfig_MACAddressControlEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_MaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANEthernetInterfaceConfig_MaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfig_DuplexMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANEthernetInterfaceConfig_DuplexMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_BytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_BytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_PacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_PacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_ErrorsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_ErrorsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_UnicastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_UnicastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_DiscardPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_DiscardPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_MulticastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_MulticastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_BroadcastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_BroadcastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANEthernetInterfaceConfigStats_UnknownProtoPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANUSBInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANUSBInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_MACAddressControlEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceLANUSBInterfaceConfig_MACAddressControlEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Standard(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Type(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Rate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfig_Power(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_BytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_BytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_CellsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_CellsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_ErrorsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_ErrorsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_UnicastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_UnicastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_DiscardPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_DiscardPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_MulticastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_MulticastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_BroadcastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_BroadcastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceLANUSBInterfaceConfigStats_UnknownProtoPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_BSSID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_MaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_MaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_Channel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_Channel(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_AutoChannelEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_AutoChannelEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_SSID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_SSID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_BeaconType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_BeaconType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_MACAddressControlEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_MACAddressControlEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_Standard(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_WEPKeyIndex(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_WEPKeyIndex(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_KeyPassphrase(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_KeyPassphrase(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_WEPEncryptionLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_BasicEncryptionModes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_BasicEncryptionModes(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_BasicAuthenticationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_BasicAuthenticationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_WPAEncryptionModes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_WPAEncryptionModes(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_WPAAuthenticationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_WPAAuthenticationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_IEEE11iEncryptionModes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_IEEE11iEncryptionModes(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_IEEE11iAuthenticationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_IEEE11iAuthenticationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_PossibleChannels(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_BasicDataTransmitRates(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_BasicDataTransmitRates(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_OperationalDataTransmitRates(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_OperationalDataTransmitRates(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_PossibleDataTransmitRates(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_InsecureOOBAccessEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_InsecureOOBAccessEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_BeaconAdvertisementEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_BeaconAdvertisementEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_SSIDAdvertisementEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_SSIDAdvertisementEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_RadioEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_RadioEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_TransmitPowerSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_TransmitPower(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_TransmitPower(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_AutoRateFallBackEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_AutoRateFallBackEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_LocationDescription(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_LocationDescription(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_RegulatoryDomain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_RegulatoryDomain(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_TotalPSKFailures(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_TotalIntegrityFailures(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_ChannelsInUse(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_DeviceOperationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_DeviceOperationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_DistanceFromRoot(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_DistanceFromRoot(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_PeerBSSID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_PeerBSSID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_AuthenticationServiceMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_AuthenticationServiceMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_WMMSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_UAPSDSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_WMMEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_WMMEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_UAPSDEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfiguration_UAPSDEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfiguration_TotalBytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_TotalBytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_TotalPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_TotalPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfiguration_TotalAssociations(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationAssociatedDevice_AssociatedDeviceMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationAssociatedDevice_AssociatedDeviceIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationAssociatedDevice_AssociatedDeviceAuthenticationState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationAssociatedDevice_LastRequestedUnicastCipher(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationAssociatedDevice_LastRequestedMulticastCipher(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationAssociatedDevice_LastPMKId(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationAssociatedDevice_LastDataTransmitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWEPKey_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWEPKey_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationWEPKey_WEPKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWEPKey_WEPKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationPreSharedKey_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationPreSharedKey_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationPreSharedKey_PreSharedKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationPreSharedKey_PreSharedKey(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationPreSharedKey_KeyPassphrase(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationPreSharedKey_KeyPassphrase(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationPreSharedKey_AssociatedDeviceMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationPreSharedKey_AssociatedDeviceMACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationAPWMMParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationAPWMMParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationAPWMMParameter_AIFSN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationAPWMMParameter_AIFSN(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationAPWMMParameter_ECWMin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationAPWMMParameter_ECWMin(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationAPWMMParameter_ECWMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationAPWMMParameter_ECWMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationAPWMMParameter_TXOP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationAPWMMParameter_TXOP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationAPWMMParameter_AckPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationAPWMMParameter_AckPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationSTAWMMParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationSTAWMMParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationSTAWMMParameter_AIFSN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationSTAWMMParameter_AIFSN(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationSTAWMMParameter_ECWMin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationSTAWMMParameter_ECWMin(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationSTAWMMParameter_ECWMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationSTAWMMParameter_ECWMax(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationSTAWMMParameter_TXOP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationSTAWMMParameter_TXOP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationSTAWMMParameter_AckPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationSTAWMMParameter_AckPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationStats_ErrorsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_ErrorsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_UnicastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_UnicastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_DiscardPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_DiscardPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_MulticastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_MulticastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_BroadcastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_BroadcastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationStats_UnknownProtoPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWPS_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_DeviceName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_DevicePassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWPS_DevicePassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_UUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_Version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_ConfigMethodsSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_ConfigMethodsEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWPS_ConfigMethodsEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_SetupLockedState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_SetupLock(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWPS_SetupLock(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_ConfigurationState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_LastConfigurationError(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_RegistrarNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPS_RegistrarEstablished(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPSRegistrar_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWPSRegistrar_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationWPSRegistrar_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANDeviceWLANConfigurationWPSRegistrar_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANDeviceWLANConfigurationWPSRegistrar_UUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceWLANConfigurationWPSRegistrar_DeviceName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHosts_HostNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_IPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_AddressSource(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_LeaseTimeRemaining(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_Layer2Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_VendorClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_ClientID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_UserClassID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_HostName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_InterfaceType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANDeviceHostsHost_Active(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANInterfaces_LANEthernetInterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANInterfaces_LANUSBInterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANInterfaces_LANWLANConfigurationNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_LANInterfacesLANEthernetInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANInterfacesLANEthernetInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANInterfacesLANUSBInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANInterfacesLANUSBInterfaceConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_LANInterfacesWLANConfiguration_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_LANInterfacesWLANConfiguration_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDevice_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDevice_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDevice_WANConnectionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_EnabledForInternet(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANCommonInterfaceConfig_EnabledForInternet(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_WANAccessType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_Layer1UpstreamMaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_Layer1DownstreamMaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_PhysicalLinkStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_WANAccessProvider(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_TotalBytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_TotalBytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_TotalPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_TotalPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_MaximumActiveConnections(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfig_NumberOfActiveConnections(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfigConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANCommonInterfaceConfigConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfigConnection_ActiveConnectionDeviceContainer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANCommonInterfaceConfigConnection_ActiveConnectionServiceID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANDSLInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationRequested(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LinkEncapsulationUsed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ModulationType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_StandardsSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_StandardUsed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LineEncoding(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_AllowedProfiles(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_CurrentProfile(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_PowerManagementState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_SuccessFailureCause(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LastStateTransmittedDownstream(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LastStateTransmittedUpstream(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_UPBOKLE(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_MREFPSDds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_MREFPSDus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LIMITMASK(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_US0MASK(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_DataPath(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_InterleaveDepth(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LPATH(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_INTLVDEPTH(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_INTLVBLOCK(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ActualInterleavingDelay(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ACTINP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_INPREPORT(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_NFEC(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_RFEC(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LSYMB(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_TRELLISds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_TRELLISus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ACTSNRMODEds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ACTSNRMODEus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_VirtualNoisePSDds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_VirtualNoisePSDus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ACTUALCE(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LineNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_UpstreamCurrRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_DownstreamCurrRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_UpstreamMaxRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_DownstreamMaxRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_UpstreamNoiseMargin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_DownstreamNoiseMargin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_SNRMpbus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_SNRMpbds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_INMIATOds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_INMIATSds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_INMCCds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_INMINPEQMODEds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_UpstreamAttenuation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_DownstreamAttenuation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_UpstreamPower(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_DownstreamPower(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATURVendor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATURCountry(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATURANSIStd(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATURANSIRev(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATUCVendor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATUCCountry(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATUCANSIStd(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ATUCANSIRev(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_TotalStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_ShowtimeStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_LastShowtimeStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_CurrentDayStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfig_QuarterHourStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_ReceiveBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_TransmitBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_CellDelin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_LinkRetrain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_InitErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_LInit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_InitTimeouts(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_LossOfFraming(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_LOF(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_ErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_SeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCSeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_FECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCFECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_HECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCHECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_CRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsTotal_ATUCCRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ReceiveBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_TransmitBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_CellDelin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LinkRetrain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_InitErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LInit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_InitTimeouts(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LossOfFraming(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_LOF(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_SeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCSeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_FECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCFECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_HECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCHECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_CRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsShowtime_ATUCCRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ReceiveBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_TransmitBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_CellDelin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LinkRetrain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_InitErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LInit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_InitTimeouts(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LossOfFraming(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_LOF(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_SeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCSeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_FECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCFECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_HECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCHECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_CRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsLastShowtime_ATUCCRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ReceiveBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_TransmitBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_CellDelin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LinkRetrain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_InitErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LInit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_InitTimeouts(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LossOfFraming(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_LOF(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_SeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCSeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_FECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCFECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_HECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCHECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_CRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsCurrentDay_ATUCCRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ReceiveBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_TransmitBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_CellDelin(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LinkRetrain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_InitErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LInit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_InitTimeouts(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LossOfFraming(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_LOF(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_SeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCSeverelyErroredSecs(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_FECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCFECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_HECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCHECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_CRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigStatsQuarterHour_ATUCCRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGGds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGGus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGMTds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_HLOGMTus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_QLNGds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_QLNGus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_QLNpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_QLNpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_QLNMTds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_QLNMTus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SNRGds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SNRGus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SNRpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SNRpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SNRMTds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SNRMTus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_LATNds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_LATNus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SATNds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLInterfaceConfigTestParams_SATNus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANEthernetInterfaceConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfig_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfig_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfig_MaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANEthernetInterfaceConfig_MaxBitRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfig_DuplexMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANEthernetInterfaceConfig_DuplexMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfig_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANEthernetInterfaceConfig_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfig_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANEthernetInterfaceConfig_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfigStats_BytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfigStats_BytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfigStats_PacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANEthernetInterfaceConfigStats_PacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLConnectionManagement_ConnectionServiceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLConnectionManagementConnectionService_WANConnectionDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLConnectionManagementConnectionService_WANConnectionService(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLConnectionManagementConnectionService_DestinationAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLConnectionManagementConnectionService_LinkType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLConnectionManagementConnectionService_ConnectionType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLConnectionManagementConnectionService_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_LoopDiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANDSLDiagnostics_LoopDiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_ACTPSDds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_ACTPSDus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_ACTATPds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_ACTATPus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLINSCds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLINSCus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLINGds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLINGus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLOGGds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLOGGus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLOGpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLOGpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLOGMTds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLOGMTus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_LATNpbds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_LATNpbus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SATNds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SATNus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLINpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_HLINpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_QLNGds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_QLNGus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_QLNpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_QLNpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_QLNMTds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_QLNMTus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SNRGds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SNRGus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SNRpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SNRpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SNRMTds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_SNRMTus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_BITSpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_BITSpsus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANDSLDiagnostics_GAINSpsds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDevice_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDevice_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDevice_WANIPConnectionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDevice_WANPPPConnectionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_LinkStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_LinkType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_LinkType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_AutoConfig(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ModulationType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_DestinationAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_DestinationAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMEncapsulation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMEncapsulation(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_FCSPreserved(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_FCSPreserved(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_VCSearchList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_VCSearchList(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMAAL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMTransmittedBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMReceivedBlocks(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMQoS(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMQoS(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMPeakCellRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMPeakCellRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMMaximumBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMMaximumBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMSustainableCellRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMSustainableCellRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_AAL5CRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMCRCErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANDSLLinkConfig_ATMHECErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_NumberOfRepetitions(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_NumberOfRepetitions(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_SuccessCount(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_FailureCount(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_AverageResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_MinimumResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANATMF5LoopbackDiagnostics_MaximumResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPTMLinkConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfig_LinkStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfig_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_FramesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_FramesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_OOSNearEnd(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_OOSFarEnd(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_ErrorsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_ErrorsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_UnicastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_UnicastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_DiscardPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_DiscardPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_MulticastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_MulticastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BroadcastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_BroadcastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPTMLinkConfigStats_UnknownProtoPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANEthernetLinkConfig_EthernetLinkStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_LinkStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPPhoneNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPPhoneNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_ISPInfo(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_LinkType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_LinkType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_NumberOfRetries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_NumberOfRetries(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DelayBetweenRetries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DelayBetweenRetries(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_Fclass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DataModulationSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DataProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_DataCompression(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPOTSLinkConfig_PlusVTRCommandSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_PossibleConnectionTypes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_Uptime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_LastConnectionError(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_AutoDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_AutoDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_IdleDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_IdleDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_WarnDisconnectDelay(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_WarnDisconnectDelay(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_RSIPAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_NATEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_NATEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_AddressingType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_AddressingType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_ExternalIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_ExternalIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_SubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_SubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_DefaultGateway(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_DefaultGateway(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_DNSEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_DNSEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_DNSOverrideAllowed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_DNSOverrideAllowed(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_MaxMTUSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_MaxMTUSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_MACAddressOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_MACAddressOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionTrigger(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_ConnectionTrigger(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_RouteProtocolRx(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_RouteProtocolRx(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnection_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnection_PortMappingNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClient_SentDHCPOptionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClient_ReqDHCPOptionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientSentDHCPOption_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Order(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Order(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Tag(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionDHCPClientReqDHCPOption_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingLeaseDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingLeaseDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_RemoteHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_RemoteHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPortEndRange(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_ExternalPortEndRange(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalClient(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_InternalClient(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingDescription(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANIPConnectionPortMapping_PortMappingDescription(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetErrorsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetErrorsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetUnicastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetUnicastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetDiscardPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetDiscardPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetMulticastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetMulticastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBroadcastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetBroadcastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANIPConnectionStats_EthernetUnknownProtoPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PossibleConnectionTypes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoESessionID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_DefaultGateway(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_Uptime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_LastConnectionError(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_AutoDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_AutoDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_IdleDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_IdleDisconnectTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_WarnDisconnectDelay(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_WarnDisconnectDelay(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_RSIPAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_NATEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_NATEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPEncryptionProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPCompressionProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPAuthenticationProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_ExternalIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_ExternalIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_RemoteIPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_MaxMRUSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_MaxMRUSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_CurrentMRUSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_DNSEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_DNSEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_DNSOverrideAllowed(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_DNSOverrideAllowed(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddressOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_MACAddressOverride(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_TransportType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEACName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEACName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEServiceName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_PPPoEServiceName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionTrigger(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_ConnectionTrigger(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_RouteProtocolRx(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_RouteProtocolRx(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPLCPEcho(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PPPLCPEchoRetry(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingRate(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnection_ShapingBurstSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnection_PortMappingNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingEnabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingLeaseDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingLeaseDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_RemoteHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_RemoteHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPortEndRange(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_ExternalPortEndRange(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalClient(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_InternalClient(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingDescription(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_WANDeviceWANConnectionDeviceWANPPPConnectionPortMapping_PortMappingDescription(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBytesSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBytesReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetErrorsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetErrorsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetUnicastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetUnicastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetDiscardPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetDiscardPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetMulticastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetMulticastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBroadcastPacketsSent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetBroadcastPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_WANDeviceWANConnectionDeviceWANPPPConnectionStats_EthernetUnknownProtoPacketsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_User_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_User_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_User_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_User_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_User_RemoteAccessCapable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_User_RemoteAccessCapable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_User_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_User_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_User_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_User_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_User_Language(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_User_Language(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPMediaServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPMediaServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPMediaRenderer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPMediaRenderer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPWLANAccessPoint(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPWLANAccessPoint(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPQoSDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPQoSDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPQoSPolicyHolder(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPQoSPolicyHolder(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPIGD(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPIGD(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPDMBasicMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPDMBasicMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPDMConfigurationMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPDMConfigurationMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDevice_UPnPDMSoftwareMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_UPnPDevice_UPnPDMSoftwareMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPArchitecture(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPArchitectureMinorVer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPMediaServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPMediaRenderer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPWLANAccessPoint(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPBasicDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPQoSDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPQoSPolicyHolder(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPIGD(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPDMBasicMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPDMConfigurationMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDeviceCapabilities_UPnPDMSoftwareMgmt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscovery_RootDeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscovery_DeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscovery_ServiceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_UUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_USN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_LeaseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_Location(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_Server(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryRootDevice_LastUpdate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_UUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_USN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_LeaseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_Location(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_Server(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryDevice_LastUpdate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_USN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_LeaseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_Location(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_Server(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_LastUpdate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDiscoveryService_ParentDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescription_DeviceDescriptionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescription_DeviceInstanceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescription_ServiceInstanceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceDescription_URLBase(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceDescription_SpecVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceDescription_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_UDN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_ParentDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_DiscoveryDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_DeviceType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_FriendlyName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_DeviceCategory(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_Manufacturer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_ManufacturerOUI(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_ManufacturerURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_ModelDescription(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_ModelName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_ModelNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_ModelURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_UPC(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionDeviceInstance_PresentationURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionServiceInstance_ParentDevice(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionServiceInstance_ServiceId(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionServiceInstance_ServiceDiscovery(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionServiceInstance_ServiceType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionServiceInstance_SCPDURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionServiceInstance_ControlURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_UPnPDescriptionServiceInstance_EventSubURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_HNDDeviceClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_DeviceCapability(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_HIDDeviceClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_ImageClassProfileID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_AudioClassProfileID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_AVClassProfileID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_MediaCollectionProfileID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DLNACapabilities_PrinterClassProfileID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReader_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SmartCardReader_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SmartCardReader_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SmartCardReader_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SmartCardReader_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReader_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReader_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SmartCardReader_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SmartCardReader_ResetTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReader_DecryptionFailedCounter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReader_DecryptionFailedNoKeyCounter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReaderSmartCard_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReaderSmartCard_Type(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReaderSmartCard_Application(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReaderSmartCard_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SmartCardReaderSmartCard_ATR(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SelfTestDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SelfTestDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SelfTestDiagnostics_Results(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_NSLookupDiagnostics_DiagnosticsState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_NSLookupDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_NSLookupDiagnostics_Interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_NSLookupDiagnostics_HostName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_NSLookupDiagnostics_HostName(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_NSLookupDiagnostics_DNSServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_NSLookupDiagnostics_DNSServer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_NSLookupDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_NSLookupDiagnostics_Timeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_NSLookupDiagnostics_NumberOfRepetitions(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_NSLookupDiagnostics_NumberOfRepetitions(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_NSLookupDiagnostics_SuccessCount(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnostics_ResultNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnosticsResult_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnosticsResult_AnswerType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnosticsResult_HostNameReturned(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnosticsResult_IPAddresses(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnosticsResult_DNSServerIP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_NSLookupDiagnosticsResult_ResponseTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Firewall_Config(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_Firewall_Config(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_Firewall_Version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Firewall_LastChange(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHosts_HostNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHost_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_USBHostsHost_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_USBHostsHost_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_USBHostsHost_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_USBHostsHost_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHost_Type(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHost_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_USBHostsHost_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_USBHostsHost_PowerManagementEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_USBHostsHost_PowerManagementEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_USBHostsHost_USBVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHost_DeviceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_DeviceNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_USBVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_DeviceClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_DeviceSubClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_DeviceVersion(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_DeviceProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_ProductID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_VendorID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_Manufacturer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_ProductClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_Port(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_Rate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_Parent(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_MaxChildren(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_IsSuspended(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_IsSelfPowered(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDevice_ConfigurationNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDeviceConfiguration_ConfigurationNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDeviceConfiguration_InterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDeviceConfigurationInterface_InterfaceNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDeviceConfigurationInterface_InterfaceClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDeviceConfigurationInterface_InterfaceSubClass(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_USBHostsHostDeviceConfigurationInterface_InterfaceProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatistics_MinSampleInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatistics_MaxReportSamples(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatistics_SampleSetNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSet_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSet_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_SampleInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_SampleInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_ReportSamples(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_ReportSamples(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_TimeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_TimeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_FetchSamples(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_FetchSamples(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_ForceSample(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSet_ForceSample(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSet_ReportStartTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSet_ReportEndTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSet_SampleSeconds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSet_ParameterNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSetParameter_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSetParameter_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_Reference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSetParameter_Reference(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_SampleMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSetParameter_SampleMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_CalculationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSetParameter_CalculationMode(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_LowThreshold(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSetParameter_LowThreshold(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_HighThreshold(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_PeriodicStatisticsSampleSetParameter_HighThreshold(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_SampleSeconds(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_SuspectData(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_Values(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_PeriodicStatisticsSampleSetParameter_Failures(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadAvailabilityAnnouncement_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadAvailabilityAnnouncement_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadAvailabilityAnnouncement_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadAvailabilityAnnouncement_GroupNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadAvailabilityAnnouncementGroup_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadAvailabilityAnnouncementGroup_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadAvailabilityAnnouncementGroup_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadAvailabilityAnnouncementGroup_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadAvailabilityAnnouncementGroup_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadAvailabilityAnnouncementGroup_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadAvailabilityAnnouncementGroup_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadAvailabilityQuery_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadAvailabilityQuery_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DownloadAvailabilityQuery_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DownloadAvailabilityQuery_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DownloadAvailabilityQuery_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModules_ExecEnvNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModules_DeploymentUnitNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModules_ExecutionUnitNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecEnv_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecEnv_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecEnv_Reset(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecEnv_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecEnv_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecEnv_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_Type(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_InitialRunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecEnv_InitialRunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecEnv_RequestedRunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecEnv_RequestedRunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecEnv_CurrentRunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_InitialExecutionUnitRunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecEnv_InitialExecutionUnitRunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecEnv_Vendor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_Version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_ParentExecEnv(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_AllocatedDiskSpace(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_AvailableDiskSpace(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_AllocatedMemory(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_AvailableMemory(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_ActiveExecutionUnits(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecEnv_ProcessorRefList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_UUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_DUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesDeploymentUnit_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesDeploymentUnit_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_Resolved(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_Description(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_Vendor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_Version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_VendorLogList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_VendorConfigList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_ExecutionUnitList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesDeploymentUnit_ExecutionEnvRef(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_EUID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecutionUnit_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecutionUnit_Name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_ExecEnvLabel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_RequestedState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecutionUnit_RequestedState(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecutionUnit_ExecutionFaultCode(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_ExecutionFaultMessage(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_AutoStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecutionUnit_AutoStart(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecutionUnit_RunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SoftwareModulesExecutionUnit_RunLevel(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SoftwareModulesExecutionUnit_Vendor(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_Version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_Description(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_DiskSpaceInUse(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_MemoryInUse(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_References(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_AssociatedProcessList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_VendorLogList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_VendorConfigList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_SupportedDataModelList(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SoftwareModulesExecutionUnit_ExecutionEnvRef(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_Security_CertificateNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_SecurityCertificate_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_SecurityCertificate_LastModif(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_SerialNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_Issuer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_NotBefore(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_NotAfter(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_Subject(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_SubjectAlt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_SecurityCertificate_SignatureAlgorithm(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmt_SupportedAlarmNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmt_MaxCurrentAlarmEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmt_CurrentAlarmNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmt_HistoryEventNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmt_ExpeditedEventNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmt_QueuedEventNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtSupportedAlarm_EventType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtSupportedAlarm_ProbableCause(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtSupportedAlarm_SpecificProblem(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtSupportedAlarm_PerceivedSeverity(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtSupportedAlarm_ReportingMechanism(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FaultMgmtSupportedAlarm_ReportingMechanism(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FaultMgmtCurrentAlarm_AlarmIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_AlarmRaisedTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_AlarmChangedTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_ManagedObjectInstance(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_EventType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_ProbableCause(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_SpecificProblem(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_PerceivedSeverity(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_AdditionalText(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtCurrentAlarm_AdditionalInformation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_EventTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_AlarmIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_NotificationType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_ManagedObjectInstance(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_EventType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_ProbableCause(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_SpecificProblem(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_PerceivedSeverity(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_AdditionalText(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtHistoryEvent_AdditionalInformation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_EventTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_AlarmIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_NotificationType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_ManagedObjectInstance(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_EventType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_ProbableCause(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_SpecificProblem(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_PerceivedSeverity(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_AdditionalText(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtExpeditedEvent_AdditionalInformation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_EventTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_AlarmIdentifier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_NotificationType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_ManagedObjectInstance(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_EventType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_ProbableCause(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_SpecificProblem(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_PerceivedSeverity(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_AdditionalText(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FaultMgmtQueuedEvent_AdditionalInformation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_ScanOnBoot(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPS_ScanOnBoot(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPS_ScanPeriodically(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPS_ScanPeriodically(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPS_PeriodicInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPS_PeriodicInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPS_PeriodicTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPS_PeriodicTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPS_ContinuousGPS(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPS_ContinuousGPS(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPS_ScanTimeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPS_ScanTimeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPS_ScanStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_ErrorDetails(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_LastScanTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_LastSuccessfulScanTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_LockedLatitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_LockedLongitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_NumberOfSatellites(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPS_GPSReset(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPS_GPSReset(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSContinuousGPSStatus_CurrentFix(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_GotFix(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_TimingGood(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_Latitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_Longitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_Elevation(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_LastFixTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_LastFixDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_FirstFixTimeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSContinuousGPSStatus_FirstFixTimeout(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSContinuousGPSStatus_SatellitesTracked(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_SatelliteTrackingInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSContinuousGPSStatus_SatelliteTrackingInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSContinuousGPSStatus_ReceiverStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_LocationType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPGPSContinuousGPSStatus_LockTimeOutDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSContinuousGPSStatus_LockTimeOutDuration(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSAGPSServerConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_ServerURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSAGPSServerConfig_ServerURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_ServerPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSAGPSServerConfig_ServerPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSAGPSServerConfig_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSAGPSServerConfig_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_ReferenceLatitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSAGPSServerConfig_ReferenceLatitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_ReferenceLongitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPGPSAGPSServerConfig_ReferenceLongitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPGPSAGPSServerConfig_ServerInUse(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnel_CryptoProfileNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnel_IKESANumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnel_ChildSANumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnel_MaxVirtualInterfaces(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnel_VirtualInterfaceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnel_UseForCWMP(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnel_UseForCWMP(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnel_MaxChildSAPerIKE(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnel_MaxIKESessions(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelCryptoProfile_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_AuthMethod(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_AuthMethod(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_MaxChildSA(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_MaxChildSA(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IKEEncrypt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IKEEncrypt(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IKEPRF(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IKEPRF(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IKEIntegrity(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IKEIntegrity(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IKEDH(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IKEDH(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_ESPEncrypt(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_ESPEncrypt(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_ESPIntegrity(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_ESPIntegrity(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IPsecWindowSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IPsecWindowSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IKERekeyLifetime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IKERekeyLifetime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IPsecRekeyLifetimeByte(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IPsecRekeyLifetimeByte(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_IPsecRekeyLifetimeTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_IPsecRekeyLifetimeTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_DPDTimer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_DPDTimer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_NATTKeepaliveTimer(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_NATTKeepaliveTimer(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_SecMaxFragSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_SecMaxFragSize(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelCryptoProfile_SecDFBit(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelCryptoProfile_SecDFBit(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelIKESA_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_PeerAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_CreationTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_IPAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_SubnetMask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_DNSServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_DHCPServers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_IntegrityErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_OtherErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelIKESA_AuthErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelChildSA_ParentID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelChildSA_SPI(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelChildSA_DirectionOutbound(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelChildSA_CreationTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelChildSA_Traffic(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelChildSA_IntegrityErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelChildSA_ReplayErrors(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPTunnelVirtualInterface_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelVirtualInterface_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelVirtualInterface_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelVirtualInterface_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelVirtualInterface_CryptoProfile(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelVirtualInterface_CryptoProfile(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPTunnelVirtualInterface_DSCPMarkPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPTunnelVirtualInterface_DSCPMarkPolicy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPPerfMgmt_ConfigNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPPerfMgmtConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPPerfMgmtConfig_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPPerfMgmtConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPPerfMgmtConfig_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPPerfMgmtConfig_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPPerfMgmtConfig_URL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPPerfMgmtConfig_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPPerfMgmtConfig_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPPerfMgmtConfig_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPPerfMgmtConfig_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPPerfMgmtConfig_PeriodicUploadInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPPerfMgmtConfig_PeriodicUploadInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPPerfMgmtConfig_PeriodicUploadTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPPerfMgmtConfig_PeriodicUploadTime(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatform_Version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatform_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatform_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatform_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatform_MaxNumberOfApplications(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatform_CurrentNumberofApplications(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_PresenceApplicationSupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_FemtoAwarenessAPISupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_SMSAPISupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_SubscribeToNotificationsOfSMSSentToApplicationSupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_QuerySMSDeliveryStatusSupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_MMSAPISupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_QueryMMSDeliveryStatusSupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_SubscribeToNotificationsOfMMSSentToApplicationSupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_TerminalLocationAPISupport(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_AuthenticationMethodsSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_AccessLevelsSupported(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_SendSMSTargetAddressType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformCapabilities_SendMMSTargetAddressType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformControl_AuthenticationMethod(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControl_AuthenticationMethod(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControl_TunnelInst(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControl_TunnelInst(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_FemtozoneID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_FemtozoneID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_NotificationsUserIdentifierMSISDN(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_NotificationsUserIdentifierMSISDN(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_SubscribeToNotificationsResponseCallbackData(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_SubscribeToNotificationsResponseCallbackData(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlFemtoAwareness_QueryFemtocellResponseTimezone(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlFemtoAwareness_QueryFemtocellResponseTimezone(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlSMS_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlSMS_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlSMS_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlSMS_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlSMS_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlSMS_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlSMS_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlSMS_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlSMS_MinSendSMSTimeInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlSMS_MinSendSMSTimeInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlSMS_EnableQuerySMSDeliveryStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlSMS_EnableQuerySMSDeliveryStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlSMS_EnableSubscribeToNotificationsOfMessageSentToApplication(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlSMS_EnableSubscribeToNotificationsOfMessageSentToApplication(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlMMS_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlMMS_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlMMS_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlMMS_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlMMS_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlMMS_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlMMS_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlMMS_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlMMS_MinSendMMSTimeInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlMMS_MinSendMMSTimeInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlMMS_EnableQueryMMSDeliveryStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlMMS_EnableQueryMMSDeliveryStatus(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlMMS_EnableSubscribeToNotificationsOfMessageSentToApplication(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlMMS_EnableSubscribeToNotificationsOfMessageSentToApplication(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_APIEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_QueueEnable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_Queueing(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_MaxAPIUsersNumber(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseLongitudeLatitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseLongitudeLatitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAltitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseAltitude(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseTimestamp(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformControlTerminalLocation_QueryMobileLocationResponseTimestamp(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformMonitoring_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformMonitoring_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformMonitoring_MonitoringInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_FAPApplicationPlatformMonitoring_MonitoringInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_FAPApplicationPlatformMonitoring_AuthenticationRequestsReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoring_AuthenticationRequestsRejected(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringFemtoAwareness_APIAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringFemtoAwareness_APIUsers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueNum(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringFemtoAwareness_QueueDiscarded(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringSMS_APIAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringSMS_APIUsers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringSMS_QueueState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringSMS_QueueNum(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringSMS_QueueReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringSMS_QueueDiscarded(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringMMS_APIAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringMMS_APIUsers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringMMS_QueueState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringMMS_QueueNum(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringMMS_QueueReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringMMS_QueueDiscarded(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringTerminalLocation_APIAvailable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringTerminalLocation_APIUsers(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringTerminalLocation_QueueState(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringTerminalLocation_QueueNum(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringTerminalLocation_QueueReceived(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_FAPApplicationPlatformMonitoringTerminalLocation_QueueDiscarded(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkData_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkData_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkData_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkData_MinReportingInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkData_Protocols(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkData_EncodingTypes(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkData_MaxNumberOfProfiles(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkData_MaxNumberOfParameterReferences(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkData_ProfileNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkDataProfile_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_Protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_Protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_EncodingType(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_EncodingType(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_ReportingInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_ReportingInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_TimeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_TimeReference(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_StreamingHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_StreamingHost(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_StreamingPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_StreamingPort(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_StreamingSessionID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_StreamingSessionID(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_FileTransferURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_FileTransferURL(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_FileTransferUsername(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_FileTransferUsername(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_FileTransferPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_FileTransferPassword(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_ControlFileFormat(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfile_ControlFileFormat(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_BulkDataProfile_ParameterNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_BulkDataProfileParameter_Reference(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_BulkDataProfileParameter_Reference(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DNSSD_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_DNSSD_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_DNSSD_ServiceNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_InstanceName(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_ApplicationProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_TransportProtocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_Domain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_Port(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_Target(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_LastUpdate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_Host(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_TimeToLive(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_Priority(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_Weight(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDService_TextRecordNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDServiceTextRecord_Key(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_DNSSDServiceTextRecord_Value(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPP_ConnectionNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnection_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_Username(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_Password(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_Domain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_Domain(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_Resource(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_Resource(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_JabberID(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnection_Status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnection_LastChangeDate(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnection_ServerConnectAlgorithm(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_ServerConnectAlgorithm(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_KeepAliveInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_KeepAliveInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_ServerConnectAttempts(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_ServerConnectAttempts(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_ServerRetryInitialInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_ServerRetryInitialInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_ServerRetryIntervalMultiplier(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_ServerRetryIntervalMultiplier(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_ServerRetryMaxInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_ServerRetryMaxInterval(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_UseTLS(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnection_UseTLS(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnection_TLSEstablished(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnection_ServerNumberOfEntries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnectionServer_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnectionServer_Enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnectionServer_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnectionServer_Alias(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnectionServer_Priority(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnectionServer_Priority(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnectionServer_Weight(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnectionServer_Weight(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnectionServer_ServerAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnectionServer_ServerAddress(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnectionServer_Port(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int set_XMPPConnectionServer_Port(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            // TODO
            break;
    }
    return 0;
}

int get_XMPPConnectionStats_ReceivedMessages(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnectionStats_TransmittedMessages(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnectionStats_ReceivedErrorMessages(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_XMPPConnectionStats_TransmittedErrorMessages(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}
