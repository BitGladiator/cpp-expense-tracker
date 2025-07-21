from flask import Flask, render_template, request, redirect
import csv
import os

app = Flask(__name__)

# Full path to ../data/expenses.csv
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.join(BASE_DIR, '..', 'data')
DATA_FILE = os.path.join(DATA_DIR, 'expenses.csv')

# Ensure data directory exists
os.makedirs(DATA_DIR, exist_ok=True)


def load_expenses():
    expenses = []
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, newline='') as f:
            reader = csv.reader(f)
            for idx, row in enumerate(reader):
                if len(row) == 4:
                    amount, category, date, note = row
                    expenses.append({
                        'id': idx,
                        'amount': amount,
                        'category': category,
                        'date': date,
                        'note': note
                    })
    return expenses


def save_all_expenses(expenses):
    with open(DATA_FILE, mode='w', newline='') as f:
        writer = csv.writer(f)
        for expense in expenses:
            writer.writerow([expense['amount'], expense['category'], expense['date'], expense['note']])

def save_expense(expense):
    with open(DATA_FILE, mode='a', newline='') as f:
        writer = csv.writer(f)
        writer.writerow([expense['amount'], expense['category'], expense['date'], expense['note']])

@app.route('/')
def index():
    expenses = load_expenses()
    return render_template('index.html', expenses=expenses)

@app.route('/add', methods=['POST'])
def add_expense():
    expense = {
        'amount': request.form['amount'],
        'category': request.form['category'],
        'date': request.form['date'],
        'note': request.form['note']
    }
    save_expense(expense)
    return redirect('/')

@app.route('/delete/<int:expense_id>', methods=['POST'])
def delete_expense(expense_id):
    expenses = load_expenses()
    if 0 <= expense_id < len(expenses):
        del expenses[expense_id]
        save_all_expenses(expenses)
    return redirect('/')

@app.route('/edit/<int:expense_id>', methods=['GET', 'POST'])
def edit_expense(expense_id):
    expenses = load_expenses()
    if request.method == 'POST':
        if 0 <= expense_id < len(expenses):
            expenses[expense_id] = {
                'amount': request.form['amount'],
                'category': request.form['category'],
                'date': request.form['date'],
                'note': request.form['note']
            }
            save_all_expenses(expenses)
            return redirect('/')
    else:
        if 0 <= expense_id < len(expenses):
            expense = expenses[expense_id]
            return render_template('edit.html', expense=expense)
    return redirect('/')