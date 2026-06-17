# import Flask from flask module
from flask import Flask, request

from utils.createResponse import createResponse
from utils.executeSelectQuery import executeSelectQuery
from utils.executeQuery import executeQuery

# create a server with Flask
server = Flask(__name__)

@server.route('/', methods=['GET'])
def homepage():
    return createResponse("This is a homepage")

@server.route('/ldr', methods=['GET'])
def retrive_ldr():
    # create a query to get data from table
    query = "select * from sensorsLog where type = 'LDR';"
    # get all data of ldr from table
    values = executeSelectQuery(query)
    # return all data into response
    return createResponse(values)

@server.route('/ldr', methods=['POST'])
def create_ldr():
    # retrive data from JSON
    #type = request.get_json().get('type')
    type="LDR"
    value = request.get_json().get('value')
    location = request.get_json().get('location')
    
    #create a query to insert data into table
    query = f"insert into sensorsLog(type, value, location) values('{type}', {value}, '{location}');"

    #execute a query on database
    executeQuery(query)

    # return success in response
    return createResponse("LDR reading is added successfully")

@server.route('/ldr', methods=['PUT'])
def update_ldr():
    pass

@server.route('/ldr', methods=['DELETE'])
def delete_ldr():
    pass

@server.route('/lm35', methods=['GET', 'POST', 'PUT', 'DELETE'])
def lm35_ops():
    if request.method == 'GET':
        # create a query to get data from table
        query = "select * from sensorsLog where type = 'LM35';"
        # get all data of LM35 from table
        values = executeSelectQuery(query)
        # return all data into response
        return createResponse(values)
    
    elif request.method == 'POST':
        # retrive data from JSON
        type = request.get_json().get('type')
        value = request.get_json().get('value')
        location = request.get_json().get('location')

        #create a query to insert data into table
        query = f"insert into sensorsLog(type, value, location) values('{type}', {value}, '{location}');"

        #execute a query on database
        executeQuery(query)

        # return success in response
        return createResponse("LM35 reading is added successfully")

    elif request.method == 'PUT':
        pass
    elif request.method == 'DELETE':
        pass


# run the server continuosly
if __name__ == '__main__':
    server.run(host='0.0.0.0', debug=True)