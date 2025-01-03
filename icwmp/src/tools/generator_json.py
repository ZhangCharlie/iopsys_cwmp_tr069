#!/usr/bin/python

#      This program is free software: you can redistribute it and/or modify
#      it under the terms of the GNU General Public License as published by
#      the Free Software Foundation, either version 2 of the License, or
#      (at your option) any later version.
#
#      Copyright (C) 2019 iopsys Software Solutions AB
#		Author: Amin Ben Ramdhane <amin.benramdhane@pivasoftware.com>

#	Copyright (C) 2019 PIVA SOFTWARE <www.pivasoftware.com> - All Rights Reserved
#		Author: Mohamed Kallel <mohamed.kallel@pivasoftware.com>

import os, sys, time, re, json
import xml.etree.ElementTree as xml
from collections import OrderedDict
from shutil import copyfile

def removefile( filename ):
	try:
		os.remove(filename)
	except OSError:
		pass

def securemkdir( folder ):
	try:
		os.mkdir(folder)
	except:
		pass

def getname( objname ):
	global model_root_name
	OBJSname = objname
	if (objname.count('.') > 1 and (objname.count('.') != 2 or objname.count('{i}') != 1) ):
		OBJSname = objname.replace(dmroot.get('name'), "", 1)
	OBJSname = OBJSname.replace("{i}", "")
	OBJSname = OBJSname.replace(".", "")
	if (objname.count('.') == 1):
		model_root_name = OBJSname
		OBJSname = "Root" + OBJSname
		return OBJSname
	if (objname.count('.') == 2 and objname.count('{i}') == 1):
		model_root_name = OBJSname
		OBJSname = "Services" + OBJSname
		return OBJSname
	return OBJSname;

def getparamtype( dmparam ):
	ptype = None
	for s in dmparam:
		if s.tag == "syntax":
			for c in s:
				if c.tag == "list":
					ptype = "string"
					break
				if c.tag == "dataType":
					reftype = c.get("ref")
					if "StatsCounter" in reftype:
						ptype = "unsignedInt"
						break
					ptype = "string"
					break
				ptype = c.tag
				break
			break
	if ptype == None:
		ptype = "__NA__"
	return ptype

def getparamrange( dmparam ):
	min = None
	max = None
	for s in dmparam:
		if s.tag == "syntax":
			for c in s:
				for o in c:
					if o.tag == "range":
						min = o.get("minInclusive")
						max = o.get("maxInclusive")
						break
	if min == None:
		min = ""
	if max == None:
		max = ""
	return min, max

def getparamunit( dmparam ):
	unit = None
	for s in dmparam:
		if s.tag == "syntax":
			for c in s:
				for o in c:
					if o.tag == "units":
						unit = o.get("value")
						break
	if unit == None:
		unit = ""
	return unit

def getparamvalues( dmparam ):
	hasvalues = 0
	values = ""
	for s in dmparam:
		if s.tag == "syntax":
			for c in s:
				if c.tag == "string":
					for a in c:
						if a.tag == "enumeration":
							hasvalues = 1
							for x in c.findall('enumeration'):
								if values:
									values = "%s, \"%s\"" % (values, x.get('value'))
								else:
									values = "\"%s\"" % x.get('value')
							break
				
			break
	return hasvalues, values

def objhaschild (parentname, level):
	hasobj = 0
	for c in model:
		objname = c.get('name')
		if c.tag == "object" and parentname in objname and (objname.count('.') - objname.count('{i}')) == level:
			hasobj = 1
			break;
	return hasobj

def objhasparam (dmobject):
	hasparam = 0
	for c in dmobject:
		if c.tag == "parameter":
			hasparam = 1
			break;
	return hasparam

def printopenobject (obj):
	fp = open('./.json_tmp', 'a')
	print >> fp, "\"%s\" : {" % obj.get('name')
	fp.close()

def printopenfile ():
	fp = open('./.json_tmp', 'a')
	print >> fp, "{"
	fp.close()

