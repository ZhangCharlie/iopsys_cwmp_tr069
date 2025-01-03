/*
 *      This program is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      Copyright (C) 2019 iopsys Software Solutions AB
 *
 *      Author: Omar Kallel <omar.kallel@pivasoftware.com>
 */

#include "dmcwmp.h"
#include "firewall.h"
#include "dmcommon.h"
#include "dmentry.h"

DMOBJ tFirewallObj[] = {
    {"Level", &DMREAD, NULL, NULL, NULL, browseLevelInst, NULL, NULL, NULL, tLevelParams, NULL}, {"Chain", &DMREAD, NULL, NULL, NULL, browseChainInst, NULL, NULL, tChainObj, tChainParams, NULL}, {0}};

DMLEAF tFirewallParams[] = {{"Enable", &DMWRITE, DMT_BOOL, get_firewall_enable, set_firewall_enable, NULL, NULL},
                            {"Config", &DMWRITE, DMT_STRING, get_firewall_config, set_firewall_config, NULL, NULL},
                            {"AdvancedLevel", &DMWRITE, DMT_STRING, get_firewall_advanced_level, set_firewall_advanced_level, NULL, NULL},
                            {"LevelNumberOfEntries", &DMREAD, DMT_UNINT, get_firewall_level_number_of_entries, NULL, NULL, NULL},
                            {"ChainNumberOfEntries", &DMREAD, DMT_UNINT, get_firewall_chain_number_of_entries, NULL, NULL, NULL},
                            {0}};

DMLEAF tLevelParams[] = {{"Name", &DMWRITE, DMT_STRING, get_level_name, set_level_name, NULL, NULL},
                         {"Description", &DMWRITE, DMT_STRING, get_level_description, set_level_description, NULL, NULL},
                         {"Chain", &DMREAD, DMT_STRING, get_level_chain, NULL, NULL, NULL},
                         {"PortMappingEnabled", &DMWRITE, DMT_BOOL, get_level_port_mapping_enabled, set_level_port_mapping_enabled, NULL, NULL},
                         {"DefaultLogPolicy", &DMWRITE, DMT_BOOL, get_level_default_log_policy, set_level_default_log_policy, NULL, NULL},
                         {0}};

DMLEAF tChainParams[] = {{"Enable", &DMWRITE, DMT_BOOL, get_chain_enable, set_chain_enable, NULL, NULL},
                         {"Name", &DMWRITE, DMT_STRING, get_chain_name, set_chain_name, NULL, NULL},
                         {"Creator", &DMREAD, DMT_STRING, get_chain_creator, NULL, NULL, NULL},
                         {"RuleNumberOfEntries", &DMREAD, DMT_UNINT, get_chain_rule_number_of_entries, NULL, NULL, NULL},
                         {0}};

DMOBJ tChainObj[] = {{"Rule", &DMWRITE, add_firewall_rule, delete_firewall_rule, NULL, browseRuleInst, NULL, NULL, tRuleObj, tRuleParams, NULL}, {0}};

DMOBJ tRuleObj[] = {{CUSTOM_PREFIX "TimeSpan", &DMREAD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, tTimeSpanParams, NULL}, {0}};

DMLEAF tRuleParams[] = {{"Enable", &DMWRITE, DMT_BOOL, get_rule_enable, set_rule_enable, NULL, NULL},
                        {"Status", &DMREAD, DMT_STRING, get_rule_status, NULL, NULL, NULL},
                        {"Order", &DMWRITE, DMT_UNINT, get_rule_order, set_rule_order, NULL, NULL},
                        {"Description", &DMWRITE, DMT_STRING, get_rule_description, set_rule_description, NULL, NULL},
                        {"Target", &DMWRITE, DMT_STRING, get_rule_target, set_rule_target, NULL, NULL},
                        {"TargetChain", &DMWRITE, DMT_STRING, get_rule_target_chain, set_rule_target_chain, NULL, NULL},
                        {"SourceInterface", &DMWRITE, DMT_STRING, get_rule_source_interface, set_rule_source_interface, NULL, NULL},
                        {"DestInterface", &DMWRITE, DMT_STRING, get_rule_dest_interface, set_rule_dest_interface, NULL, NULL},
                        {"IPVersion", &DMWRITE, DMT_INT, get_rule_i_p_version, set_rule_i_p_version, NULL, NULL},
                        {"DestIp", &DMWRITE, DMT_STRING, get_rule_dest_ip, set_rule_dest_ip, NULL, NULL},
                        {"DestMask", &DMWRITE, DMT_STRING, get_rule_dest_mask, set_rule_dest_mask, NULL, NULL},
                        {"SourceIp", &DMWRITE, DMT_STRING, get_rule_source_ip, set_rule_source_ip, NULL, NULL},
                        {"SourceMask", &DMWRITE, DMT_STRING, get_rule_source_mask, set_rule_source_mask, NULL, NULL},
                        {"Protocol", &DMWRITE, DMT_INT, get_rule_protocol, set_rule_protocol, NULL, NULL},
                        {"DestPort", &DMWRITE, DMT_INT, get_rule_dest_port, set_rule_dest_port, NULL, NULL},
                        {"DestPortRangeMax", &DMWRITE, DMT_INT, get_rule_dest_port_range_max, set_rule_dest_port_range_max, NULL, NULL},
                        {"SourcePort", &DMWRITE, DMT_INT, get_rule_source_port, set_rule_source_port, NULL, NULL},
                        {"SourcePortRangeMax", &DMWRITE, DMT_INT, get_rule_source_port_range_max, set_rule_source_port_range_max, NULL, NULL},
                        {CUSTOM_PREFIX "IcmpType", &DMWRITE, DMT_STRING, get_rule_icmp_type, set_rule_icmp_type, NULL, NULL},
                        {CUSTOM_PREFIX "SourceMac", &DMWRITE, DMT_STRING, get_rule_source_mac, set_rule_source_mac, NULL, NULL},
                        {0}};

