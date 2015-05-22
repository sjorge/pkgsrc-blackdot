$NetBSD$

--- SickBeard.py.orig	2015-05-22 22:51:55.332104723 +0000
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
@@ -170,7 +174,7 @@ def main():
     # do some preliminary stuff
     sickbeard.MY_FULLNAME = os.path.normpath(os.path.abspath(sys.argv[0]))
     sickbeard.MY_NAME = os.path.basename(sickbeard.MY_FULLNAME)
-    sickbeard.PROG_DIR = os.path.dirname(sickbeard.MY_FULLNAME)
+    sickbeard.PROG_DIR = '%%PREFIX%%/share/sickbeard'
     sickbeard.DATA_DIR = sickbeard.PROG_DIR
     sickbeard.MY_ARGS = sys.argv[1:]
     sickbeard.DAEMON = False