def printclosefile ():
	fp = open('./.json_tmp', 'a')
	print >> fp, "}"
	fp.close()

def removelastline ():
	file = open("./.json_tmp")
	lines = file.readlines()
	lines = lines[:-1]
	file.close()
	w = open("./.json_tmp",'w')
	w.writelines(lines)
	w.close()
	printclosefile ()

def replace_data_in_file( data_in, data_out ):
	file_r = open("./.json_tmp", "rt")
	file_w = open("./.json_tmp_1", "wt")
	text = ''.join(file_r).replace(data_in, data_out)
	file_w.write(text)
	file_r.close()
	file_w.close()
	copyfile("./.json_tmp_1", "./.json_tmp")
	removefile("./.json_tmp_1")

def updatejsontmpfile ():
	replace_data_in_file ("}\n", "},\n")
	replace_data_in_file ("},\n},", "}\n},")
	replace_data_in_file ("}\n},\n},", "}\n}\n},")
	replace_data_in_file ("}\n},\n}\n},", "}\n}\n}\n},")
	replace_data_in_file ("}\n},\n}\n}\n},", "}\n}\n}\n}\n},")
	replace_data_in_file ("}\n}\n}\n},\n}\n},", "}\n}\n}\n}\n}\n},")
	replace_data_in_file ("}\n}\n}\n}\n}\n}\n},", "}\n}\n}\n}\n}\n}\n},")

def removetmpfiles():
	removefile("./.json_tmp")
	removefile("./.json_tmp_1")

def printOBJ( dmobject, hasobj, hasparam ):
	if (dmobject.get('name')).endswith(".{i}."):
		fbrowse = "true"
	else:
		fbrowse = "false"

	fp = open('./.json_tmp', 'a')
	print >> fp,  "\"type\" : \"object\","
	if (dmobject.get('access') == "readOnly"):
		print >> fp,  "\"access\" : \"false\","	
	else:
		print >> fp,  "\"access\" : \"true\","
	if hasparam or hasobj:
		print >> fp,  "\"array\" : \"%s\"," % fbrowse
	else:
		print >> fp,  "\"array\" : \"%s\"" % fbrowse
	fp.close()

def printPARAM( dmparam ):
	ptype = getparamtype(dmparam)
	min, max = getparamrange(dmparam)
	unit = getparamunit(dmparam)
	hasvalues, values = getparamvalues(dmparam)
	if (dmparam.get('access') == "readOnly"):
		access = "false"
	else:
		access = "true"

	fp = open('./.json_tmp', 'a')
	print >> fp,  "\"%s\" : {" % dmparam.get('name')
	print >> fp,  "\"type\" : \"%s\"," % ptype
	if min != "" and max != "":
		print >> fp,  "\"range\" : {"
		print >> fp,  "\"min\" : \"%s\"," % min
		print >> fp,  "\"max\" : \"%s\"" % max
		print >> fp,  "},"
	elif min != "" and max == "":
		print >> fp,  "\"range\" : {"
		print >> fp,  "\"min\" : \"%s\"" % min
		print >> fp,  "},"
	elif min == "" and max != "":
		print >> fp,  "\"range\" : {"
		print >> fp,  "\"max\" : \"%s\"" % max
		print >> fp,  "},"
	if unit != "":
		print >> fp,  "\"unit\" : \"%s\"," % unit
	print >> fp,  "\"read\" : \"true\","
	if hasvalues:
		print >> fp,  "\"write\" : \"%s\"," % access
		print >> fp,  "\"values\": [%s]" % values
	else:
		print >> fp,  "\"write\" : \"%s\"" % access
	print >> fp,  "}"
	fp.close()

