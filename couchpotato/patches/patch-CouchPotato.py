$NetBSD$

--- CouchPotato.py.orig	2015-05-23 00:46:33.149538780 +0000
+++ CouchPotato.py
@@ -12,10 +12,11 @@ import sys
 import traceback
 
 # Root path
-base_path = dirname(os.path.abspath(__file__))
+import site;
+base_path = site.getsitepackages()[0]
 
 # Insert local directories into path
-sys.path.insert(0, os.path.join(base_path, 'libs'))
+sys.path.insert(0, os.path.join('%%PREFIX%%/share/couchpotato', 'libs'))
 
 from couchpotato.environment import Env
 from couchpotato.core.helpers.variable import getDataDir, removePyc
