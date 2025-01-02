/*
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	Copyright (C) 2011 Luka Perkov <freecwmp@lukaperkov.net>
 */

#ifndef _FREECWMP_MESSAGES_H__
#define _FREECWMP_MESSAGES_H__

#define CWMP_LWNOTIFICATION_MESSAGE                                                  \
    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"                                     \
    "<Notification "                                                                 \
    "xmlns=\"urn:broadband-forum-org:cwmp:lwnotif-1-0\" "                            \
    "xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" "                                 \
    "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "                       \
    "xsi:schemaLocation=\"urn:broadband-forum-org:cwmp:lwnotif-1-0 "                 \
    "http://www.broadband-forum.org/cwmp/cwmp-UDPLightweightNotification-1-0.xsd\">" \
    "<TS/>"                                                                          \
    "<UN/>"                                                                          \
    "<CN/>"                                                                          \
    "<OUI/>"                                                                         \
    "<ProductClass/>"                                                                \
    "<SerialNumber/>"                                                                \
    "</Notification>"
#define CWMP_INFORM_MESSAGE                                                 \
    "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>"          \
    "<soap_env:Envelope "                                                   \
    "xmlns:soap_env=\"http://schemas.xmlsoap.org/soap/envelope/\" "         \
    "xmlns:soap_enc=\"http://schemas.xmlsoap.org/soap/encoding/\" "         \
    "xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" "                       \
    "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" >"             \
    "<soap_env:Header>"                                                     \
    "<cwmp:ID soap_env:mustUnderstand=\"1\"/>"                              \
    "</soap_env:Header>"                                                    \
    "<soap_env:Body>"                                                       \
    "<cwmp:Inform>"                                                         \
    "<DeviceId>"                                                            \
    "<Manufacturer/>"                                                       \
    "<OUI/>"                                                                \
    "<ProductClass/>"                                                       \
    "<SerialNumber/>"                                                       \
    "</DeviceId>"                                                           \
    "<Event soap_enc:arrayType=\"cwmp:EventStruct[0]\" />"                  \
    "<MaxEnvelopes>1</MaxEnvelopes>"                                        \
    "<CurrentTime/>"                                                        \
    "<RetryCount/>"                                                         \
    "<ParameterList soap_enc:arrayType=\"cwmp:ParameterValueStruct[0]\" />" \
    "</cwmp:Inform>"                                                        \
    "</soap_env:Body>"                                                      \
    "</soap_env:Envelope>"

#define CWMP_RESPONSE_MESSAGE                                       \
    "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>"  \
    "<soap_env:Envelope "                                           \
    "xmlns:soap_env=\"http://schemas.xmlsoap.org/soap/envelope/\" " \
    "xmlns:soap_enc=\"http://schemas.xmlsoap.org/soap/encoding/\" " \
    "xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" "               \
    "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"      \
    "<soap_env:Header>"                                             \
    "<cwmp:ID soap_env:mustUnderstand=\"1\"/>"                      \
    "</soap_env:Header>"                                            \
    "<soap_env:Body/>"                                              \
    "</soap_env:Envelope>"

#endif