DMLEAF tTimeSpanParams[] = {{"SupportedDays", &DMWRITE, DMT_STRING, get_time_span_supported_days, set_time_span_supported_days, NULL, NULL},
                            {"Days", &DMWRITE, DMT_STRING, get_time_span_days, set_time_span_days, NULL, NULL},
                            {"StartTime", &DMWRITE, DMT_STRING, get_time_span_start_time, set_time_span_start_time, NULL, NULL},
                            {"StopTime", &DMWRITE, DMT_STRING, get_time_span_stop_time, set_time_span_stop_time, NULL, NULL},
                            {0}};

/***************************** Browse Functions ***********************************/
int browseLevelInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    struct uci_section *s;
    char               *v, *instance, *instnbr = NULL;

    check_create_dmmap_package("dmmap_firewall");
    s = is_dmmap_section_exist("dmmap_firewall", "level");
    if (!s)
        dmuci_add_section_icwmpd("dmmap_firewall", "level", &s, &v);
    instance = handle_update_instance(1, dmctx, &instnbr, update_instance_alias, 3, s, "firewall_level_instance", "firewall_level_alias");

    DM_LINK_INST_OBJ(dmctx, parent_node, s, "1");
    return 0;
}

int browseChainInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    struct uci_section *s;
    char               *v, *instance, *instnbr = NULL;

    check_create_dmmap_package("dmmap_firewall");
    s = is_dmmap_section_exist("dmmap_firewall", "chain");
    if (!s)
        dmuci_add_section_icwmpd("dmmap_firewall", "chain", &s, &v);
    instance = handle_update_instance(1, dmctx, &instnbr, update_instance_alias, 3, s, "firewall_chain_instance", "firewall_chain_alias");

    DM_LINK_INST_OBJ(dmctx, parent_node, s, "1");
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.!UCI:firewall/rule/dmmap_firewall*/
int browseRuleInst(struct dmctx *dmctx, DMNODE *parent_node, void *prev_data, char *prev_instance)
{
    char             *instance, *instnbr = NULL;
    struct dmmap_dup *p;
    LIST_HEAD(dup_list);

    synchronize_specific_config_sections_with_dmmap("firewall", "rule", "dmmap_firewall", &dup_list);
    list_for_each_entry(p, &dup_list, list)
    {
        instance = handle_update_instance(1, dmctx, &instnbr, update_instance_alias, 3, p->dmmap_section, "firewall_chain_rule_instance", "firewall_chain_rule_alias");
        if (DM_LINK_INST_OBJ(dmctx, parent_node, ( void * )p->config_section, instance) == DM_STOP)
            return 0;
    }
    free_dmmap_config_dup_list(&dup_list);
    return 0;
}

