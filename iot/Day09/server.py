from flask import Flask, request

server = Flask(__name__)

@server.get('/')
def homepage():
    return "This is a home page"

@server.post('/ldr')
def post_ldr():
    location = request.get_json().get('location')
    value = request.get_json().get('value')

    print(f"location = {location}, value = {value}")

    return "value is received"

if __name__ == '__main__':
    server.run(host='0.0.0.0', port=4000, debug=True)