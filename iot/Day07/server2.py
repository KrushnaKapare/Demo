# import Flask from flask module
from flask import Flask

# create a server
server = Flask(__name__)

@server.get('/')
def homepage():
    return "<html> <body> <h1>This is home page </h1></body></html>"

@server.get('/welcome')
def welcome():
    return "<html> <body> <h1>Welcome to IoT Application </h1></body></html>"


# run the server
if __name__ == '__main__':
    server.run(host='0.0.0.0', port=4000, debug=True)

# host='0.0.0.0'  --> server can be accessed from any machine in network
# port=4000     --> server is listening on port 4000 instead of 5000
# debug=True    --> server will automatically restarted when server code is updated