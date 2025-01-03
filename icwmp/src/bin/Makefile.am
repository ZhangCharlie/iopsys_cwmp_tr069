CWMP_VERSION = 3.0.0
LIB_DATAMODEL_VERSION = 3:0:0

lib_LTLIBRARIES = libdatamodel.la

libdatamodel_la_SOURCES =	\
	../md5.c				\
	../dm/dmcwmp.c			\
	../dm/dmentry.c			\
	../dm/dmmem.c			\
	../dm/dmubus.c			\
	../dm/dmjson.c			\
	../dm/dmuci.c			\
	../dm/dmcommon.c		\
	../dm/wepkey.c			\
	../dm/dmtree/common/deviceinfo.c				\
	../dm/dmtree/common/managementserver.c			\
	../dm/dmtree/common/softwaremodules.c			\
	../dm/dmtree/common/times.c						\
	../dm/dmtree/common/upnp.c						\
	../dm/dmtree/common/voice_services.c 			\
	../dm/dmtree/common/x_iopsys_eu_ice.c 			\
	../dm/dmtree/common/x_iopsys_eu_igmp.c 			\
	../dm/dmtree/common/x_iopsys_eu_ipacccfg.c		\
	../dm/dmtree/common/x_iopsys_eu_logincfg.c		\
	../dm/dmtree/common/x_iopsys_eu_power_mgmt.c	\
	../dm/dmtree/common/x_iopsys_eu_syslog.c			\
	../dm/dmtree/common/x_iopsys_eu_dropbear.c		\
	../dm/dmtree/common/x_iopsys_eu_owsd.c			\
	../dm/dmtree/common/x_iopsys_eu_buttons.c		\
	../dm/dmtree/common/x_iopsys_eu_wifilife.c		\
	../dm/dmtree/common/root.c

if XMPP_ENABLE
libdatamodel_la_SOURCES += 							\
	../dm/dmtree/common/xmpp.c
endif

libdatamodel_la_SOURCES += 							\
	../dm/dmtree/tr098/lan_interfaces.c				\
	../dm/dmtree/tr098/landevice.c					\
	../dm/dmtree/tr098/layer_2_bridging.c			\
	../dm/dmtree/tr098/wandevice.c					\
	../dm/dmtree/tr098/x_iopsys_eu_wifi.c			\
	../dm/dmtree/tr098/ippingdiagnostics.c			\
	../dm/dmtree/tr098/downloaddiagnostic.c			\
	../dm/dmtree/tr098/uploaddiagnostic.c			\
	../dm/dmtree/tr098/deviceconfig.c				\
	../dm/dmtree/tr098/layer_3_forwarding.c

libdatamodel_la_SOURCES +=							\
	../dm/dmtree/tr181/wifi.c						\
	../dm/dmtree/tr181/ethernet.c					\
	../dm/dmtree/tr181/wan.c						\
	../dm/dmtree/tr181/bridging.c					\
	../dm/dmtree/tr181/hosts.c						\
	../dm/dmtree/tr181/dhcp.c						\
	../dm/dmtree/tr181/ip.c							\
	../dm/dmtree/tr181/ppp.c						\
	../dm/dmtree/tr181/nat.c						\
	../dm/dmtree/tr181/routing.c					\
	../dm/dmtree/tr181/userinterface.c				\
	../dm/dmtree/tr181/firewall.c					\
	../dm/dmtree/tr181/dns.c						\
	../dm/dmtree/tr181/users.c						\
	../dm/dmtree/tr181/dhcpv6.c						\
	../dm/dmtree/tr181/dsl.c						\
	../dm/dmtree/tr181/interfacestack.c					\
        ../dm/dmtree/tr181/qos.c

if UPNP_TR064
libdatamodel_la_SOURCES +=							\
	../dm/dmtree/upnp/upnp_deviceinfo.c	            \
	../dm/dmtree/upnp/upnp_configuration.c			\
	../dm/dmtree/upnp/upnp_monitoring.c				\
	../dm/dmtree/upnp/upnp_common.c
endif

libdatamodel_la_CFLAGS =	\
	$(AM_CFLAGS)			\
	$(LIBUCI_CFLAGS)		\
	$(LIBUBOX_CFLAGS)		\
	$(LIBUBUS_CFLAGS)

