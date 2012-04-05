Readme file for the Profile visits module for Drupal
---------------------------------------------

Overview:
This simple module stores visits of user's profile. The visit is stored in
database table with indication when it was made and if the user, which profile
was visIted, saw it. Currently there is limited functionality of the module,
there is no admin panel, but if the module will be approved and there will be
request for more
functionality I'm willing to extend it.

Features:

Every unique visit is stored for 1 month. If there are more visits in 1 month
time from the current user, they won't be recoreded.
Module was tuned up for performance. It uses Drupal built-in cache system and
cron jobs to clean old data.
Module has integration with views.
Requirements:

Views (required)
Installation:
Install the module through the admin panel.
For this module to work properly cron jobs must run on the site.

Usage:
For user to see his visits a proper permission must be granted "access own
visits".
Every user can see only his visits unless he has "administer users" permission.
The visits are shown under user tabs on tab "Visits". If there is any new visit
the tab title will indicate it.
Currently the visits are not stored for admin user ($uid == 1). So if admin
visit any profile it won't be recorded.
