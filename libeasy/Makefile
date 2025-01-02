#
# Copyright (C) 2020-2023 Iopsys
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libeasy
PKG_VERSION:=7.4.3

LOCAL_DEV=0
ifneq ($(LOCAL_DEV),1)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=ba80dcc51056772c906cac8022a2537b74959e6a
PKG_SOURCE_URL:=https://dev.iopsys.eu/iopsys/libeasy.git
PKG_MAINTAINER:=Anjan Chanda <anjan.chanda@iopsys.eu>
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)_$(PKG_SOURCE_VERSION).tar.xz
PKG_MIRROR_HASH:=skip
endif

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_LICENSE:=LGPL-2.1-only
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/usr/include \
	-I$(STAGING_DIR)/usr/include/openssl \
	-I$(STAGING_DIR)/usr/include/libnl3

ifeq ($(LOCAL_DEV),1)
define Build/Prepare
	rsync -r --exclude=.* ~/git/libeasy/ $(PKG_BUILD_DIR)/
endef
endif

MAKE_FLAGS += \
	CFLAGS="$(TARGET_CFLAGS) -Wall"

define Package/libeasy
  SECTION:=libs
  CATEGORY:=Libraries
  SUBMENU:=IOPSYS HAL libs
  MENU:=1
  TITLE:= Common helper library (libeasy)
  DEPENDS+=+libnl +libnl-route +libopenssl
endef

define Package/libeasy/description
  Library provides common utility functions
endef

define Build/InstallDev/libeasy
	$(INSTALL_DIR) $(1)/usr/include/easy
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/easy.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/event.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/utils.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/bufutil.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/cryptutil.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/ecc_cryptutil.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/if_utils.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/debug.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/hlist.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/timestamp.h $(1)/usr/include/easy/
	$(CP) $(PKG_BUILD_DIR)/libeasy*.so* $(1)/usr/lib/
endef

define Build/InstallDev
	$(call Build/InstallDev/libeasy,$(1),$(2))
endef

define Package/libeasy/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libeasy*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libeasy))