libdatamodel_la_LDFLAGS = 	\
	$(AM_LDFLAGS)			\
	$(LIBUCI_LDFLAGS)		\
	$(LIBUBOX_LDFLAGS)		\
	$(LIBUBUS_LDFLAGS)		\
	-share					\
	-version-info $(LIB_DATAMODEL_VERSION)

libdatamodel_la_LIBADD =	\
	$(AM_LIBS)				\
	$(LIBUCI_LIBS)			\
	$(LIBUBOX_LIBS)			\
	$(LIBUBUS_LIBS)			\
	$(LIBJSON_LIBS)			\
	$(LBLOBMSG_LIBS)

libdatamodel_la_CFLAGS+=-DCWMP_VERSION=\"$(CWMP_VERSION)\"
libdatamodel_la_LDFLAGS+=-DCWMP_VERSION=\"$(CWMP_VERSION)\"

libdatamodel_la_CFLAGS+=-I../inc/
libdatamodel_la_CFLAGS+=-I../dm/
libdatamodel_la_CFLAGS+=-I../dm/dmtree/
libdatamodel_la_CFLAGS+=-I../dm/dmtree/common
libdatamodel_la_CFLAGS+=-I../dm/dmtree/tr098
libdatamodel_la_CFLAGS+=-I../dm/dmtree/tr181
libdatamodel_la_CFLAGS+=-I../dm/dmtree/upnp

bin_PROGRAMS = icwmpd icwmp_stund

icwmp_stund_SOURCES =		    \
	../stun/stun.c			\
	../stun/stun.h			\
	../stun/log.c			\
	../stun/log.h			\
	../stun/ubus.c			\
	../stun/ubus.h			\
	../stun/config.c 		\
	../stun/config.h

icwmp_stund_CFLAGS =			\
	$(AM_CFLAGS)				\
	$(LIBUCI_CFLAGS)			\
	$(LIBUBUS_CFLAGS)			\
	$(LIBUBOX_CFLAGS)

icwmp_stund_LDFLAGS =			\
	$(AM_LDFLAGS)				\
	$(LIBUCI_LDFLAGS)			\
	$(LIBUBUS_LDFLAGS)			\
	$(LIBUBOX_LDFLAGS)			\
	$(LIBJSONC_LDFLAGS)

icwmp_stund_LDADD =				\
	$(AM_LIBS)					\
	$(LIBUCI_LIBS)				\
	$(LIBUBOX_LIBS)				\
	$(LIBJSON_LIBS)			    \
	$(LBLOBMSG_LIBS)			\
	$(LIBUBUS_LIBS)				\
	$(LCRYPTO_LIBS)

icwmpd_SOURCES =			\
	../backupSession.c		\
	../config.c				\
	../cwmp.c				\
	../digestauth.c			\
	../event.c				\
	../external.c			\
	../http.c				\
	../jshn.c				\
	../log.c				\
	../md5.c				\
	../netlink.c			\
	../time.c				\
	../ubus.c				\
	../xml.c				\
	../diagnostic.c			\
	../zlib.c

icwmpd_CFLAGS =			\
	$(AM_CFLAGS)		\
	$(LIBUCI_CFLAGS)	\
	$(LIBUBOX_CFLAGS)	\
	$(LIBUBUS_CFLAGS)	\
	$(MICROXML_CFLAGS)	\
	$(LIBCURL_CFLAGS)	\
	$(LIBZSTREAM_CFLAGS)

icwmpd_LDFLAGS =		\
	$(AM_LDFLAGS)		\
	$(LIBUCI_LDFLAGS)	\
	$(LIBUBOX_LDFLAGS)	\
	$(LIBUBUS_LDFLAGS)	\
	$(MICROXML_LDFLAGS)	\
	$(LIBCURL_LDFLAGS)	\
	$(LIBZSTREAM_LDFLAGS)

