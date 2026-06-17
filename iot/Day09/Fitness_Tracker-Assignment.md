# Fitness Tracker
Create an IoT Application for Fitness Tracker (Fit Band/watch) of multiple users.
Health parameters are as follows:
1. Step Detection
	Healthy Range: About 10,000 steps per day
2. Pulse
	Healthy Range: 60 — 100 beats per minute
3. Blood Oxygenation
	Healthy Range: 95 — 99 percent
4. Body Temperature
	Healthy Range: 97.6 — 99.6 degrees Fahrenheit
	
Along with above parameters, store users information like name, age and city.

1. Create database and table to store users information and health parameters.
2. Create web server with following routes
	i. /add - add user and health information into database table.
	ii. /all - display health information of all users.
	iii. /info - display health information of single user.
	iv. /update - update city of given user.
	v. /steps - display user information whose steps are maximum.
3. Subscribe for topic "health/status" using linux command (mosquitto_sub) and publish method name and its status(success/failure) for all above 5 requests on same topic.
