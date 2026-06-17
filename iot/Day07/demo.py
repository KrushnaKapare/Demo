import mysql.connector
from flask import Flask, request, jsonify

app = Flask(__name__)

# Global database connection
def get_db_connection():
    return mysql.connector.connect(
        host="127.0.0.1",
        port=3306,
        user="root",
        password="root",
        database="employees",
        use_pure=True
    )

# Function to display menu
def show_menu():
    print("\n" + "="*50)
    print("EMPLOYEE MANAGEMENT SYSTEM")
    print("="*50)
    print("1. View all employees")
    print("2. Add new employee")
    print("3. Update employee name")
    print("4. Delete employee")
    print("5. View specific employee")
    print("6. Exit")
    print("="*50)
    
    choice = input("Enter your choice (1-6): ")
    return choice

# 1. View all employees
def view_all_employees():
    try:
        connection = get_db_connection()
        cursor = connection.cursor()
        
        query = "SELECT * FROM employees;"
        cursor.execute(query)
        data = cursor.fetchall()
        
        print("\n" + "-"*80)
        print(f"{'ID':<5} {'Name':<20} {'Department':<15} {'Email':<25} {'Salary':<10} {'Joining Date':<12}")
        print("-"*80)
        
        for employee in data:
            print(f"{employee[0]:<5} {employee[1]:<20} {employee[2]:<15} {employee[3]:<25} {employee[4]:<10} {employee[5]:<12}")
        
        cursor.close()
        connection.close()
        
    except Exception as e:
        print(f"Error: {e}")

# 2. Add new employee
def add_employee():
    try:
        print("\n--- ADD NEW EMPLOYEE ---")
        empid = input("Enter Employee ID: ")
        name = input("Enter Name: ")
        department = input("Enter Department: ")
        email = input("Enter Email: ")
        salary = input("Enter Salary: ")
        joining_date = input("Enter Joining Date (YYYY-MM-DD): ")
        
        connection = get_db_connection()
        cursor = connection.cursor()
        
        # Use parameterized query to prevent SQL injection
        query = "INSERT INTO employees VALUES (%s, %s, %s, %s, %s, %s)"
        values = (empid, name, department, email, salary, joining_date)
        
        cursor.execute(query, values)
        connection.commit()
        
        print(f"\n✅ Employee {name} added successfully!")
        
        cursor.close()
        connection.close()
        
    except Exception as e:
        print(f"❌ Error: {e}")

# 3. Update employee name
def update_employee():
    try:
        print("\n--- UPDATE EMPLOYEE NAME ---")
        empid = input("Enter Employee ID to update: ")
        new_name = input("Enter new name: ")
        
        connection = get_db_connection()
        cursor = connection.cursor()
        
        # Check if employee exists first
        check_query = "SELECT name FROM employees WHERE empid = %s"
        cursor.execute(check_query, (empid,))
        result = cursor.fetchone()
        
        if not result:
            print(f"❌ Employee with ID {empid} not found!")
            return
        
        # Update with parameterized query
        update_query = "UPDATE employees SET name = %s WHERE empid = %s"
        cursor.execute(update_query, (new_name, empid))
        connection.commit()
        
        print(f"\n✅ Employee {empid} updated successfully!")
        print(f"Old name: {result[0]}")
        print(f"New name: {new_name}")
        
        cursor.close()
        connection.close()
        
    except Exception as e:
        print(f"❌ Error: {e}")

# 4. Delete employee
def delete_employee():
    try:
        print("\n--- DELETE EMPLOYEE ---")
        empid = input("Enter Employee ID to delete: ")
        
        connection = get_db_connection()
        cursor = connection.cursor()
        
        # Check if employee exists first
        check_query = "SELECT name FROM employees WHERE empid = %s"
        cursor.execute(check_query, (empid,))
        result = cursor.fetchone()
        
        if not result:
            print(f"❌ Employee with ID {empid} not found!")
            return
        
        # Confirm deletion
        confirm = input(f"Are you sure you want to delete {result[0]} (ID: {empid})? (yes/no): ")
        
        if confirm.lower() == 'yes':
            delete_query = "DELETE FROM employees WHERE empid = %s"
            cursor.execute(delete_query, (empid,))
            connection.commit()
            print(f"\n✅ Employee {result[0]} (ID: {empid}) deleted successfully!")
        else:
            print("Deletion cancelled.")
        
        cursor.close()
        connection.close()
        
    except Exception as e:
        print(f"❌ Error: {e}")

# 5. View specific employee
def view_employee():
    try:
        print("\n--- VIEW EMPLOYEE DETAILS ---")
        empid = input("Enter Employee ID: ")
        
        connection = get_db_connection()
        cursor = connection.cursor()
        
        query = "SELECT * FROM employees WHERE empid = %s"
        cursor.execute(query, (empid,))
        employee = cursor.fetchone()
        
        if employee:
            print("\n" + "-"*80)
            print(f"{'ID':<5} {'Name':<20} {'Department':<15} {'Email':<25} {'Salary':<10} {'Joining Date':<12}")
            print("-"*80)
            print(f"{employee[0]:<5} {employee[1]:<20} {employee[2]:<15} {employee[3]:<25} {employee[4]:<10} {employee[5]:<12}")
        else:
            print(f"❌ Employee with ID {empid} not found!")
        
        cursor.close()
        connection.close()
        
    except Exception as e:
        print(f"❌ Error: {e}")

# Main menu loop
def main_menu():
    while True:
        choice = show_menu()
        
        if choice == '1':
            view_all_employees()
        elif choice == '2':
            add_employee()
        elif choice == '3':
            update_employee()
        elif choice == '4':
            delete_employee()
        elif choice == '5':
            view_employee()
        elif choice == '6':
            print("\n👋 Thank you for using Employee Management System!")
            break
        else:
            print("❌ Invalid choice! Please enter 1-6.")
        
        input("\nPress Enter to continue...")

# Flask API routes (if you still want REST API)
@app.route('/')
def home():
    return "Employee Management System is running!"

@app.route('/employees', methods=['GET'])
def get_employees():
    try:
        connection = get_db_connection()
        cursor = connection.cursor(dictionary=True)
        
        query = "SELECT * FROM employees;"
        cursor.execute(query)
        data = cursor.fetchall()
        
        cursor.close()
        connection.close()
        
        return jsonify({"employees": data})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route('/employees', methods=['POST'])
def api_add_employee():
    try:
        data = request.json
        
        connection = get_db_connection()
        cursor = connection.cursor()
        
        query = "INSERT INTO employees VALUES (%s, %s, %s, %s, %s, %s)"
        values = (
            data.get('empid'),
            data.get('name'),
            data.get('department'),
            data.get('email'),
            data.get('salary'),
            data.get('joining_date')
        )
        
        cursor.execute(query, values)
        connection.commit()
        
        cursor.close()
        connection.close()
        
        return jsonify({"message": "Employee added successfully"}), 201
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    print("Starting Employee Management System...")
    
    # Run menu-driven program
    main_menu()
    
    # If you want Flask API instead, comment main_menu() and uncomment below:
    # app.run(debug=True, port=5000)