icwmpd_LDADD =			\
	$(AM_LIBS)			\
	$(LIBUCI_LIBS)		\
	$(LIBUBOX_LIBS)		\
	$(LIBUBUS_LIBS)		\
	$(MICROXML_LIBS)	\
	$(LIBCURL_LIBS)		\
	$(LIBTRACE_LIBS)	\
	$(LIBZSTREAM_LIBS)	\
	$(LIBPTHREAD_LIBS)	\
	$(LIBSTROPHE_LIBS)	\
	$(LCRYPTO_LIBS)		\
	$(LSSL_LIBS)		\
	$(LIBJSON_LIBS)		\
	$(LBLOBMSG_LIBS)	\
	$(LIBZ_LIBS)		\
	$(LIBM_LIBS)		\
	-ldatamodel

icwmpd_CFLAGS+=-DCWMP_VERSION=\"$(CWMP_VERSION)\"
icwmpd_LDFLAGS+=-DCWMP_VERSION=\"$(CWMP_VERSION)\"

CWMP_BKP_FILE=/etc/icwmpd/.icwmpd_backup_session.xml
icwmpd_CFLAGS+=-DCWMP_BKP_FILE=\"$(CWMP_BKP_FILE)\"
icwmpd_CFLAGS+=-I../inc
icwmpd_CFLAGS+=-I../dm/
icwmpd_CFLAGS+=-I../dm/dmtree/
icwmpd_CFLAGS+=-I../dm/dmtree/common
icwmpd_CFLAGS+=-I../dm/dmtree/tr098
icwmpd_CFLAGS+=-I../dm/dmtree/tr181
icwmpd_CFLAGS+=-I../dm/dmtree/upnp
icwmpd_CFLAGS+=-I../stun/
icwmpd_CFLAGS+=-I../stun/src/

bin_PROGRAMS += icwmp_udpechoserverd

icwmp_udpechoserverd_SOURCES =		    \
	../udpechoserver/udpechoserver.c			\
	../udpechoserver/udpechoserver.h			\
	../udpechoserver/udpechoserveruci.c			\
	../udpechoserver/udpechoserveruci.h			\
	../udpechoserver/udpechoserverlog.c			\
	../udpechoserver/udpechoserverlog.h

icwmp_udpechoserverd_CFLAGS =			\
	$(AM_CFLAGS)				\
	$(LIBUCI_CFLAGS)

icwmp_udpechoserverd_LDFLAGS =			\
	$(AM_LDFLAGS)				\
	$(LIBUCI_LDFLAGS)

icwmp_udpechoserverd_LDADD =				\
	$(AM_LIBS)					\
	$(LIBUCI_LIBS)

bin_PROGRAMS += icwmp_twampd

icwmp_twampd_SOURCES =		    \
	../twamp/twamp.c			\
	../twamp/twamp.h			\
	../twamp/twamptimestamp.c	\
	../twamp/twampuci.c			\
	../twamp/twampuci.h			\
	../twamp/twamplog.c			\
	../twamp/twamplog.h

icwmp_twampd_CFLAGS =			\
	$(AM_CFLAGS)				\
	$(LIBUCI_CFLAGS)

icwmp_twampd_LDFLAGS =			\
	$(AM_LDFLAGS)				\
	$(LIBUCI_LDFLAGS)

icwmp_twampd_LDADD =				\
	$(AM_LIBS)					\
	$(LIBUCI_LIBS)

if XMPP_ENABLE
bin_PROGRAMS += icwmp_xmppd

icwmp_xmppd_SOURCES =		    \
	../xmpp/xmpp.c				\
	../xmpp/xmpp.h				\
	../xmpp/xmppuci.c			\
	../xmpp/xmppuci.h			\
	../xmpp/xmppcmd.c			\
	../xmpp/xmppcmd.h			\
	../xmpp/xmpplog.c			\
	../xmpp/xmpplog.h			\
	../xmpp/xmppconfig.c		\
	../xmpp/xmppconfig.h

icwmp_xmppd_CFLAGS =			\
	$(AM_CFLAGS)				\
	$(LIBUCI_CFLAGS)			\
	$(LIBUBOX_CFLAGS)

icwmp_xmppd_LDFLAGS =			\
	$(AM_LDFLAGS)				\
	$(LIBUCI_LDFLAGS)			\
	$(LIBUBOX_LDFLAGS)

icwmp_xmppd_LDADD =				\
	$(AM_LIBS)					\
	$(LIBUCI_LIBS)				\
	$(LIBUBOX_LIBS)				\
	$(LIBSTROPHE_LIBS)
endif