int add_firewall_rule(char *refparam, struct dmctx *ctx, void *data, char **instance)
{
    struct uci_section *s, *dmmap_firewall_rule;
    char               *last_inst = NULL, *sect_name = NULL, *rule_name, *v;
    char                ib[8];
    last_inst = get_last_instance_icwmpd("dmmap_firewall", "rule", "firewall_chain_rule_instance");
    if (last_inst)
        sprintf(ib, "%s", last_inst);
    else
        sprintf(ib, "%s", "1");
    dmasprintf(&rule_name, "Firewall rule %d", atoi(ib) + 1);

    dmuci_add_section("firewall", "rule", &s, &sect_name);
    dmuci_set_value_by_section(s, "name", rule_name);
    dmuci_set_value_by_section(s, "dest", "lan");
    dmuci_set_value_by_section(s, "src", "wan");
    dmuci_set_value_by_section(s, "target", "ACCEPT");

    dmuci_add_section_icwmpd("dmmap_firewall", "rule", &dmmap_firewall_rule, &v);
    dmuci_set_value_by_section(dmmap_firewall_rule, "section_name", sect_name);
    *instance = update_instance_icwmpd(dmmap_firewall_rule, last_inst, "firewall_chain_rule_instance");
    return 0;
}

int delete_firewall_rule(char *refparam, struct dmctx *ctx, void *data, char *instance, unsigned char del_action)
{
    struct uci_section *s  = NULL;
    struct uci_section *ss = NULL;
    struct uci_section *dmmap_section;
    int                 found = 0;

    switch (del_action)
    {
        case DEL_INST:
            if (is_section_unnamed(section_name(( struct uci_section * )data)))
            {
                LIST_HEAD(dup_list);
                delete_sections_save_next_sections("dmmap_firewall", "rule", "firewall_chain_rule_instance", section_name(( struct uci_section * )data), atoi(instance), &dup_list);
                update_dmmap_sections(&dup_list, "firewall_chain_rule_instance", "dmmap_firewall", "rule");
                dmuci_delete_by_section_unnamed(( struct uci_section * )data, NULL, NULL);
            }
            else
            {
                get_dmmap_section_of_config_section("dmmap_firewall", "rule", section_name(( struct uci_section * )data), &dmmap_section);
                dmuci_delete_by_section_unnamed_icwmpd(dmmap_section, NULL, NULL);
                dmuci_delete_by_section(( struct uci_section * )data, NULL, NULL);
            }
            break;
        case DEL_ALL:
            uci_foreach_sections("firewall", "rule", s)
            {
                if (found != 0)
                {
                    get_dmmap_section_of_config_section("dmmap_firewall", "rule", section_name(ss), &dmmap_section);
                    if (dmmap_section != NULL)
                        dmuci_delete_by_section(dmmap_section, NULL, NULL);
                    dmuci_delete_by_section(ss, NULL, NULL);
                }
                ss = s;
                found++;
            }
            if (ss != NULL)
            {
                get_dmmap_section_of_config_section("dmmap_firewall", "rule", section_name(ss), &dmmap_section);
                if (dmmap_section != NULL)
                    dmuci_delete_by_section(dmmap_section, NULL, NULL);
                dmuci_delete_by_section(ss, NULL, NULL);
            }
    }
    return 0;
}

/***************************************** Set/Get Parameter functions ***********************/
int get_firewall_enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *path = "/etc/rc.d/*firewall";
    if (check_file(path))
        *value = "1";
    else
        *value = "0";
    return 0;
}

int get_firewall_config(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "Advanced";
    return 0;
}

int get_firewall_advanced_level(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "Device.Firewall.Level.1.";
    return 0;
}

int get_firewall_level_number_of_entries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "1";
    return 0;
}

int get_firewall_chain_number_of_entries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "1";
    return 0;
}

int get_level_name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *levels = ( struct uci_section * )data;
    dmuci_get_value_by_section_string(levels, "name", value);
    return 0;
}

int get_level_description(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *levels = ( struct uci_section * )data;
    dmuci_get_value_by_section_string(levels, "description", value);
    return 0;
}

int get_level_chain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "Device.Firewall.Chain.1.";
    return 0;
}

int get_level_port_mapping_enabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *s = NULL;
    char               *v;

    uci_foreach_sections("firewall", "zone", s)
    {
        dmuci_get_value_by_section_string(s, "masq", &v);
        if (*v == '1')
        {
            *value = "1";
            return 0;
        }
    }
    *value = "0";
    return 0;
}

int get_level_default_log_policy(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *s = NULL;
    char               *v;

    uci_foreach_sections("firewall", "zone", s)
    {
        dmuci_get_value_by_section_string(s, "log", &v);
        if (*v == '1')
        {
            *value = "1";
            return 0;
        }
    }
    *value = "0";
    return 0;
}

int get_chain_enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "1";
    return 0;
}

int get_chain_name(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *chains = ( struct uci_section * )data;
    dmuci_get_value_by_section_string(chains, "name", value);
    return 0;
}

int get_chain_creator(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "Defaults";
    return 0;
}

