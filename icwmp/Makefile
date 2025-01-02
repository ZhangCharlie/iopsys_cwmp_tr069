#
# Copyright (C) 2020-2023 IOPSYS Software Solutions AB
#
# This is free software, licensed under the BSD-3-Clause
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=icwmp
PKG_VERSION:=4.3

LOCAL_DEV:=1
ifneq ($(LOCAL_DEV),1)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://dev.iopsys.eu/bbf/icwmp.git
PKG_SOURCE_VERSION:=d1caec840201824b590a4aa98766d0aa94a409b0
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_MIRROR_HASH:=skip
endif

PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=LICENSE



PKG_FIXUP:=autoreconf
PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
#include $(INCLUDE_DIR)/cmake.mk
#include ../bbfdm/bbfdm.mk

define Package/icwmp
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=TRx69
  TITLE:=TR069 CWMP client
  DEPENDS:=+libuci +libubox +libblobmsg-json +libubus +libjson-c +libcurl +libmicroxml +libuuid +libopenssl  +libstrophe +libtrace
#+libxml2
endef

ifeq ($(LOCAL_DEV),1)
define Build/Prepare
	$(CP) -rf src/* $(PKG_BUILD_DIR)/
endef
endif

TARGET_CFLAGS += -DCUSTOM_PREFIX=""
#TARGET_CFLAGS += -DHTTP_CURL
#TARGET_CFLAGS += -DWITH_CWMP_DEBUG
#TARGET_CFLAGS += -DWITH_DEV_DEBUG

CONFIGURE_ARGS += \
	--enable-shared \
	--enable-http=curl \
	--enable-debug \
	--enable-devel \
	--enable-xmpp


MAKE_FLAGS += \
	CFLAGS="$(TARGET_CFLAGS)"

define Package/icwmp/install
	$(INSTALL_DIR) $(1)/etc/icwmpd
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_DIR) $(1)/lib/upgrade/keep.d
	$(INSTALL_DIR) $(1)/etc/udhcpc.user.d
	$(INSTALL_DIR) $(1)/lib/db/config
	#$(INSTALL_DIR) $(1)/etc/icwmpd/plugins
	
	#icwmpd
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/icwmpd $(1)/usr/sbin/icwmpd
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/libdatamodel.so* $(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/sbin/icwmp
	$(CP) $(PKG_BUILD_DIR)/scripts/* $(1)/usr/sbin/icwmp
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/config/cwmp $(1)/etc/config/cwmp
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/config/firewall.cwmp $(1)/etc/firewall.cwmp

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/init/icwmpd.init $(1)/etc/init.d/icwmpd
	#$(INSTALL_BIN) $(PKG_BUILD_DIR)/uci-defaults/85-cwmp-set-userid $(1)/etc/uci-defaults/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/uci-defaults/90-cwmpfirewall $(1)/etc/uci-defaults/
	#$(INSTALL_BIN) ./files/etc/uci-defaults/95-set-random-inform-time $(1)/etc/uci-defaults/
	$(INSTALL_DATA) ./files/lib/upgrade/keep.d/icwmp $(1)/lib/upgrade/keep.d/icwmp
	#$(INSTALL_BIN) ./files/etc/udhcpc.user.d/udhcpc_icwmp_opt125.user $(1)/etc/udhcpc.user.d/udhcpc_icwmp_opt125.user
	#$(INSTALL_BIN) ./files/etc/udhcpc.user.d/udhcpc_icwmp_opt43.user $(1)/etc/udhcpc.user.d/udhcpc_icwmp_opt43.user
	
	#stun
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/icwmp_stund $(1)/usr/sbin/icwmp_stund
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/init/icwmp_stund $(1)/etc/init.d/icwmp_stund
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/config/cwmp_stun $(1)/etc/config/cwmp_stun

	#xmpp
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/icwmp_xmppd $(1)/usr/sbin/icwmp_xmppd
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/init/icwmp_xmppd $(1)/etc/init.d/icwmp_xmppd
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/config/cwmp_xmpp $(1)/etc/config/cwmp_xmpp

	#udpechoserver
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/icwmp_udpechoserverd $(1)/usr/sbin/icwmp_udpechoserverd
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/init/icwmp_udpechoserverd $(1)/etc/init.d/icwmp_udpechoserverd
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/config/cwmp_udpechoserver $(1)/etc/config/cwmp_udpechoserver
	
	#twamp
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/icwmp_twampd $(1)/usr/sbin/icwmp_twampd
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/init/icwmp_twampd $(1)/etc/init.d/icwmp_twampd
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/config/cwmp_twamp $(1)/etc/config/cwmp_twamp
	

endef

$(eval $(call BuildPackage,icwmp))
