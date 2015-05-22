$NetBSD$

--- SickBeard.py.orig	2015-05-22 22:30:19.716084585 +0000
+++ SickBeard.py
@@ -22,6 +22,10 @@ import sys
 if sys.version_info < (2, 5):
     sys.exit("Sorry, requires Python 2.5, 2.6 or 2.7.")
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,'%%PREFIX%%/share/sickbeard')
+
 try:
     import Cheetah
     if Cheetah.Version[0] != '2':
