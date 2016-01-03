$NetBSD$

--- sickbeard/versionChecker.py.orig	2015-12-31 12:10:41.000000000 +0000
+++ sickbeard/versionChecker.py
@@ -51,12 +51,9 @@ class CheckVersion(object):
         self.updater = None
         self.install_type = None
         self.amActive = False
-        if sickbeard.gh:
-            self.install_type = self.find_install_type()
-            if self.install_type == 'git':
-                self.updater = GitUpdateManager()
-            elif self.install_type == 'source':
-                self.updater = SourceUpdateManager()
+
+        sickbeard.BRANCH = 'master'
+        sickbeard.CUR_COMMIT_HASH = 'pkgsrc-5.0.3'
 
         self.session = requests.Session()
 