/*#Device.Firewall.Chain.{i}.RuleNumberOfEntries!UCI:firewall/rule/*/
int get_chain_rule_number_of_entries(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *s   = NULL;
    int                 cnt = 0;

    uci_foreach_sections("firewall", "rule", s)
    {
        cnt++;
    }
    dmasprintf(value, "%d", cnt);
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.Enable!UCI:firewall/rule,@i-1/enabled*/
int get_rule_enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "enabled", &v);
    *value = (*v == 'n' || *v == '0') ? "0" : "1";
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.Status!UCI:firewall/rule,@i-1/enabled*/
int get_rule_status(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "enabled", &v);
    *value = (*v == 'n' || *v == '0') ? "Disabled" : "Enabled";
    return 0;
}

int get_rule_order(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *dms;
    get_dmmap_section_of_config_section("dmmap_firewall", "rule", section_name(( struct uci_section * )data), &dms);
    dmuci_get_value_by_section_string(dms, "firewall_chain_rule_instance", value);
    return 0;
}

int get_rule_description(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_section *dms;
    get_dmmap_section_of_config_section("dmmap_firewall", "rule", section_name(( struct uci_section * )data), &dms);
    dmuci_get_value_by_section_string(dms, "description", value);
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.Target!UCI:firewall/rule,@i-1/target*/
int get_rule_target(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *v;
    *value = "";
    dmuci_get_value_by_section_string(( struct uci_section * )data, "target", &v);
    if (strcasecmp(v, "Accept") == 0)
    {
        *value = "Accept";
    }
    else if (strcasecmp(v, "Reject") == 0)
    {
        *value = "Reject";
    }
    else if (strcasecmp(v, "Drop") == 0)
    {
        *value = "Drop";
    }
    else if (strcasecmp(v, "MARK") == 0)
    {
        *value = "Return";
    }
    else
    {
        *value = v;
    }
    return 0;
}

int get_rule_target_chain(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    // TODO
    return 0;
}

int get_rule_source_interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_list    *v = NULL, *v1 = NULL;
    struct uci_element *e;
    char               *zone, *ifaceobj, buf[256] = "", *val;
    struct uci_section *s          = NULL;
    char                linker[64] = "", *vallink;

    dmuci_get_value_by_section_string(( struct uci_section * )data, "src", &zone);
    if (zone == NULL || strlen(zone) == 0)
        return 0;

    if (strcmp(zone, "*") == 0)
    {
        v = dmcalloc(1, sizeof(struct uci_list));
        uci_list_init(v);
        uci_foreach_sections("firewall", "zone", s)
        {
            dmuci_get_value_by_section_list(s, "network", &v1);
            uci_add_list_to_list(v1, v);
        }
    }
    else
    {
        uci_foreach_sections("firewall", "zone", s)
        {
            dmuci_get_value_by_section_string(s, "name", &val);
            if (strcmp(val, zone) == 0)
            {
                dmuci_get_value_by_section_list(s, "network", &v);
                break;
            }
        }
    }

    if (v != NULL)
    {
        uci_foreach_element(v, e)
        {
            adm_entry_get_linker_param(ctx, dm_print_path("%s%cIP%cInterface%c", dmroot, dm_delim, dm_delim, dm_delim), e->name, &vallink);
            if (*vallink == '\0')
                continue;
            if (*buf != '\0')
                strcat(buf, ",");
            strcat(buf, vallink);
        }
    }
    else
    {
        adm_entry_get_linker_param(ctx, dm_print_path("%s%cIP%cInterface%c", dmroot, dm_delim, dm_delim, dm_delim), zone, &vallink);
        strcpy(buf, vallink);
    }

    *value = dmstrdup(buf);
    return 0;
}

