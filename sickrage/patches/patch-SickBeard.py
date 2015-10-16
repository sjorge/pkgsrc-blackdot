$NetBSD$

--- SickBeard.py.orig	2015-10-14 23:36:41.000000000 +0000
+++ SickBeard.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python2.7
+#!/opt/local/bin/python2.7
 # Author: Nic Wolfe <nic@wolfeden.ca>
 # URL: http://code.google.com/p/sickbeard/
 #
@@ -34,7 +34,10 @@ import subprocess
 import traceback
 
 import os
-sys.path.insert(1, os.path.abspath(os.path.join(os.path.dirname(__file__), 'lib')))
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,'/opt/local/share/sickrage/lib')
+sys.path.insert(1,'/opt/local/share/sickrage')
 
 import shutil
 import shutil_custom
@@ -156,7 +159,7 @@ class SickRage(object):
         # do some preliminary stuff
         sickbeard.MY_FULLNAME = os.path.normpath(os.path.abspath(__file__))
         sickbeard.MY_NAME = os.path.basename(sickbeard.MY_FULLNAME)
-        sickbeard.PROG_DIR = os.path.dirname(sickbeard.MY_FULLNAME)
+        sickbeard.PROG_DIR = '/opt/local/share/sickrage'
         sickbeard.DATA_DIR = sickbeard.PROG_DIR
         sickbeard.MY_ARGS = sys.argv[1:]
         sickbeard.SYS_ENCODING = None