def printusage():
	print "Usage: " + sys.argv[0] + " <xml data model> [Object path]...[Object path]"
	print "Examples:"
	print "  - " + sys.argv[0] + " tr-181-2-12-0-cwmp-full.xml Device.WiFi."
	print "    ==> Generate the json file of the sub tree Device.WiFi. in wifi.json"
	print "  - " + sys.argv[0] + " tr-181-2-12-0-cwmp-full.xml Device.IP.Diagnostics."
	print "    ==> Generate the json file of the sub tree Device.IP.Diagnostics. in ipdiagnostics.json"
	print "  - " + sys.argv[0] + " tr-181-2-12-0-cwmp-full.xml Device.WiFi. Device.Time."
	print "    ==> Generate the json file of the sub tree Device.IP. and Device.WiFi. in time.json and wifi.json"
	print "  - " + sys.argv[0] + " tr-181-2-12-0-cwmp-full.xml Device."
	print "    ==> Generate the json file of all data model in rootdevice.json"
	print "Example of xml data model file: https://www.broadband-forum.org/cwmp/tr-181-2-12-0-cwmp-full.xml"

def getobjectpointer( objname ):
	obj = None
	for c in model:
		if c.tag == "object" and (c.get('name') == objname or c.get('name') == (objname + "{i}.")):
			obj = c
			break
	return obj

def object_parse_childs( dmobject, level):
	hasobj = objhaschild(dmobject.get('name'), level)
	hasparam = objhasparam(dmobject)

	printOBJ(dmobject, hasobj, hasparam)

	if hasparam:
		for c in dmobject:
			paramname = c.get('name')
			if c.tag == "parameter":
				printPARAM(c)

	if hasobj:
		for c in model:
			objname = c.get('name')
			if c.tag == "object" and dmobject.get('name') in objname and (objname.count('.') - objname.count('{i}')) == level:
				printopenobject(c)
				object_parse_childs(c, level+1)
				printclosefile ()

	return;

def generatejsonfromobj(pobj, pdir):
	securemkdir(pdir)
	removetmpfiles()
	dmlevel = (pobj.get('name')).count(".") - (pobj.get('name')).count("{i}.") + 1
	printopenfile ()
	printopenobject(pobj)
	object_parse_childs(pobj, dmlevel)
	dmfp = open(pdir + "/" +  (getname(pobj.get('name'))).lower() + ".json", "a")
	printclosefile ()
	printclosefile ()
	updatejsontmpfile ()
	removelastline ()

	with open("./.json_tmp", "r") as f:
		obj = json.load(f, object_pairs_hook=OrderedDict)
		dump = json.dumps(obj, indent=4)
		tabs = re.sub('\n +', lambda match: '\n' + '\t' * (len(match.group().strip('\n')) / 4), dump)

	try:
		print >> dmfp, "%s" % tabs
		dmfp.close()
	except:
		pass

	removetmpfiles()

### main ###
if len(sys.argv) < 3:
	printusage()
	exit(1)
	
if (sys.argv[1]).lower() == "-h" or (sys.argv[1]).lower() == "--help":
	printusage()
	exit(1)

model_root_name = "Root"
tree = xml.parse(sys.argv[1])

xmlroot = tree.getroot()
model = xmlroot

for child in model:
	if child.tag == "model":
		model = child

if model.tag != "model":
	print "Wrong XML Data model format!"
	exit(1)

dmroot = None
for c in model:
	if c.tag == "object" and c.get("name").count(".") == 1:
		dmroot = c
		break;

if dmroot == None:
	print "Wrong XML Data model format!"
	exit(1)

gendir = "source_" + time.strftime("%Y-%m-%d_%H-%M-%S")
isemptytreeargs = 1
	
if (len(sys.argv) > 2):
	for i in range(2, len(sys.argv)):
		if sys.argv[i] == "":
			continue
		isemptytreeargs = 0
		objstart = getobjectpointer(sys.argv[i])
		if objstart == None:
			print "Wrong Object Name! %s" % sys.argv[i]
			continue
		generatejsonfromobj(objstart, gendir)

if (os.path.isdir(gendir)):
	print "Json file generated under \"./%s\"" % gendir
else:
	print "No json file generated!"

