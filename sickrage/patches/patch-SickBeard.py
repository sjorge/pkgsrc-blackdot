$NetBSD$

--- SickBeard.py.orig	2015-12-31 12:10:41.000000000 +0000
+++ SickBeard.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python2.7
+#!/opt/local/bin/python2.7
 # -*- coding: utf-8 -*
 # Author: Nic Wolfe <nic@wolfeden.ca>
 # URL: http://code.google.com/p/sickbeard/
@@ -34,7 +34,11 @@ import subprocess
 import traceback
 
 import os
-sys.path.insert(1, os.path.abspath(os.path.join(os.path.dirname(__file__), 'lib')))
+#sys.path.insert(1, os.path.abspath(os.path.join(os.path.dirname(__file__), 'lib')))
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,'/opt/local/share/sickrage/lib')
+sys.path.insert(1,'/opt/local/share/sickrage')
 
 import shutil
 import shutil_custom
@@ -151,7 +155,7 @@ class SickRage(object):
         # do some preliminary stuff
         sickbeard.MY_FULLNAME = ek(os.path.normpath, ek(os.path.abspath, __file__))
         sickbeard.MY_NAME = ek(os.path.basename, sickbeard.MY_FULLNAME)
-        sickbeard.PROG_DIR = ek(os.path.dirname, sickbeard.MY_FULLNAME)
+        sickbeard.PROG_DIR = '/opt/local/share/sickrage'
         sickbeard.DATA_DIR = sickbeard.PROG_DIR
         sickbeard.MY_ARGS = sys.argv[1:]
 
