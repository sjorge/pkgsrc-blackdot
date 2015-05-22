$NetBSD$

--- SABnzbd.py.orig	2015-05-22 20:46:07.943361541 +0000
+++ SABnzbd.py
@@ -41,6 +41,9 @@ except:
     print "The Python module Cheetah is required"
     sys.exit(1)
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,'%%PREFIX%%/share/sabnzbdplus')
 import cherrypy
 if not cherrypy.__version__.startswith("3.2"):
     print "Sorry, requires Python module Cherrypy 3.2 (use the included version)"
