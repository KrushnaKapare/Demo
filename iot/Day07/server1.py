# import Flask class from flask module
from flask import Flask

# create a server with Flask
server = Flask(__name__)

@server.get('/')
def homepage():
    return "This is home page"

@server.get('/welcome')
def welcome():
    return "Welcome to IoT Application"


# run the server
server.run()