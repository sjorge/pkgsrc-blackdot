$NetBSD$

--- CouchPotato.py.orig	2015-05-23 00:26:37.208217343 +0000
+++ CouchPotato.py
@@ -12,7 +12,7 @@ import sys
 import traceback
 
 # Root path
-base_path = dirname(os.path.abspath(__file__))
+base_path = '%%PREFIX%%/share/couchpotato'
 
 # Insert local directories into path
 sys.path.insert(0, os.path.join(base_path, 'libs'))
