$NetBSD$

--- CouchPotato.py.orig	2015-05-23 00:06:22.501574361 +0000
+++ CouchPotato.py
@@ -15,7 +15,7 @@ import traceback
 base_path = dirname(os.path.abspath(__file__))
 
 # Insert local directories into path
-sys.path.insert(0, os.path.join(base_path, 'libs'))
+sys.path.insert(0,'%%PREFIX%%/share/couchpotato')
 
 from couchpotato.environment import Env
 from couchpotato.core.helpers.variable import getDataDir, removePyc
