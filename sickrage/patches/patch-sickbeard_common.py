$NetBSD$

--- sickbeard/common.py.orig	2015-12-31 12:10:41.000000000 +0000
+++ sickbeard/common.py
@@ -45,7 +45,7 @@ from sickrage.helper.encoding import ek
 SPOOF_USER_AGENT = False
 INSTANCE_ID = str(uuid.uuid1())
 USER_AGENT = ('SickRage/(' + platform.system() + '; ' + platform.release() + '; ' + INSTANCE_ID + ')')
-UA_SETTINGS.DB = ek(path.abspath, ek(path.join, ek(path.dirname, __file__), '../lib/fake_useragent/ua.json'))
+UA_SETTINGS.DB = 'ua.json'
 UA_POOL = UserAgent()
 if SPOOF_USER_AGENT:
     USER_AGENT = UA_POOL.random