int get_rule_dest_interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_list    *v = NULL;
    struct uci_element *e;
    char               *zone, *ifaceobj, buf[256] = "", *val;
    struct uci_section *s = NULL;

    dmuci_get_value_by_section_string(( struct uci_section * )data, "dest", &zone);
    uci_foreach_sections("firewall", "zone", s)
    {
        dmuci_get_value_by_section_string(s, "name", &val);
        if (strcmp(val, zone) == 0)
        {
            dmuci_get_value_by_section_list(s, "network", &v);
            break;
        }
    }
    if (v != NULL)
    {
        uci_foreach_element(v, e)
        {
            adm_entry_get_linker_param(ctx, dm_print_path("%s%cIP%cInterface%c", dmroot, dm_delim, dm_delim, dm_delim), e->name, &ifaceobj);
            if (*ifaceobj == '\0')
                continue;
            if (*buf != '\0')
                strcat(buf, ",");
            strcat(buf, ifaceobj);
        }
    }

    *value = dmstrdup(buf);
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.IPVersion!UCI:firewall/rule,@i-1/family*/
int get_rule_i_p_version(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *ipversion;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "family", &ipversion);
    if (strcasecmp(ipversion, "ipv4") == 0)
    {
        *value = "4";
    }
    else if (strcasecmp(ipversion, "ipv6") == 0)
    {
        *value = "6";
    }
    else
    {
        *value = "-1";
    }
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.DestIp!UCI:firewall/rule,@i-1/dest_ip*/
int get_rule_dest_ip(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char  buf[64];
    char *pch;
    char *destip;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_ip", &destip);
    strcpy(buf, destip);
    pch = strchr(buf, '/');
    if (pch)
        *pch = '\0';
    *value = dmstrdup(buf);
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.DestMask!UCI:firewall/rule,@i-1/dest_ip*/
int get_rule_dest_mask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *pch;
    *value = "";

    char *destip;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_ip", &destip);
    if (*destip == '\0')
        return 0;

    pch = strchr(destip, '/');
    if (pch)
    {
        *value = pch + 1;
    }
    else
    {
        *value = "";
    }
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.SourceIp!UCI:firewall/rule,@i-1/src_ip*/
int get_rule_source_ip(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char  buf[64];
    char *pch;
    char *srcip;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "src_ip", &srcip);
    strcpy(buf, srcip);
    pch = strchr(buf, '/');
    if (pch)
        *pch = '\0';
    *value = dmstrdup(buf);
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.SourceMask!UCI:firewall/rule,@i-1/src_ip*/
int get_rule_source_mask(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *pch;
    *value = "";

    char *srcip;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "src_ip", &srcip);
    if (*srcip == '\0')
        return 0;

    pch = strchr(srcip, '/');
    if (pch)
    {
        *value = pch + 1;
    }
    else
    {
        *value = "";
    }
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.Protocol!UCI:firewall/rule,@i-1/proto*/
int get_rule_protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    FILE               *fp;
    char                buf[256];
    char                protocol[32];
    char                protocol_nbr[16];
    struct uci_section *ss = ( struct uci_section * )data;
    char               *v;

    dmuci_get_value_by_section_string(( struct uci_section * )data, "proto", &v);
    *value = "-1";
    if (*v == '\0' || *v == '0')
    {
        return 0;
    }
    if (isdigit_str(v))
    {
        *value = v;
        return 0;
    }
    fp = fopen("/etc/protocols", "r");
    if (fp == NULL)
        return 0;
    while (fgets(buf, 256, fp) != NULL)
    {
        sscanf(buf, "%s %s", protocol, protocol_nbr);
        if (strcmp(protocol, v) == 0)
        {
            *value = dmstrdup(protocol_nbr);
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.DestPort!UCI:firewall/rule,@i-1/dest_port*/
int get_rule_dest_port(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *tmp;
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_port", &v);
    v   = dmstrdup(v);
    tmp = strchr(v, ':');
    if (tmp == NULL)
        tmp = strchr(v, '-');
    if (tmp)
        *tmp = '\0';
    if (*v == '\0')
    {
        *value = "-1";
        return 0;
    }
    *value = v;
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.DestPortRangeMax!UCI:firewall/rule,@i-1/dest_port*/
int get_rule_dest_port_range_max(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *rpch, *tmp;
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_port", &v);
    tmp = strchr(v, ':');
    if (tmp == NULL)
        tmp = strchr(v, '-');
    *value = (tmp) ? tmp + 1 : "-1";
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.SourcePort!UCI:firewall/rule,@i-1/src_port*/
int get_rule_source_port(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *tmp;
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "src_port", &v);
    v   = dmstrdup(v);
    tmp = strchr(v, ':');
    if (tmp == NULL)
        tmp = strchr(v, '-');
    if (tmp)
        *tmp = '\0';
    if (*v == '\0')
    {
        *value = "-1";
        return 0;
    }
    *value = v;
    return 0;
}

/*#Device.Firewall.Chain.{i}.Rule.{i}.SourcePortRangeMax!UCI:firewall/rule,@i-1/src_port*/
int get_rule_source_port_range_max(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *rpch, *tmp;
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "src_port", &v);
    tmp = strchr(v, ':');
    if (tmp == NULL)
        tmp = strchr(v, '-');
    *value = (tmp) ? tmp + 1 : "-1";
    return 0;
}

int get_rule_icmp_type(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    struct uci_list    *v = NULL;
    struct uci_element *e;
    char               *ptr;

    dmasprintf(value, "%s", "");
    dmuci_get_value_by_section_list(( struct uci_section * )data, "icmp_type", &v);
    if (v != NULL)
    {
        uci_foreach_element(v, e)
        {
            ptr = dmstrdup(*value);
            free(*value);

            if (strlen(ptr) == 0)
                dmasprintf(value, "%s", e->name);
            else
            {
                dmasprintf(value, "%s %s", ptr, e->name);
                free(ptr);
            }
        }
    }
    return 0;
}

int get_rule_source_mac(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *v = NULL;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "src_mac", &v);
    *value = (v) ? v : "";
    return 0;
}

int get_time_span_supported_days(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    *value = "mon tue wed thu fri sat sun";
    return 0;
}

int get_time_span_days(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "weekdays", &v);
    *value = (v) ? v : "";
    return 0;
}

int get_time_span_start_time(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "start_time", &v);
    *value = (v) ? v : "";
    return 0;
}

