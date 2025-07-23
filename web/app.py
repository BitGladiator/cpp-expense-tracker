from flask import Flask, render_template, request, redirect
import csv
import os

app = Flask(__name__)

# Define full path to ../data/expenses.csv
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.join(BASE_DIR, '..', 'data')
DATA_FILE = os.path.join(DATA_DIR, 'expenses.csv')

# Create the data directory if it doesn't exist
os.makedirs(DATA_DIR, exist_ok=True)

# Load expenses from the CSV file
def load_expenses():
    expenses = []
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, newline='') as f:
            reader = csv.reader(f)
            for idx, row in enumerate(reader):
                if len(row) == 4:
                    date, amount, category, note = row
                    expenses.append({
                        'id': idx,  # Assign an ID based on the row index
                        'date': date,
                        'amount': amount,
                        'category': category,
                        'note': note
                    })
    return expenses

# Save all expenses (used after deletion or editing)
def save_all_expenses(expenses):
    with open(DATA_FILE, mode='w', newline='') as f:
        writer = csv.writer(f)
        for expense in expenses:
            writer.writerow([expense['date'], expense['amount'], expense['category'], expense['note']])

# Append a single new expense to the file
def save_expense(expense):
    with open(DATA_FILE, mode='a', newline='') as f:
        writer = csv.writer(f)
        writer.writerow([expense['date'], expense['amount'], expense['category'], expense['note']])

# Home page: show all expenses
@app.route('/')
def index():
    expenses = load_expenses()
    return render_template('index.html', expenses=expenses)

# Handle form submission to add a new expense
@app.route('/add', methods=['POST'])
def add_expense():
    expense = {
        'date': request.form['date'],
        'amount': request.form['amount'],
        'category': request.form['category'],
        'note': request.form['note']
    }
    save_expense(expense)
    return redirect('/')

# Handle deletion of an expense by ID
@app.route('/delete/<int:expense_id>', methods=['POST'])
def delete_expense(expense_id):
    expenses = load_expenses()
    if 0 <= expense_id < len(expenses):
        del expenses[expense_id]  # Remove the selected expense
        save_all_expenses(expenses)  # Overwrite the file with the updated list
    return redirect('/')

# Edit an existing expense
@app.route('/edit/<int:expense_id>', methods=['GET', 'POST'])
def edit_expense(expense_id):
    expenses = load_expenses()
    if request.method == 'POST':
        # Update the expense with new form data
        if 0 <= expense_id < len(expenses):
            expenses[expense_id] = {
                'date': request.form['date'],
                'amount': request.form['amount'],
                'category': request.form['category'],
                'note': request.form['note']
            }
            save_all_expenses(expenses)
            return redirect('/')
    else:
        # Render the edit form with current data
        if 0 <= expense_id < len(expenses):
            expense = expenses[expense_id]
            return render_template('edit.html', expense=expense)
    return redirect('/')
