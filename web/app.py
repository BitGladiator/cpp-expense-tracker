from flask import Flask, render_template, request, redirect
import csv
import os

app = Flask(__name__)

# Full path to ../data/expenses.csv
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.join(BASE_DIR, '..', 'data')
DATA_FILE = os.path.join(DATA_DIR, 'expenses.csv')

def load_expenses():
    expenses = []
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, newline='', encoding='utf-8') as f:
            reader = csv.reader(f)
            for row in reader:
                if len(row) == 4:
                    amount, category, date, note = row
                    expenses.append({
                        'amount': amount,
                        'category': category,
                        'date': date,
                        'note': note
                    })
    return expenses

def save_expense(expense):
    # Ensure the ../data directory exists
    os.makedirs(DATA_DIR, exist_ok=True)

    with open(DATA_FILE, mode='a', newline='', encoding='utf-8') as f:
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

if __name__ == '__main__':
    app.run(debug=True)