int get_time_span_stop_time(char *refparam, struct dmctx *ctx, void *data, char *instance, char **value)
{
    char *v;
    dmuci_get_value_by_section_string(( struct uci_section * )data, "stop_time", &v);
    *value = (v) ? v : "";
    return 0;
}

int set_firewall_enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    bool b;
    switch (action)
    {
        case VALUECHECK:
            if (string_to_bool(value, &b))
                return FAULT_9007;
            break;
        case VALUESET:
            string_to_bool(value, &b);
            if (b)
                dmcmd("/etc/init.d/firewall", 1, "enable");
            else
                dmcmd("/etc/init.d/firewall", 1, "disable");
            break;
    }
    return 0;
}

int set_firewall_config(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            if (strcasecmp(value, "Advanced") != 0)
                return FAULT_9007;
            break;
        case VALUESET:
            break;
    }
    return 0;
}

int set_firewall_advanced_level(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            if (strcasecmp(value, "Device.Firewall.Level.1.") != 0)
                return FAULT_9007;
            break;
        case VALUESET:
            break;
    }
    return 0;
}

int set_level_name(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    struct uci_section *level = ( struct uci_section * )data;
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            DMUCI_SET_VALUE_BY_SECTION(icwmpd, level, "name", value);
            break;
    }
    return 0;
}

int set_level_description(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    struct uci_section *level = ( struct uci_section * )data;
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            DMUCI_SET_VALUE_BY_SECTION(icwmpd, level, "description", value);
            break;
    }
    return 0;
}

int set_level_port_mapping_enabled(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    bool                b;
    struct uci_section *s = NULL;
    char               *v, *v2;

    switch (action)
    {
        case VALUECHECK:
            if (string_to_bool(value, &b))
                return FAULT_9007;
            break;
        case VALUESET:
            string_to_bool(value, &b);
            if (b)
            {
                uci_foreach_sections("firewall", "zone", s)
                {
                    dmuci_get_value_by_section_string(s, "src", &v);
                    dmuci_get_value_by_section_string(s, "name", &v2);
                    if (strcasestr(v, "wan") || strcasestr(v2, "wan"))
                    {
                        dmuci_set_value_by_section(s, "masq", "1");
                        return 0;
                    }
                }
            }
            else
            {
                uci_foreach_sections("firewall", "zone", s)
                {
                    dmuci_set_value_by_section(s, "masq", "");
                }
            }
            break;
    }
    return 0;
}

int set_level_default_log_policy(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    bool                b;
    struct uci_section *s = NULL;

    switch (action)
    {
        case VALUECHECK:
            if (string_to_bool(value, &b))
                return FAULT_9007;
            break;
        case VALUESET:
            string_to_bool(value, &b);
            if (b)
            {
                uci_foreach_sections("firewall", "zone", s)
                {
                    dmuci_set_value_by_section(s, "log", "1");
                }
            }
            else
            {
                uci_foreach_sections("firewall", "zone", s)
                {
                    dmuci_set_value_by_section(s, "log", "");
                }
            }
            break;
    }
    return 0;
}

int set_chain_enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    bool b;
    switch (action)
    {
        case VALUECHECK:
            if (string_to_bool(value, &b) || !b)
                return FAULT_9007;
            break;
        case VALUESET:
            break;
    }
    return 0;
}

int set_chain_name(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    struct uci_section *chains = ( struct uci_section * )data;

    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            DMUCI_SET_VALUE_BY_SECTION(icwmpd, chains, "name", value);
            break;
    }
    return 0;
}

int set_rule_enable(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    bool b;

    switch (action)
    {
        case VALUECHECK:
            if (string_to_bool(value, &b))
                return FAULT_9007;
            break;
        case VALUESET:
            string_to_bool(value, &b);
            dmuci_set_value_by_section(( struct uci_section * )data, "enabled", (b) ? "" : "no");
            break;
    }
    return 0;
}

int set_rule_order(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            break;
    }
    return 0;
}

int set_rule_description(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    struct uci_section *dms;
    get_dmmap_section_of_config_section("dmmap_firewall", "rule", section_name(( struct uci_section * )data), &dms);
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            DMUCI_SET_VALUE_BY_SECTION(icwmpd, dms, "description", value);
            break;
    }
    return 0;
}

int set_rule_target(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            if (strcasecmp(value, "Accept") == 0)
            {
                dmuci_set_value_by_section(( struct uci_section * )data, "target", "ACCEPT");
            }
            else if (strcasecmp(value, "Reject") == 0)
            {
                dmuci_set_value_by_section(( struct uci_section * )data, "target", "REJECT");
            }
            else if (strcasecmp(value, "Drop") == 0)
            {
                dmuci_set_value_by_section(( struct uci_section * )data, "target", "DROP");
            }
            else if (strcasecmp(value, "Return") == 0)
            {
                dmuci_set_value_by_section(( struct uci_section * )data, "target", "MARK");
            }
            break;
    }
    return 0;
}

int set_rule_target_chain(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            break;
    }
    return 0;
}

int set_rule_source_interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char               *iface, *zone, *v = "", *val, *net;
    struct uci_section *s = NULL;

    switch (action)
    {
        case VALUECHECK:
            adm_entry_get_linker_value(ctx, value, &iface);
            if (iface == NULL || iface[0] == '\0')
                return FAULT_9007;
            break;
        case VALUESET:
            adm_entry_get_linker_value(ctx, value, &iface);
            if (iface && iface[0] != '\0')
            {
                uci_foreach_sections("firewall", "zone", s)
                {
                    dmuci_get_value_by_section_string(s, "network", &net);
                    if (dm_strword(net, iface))
                    {
                        dmuci_get_value_by_section_string(s, "name", &zone);
                        dmuci_set_value_by_section(( struct uci_section * )data, "src", zone);
                        break;
                    }
                }
            }
            break;
    }
    return 0;
}

int set_rule_dest_interface(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char               *iface, *zone, *v = "", *net;
    struct uci_section *s = NULL;

    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            adm_entry_get_linker_value(ctx, value, &iface);
            if (iface != NULL && iface[0] != '\0')
            {
                uci_foreach_sections("firewall", "zone", s)
                {
                    dmuci_get_value_by_section_string(s, "name", &net);
                    if (dm_strword(net, iface))
                    {
                        dmuci_get_value_by_section_string(s, "name", &zone);
                        dmuci_set_value_by_section(( struct uci_section * )data, "dest", zone);
                        break;
                    }
                }
            }
            break;
    }
    return 0;
}

int set_rule_i_p_version(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            if (strcmp(value, "4") == 0)
            {
                dmuci_set_value_by_section(( struct uci_section * )data, "family", "ipv4");
            }
            else if (strcmp(value, "6") == 0)
            {
                dmuci_set_value_by_section(( struct uci_section * )data, "family", "ipv6");
            }
            else if (strcmp(value, "-1") == 0)
            {
                dmuci_set_value_by_section(( struct uci_section * )data, "family", "");
            }
            break;
            break;
    }
    return 0;
}

int set_rule_dest_ip(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char  buf[64], new[64];
    char *pch, *destip;

    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_ip", &destip);
            strcpy(buf, destip);
            pch = strchr(buf, '/');
            if (pch)
            {
                sprintf(new, "%s%s", value, pch);
            }
            else
            {
                strcpy(new, value);
            }
            dmuci_set_value_by_section(( struct uci_section * )data, "dest_ip", new);
            break;
    }
    return 0;
}

int set_rule_dest_mask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char  buf[64], new[64];
    char *pch, *destip;

    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_ip", &destip);
            strcpy(buf, destip);
            pch = strchr(buf, '/');
            if (pch)
            {
                *pch = '\0';
            }
            sprintf(new, "%s/%s", buf, value);
            dmuci_set_value_by_section(( struct uci_section * )data, "dest_ip", new);
            break;
    }
    return 0;
}

int set_rule_source_ip(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char  buf[64], new[64];
    char *pch, *srcip;

    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_get_value_by_section_string(( struct uci_section * )data, "src_ip", &srcip);
            strcpy(buf, srcip);
            pch = strchr(buf, '/');
            if (pch)
            {
                sprintf(new, "%s%s", value, pch);
            }
            else
            {
                strcpy(new, value);
            }
            dmuci_set_value_by_section(( struct uci_section * )data, "src_ip", new);
            break;
    }
    return 0;
}

int set_rule_source_mask(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char  buf[64], new[64];
    char *pch, *srcip;

    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_get_value_by_section_string(( struct uci_section * )data, "src_ip", &srcip);
            strcpy(buf, srcip);
            pch = strchr(buf, '/');
            if (pch)
            {
                *pch = '\0';
            }
            sprintf(new, "%s/%s", buf, value);
            dmuci_set_value_by_section(( struct uci_section * )data, "src_ip", new);
            break;
    }
    return 0;
}

int set_rule_protocol(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            if (*value == '-')
                dmuci_set_value_by_section(( struct uci_section * )data, "proto", "");
            else
                dmuci_set_value_by_section(( struct uci_section * )data, "proto", value);
            break;
    }
    return 0;
}

int set_rule_dest_port(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char *v, buffer[64], *tmp;
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            if (*value == '-')
                value = "";
            dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_port", &v);
            tmp = strchr(v, ':');
            if (tmp == NULL)
                tmp = strchr(v, '-');

            if (tmp == NULL)
            {
                sprintf(buffer, "%s", value);
            }
            else
            {
                sprintf(buffer, "%s%s", value, tmp);
            }
            dmuci_set_value_by_section(( struct uci_section * )data, "dest_port", buffer);
            break;
    }
    return 0;
}

int set_rule_dest_port_range_max(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char *v, *tmp, *buf, buffer[64];
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_get_value_by_section_string(( struct uci_section * )data, "dest_port", &v);
            buf = dmstrdup(v);
            v   = buf;
            tmp = strchr(buf, ':');
            if (tmp == NULL)
                tmp = strchr(v, '-');
            if (tmp)
                *tmp = '\0';
            if (*value == '-')
            {
                sprintf(buffer, "%s", v);
            }
            else
            {
                sprintf(buffer, "%s:%s", v, value);
            }
            dmfree(buf);
            dmuci_set_value_by_section(( struct uci_section * )data, "dest_port", buffer);
            break;
    }
    return 0;
}

int set_rule_source_port(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char *v, buffer[64], *tmp;
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            if (*value == '-')
                value = "";
            dmuci_get_value_by_section_string(( struct uci_section * )data, "src_port", &v);
            tmp = strchr(v, ':');
            if (tmp == NULL)
                tmp = strchr(v, '-');
            if (tmp == NULL)
            {
                sprintf(buffer, "%s", value);
            }
            else
            {
                sprintf(buffer, "%s%s", value, tmp);
            }
            dmuci_set_value_by_section(( struct uci_section * )data, "src_port", buffer);
            break;
    }
    return 0;
}

int set_rule_source_port_range_max(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    char *v, *tmp, *buf, buffer[64];
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_get_value_by_section_string(( struct uci_section * )data, "src_port", &v);
            buf = dmstrdup(v);
            v   = buf;
            tmp = strchr(buf, ':');
            if (tmp == NULL)
                tmp = strchr(buf, '-');
            if (tmp)
                *tmp = '\0';
            if (*value == '-')
            {
                sprintf(buffer, "%s", v);
            }
            else
            {
                sprintf(buffer, "%s:%s", v, value);
            }
            dmfree(buf);
            dmuci_set_value_by_section(( struct uci_section * )data, "src_port", buffer);
            break;
    }
    return 0;
}

int set_rule_icmp_type(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    int    length, i;
    char **devices = NULL;
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_set_value_by_section(( struct uci_section * )data, "icmp_type", "");
            devices = strsplit(value, " ", &length);
            for (i = 0; i < length; i++) dmuci_add_list_value_by_section(( struct uci_section * )data, "icmp_type", devices[i]);
            break;
    }
    return 0;
}

int set_rule_source_mac(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_set_value_by_section(( struct uci_section * )data, "src_mac", value);
            break;
    }
    return 0;
}

int set_time_span_supported_days(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            break;
    }
    return 0;
}

int set_time_span_days(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_set_value_by_section(( struct uci_section * )data, "weekdays", value);
            break;
    }
    return 0;
}

int set_time_span_start_time(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_set_value_by_section(( struct uci_section * )data, "start_time", value);
            break;
    }
    return 0;
}

int set_time_span_stop_time(char *refparam, struct dmctx *ctx, void *data, char *instance, char *value, int action)
{
    switch (action)
    {
        case VALUECHECK:
            break;
        case VALUESET:
            dmuci_set_value_by_section(( struct uci_section * )data, "stop_time", value);
            break;
    }
    return 0;
}
